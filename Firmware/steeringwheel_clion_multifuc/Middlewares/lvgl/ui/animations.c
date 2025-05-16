#include "animations.h"
#include "ui.h"

static void set_value(void * bar, int32_t v)
{
    lv_bar_set_value(bar, v, LV_ANIM_OFF);
}

void ui_anim_to_main(void){
    static lv_anim_t   anim_disp_to_main;

    lv_anim_init(&anim_disp_to_main);

/* MANDATORY SETTINGS
 *------------------*/

/* Set the "animator" function */
    lv_anim_set_exec_cb(&anim_disp_to_main, set_value);

/* Set target of the Animation */
    lv_anim_set_var(&anim_disp_to_main, objects.bar_switch_to_main);

/* Length of the Animation [ms] */
    lv_anim_set_duration(&anim_disp_to_main, 2000);
    //lv_anim_set_time(&anim_disp_to_main,2000);
/* Set start and end values. E.g. 0, 150 */
    lv_anim_set_values(&anim_disp_to_main, 0, 100);

    lv_anim_start(&anim_disp_to_main);
}
