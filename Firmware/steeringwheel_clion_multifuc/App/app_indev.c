#include "app_indev.h"

uint8_t key_scan_click() {
    static uint8_t Key_Pressed = 0;
    static uint8_t KeyPress_Count = 0;   //用来保证按键在按下途中只起一次作用
    static uint8_t key_num = 0;

    if (HAL_GPIO_ReadPin(keyl_1_GPIO_Port, keyl_1_Pin) == GPIO_PIN_RESET) {
        key_num |= 0x01;
        KeyPress_Count++;
    }
    if (HAL_GPIO_ReadPin(keyr_1_GPIO_Port, keyr_1_Pin) == GPIO_PIN_RESET) {
        key_num |= (0x01 << 1);
        KeyPress_Count++;
    }
    if (HAL_GPIO_ReadPin(keyl_2_GPIO_Port, keyl_2_Pin) == GPIO_PIN_RESET) {
        key_num |= (0x01 << 2);
        KeyPress_Count++;
    }
    if (HAL_GPIO_ReadPin(keyr_2_GPIO_Port, keyr_2_Pin) == GPIO_PIN_RESET) {
        key_num |= (0x01 << 3);
        KeyPress_Count++;
    }
    if (HAL_GPIO_ReadPin(keyl_3_GPIO_Port, keyl_3_Pin) == GPIO_PIN_RESET) {
        key_num |= (0x01 << 4);
        KeyPress_Count++;
    }
    if (HAL_GPIO_ReadPin(keyr_3_GPIO_Port, keyr_3_Pin) == GPIO_PIN_RESET) {
        key_num |= (0x01 << 5);
        KeyPress_Count++;
    }

    if(KeyPress_Count != 0 && Key_Pressed == 1){
        KeyPress_Count = 0;
        key_num = 0;
        return  0;
    }

    if(KeyPress_Count == 0) {
        KeyPress_Count = 0;
        Key_Pressed = 0;
        key_num = 0;
        return 0;
    }

    KeyPress_Count = 0;
    Key_Pressed = 1;

    return key_num;
}

uint8_t key_scan_press() {
    uint8_t key_num = 0;

    if (HAL_GPIO_ReadPin(keyl_1_GPIO_Port, keyl_1_Pin) == GPIO_PIN_RESET) {
        key_num |= 0x01;
    }
    if (HAL_GPIO_ReadPin(keyr_1_GPIO_Port, keyr_1_Pin) == GPIO_PIN_RESET) {
        key_num |= (0x01 << 1);
    }
    if (HAL_GPIO_ReadPin(keyl_2_GPIO_Port, keyl_2_Pin) == GPIO_PIN_RESET) {
        key_num |= (0x01 << 2);
    }
    if (HAL_GPIO_ReadPin(keyr_2_GPIO_Port, keyr_2_Pin) == GPIO_PIN_RESET) {
        key_num |= (0x01 << 3);
    }
    if (HAL_GPIO_ReadPin(keyl_3_GPIO_Port, keyl_3_Pin) == GPIO_PIN_RESET) {
        key_num |= (0x01 << 4);
    }
    if (HAL_GPIO_ReadPin(keyr_3_GPIO_Port, keyr_3_Pin) == GPIO_PIN_RESET) {
        key_num |= (0x01 << 5);
    }

    return key_num;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
    //encoder3
    if(GPIO_Pin == encoder3_1_Pin)
    {
        if(HAL_GPIO_ReadPin(encoder3_1_GPIO_Port,encoder3_1_Pin) == GPIO_PIN_RESET)
        {
            if(HAL_GPIO_ReadPin(encoder3_2_GPIO_Port,encoder3_2_Pin) == GPIO_PIN_RESET){
                Encoder3_Counter++;
            }
        }
    }
    if(GPIO_Pin == encoder3_2_Pin)
    {
        if(HAL_GPIO_ReadPin(encoder3_2_GPIO_Port,encoder3_2_Pin) == GPIO_PIN_RESET)
        {
            if(HAL_GPIO_ReadPin(encoder3_1_GPIO_Port,encoder3_1_Pin) == GPIO_PIN_RESET){
                Encoder3_Counter--;
            }
        }
    }
    //encoder2
    if(GPIO_Pin == encoder2_1_Pin)
    {
        if(HAL_GPIO_ReadPin(encoder2_1_GPIO_Port,encoder2_1_Pin) == GPIO_PIN_RESET)
        {
            if(HAL_GPIO_ReadPin(encoder2_2_GPIO_Port,encoder2_2_Pin) == GPIO_PIN_RESET){
                Encoder2_Counter++;
            }
        }
    }
    if(GPIO_Pin == encoder2_2_Pin)
    {
        if(HAL_GPIO_ReadPin(encoder2_2_GPIO_Port,encoder2_2_Pin) == GPIO_PIN_RESET)
        {
            if(HAL_GPIO_ReadPin(encoder2_1_GPIO_Port,encoder2_1_Pin) == GPIO_PIN_RESET){
                Encoder2_Counter--;
            }
        }
    }
    //encoder1
    if(GPIO_Pin == encoder1_1_Pin)
    {
        if(HAL_GPIO_ReadPin(encoder1_1_GPIO_Port,encoder1_1_Pin) == GPIO_PIN_RESET)
        {
            if(HAL_GPIO_ReadPin(encoder1_2_GPIO_Port,encoder1_2_Pin) == GPIO_PIN_RESET){
                Encoder1_Counter++;
            }
        }
    }
    if(GPIO_Pin == encoder1_2_Pin)
    {
        if(HAL_GPIO_ReadPin(encoder1_2_GPIO_Port,encoder1_2_Pin) == GPIO_PIN_RESET)
        {
            if(HAL_GPIO_ReadPin(encoder1_1_GPIO_Port,encoder1_1_Pin) == GPIO_PIN_RESET){
                Encoder1_Counter--;
            }
        }
    }
}
