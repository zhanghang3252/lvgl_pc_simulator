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
#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

LinkList *lvgl_link_list;
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
            ui_load_scr_animation(&guider_ui, &lvgl_link_list->next->lvgl_scr,lvgl_link_list->next->lvgl_scr_del, &lvgl_link_list->lvgl_scr_del, lvgl_link_list->next->setup_scr, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 0, false, false);
            lvgl_link_list=lvgl_link_list->next;
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &lvgl_link_list->on->lvgl_scr,lvgl_link_list->on->lvgl_scr_del, &lvgl_link_list->lvgl_scr_del, lvgl_link_list->on->setup_scr, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, false, false);
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
            ui_load_scr_animation(&guider_ui, &lvgl_link_list->next->lvgl_scr,lvgl_link_list->next->lvgl_scr_del, &lvgl_link_list->lvgl_scr_del, lvgl_link_list->next->setup_scr, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 0, false, false);
            lvgl_link_list=lvgl_link_list->next;
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &lvgl_link_list->on->lvgl_scr,lvgl_link_list->on->lvgl_scr_del, &lvgl_link_list->lvgl_scr_del, lvgl_link_list->on->setup_scr, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, false, false);
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

static void led_scr_btn_open_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        printf("OPEN LED\r\n");
        lv_led_on(guider_ui.led_scr_led_1);
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
        printf("CLOSE LED\r\n");
        lv_led_off(guider_ui.led_scr_led_1);
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
            case LV_DIR_LEFT:
            {
                lv_indev_wait_release(lv_indev_get_act());
                ui_load_scr_animation(&guider_ui, &lvgl_link_list->next->lvgl_scr,lvgl_link_list->next->lvgl_scr_del, &lvgl_link_list->lvgl_scr_del, lvgl_link_list->next->setup_scr, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 0, false, false);
                lvgl_link_list=lvgl_link_list->next;
                break;
            }
            case LV_DIR_RIGHT:
            {
                lv_indev_wait_release(lv_indev_get_act());
                ui_load_scr_animation(&guider_ui, &lvgl_link_list->on->lvgl_scr,lvgl_link_list->on->lvgl_scr_del, &lvgl_link_list->lvgl_scr_del, lvgl_link_list->on->setup_scr, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, false, false);
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

void events_init_tz_scr (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->tz_scr, tz_scr_event_handler, LV_EVENT_ALL, ui);
}


static void watch_scr_event_handler (lv_event_t *e)
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
                    ui_load_scr_animation(&guider_ui, &lvgl_link_list->next->lvgl_scr,lvgl_link_list->next->lvgl_scr_del, &lvgl_link_list->lvgl_scr_del, lvgl_link_list->next->setup_scr, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 0, false, false);
                    lvgl_link_list=lvgl_link_list->next;
                    break;
                }
                case LV_DIR_RIGHT:
                {
                    lv_indev_wait_release(lv_indev_get_act());
                    ui_load_scr_animation(&guider_ui, &lvgl_link_list->on->lvgl_scr,lvgl_link_list->on->lvgl_scr_del, &lvgl_link_list->lvgl_scr_del, lvgl_link_list->on->setup_scr, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, false, false);
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


void events_init_watch_scr(lv_ui *ui) {
    lv_obj_add_event_cb(ui->watch_scr, watch_scr_event_handler, LV_EVENT_ALL, ui);
}

static void page_switching_event_handler (lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_GESTURE:
        {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
            switch(dir) {
                case LV_DIR_LEFT:
                {
                    lv_indev_wait_release(lv_indev_get_act());
                    ui_load_scr_animation(&guider_ui, &lvgl_link_list->next->lvgl_scr,lvgl_link_list->next->lvgl_scr_del, &lvgl_link_list->lvgl_scr_del, lvgl_link_list->next->setup_scr, LV_SCR_LOAD_ANIM_MOVE_LEFT, 100, 0, false, false);
                    lvgl_link_list=lvgl_link_list->next;
                    break;
                }
                case LV_DIR_RIGHT:
                {
                    lv_indev_wait_release(lv_indev_get_act());
                    ui_load_scr_animation(&guider_ui, &lvgl_link_list->on->lvgl_scr,lvgl_link_list->on->lvgl_scr_del, &lvgl_link_list->lvgl_scr_del, lvgl_link_list->on->setup_scr, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 100, 0, false, false);
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


void events_page_switching(lv_ui *ui) {
    //页面滑动事件
    lv_obj_add_event_cb(ui->watch_scr, page_switching_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->led_scr, page_switching_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->timer_scr, page_switching_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->tz_scr, page_switching_event_handler, LV_EVENT_ALL, ui);

    //按钮点击事件
    lv_obj_add_event_cb(ui->led_scr_btn_open, led_scr_btn_open_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->led_scr_btn_close, led_scr_btn_close_event_handler, LV_EVENT_ALL, ui);
}
void events_init(lv_ui *ui)
{
    events_page_switching(ui);
    // events_init_tz_scr(ui);
    // events_init_watch_scr(ui);
    // events_init_timer_scr(ui);
}
