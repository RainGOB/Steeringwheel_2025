#include "actions.h"
#include "screens.h"
#include "ui.h"

void action_disp_switch(lv_event_t *e) {
    // TODO: Implement action disp_switch here
    if(lv_bar_get_value(objects.bar_switch_to_main) == 100)
        loadScreen(SCREEN_ID_MAIN);
}

