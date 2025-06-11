#ifndef _VARIABLE_H_
#define _VARIABLE_H_

#include <stdbool.h>
#include "main.h"

#define RXBUFFERSIZE  100    //�������ֽ���
#define RESPONSEWAITING 500

extern uint8_t Rx_buff;
extern char Rx_string[RXBUFFERSIZE];
extern uint8_t Rx_Count;
extern uint8_t Tx_Flag;
extern uint8_t IRQ_JudgEnable;
extern uint8_t CANOK_Flag;
extern uint8_t accsencordata[8];

extern uint8_t EC200_RdyFlag;
extern uint8_t MQTTClient_RdyFlag;
extern uint8_t PUBOK_Flag;

extern uint8_t QMTOPEN_Flag;
extern uint8_t QMTCONN_Flag;
extern uint8_t QMTCFG_Flag;

//lv输入用
extern uint8_t Key_Num_Click;
extern uint8_t Key_Num_Press;
extern uint8_t Encoder1_Counter;
extern uint8_t Encoder2_Counter;
extern uint8_t Encoder3_Counter;
extern _Bool history_log_appear_flag;
extern char history_log_str[100];
extern char history_str[5];

struct RacingCarData{
    //CAN2
    //ID:0X211
    uint8_t FrontSpeed;          //前轮车速 在这里作为参考车速 1Byte
    uint8_t PedalTravel;         //油门踏板开度    1Byte
    uint8_t brakeTravel;         //刹车踏板开度    1Byte
    uint8_t carTravel;           //车辆跑动距离    1Byte

    //ID:0X213
    uint8_t gearMode;            //挡位信息  1Bit
    uint8_t angle;
    _Bool safety_circuit_offline;

    //ID:0x50
    uint8_t sensor_diff;
    float acc_x;
    float acc_y;
    float acc_z;
    float yaw;
    float pitch;
    float roll;

    //CAN1
    //0x08C1EF21:  //VCUtoMCU1
    uint16_t l_motor_target_torque;      //左电机目标转矩  2Byte
    uint16_t l_motor_target_rpm;		 //左电机目标转速 2Byte
    uint8_t  l_target_controlmodeorder;  //左电机目标控制模式指令
    uint8_t  l_gearstage;         		 //左电机扭挡位状态+主正接触器
    float dccur;          		     //直流母线电压

    //0x08B1EF21:  //VCUtoMCU2
    uint16_t r_motor_target_torque;      //右电机目标转矩  2Byte
    uint16_t r_motor_target_rpm;		 //右电机目标转速 2Byte
    uint8_t  r_target_controlmodeorder;  //右电机目标控制模式指令
    uint8_t  r_gearstage;         	  	 //右电机扭挡位状态+主正接触器
    //uint16_t dccur;     	  		 //右电机直流母线电压

    //0x0CFFC6EF:  //MCU1toVCU1
    uint16_t l_motor_torque;        	 //左转矩  2Byte
    uint16_t l_motor_rpm;		    	 //左转速 2Byte
    uint8_t l_controlmodeorder;			 //左电机控制模式指令
    uint8_t l_mcu_ready;
    uint8_t l_mcu_precharge_state;
    uint8_t l_mcu_wrong_code;
    uint8_t l_mcu_selftest_state;
    uint8_t l_mcu_alert;

    //0x0CB221EF:  //MCU2toVCU1
    uint16_t r_motor_torque;        	 //右转矩  2Byte
    uint16_t r_motor_rpm;		    	 //右转速 2Byte
    uint8_t r_controlmodeorder; 		 //右电机控制模式指令
    uint8_t r_mcu_ready;
    uint8_t r_mcu_precharge_state;
    uint8_t r_mcu_wrong_code;
    uint8_t r_mcu_selftest_state;
    uint8_t r_mcu_alert;

    //0x0CFFC7EF:  //MCU1toVCU2
    int8_t l_mcu_temp;				     //左控制器温度
    int8_t l_motor_temp;				 //左电机温度
    float lmcu_dcvol;          		     //左电机直流母线电压
    float lmcu_dccur;          		     //左电机直流母线电流
    float lmcu_accur;  	     		     //左电机交流电流有效值

    //0x0CB321EF:  //MCU2toVCU2
    int8_t r_mcu_temp;			    	 //右控制器温度
    int8_t r_motor_temp;				 //右电机温度
    float rmcu_dcvol;          		     //右电机直流母线电压
    float rmcu_dccur;          		     //右电机直流母线电流
    float rmcu_accur;          		     //右电机交流电流有效值

    //0x186040F3  //电池箱
    uint16_t BatVoltage; 					 //动力电池总电压
    double BatCurrent;		             //动力电池总电流
    uint8_t BatSoc;                      //动力电池Soc
    uint8_t BatSoh;                      //动力电池Soh
    uint8_t BatState;                    //动力电池状态
    uint8_t BatAlmLv;					 //动力警告级别
    uint8_t Batlife;                     //通信生命信息

    //0x186140F3  //电池箱
    uint16_t MaxCellVolt;                //最高单体电压
    uint16_t MinCellVolt;                //最低单体电压
};

extern struct RacingCarData racingCarData;

extern uint8_t TB_State;
extern uint8_t TBSA_Flag;
extern uint8_t TBSO_Flag;

#endif
