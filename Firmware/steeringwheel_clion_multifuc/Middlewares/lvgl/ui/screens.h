#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *start_up;
    lv_obj_t *main;
    lv_obj_t *ly_icon;
    lv_obj_t *bar_switch_to_main;
    lv_obj_t *speed;
    lv_obj_t *speed_label;
    lv_obj_t *best_time;
    lv_obj_t *last_time;
    lv_obj_t *best_label;
    lv_obj_t *last_label;
    lv_obj_t *lap_label;
    lv_obj_t *lap;
    lv_obj_t *gear;
    lv_obj_t *mcu1_temp;
    lv_obj_t *mcu2_temp;
    lv_obj_t *motor2_temp;
    lv_obj_t *motor1_temp;
    lv_obj_t *soc;
    lv_obj_t *lmot_rpm;
    lv_obj_t *bat_volt;
    lv_obj_t *rmot_rpm;
    lv_obj_t *mincellvolt;
    lv_obj_t *bat_vol_label;
    lv_obj_t *mincellvolt_label;
    lv_obj_t *lmot_rpm_label;
    lv_obj_t *rmot_rpm_label;
    lv_obj_t *wifi_off;
    lv_obj_t *wifi_on;
    lv_obj_t *saf_cir_ofl_label;
    lv_obj_t *history_log_panel;
    lv_obj_t *history_log_can_label;
    lv_obj_t *history_log_lready;
    lv_obj_t *history_log_lprecharge;
    lv_obj_t *history_log_lselftest;
    lv_obj_t *history_log_lalert;
    lv_obj_t *history_log_lwrong_code;
    lv_obj_t *history_log_rready;
    lv_obj_t *history_log_rprecharge;
    lv_obj_t *history_log_rselftest;
    lv_obj_t *history_log_ralert;
    lv_obj_t *history_log_rwrong_code;
    lv_obj_t *history_log_batstate;
    lv_obj_t *history_log_batalmlv;
    lv_obj_t *history_log_fail_label;
    lv_obj_t *history_log_fail;
    lv_obj_t *history_log_fail_rpm_difference_label;
    lv_obj_t *history_log_rpm_difference;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_START_UP = 1,
    SCREEN_ID_MAIN = 2,
};

void create_screen_start_up();
void tick_screen_start_up();

void create_screen_main();
void tick_screen_main();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/