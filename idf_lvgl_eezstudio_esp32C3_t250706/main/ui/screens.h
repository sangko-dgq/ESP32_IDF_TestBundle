#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _groups_t {
    lv_group_t *group_main;
} groups_t;

extern groups_t groups;

void ui_create_groups();

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *page_2nd;
    lv_obj_t *obj0;
    lv_obj_t *btn_home_next_2;
    lv_obj_t *roller_2nd;
    lv_obj_t *btn_home_next_1;
    lv_obj_t *obj1;
    lv_obj_t *spinner_main;
    lv_obj_t *con_header_home;
    lv_obj_t *header_charge_bar_home;
    lv_obj_t *con_2nd;
    lv_obj_t *con_header_2nd;
    lv_obj_t *header_charge_bar_home_1;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_PAGE_2ND = 2,
};

void create_screen_main();
void tick_screen_main();

void create_screen_page_2nd();
void tick_screen_page_2nd();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/