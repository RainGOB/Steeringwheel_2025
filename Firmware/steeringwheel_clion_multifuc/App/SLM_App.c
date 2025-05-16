#include "SLM_App.h"
#include "Variable.h"
//#include "cmsis_os2.h"

void RPM_LED_Shine()
{
	uint16_t ledNums, i;
	ws2812_init(12);

    ledNums = racingCarData.l_motor_rpm / 400;
    for(i = 0; i < ledNums; i++)
    {
        ws2812_set_RGB(i*25, (12-i)*5, (12-i)*2, i);//RGB
    }
    while(ledNums>8)
    {
        ws2812_red(ledNums);//RGB
        //osDelay(80);
        HAL_Delay(80);
        ws2812_init(12);
        //osDelay(80);
        HAL_Delay(80);
        ledNums = racingCarData.l_motor_rpm / 400;
    }

}
