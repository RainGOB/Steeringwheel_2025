#include "Variable.h"

uint8_t Rx_buff;
char Rx_string[RXBUFFERSIZE];
uint8_t Rx_Count = 0;
uint8_t Tx_Flag;
uint8_t interrupt;
uint8_t IRQ_JudgEnable = 0;
uint8_t CANOK_Flag = 0;
uint8_t KeyControlData[8];
uint8_t accsencordata[8];

uint8_t EC200_RdyFlag=0;
uint8_t MQTTClient_RdyFlag = 0;
uint8_t PUBOK_Flag = 0;

uint8_t QMTOPEN_Flag = 0;
uint8_t QMTCONN_Flag = 0;
uint8_t QMTCFG_Flag = 0;

struct RacingCarData racingCarData;

uint16_t *lcd_fb;

uint8_t TB_State = 0;   //1 ǰ�� 0 ����
uint8_t TBSA_Flag = 0;
uint8_t TBSO_Flag = 0;
