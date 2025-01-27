/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl/lvgl.h"
#include "user/link_list.h"
LinkList *lvgl_link_list;
#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


static void timer_scr_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.led_scr, guider_ui.led_scr_del, &guider_ui.timer_scr_del, setup_scr_led_scr, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, false);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.led_scr, guider_ui.led_scr_del, &guider_ui.timer_scr_del, setup_scr_led_scr, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, false);
            break;
        }
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.tz_scr, guider_ui.tz_scr_del, &guider_ui.timer_scr_del, setup_scr_tz_scr, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, false);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_timer_scr (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->timer_scr, timer_scr_event_handler, LV_EVENT_ALL, ui);
}

static void led_scr_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.timer_scr, guider_ui.timer_scr_del, &guider_ui.led_scr_del, setup_scr_timer_scr, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, false);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.timer_scr, guider_ui.timer_scr_del, &guider_ui.led_scr_del, setup_scr_timer_scr, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, false);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void led_scr_btn_open_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_led_set_brightness(guider_ui.led_scr_led_1, 255);
        break;
    }
    default:
        break;
    }
}

static void led_scr_btn_close_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_led_set_brightness(guider_ui.led_scr_led_1, 0);
        break;
    }
    default:
        break;
    }
}

void events_init_led_scr (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->led_scr, led_scr_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->led_scr_btn_open, led_scr_btn_open_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->led_scr_btn_close, led_scr_btn_close_event_handler, LV_EVENT_ALL, ui);
}

static void tz_scr_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.timer_scr, guider_ui.timer_scr_del, &guider_ui.tz_scr_del, setup_scr_timer_scr, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, false);
            break;
        }
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.timer_scr, guider_ui.timer_scr_del, &guider_ui.tz_scr_del, setup_scr_timer_scr, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, false);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_tz_scr (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->tz_scr, tz_scr_event_handler, LV_EVENT_ALL, ui);
}

static void events_switch_page_handler (lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_GESTURE:
        {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
            switch(dir) {
                case LV_DIR_LEFT:
                {
                    lv_indev_wait_release(lv_indev_get_act());
                    ui_load_scr_animation(&guider_ui, &lvgl_link_list->next->lvgl_scr, lvgl_link_list->next->lvgl_scr_del, &lvgl_link_list->lvgl_scr_del, lvgl_link_list->next->setup_scr, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 0, false, false);
                    lvgl_link_list=lvgl_link_list->next;
                    break;
                }
                case LV_DIR_RIGHT:
                {
                    ui_load_scr_animation(&guider_ui, &lvgl_link_list->on->lvgl_scr, lvgl_link_list->on->lvgl_scr_del, &lvgl_link_list->lvgl_scr_del, lvgl_link_list->on->setup_scr, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, false, false);
                    lvgl_link_list=lvgl_link_list->on;
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}
static void control_scr_spinbox_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_VALUE_CHANGED:
        {
            int32_t spinbox_value =lv_spinbox_get_value(guider_ui.control_scr_spinbox_1);
            lv_bar_set_value(guider_ui.control_scr_bar_1,spinbox_value,LV_ANIM_ON);
            lv_slider_set_value(guider_ui.control_scr_slider_1,spinbox_value,LV_ANIM_ON);
            break;
        }
        default:
            break;
    }
}
static void control_scr_slider_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_VALUE_CHANGED:
        {
            int32_t slider_value=lv_slider_get_value(guider_ui.control_scr_slider_1);
            lv_bar_set_value(guider_ui.control_scr_bar_1,slider_value,LV_ANIM_ON);
            lv_spinbox_set_value(guider_ui.control_scr_spinbox_1,slider_value);
            break;
        }
        default:
            break;
    }
}
void events_init_all (lv_ui *ui) {
    //页面切换事件
    lv_obj_add_event_cb(ui->timer_scr, events_switch_page_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->led_scr, events_switch_page_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->tz_scr, events_switch_page_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->control_scr, events_switch_page_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->watch_scr, events_switch_page_handler, LV_EVENT_ALL, ui);

    //按钮切换事件
    lv_obj_add_event_cb(ui->led_scr_btn_open, led_scr_btn_open_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->led_scr_btn_close, led_scr_btn_close_event_handler, LV_EVENT_ALL, ui);
    //微调框数值变化事件
    lv_obj_add_event_cb(ui->control_scr_spinbox_1, control_scr_spinbox_1_event_handler, LV_EVENT_ALL, ui);

    lv_obj_add_event_cb(ui->control_scr_slider_1, control_scr_slider_1_event_handler, LV_EVENT_ALL, ui);

}

void events_init(lv_ui *ui)
{
    events_init_all(ui);
}
