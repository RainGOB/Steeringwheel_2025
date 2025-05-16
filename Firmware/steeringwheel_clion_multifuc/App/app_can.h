#ifndef _APP_CAN_H_
#define _APP_CAN_H_

#include "main.h"
#include "bsp_can.h"

void decode(uint32_t ID,uint8_t *mdata);
void decode_power(uint32_t ID,uint8_t *candata);

#endif
