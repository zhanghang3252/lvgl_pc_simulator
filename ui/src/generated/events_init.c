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
#include <unistd.h>

#include "lvgl/lvgl.h"
int8_t led_1_value=0;
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
            ui_load_scr_animation(&guider_ui, &guider_ui.led_scr, guider_ui.led_scr_del, &guider_ui.timer_scr_del, setup_scr_led_scr, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, false, false);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.led_scr, guider_ui.led_scr_del, &guider_ui.timer_scr_del, setup_scr_led_scr, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, false, false);
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
            ui_load_scr_animation(&guider_ui, &guider_ui.timer_scr, guider_ui.timer_scr_del, &guider_ui.led_scr_del, setup_scr_timer_scr, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, false, false);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.timer_scr, guider_ui.timer_scr_del, &guider_ui.led_scr_del, setup_scr_timer_scr, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, false, false);
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
    case LV_EVENT_PRESSING:
    {
        led_1_value++;
        if (led_1_value>=255)
            led_1_value=255;
        usleep(10*1000);
        lv_led_set_brightness(guider_ui.led_scr_led_1, led_1_value);
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
    case LV_EVENT_PRESSING:
    {
        led_1_value--;
        if (led_1_value<=0)
            led_1_value=0;
        usleep(10*1000);
        lv_led_set_brightness(guider_ui.led_scr_led_1, led_1_value);
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


void events_init(lv_ui *ui)
{

}
