/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl/lvgl.h"
#include "gui_guider.h"
#include "widgets_init.h"
#include <stdlib.h>


__attribute__((unused)) void kb_event_cb (lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *kb = lv_event_get_target(e);
    if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
}

__attribute__((unused)) void ta_event_cb (lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
#if LV_USE_KEYBOARD || LV_USE_ZH_KEYBOARD
    lv_obj_t *ta = lv_event_get_target(e);
#endif
    lv_obj_t *kb = lv_event_get_user_data(e);
    if (code == LV_EVENT_FOCUSED || code == LV_EVENT_CLICKED)
    {
#if LV_USE_ZH_KEYBOARD != 0
        lv_zh_keyboard_set_textarea(kb, ta);
#endif
#if LV_USE_KEYBOARD != 0
        lv_keyboard_set_textarea(kb, ta);
#endif
        lv_obj_move_foreground(kb);
        lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
    if (code == LV_EVENT_CANCEL || code == LV_EVENT_DEFOCUSED)
    {

#if LV_USE_ZH_KEYBOARD != 0
        lv_zh_keyboard_set_textarea(kb, ta);
#endif
#if LV_USE_KEYBOARD != 0
        lv_keyboard_set_textarea(kb, ta);
#endif
        lv_obj_move_background(kb);
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
}

#if LV_USE_ANALOGCLOCK != 0
void clock_count(int *hour, int *min, int *sec)
{
    (*sec)++;
    if(*sec == 60)
    {
        *sec = 0;
        (*min)++;
    }
    if(*min == 60)
    {
        *min = 0;
        if(*hour < 12)
        {
            (*hour)++;
        } else {
            (*hour)++;
            *hour = *hour %12;
        }
    }
}
#endif

static lv_obj_t * timer_scr_datetext_1_calendar;

void timer_scr_datetext_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_FOCUSED) {
        char * s = lv_label_get_text(btn);
        if(timer_scr_datetext_1_calendar == NULL) {
            timer_scr_datetext_1_init_calendar(btn, s);
        }
    }
}

void timer_scr_datetext_1_init_calendar(lv_obj_t *obj, char * s)
{
    if (timer_scr_datetext_1_calendar == NULL) {
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        timer_scr_datetext_1_calendar = lv_calendar_create(lv_layer_top());
        lv_obj_t * scr = lv_obj_get_screen(obj);
        lv_coord_t scr_height = lv_obj_get_height(scr);
        lv_coord_t scr_width = lv_obj_get_width(scr);
        lv_obj_set_size(timer_scr_datetext_1_calendar, scr_width * 0.8, scr_height * 0.8);
        char * year = strtok(s, "/");
        char * month = strtok(NULL, "/");
        char * day = strtok(NULL, "/");
        lv_calendar_set_showed_date(timer_scr_datetext_1_calendar, atoi(year), atoi(month));
        lv_calendar_date_t highlighted_days[1];       /*Only its pointer will be saved so should be static*/
        highlighted_days[0].year = atoi(year);
        highlighted_days[0].month = atoi(month);
        highlighted_days[0].day = atoi(day);
        lv_calendar_set_highlighted_dates(timer_scr_datetext_1_calendar, highlighted_days, 1);
        lv_obj_align(timer_scr_datetext_1_calendar,LV_ALIGN_CENTER, 0, 0);

        lv_obj_add_event_cb(timer_scr_datetext_1_calendar, timer_scr_datetext_1_calendar_event_handler, LV_EVENT_ALL,NULL);
        lv_calendar_header_arrow_create(timer_scr_datetext_1_calendar);
        lv_obj_update_layout(scr);
    }
}

void timer_scr_datetext_1_calendar_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_current_target(e);

    if (code == LV_EVENT_VALUE_CHANGED) {
        lv_calendar_date_t date;
        lv_calendar_get_pressed_date(obj,&date);
        char buf[16];
        lv_snprintf(buf,sizeof(buf),"%d/%02d/%02d", date.year, date.month,date.day);
        lv_label_set_text(guider_ui.timer_scr_datetext_1, buf);
        lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_style_bg_opa(lv_layer_top(), LV_OPA_TRANSP, 0);
        lv_obj_del(timer_scr_datetext_1_calendar);
        timer_scr_datetext_1_calendar = NULL;
    }
}


extern int timer_scr_digital_clock_1_hour_value;
extern int timer_scr_digital_clock_1_min_value;
extern int timer_scr_digital_clock_1_sec_value;

void timer_scr_digital_clock_1_timer(lv_timer_t *timer)
{
    clock_count_24(&timer_scr_digital_clock_1_hour_value, &timer_scr_digital_clock_1_min_value, &timer_scr_digital_clock_1_sec_value);
    if (lv_obj_is_valid(guider_ui.timer_scr_digital_clock_1))
    {
        lv_dclock_set_text_fmt(guider_ui.timer_scr_digital_clock_1, "%d:%02d:%02d", timer_scr_digital_clock_1_hour_value, timer_scr_digital_clock_1_min_value, timer_scr_digital_clock_1_sec_value);
    }
}


extern int watch_scr_analog_clock_1_hour_value;
extern int watch_scr_analog_clock_1_min_value;
extern int watch_scr_analog_clock_1_sec_value;

void watch_scr_analog_clock_1_timer(lv_timer_t *timer)
{
    clock_count(&watch_scr_analog_clock_1_hour_value, &watch_scr_analog_clock_1_min_value, &watch_scr_analog_clock_1_sec_value);
    if (lv_obj_is_valid(guider_ui.watch_scr_analog_clock_1))
    {
        lv_analogclock_set_time(guider_ui.watch_scr_analog_clock_1, watch_scr_analog_clock_1_hour_value, watch_scr_analog_clock_1_min_value, watch_scr_analog_clock_1_sec_value);
    }
}
void lv_control_scr_spinbox_1_increment_event_cb(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT) {
        lv_spinbox_increment(guider_ui.control_scr_spinbox_1);
    }
}
void lv_control_scr_spinbox_1_decrement_event_cb(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if(code == LV_EVENT_SHORT_CLICKED || code == LV_EVENT_LONG_PRESSED_REPEAT) {
        lv_spinbox_decrement(guider_ui.control_scr_spinbox_1);
    }
}

