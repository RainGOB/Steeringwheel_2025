#ifndef _BSP_CAN_H_
#define _BSP_CAN_H_

#include "main.h"
#include "fdcan.h"
#include "app_can.h"

static FDCAN_TxHeaderTypeDef TxBuff1;    //can发送消息消息头
static FDCAN_TxHeaderTypeDef TxBuff2;
static FDCAN_RxHeaderTypeDef RxBuff1;    //can接收消息消息头
static FDCAN_RxHeaderTypeDef RxBuff2;



void CanFilter_init(void);
void CAN1_Send(uint32_t CAN_ID,uint8_t *CAN_Data);
void CAN2_Send(uint32_t CAN_ID,uint8_t *CAN_Data);

#define GUI_UPDATE_EVENT (0x01) //设置事件标志位0号

#endif
