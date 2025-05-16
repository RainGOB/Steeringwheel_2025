#include "BSP_CAN.h"
#include "cmsis_os.h"

extern osEventFlagsId_t Upld_data_eventHandle;

uint8_t  data1[8] = {1,2,3,4,5,6,7,8};

void Can1Filter_Config(){
    FDCAN_FilterTypeDef FDCan1_FilterStructure;

    FDCan1_FilterStructure.IdType = FDCAN_EXTENDED_ID;               //扩展ID
    FDCan1_FilterStructure.FilterIndex = 1;                          //用于过滤索引，扩展ID，范围0到64
    FDCan1_FilterStructure.FilterType = FDCAN_FILTER_MASK;           //过滤器采样屏蔽位模式
    FDCan1_FilterStructure.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;   //如果过滤匹配，将数据保存到RX FIFO 0
    FDCan1_FilterStructure.FilterID1 = 0;
    FDCan1_FilterStructure.FilterID2 = 0;
    if(HAL_FDCAN_ConfigFilter(&hfdcan1,&FDCan1_FilterStructure)){
        Error_Handler();
    };
}

void Can2Filter_Config(){
    FDCAN_FilterTypeDef FDCan2_FilterStructure;

    FDCan2_FilterStructure.IdType = FDCAN_EXTENDED_ID;               //扩展ID
    FDCan2_FilterStructure.FilterIndex = 1;                          //用于过滤索引，扩展ID，范围0到64
    FDCan2_FilterStructure.FilterType = FDCAN_FILTER_MASK;           //过滤器采样屏蔽位模式
    FDCan2_FilterStructure.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;   //如果过滤匹配，将数据保存到RX FIFO 0
    FDCan2_FilterStructure.FilterID1 = 0;
    FDCan2_FilterStructure.FilterID2 = 0;
    if(HAL_FDCAN_ConfigFilter(&hfdcan2,&FDCan2_FilterStructure)) {
        Error_Handler();
    }
}

//can init
void CanFilter_init(){

    Can1Filter_Config();
    Can2Filter_Config();

    HAL_FDCAN_ConfigGlobalFilter(&hfdcan1, FDCAN_ACCEPT_IN_RX_FIFO0, FDCAN_ACCEPT_IN_RX_FIFO0, FDCAN_FILTER_REMOTE, FDCAN_FILTER_REMOTE);
    HAL_FDCAN_ConfigGlobalFilter(&hfdcan2, FDCAN_ACCEPT_IN_RX_FIFO0, FDCAN_ACCEPT_IN_RX_FIFO0, FDCAN_FILTER_REMOTE, FDCAN_FILTER_REMOTE);

    if(HAL_FDCAN_Start(&hfdcan1) != HAL_OK){
        Error_Handler();
    }
    if(HAL_FDCAN_Start(&hfdcan2) != HAL_OK){
        Error_Handler();
    }

    if(HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE,0) != HAL_OK){
        Error_Handler();
    }
    if(HAL_FDCAN_ActivateNotification(&hfdcan2, FDCAN_IT_RX_FIFO0_NEW_MESSAGE,0) != HAL_OK){
        Error_Handler();
    }
}

//can Tx
void CAN1_Send(uint32_t CAN_ID,uint8_t *CAN_DATA){
    TxBuff1.Identifier = CAN_ID;
    TxBuff1.IdType = FDCAN_EXTENDED_ID;
    TxBuff1.TxFrameType = FDCAN_DATA_FRAME;             //数据帧
    TxBuff1.DataLength = FDCAN_DLC_BYTES_8;
    TxBuff1.ErrorStateIndicator = FDCAN_ESI_ACTIVE;     //设置错误状态指示
    TxBuff1.BitRateSwitch = FDCAN_BRS_OFF;              //开启可变波特率
    TxBuff1.FDFormat = FDCAN_CLASSIC_CAN;
    TxBuff1.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    TxBuff1.MessageMarker = 0;

#if 1
    HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1,&TxBuff1,CAN_DATA);
#endif
}


void CAN2_Send(uint32_t CAN_ID,uint8_t *CAN_DATA){
    TxBuff2.Identifier = CAN_ID;
    TxBuff2.IdType = FDCAN_EXTENDED_ID;
    TxBuff2.TxFrameType = FDCAN_DATA_FRAME;             //数据帧
    TxBuff2.DataLength = FDCAN_DLC_BYTES_8;
    TxBuff2.ErrorStateIndicator = FDCAN_ESI_ACTIVE;     //设置错误状态指示
    TxBuff2.BitRateSwitch = FDCAN_BRS_OFF;              //开启可变波特率
    TxBuff2.FDFormat = FDCAN_CLASSIC_CAN;
    TxBuff2.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    TxBuff2.MessageMarker = 1;

#if 1
    HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2,&TxBuff2,CAN_DATA);
#endif
}


void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan,uint32_t RxFifo0ITs){
    uint8_t  mdata[8];
    HAL_StatusTypeDef	status;
    if ((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET) {
        if (hfdcan == &hfdcan1) {
            status = HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxBuff1, mdata);
            if (HAL_OK == status) {
                decode_power(RxBuff1.Identifier, mdata);
                osEventFlagsSet(Upld_data_eventHandle, 0x0f);  //0000 1111  事件标志位
            }
        }
        if (hfdcan == &hfdcan2) {
            status = HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxBuff2, mdata);
            if (HAL_OK == status) {
                decode(RxBuff2.Identifier, mdata);
                osEventFlagsSet(Upld_data_eventHandle, 0x0f);  //0000 1111  事件标志位
            }
        }
    }
}

//void HAL_FDCAN_RxFifo1Callback(FDCAN_HandleTypeDef *hfdcan,uint32_t RxFifo1ITs){
//    uint8_t  mdata[8];
//    HAL_StatusTypeDef	status;
//    if (hfdcan == &hfdcan2) {
//        if ((RxFifo1ITs & FDCAN_IT_RX_FIFO1_NEW_MESSAGE) != RESET) {
//            status = HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO1, &RxBuff2, mdata);
//            if(HAL_OK == status) {
//                CAN1_Send(0x413,data1);
//                decode(RxBuff2.Identifier, mdata);
//                //osEventFlagsSet(Upld_data_eventHandle, 0x0f);  //0000 1111  事件标志位
//            }
//        }
//    }
//}
