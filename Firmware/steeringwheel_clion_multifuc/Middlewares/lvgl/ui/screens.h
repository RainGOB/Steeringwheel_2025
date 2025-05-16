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
    lv_obj_t *l_rpm_back_photo;
    lv_obj_t *l_rpm_pt_photo;
    lv_obj_t *r_rpm_back_photo;
    lv_obj_t *r_rpm_pt_photo;
    lv_obj_t *l_rpm;
    lv_obj_t *r_rpm;
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