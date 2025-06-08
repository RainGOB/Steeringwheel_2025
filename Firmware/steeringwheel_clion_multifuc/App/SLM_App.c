#include "SLM_App.h"
#include "Variable.h"
//#include "cmsis_os2.h"

void RPM_LED_Shine()
{
    uint16_t lnums,rnums,i;
    ws2812_init(10);

    const struct {
        uint8_t r;
        uint8_t g;
        uint8_t b;
    } led_colors[10] = {
            {0x00, 0xFF, 0x00},  // 绿色 (LED 1,2,6,7)
            {0x00, 0xFF, 0x00},
            {0x00, 0x00, 0xFF},  // 蓝色 (LED 3,4,8,9)
            {0x00, 0x00, 0xFF},
            {0xFF, 0x00, 0x00},  // 红色 (LED 5,10)
            {0xFF, 0x00, 0x00},
            {0x00, 0x00, 0xFF},
            {0x00, 0x00, 0xFF},
            {0x00, 0xFF, 0x00},
            {0x00, 0xFF, 0x00}
    };

    lnums = racingCarData.l_motor_rpm / 1400 % 6;
    rnums = racingCarData.r_motor_rpm / 1400 % 6;

    for(i = 0; i < 5; i++) {
        if(i<lnums){
            ws2812_set_RGB(led_colors[i].r, led_colors[i].g, led_colors[i].b, i);
        }
        else
            ws2812_set_RGB(0x00,0x00,0x00, i);
    }
    for (i = 9; i > 4; i--)  {
        if ((9-i)< rnums){
            ws2812_set_RGB(led_colors[i].r, led_colors[i].g, led_colors[i].b, i);
        }
        else
            ws2812_set_RGB(0x00,0x00,0x00, i);
    }



//    ledNums = racingCarData.l_motor_rpm / 800;
//    for(i = 0; i < ledNums; i++)
//    {
//        ws2812_set_RGB(i*25, (12-i)*5, (12-i)*2, i);//RGB
//    }
//    while(ledNums>8)
//    {
//        ws2812_red(ledNums);//RGB
//        //osDelay(80);
//        HAL_Delay(80);
//        ws2812_init(12);
//        //osDelay(80);
//        HAL_Delay(80);
//        ledNums = racingCarData.l_motor_rpm / 800;
//    }

}
