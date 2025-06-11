#include "Variable.h"

uint8_t Rx_buff;
char Rx_string[RXBUFFERSIZE];
uint8_t Rx_Count = 0;
uint8_t Tx_Flag;
uint8_t interrupt;
uint8_t IRQ_JudgEnable = 0;
uint8_t CANOK_Flag = 0;
uint8_t accsencordata[8];

uint8_t EC200_RdyFlag=0;
uint8_t MQTTClient_RdyFlag = 0;
uint8_t PUBOK_Flag = 0;

uint8_t QMTOPEN_Flag = 0;
uint8_t QMTCONN_Flag = 0;
uint8_t QMTCFG_Flag = 0;

//lv输入用
uint8_t Key_Num_Click = 0;
uint8_t Key_Num_Press = 0;
uint8_t Encoder1_Counter = 0;
uint8_t Encoder2_Counter = 0;
uint8_t Encoder3_Counter = 0;
_Bool history_log_appear_flag = 0;
char history_log_str[100] = "CAN Receive Wrong \nmessage:\nLMCU:000,000\nRMCU:000,000\nBMS:0,0power off cause by\n";
char history_str[5];

struct RacingCarData racingCarData;

uint8_t TB_State = 0;   //1 ǰ�� 0 ����
uint8_t TBSA_Flag = 0;
uint8_t TBSO_Flag = 0;
