#include "APP_CAN.h"
//#include "ui.h"

void decode(uint32_t ID,uint8_t *canData){
    switch(ID){
        case 0x211:
            racingCarData.FrontSpeed = canData[0];
            racingCarData.PedalTravel = canData[1];
            racingCarData.brakeTravel = canData[2];
            racingCarData.carTravel = canData[3];
            break;

        case 0x213:
            racingCarData.gearMode = canData[5] & 0x03;
            racingCarData.angle = canData[7] - 90;
            break;
            /*
            case 0x214:
                racingCarData.lmcu_dccur = (canData[1] + canData[0] * 256) * 0.1 -1600;
                racingCarData.rmcu_dccur = (canData[3] + canData[2] * 256) * 0.1 -1600;
                racingCarData.lmcu_accur = (canData[5] + canData[4] * 256) * 0.1 -1600;
                racingCarData.rmcu_accur = (canData[7] + canData[6] * 256) * 0.1 -1600;
                break;
        */
        case 0x50:
            racingCarData.sensor_diff = canData[1];

            if(racingCarData.sensor_diff == 0x51){
                racingCarData.acc_x = ((int16_t)(canData[2] | canData[3] << 8))  / 32768.0f * 16.0f;
                racingCarData.acc_y = ((int16_t)(canData[4] | canData[5] << 8))  / 32768.0f * 16.0f;
                racingCarData.acc_z = ((int16_t)(canData[6] | canData[7] << 8)) / 32768.0f * 16.0f;
            }
            else if(racingCarData.sensor_diff == 0x53){
                racingCarData.roll = ((int16_t)(canData[2] | canData[3] << 8)) / 32768.0 * 180.0;
                racingCarData.pitch = ((int16_t)(canData[4] | canData[5] << 8)) / 32768.0 * 180.0;
                racingCarData.yaw = ((int16_t)(canData[6] | canData[7] << 8)) / 32768.0 * 180.0;
            }
            break;
    }

}


void decode_power(uint32_t ID,uint8_t *candata){
    switch(ID){
        case 0x08C1EF21:  //VCUtoMCU1
            racingCarData.l_motor_target_rpm = (candata[0] + candata[1] * 256)/2 - 10000;
            racingCarData.l_motor_target_torque= (candata[2] + candata[3] * 256);
            racingCarData.l_target_controlmodeorder = candata[4];
            racingCarData.l_gearstage = candata[5] & 0x03;
            racingCarData.dccur = (candata[6] + candata[7] * 256 ) * 0.1;
            break;
        case 0x08B1EF21:  //VCUtoMCU2
            racingCarData.r_motor_target_rpm = (candata[0] + candata[1] * 256)/2 - 10000;
            racingCarData.r_motor_target_torque = (candata[2] + candata[3] * 256);
            racingCarData.r_target_controlmodeorder = candata[4];
            racingCarData.r_gearstage = candata[5] & 0x03;
            //racingCarData.dccur = (candata[6] + candata[7] * 256 ) * 0.1;
            break;
        case 0x0CFFC6EF:  //MCU1toVCU1
            racingCarData.l_motor_rpm = (candata[0] + candata[1] * 256)/2 - 10000;
            racingCarData.l_motor_torque = (candata[2] + candata[3] * 256);
            racingCarData.l_controlmodeorder = candata[4];
            racingCarData.lmcuinfo1 = candata[5];
            racingCarData.lmcuinfo2 = (candata[6] | candata[7] >> 2);
            break;
        case 0x0CB221EF:  //MCU2toVCU1
            racingCarData.r_motor_rpm = (candata[0] + candata[1] * 256)/2 - 10000;
            racingCarData.r_motor_torque = (candata[2] + candata[3] * 256);
            racingCarData.r_controlmodeorder = candata[4];
            racingCarData.rmcuinfo1 = candata[5];
            racingCarData.rmcuinfo2 = (candata[6] | candata[7] >> 2);
            break;
        case 0x0CFFC7EF:  //MCU1toVCU2
            racingCarData.l_mcu_temp = candata[0] - 50;
            racingCarData.l_motor_temp = candata[1] - 50;
            racingCarData.lmcu_dcvol = (candata[2] + candata[3] * 256) * 0.1;
            racingCarData.lmcu_dccur = (candata[4] + candata[5] * 256) * 0.1 - 1600;
            racingCarData.lmcu_accur = (candata[6] + candata[7] * 256) * 0.1 - 1600;
            break;
        case 0x0CB321EF:  //MCU2toVCU2
            racingCarData.r_mcu_temp = candata[0] - 50;
            racingCarData.r_motor_temp = candata[1] - 50;
            racingCarData.rmcu_dcvol = (candata[2] + candata[3] * 256) * 0.1;
            racingCarData.rmcu_dccur = (candata[4] + candata[5] * 256) * 0.1 - 1600;
            racingCarData.rmcu_accur = (candata[6] + candata[7] * 256) * 0.1 - 1600;
            break;
        case 0x186040F3:
            racingCarData.BatVoltage = (candata[1] + candata[0] * 256) * 0.1;
            racingCarData.BatCurrent = (candata[3] + candata[2] * 256) * 0.1 - 1000;
            racingCarData.BatSoc = candata[4];
            racingCarData.BatSoh = candata[5];
            racingCarData.BatState = candata[6] >> 4;   //调试的时候注意一下
            racingCarData.BatAlmLv = candata[6] | 0xF;
            racingCarData.Batlife = candata[7];
            break;
    }
}

/*
void keyControlCanSend()
{
	KeyControlData[0] = 000;
	if(HAL_GPIO_ReadPin(INPUT2_GPIO_Port, INPUT2_Pin) == RESET) KeyControlData[0] |= 0x01 << 1;
	if(HAL_GPIO_ReadPin(INPUT3_GPIO_Port, INPUT3_Pin) == RESET) KeyControlData[0] |= 0x01 << 2;
	if(HAL_GPIO_ReadPin(INPUT4_GPIO_Port, INPUT4_Pin) == RESET) KeyControlData[0] |= 0x01 << 3;
	
	
	CAN2_Send(0X155, KeyControlData);
	
	
}
*/

