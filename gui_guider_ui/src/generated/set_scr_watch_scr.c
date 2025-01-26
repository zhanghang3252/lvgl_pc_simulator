/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "gui_guider_ui/src/custom/custom.h"

void setup_scr_watch_scr(lv_ui *ui)
{
    //Write codes watch_scr
    ui->watch_scr = lv_obj_create(NULL);
    lv_obj_set_size(ui->watch_scr, 240, 280);
    lv_obj_set_scrollbar_mode(ui->watch_scr, LV_SCROLLBAR_MODE_OFF);

    //Write style for watch_scr, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->watch_scr, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->watch_scr, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->watch_scr, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes watch_scr_analog_clock_1
    static bool watch_scr_analog_clock_1_timer_enabled = false;
    ui->watch_scr_analog_clock_1 = lv_analogclock_create(ui->watch_scr);
    lv_analogclock_hide_digits(ui->watch_scr_analog_clock_1, false);
    lv_analogclock_hide_point(ui->watch_scr_analog_clock_1, true);
    lv_analogclock_set_major_ticks(ui->watch_scr_analog_clock_1, 2, 10, lv_color_hex(0x555555), 7);
    lv_analogclock_set_ticks(ui->watch_scr_analog_clock_1, 2, 5, lv_color_hex(0x333333));
    lv_analogclock_set_hour_needle_line(ui->watch_scr_analog_clock_1, 2, lv_color_hex(0xff0027), -40);
    lv_analogclock_set_min_needle_line(ui->watch_scr_analog_clock_1, 2, lv_color_hex(0x2FDA64), -30);
    lv_analogclock_set_sec_needle_line(ui->watch_scr_analog_clock_1, 2, lv_color_hex(0x2F35DA), -10);
    // lv_analogclock_set_time(ui->watch_scr_analog_clock_1, watch_scr_analog_clock_1_hour_value, watch_scr_analog_clock_1_min_value,watch_scr_analog_clock_1_sec_value);

    lv_obj_set_pos(ui->watch_scr_analog_clock_1, 22, 37);
    lv_obj_set_size(ui->watch_scr_analog_clock_1, 200, 200);

    //Write style for watch_scr_analog_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->watch_scr_analog_clock_1, 127, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->watch_scr_analog_clock_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->watch_scr_analog_clock_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->watch_scr_analog_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->watch_scr_analog_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for watch_scr_analog_clock_1, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->watch_scr_analog_clock_1, lv_color_hex(0xff0000), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->watch_scr_analog_clock_1, &lv_font_montserratMedium_12, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->watch_scr_analog_clock_1, 255, LV_PART_TICKS|LV_STATE_DEFAULT);

    //Write style for watch_scr_analog_clock_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->watch_scr_analog_clock_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->watch_scr_analog_clock_1, lv_color_hex(0x000000), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->watch_scr_analog_clock_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //The custom code of watch_scr.


    //Update current screen layout.
    lv_obj_update_layout(ui->watch_scr);

}
