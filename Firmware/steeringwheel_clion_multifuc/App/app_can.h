#ifndef _APP_CAN_H_
#define _APP_CAN_H_

#include "main.h"
#include "bsp_can.h"
#include "lvgl.h"
#include "screens.h"

void decode(uint32_t ID,uint8_t *mdata);
void decode_power(uint32_t ID,uint8_t *candata);
//void test();

#endif
