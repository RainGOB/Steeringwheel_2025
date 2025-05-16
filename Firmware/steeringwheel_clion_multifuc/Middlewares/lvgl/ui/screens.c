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
            lv_obj_set_pos(obj, 428, 200);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffafafa), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "00");
        }
        {
            // speed_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.speed_label = obj;
            lv_obj_set_pos(obj, 376, 182);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "SPEED KMH");
        }
        {
            // best_time
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.best_time = obj;
            lv_obj_set_pos(obj, 180, 274);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "0:00:00");
        }
        {
            // last_time
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.last_time = obj;
            lv_obj_set_pos(obj, 340, 274);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "0:00:00");
        }
        {
            // best_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.best_label = obj;
            lv_obj_set_pos(obj, 342, 256);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "BEST LAP");
        }
        {
            // last_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.last_label = obj;
            lv_obj_set_pos(obj, 201, 256);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "LAST LAP");
        }
        {
            // lap_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lap_label = obj;
            lv_obj_set_pos(obj, 110, 256);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "LAP");
        }
        {
            // lap
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lap = obj;
            lv_obj_set_pos(obj, 120, 274);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "0");
        }
        {
            // gear
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.gear = obj;
            lv_obj_set_pos(obj, 97, 174);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "ACC");
        }
        {
            // mcu1_temp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.mcu1_temp = obj;
            lv_obj_set_pos(obj, 240, 220);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "00");
        }
        {
            // mcu2_temp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.mcu2_temp = obj;
            lv_obj_set_pos(obj, 273, 220);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "00");
        }
        {
            // motor2_temp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.motor2_temp = obj;
            lv_obj_set_pos(obj, 305, 220);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "00");
        }
        {
            // motor1_temp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.motor1_temp = obj;
            lv_obj_set_pos(obj, 341, 220);
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
            // l_rpm_back_photo
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.l_rpm_back_photo = obj;
            lv_obj_set_pos(obj, 64, 16);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_rpm_back);
        }
        {
            // l_rpm_pt_photo
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.l_rpm_pt_photo = obj;
            lv_obj_set_pos(obj, 67, 126);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_rpm_pt);
            lv_image_set_pivot(obj, 120, 14);
            lv_image_set_rotation(obj, 1200);
            lv_image_set_inner_align(obj, LV_IMAGE_ALIGN_DEFAULT);
        }
        {
            // r_rpm_back_photo
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.r_rpm_back_photo = obj;
            lv_obj_set_pos(obj, 273, 16);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_rpm_back);
        }
        {
            // r_rpm_pt_photo
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.r_rpm_pt_photo = obj;
            lv_obj_set_pos(obj, 275, 126);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_rpm_pt);
            lv_image_set_pivot(obj, 120, 14);
            lv_image_set_rotation(obj, 800);
            lv_image_set_inner_align(obj, LV_IMAGE_ALIGN_DEFAULT);
        }
        {
            // l_rpm
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.l_rpm = obj;
            lv_obj_set_pos(obj, 75, 29);
            lv_obj_set_size(obj, 230, 230);
            lv_arc_set_range(obj, 0, 8000);
            lv_arc_set_value(obj, 2000);
            lv_arc_set_bg_start_angle(obj, 180);
            lv_arc_set_bg_end_angle(obj, 303);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_rpm_pt, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_rounded(obj, false, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xffff0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 7, LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            // r_rpm
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.r_rpm = obj;
            lv_obj_set_pos(obj, 284, 29);
            lv_obj_set_size(obj, 230, 249);
            lv_arc_set_range(obj, 0, 8000);
            lv_arc_set_value(obj, 1700);
            lv_arc_set_bg_start_angle(obj, 180);
            lv_arc_set_bg_end_angle(obj, 303);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_rounded(obj, false, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xffff0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 7, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
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
