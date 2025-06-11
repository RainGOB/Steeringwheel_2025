#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

#include "animations.h"

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

void create_screen_start_up() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.start_up = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    {
        lv_obj_t *parent_obj = obj;
        {
            // ly_icon
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.ly_icon = obj;
            lv_obj_set_pos(obj, 140, 52);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_ly_icon);
        }
        {
            // bar_switch_to_main
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.bar_switch_to_main = obj;
            lv_obj_set_pos(obj, 140, 220);
            lv_obj_set_size(obj, 200, 13);
            lv_obj_add_event_cb(obj, action_disp_switch, LV_EVENT_ALL, (void *)0);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);

            ui_anim_to_main();
        }
    }
    
    tick_screen_start_up();
}

void tick_screen_start_up() {
}

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 320);
    {
        lv_obj_t *parent_obj = obj;
        {
            // speed
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.speed = obj;
            lv_obj_set_pos(obj, 430, 80);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_harmony_os_sans_regular_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "00");
        }
        {
            // speed_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.speed_label = obj;
            lv_obj_set_pos(obj, 381, 61);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_harmony_os_sans_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "SPEED KMH");
        }
        {
            // best_time
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.best_time = obj;
            lv_obj_set_pos(obj, 201, 277);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_harmony_os_sans_regular_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "0:00:00");
        }
        {
            // last_time
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.last_time = obj;
            lv_obj_set_pos(obj, 342, 277);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_harmony_os_sans_regular_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "0:00:00");
        }
        {
            // best_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.best_label = obj;
            lv_obj_set_pos(obj, 342, 258);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_harmony_os_sans_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "BEST LAP");
        }
        {
            // last_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.last_label = obj;
            lv_obj_set_pos(obj, 201, 258);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_harmony_os_sans_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "LAST LAP");
        }
        {
            // lap_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lap_label = obj;
            lv_obj_set_pos(obj, 119, 258);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_harmony_os_sans_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "LAP");
        }
        {
            // lap
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lap = obj;
            lv_obj_set_pos(obj, 123, 277);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_harmony_os_sans_regular_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "0");
        }
        {
            // gear
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.gear = obj;
            lv_obj_set_pos(obj, 60, 162);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
            lv_obj_set_style_text_font(obj, &ui_font_harmony_os_sans_regular_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "AC");
        }
        {
            // mcu1_temp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.mcu1_temp = obj;
            lv_obj_set_pos(obj, 59, 232);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "00");
        }
        {
            // mcu2_temp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.mcu2_temp = obj;
            lv_obj_set_pos(obj, 92, 232);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "00");
        }
        {
            // motor2_temp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.motor2_temp = obj;
            lv_obj_set_pos(obj, 124, 232);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "00");
        }
        {
            // motor1_temp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.motor1_temp = obj;
            lv_obj_set_pos(obj, 160, 232);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "00");
        }
        {
            // soc
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.soc = obj;
            lv_obj_set_pos(obj, 20, 10);
            lv_obj_set_size(obj, 25, 300);
            lv_bar_set_value(obj, 65, LV_ANIM_OFF);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 12, 10);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_soc_bc);
        }
        {
            // lmot_rpm
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lmot_rpm = obj;
            lv_obj_set_pos(obj, 60, 40);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_harmony_os_sans_regular_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "0000");
        }
        {
            // bat_volt
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.bat_volt = obj;
            lv_obj_set_pos(obj, 409, 200);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_harmony_os_sans_regular_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "000");
        }
        {
            // rmot_rpm
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.rmot_rpm = obj;
            lv_obj_set_pos(obj, 60, 103);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_harmony_os_sans_regular_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "0000");
        }
        {
            // mincellvolt
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.mincellvolt = obj;
            lv_obj_set_pos(obj, 388, 142);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_harmony_os_sans_regular_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "0000");
        }
        {
            // bat_vol_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.bat_vol_label = obj;
            lv_obj_set_pos(obj, 387, 179);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_harmony_os_sans_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Bat Voltage");
        }
        {
            // mincellvolt_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.mincellvolt_label = obj;
            lv_obj_set_pos(obj, 382, 123);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_harmony_os_sans_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Min Cell Volt");
        }
        {
            // lmot_rpm_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lmot_rpm_label = obj;
            lv_obj_set_pos(obj, 60, 21);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_harmony_os_sans_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "SPEED KMH");
        }
        {
            // rmot_rpm_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.rmot_rpm_label = obj;
            lv_obj_set_pos(obj, 60, 84);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_harmony_os_sans_regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "SPEED KMH");
        }
        {
            // wifi_off
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.wifi_off = obj;
            lv_obj_set_pos(obj, 417, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_wifi_off);
        }
        {
            // wifi_on
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.wifi_on = obj;
            lv_obj_set_pos(obj, 417, 6);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_wifi_on);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
        }
        {
            // saf_cir_ofl_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.saf_cir_ofl_label = obj;
            lv_obj_set_pos(obj, 171, 210);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffe9b1c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "SAFETY CIRCUIT OFFLINE");
        }
        {
            // history_log_panel
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.history_log_panel = obj;
            lv_obj_set_pos(obj, 171, 20);
            lv_obj_set_size(obj, 180, 180);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff272727), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_harmony_os_sans_regular_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // history_log_can_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.history_log_can_label = obj;
                    lv_obj_set_pos(obj, 0, -4);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "CAN Receive Wrong \nmessage:\nLMCU:\nRMCU:\nBMS:");
                }
                {
                    // history_log_lready
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.history_log_lready = obj;
                    lv_obj_set_pos(obj, 48, 28);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "0");
                }
                {
                    // history_log_lprecharge
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.history_log_lprecharge = obj;
                    lv_obj_set_pos(obj, 61, 28);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "0");
                }
                {
                    // history_log_lselftest
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.history_log_lselftest = obj;
                    lv_obj_set_pos(obj, 74, 28);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "0");
                }
                {
                    // history_log_lalert
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.history_log_lalert = obj;
                    lv_obj_set_pos(obj, 87, 28);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "0");
                }
                {
                    // history_log_lwrong_code
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.history_log_lwrong_code = obj;
                    lv_obj_set_pos(obj, 101, 28);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "000");
                }
                {
                    // history_log_rready
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.history_log_rready = obj;
                    lv_obj_set_pos(obj, 48, 44);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "0");
                }
                {
                    // history_log_rprecharge
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.history_log_rprecharge = obj;
                    lv_obj_set_pos(obj, 61, 44);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "0");
                }
                {
                    // history_log_rselftest
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.history_log_rselftest = obj;
                    lv_obj_set_pos(obj, 74, 44);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "0");
                }
                {
                    // history_log_ralert
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.history_log_ralert = obj;
                    lv_obj_set_pos(obj, 87, 44);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "0");
                }
                {
                    // history_log_rwrong_code
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.history_log_rwrong_code = obj;
                    lv_obj_set_pos(obj, 101, 44);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "000");
                }
                {
                    // history_log_batstate
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.history_log_batstate = obj;
                    lv_obj_set_pos(obj, 48, 60);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "0");
                }
                {
                    // history_log_batalmlv
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.history_log_batalmlv = obj;
                    lv_obj_set_pos(obj, 61, 60);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "0");
                }
                {
                    // history_log_fail_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.history_log_fail_label = obj;
                    lv_obj_set_pos(obj, 0, 76);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "power off cause by:");
                }
                {
                    // history_log_fail
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.history_log_fail = obj;
                    lv_obj_set_pos(obj, 0, 92);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "IMD");
                }
                {
                    // history_log_fail_rpm_difference_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.history_log_fail_rpm_difference_label = obj;
                    lv_obj_set_pos(obj, 0, 108);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Moter RPM difference:");
                }
                {
                    // history_log_rpm_difference
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.history_log_rpm_difference = obj;
                    lv_obj_set_pos(obj, 0, 124);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "0000");
                }
            }
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
}



typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_start_up,
    tick_screen_main,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_start_up();
    create_screen_main();
}
