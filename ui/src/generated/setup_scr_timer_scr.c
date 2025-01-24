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
#include "widgets_init.h"
#include "ui/src/custom/custom.h"



int timer_scr_digital_clock_1_min_value = 25;
int timer_scr_digital_clock_1_hour_value = 11;
int timer_scr_digital_clock_1_sec_value = 50;
void setup_scr_timer_scr(lv_ui *ui)
{
    //Write codes timer_scr
    ui->timer_scr = lv_obj_create(NULL);
    lv_obj_set_size(ui->timer_scr, 240, 280);
    lv_obj_set_scrollbar_mode(ui->timer_scr, LV_SCROLLBAR_MODE_OFF);

    //Write style for timer_scr, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->timer_scr, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->timer_scr, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->timer_scr, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes timer_scr_datetext_1
    ui->timer_scr_datetext_1 = lv_label_create(ui->timer_scr);
    lv_label_set_text(ui->timer_scr_datetext_1, "2023/07/31");
    lv_obj_set_style_text_align(ui->timer_scr_datetext_1, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_flag(ui->timer_scr_datetext_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui->timer_scr_datetext_1, timer_scr_datetext_1_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_set_pos(ui->timer_scr_datetext_1, 6, 3);
    lv_obj_set_size(ui->timer_scr_datetext_1, 84, 23);

    //Write style for timer_scr_datetext_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->timer_scr_datetext_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->timer_scr_datetext_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->timer_scr_datetext_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->timer_scr_datetext_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->timer_scr_datetext_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->timer_scr_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->timer_scr_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->timer_scr_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->timer_scr_datetext_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->timer_scr_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->timer_scr_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->timer_scr_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes timer_scr_digital_clock_1
    static bool timer_scr_digital_clock_1_timer_enabled = false;
    ui->timer_scr_digital_clock_1 = lv_dclock_create(ui->timer_scr, "11:25:50");
    if (!timer_scr_digital_clock_1_timer_enabled) {
        // lv_timer_create(timer_scr_digital_clock_1_timer, 1000, NULL);
        // timer_scr_digital_clock_1_timer_enabled = true;
    }
    lv_obj_set_pos(ui->timer_scr_digital_clock_1, 0, 44);
    lv_obj_set_size(ui->timer_scr_digital_clock_1, 240, 74);

    //Write style for timer_scr_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->timer_scr_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->timer_scr_digital_clock_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->timer_scr_digital_clock_1, &lv_font_Antonio_Regular_67, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->timer_scr_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->timer_scr_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->timer_scr_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->timer_scr_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->timer_scr_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->timer_scr_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->timer_scr_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->timer_scr_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->timer_scr_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes timer_scr_cont_1
    ui->timer_scr_cont_1 = lv_obj_create(ui->timer_scr);
    lv_obj_set_pos(ui->timer_scr_cont_1, 40, 120);
    lv_obj_set_size(ui->timer_scr_cont_1, 171, 104);
    lv_obj_set_scrollbar_mode(ui->timer_scr_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for timer_scr_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->timer_scr_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->timer_scr_cont_1, 19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->timer_scr_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->timer_scr_cont_1, lv_color_hex(0x009bff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->timer_scr_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->timer_scr_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->timer_scr_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->timer_scr_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->timer_scr_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->timer_scr_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes timer_scr_textprogress_1
    ui->timer_scr_textprogress_1 = lv_textprogress_create(ui->timer_scr);
    lv_textprogress_set_range_value(ui->timer_scr_textprogress_1, 0, 100, 0, 0);
    lv_textprogress_set_decimal(ui->timer_scr_textprogress_1, 0);
    lv_textprogress_set_value(ui->timer_scr_textprogress_1, 0);
    lv_obj_set_pos(ui->timer_scr_textprogress_1, 191, 4);
    lv_obj_set_size(ui->timer_scr_textprogress_1, 45, 23);

    //Write style for timer_scr_textprogress_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->timer_scr_textprogress_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->timer_scr_textprogress_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->timer_scr_textprogress_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->timer_scr_textprogress_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->timer_scr_textprogress_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->timer_scr_textprogress_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->timer_scr_textprogress_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->timer_scr_textprogress_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->timer_scr_textprogress_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->timer_scr_textprogress_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->timer_scr_textprogress_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes timer_scr_bar_power
    ui->timer_scr_bar_power = lv_bar_create(ui->timer_scr);
    lv_obj_set_style_anim_time(ui->timer_scr_bar_power, 1000, 0);
    lv_bar_set_mode(ui->timer_scr_bar_power, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->timer_scr_bar_power, 0, 100);
    lv_bar_set_value(ui->timer_scr_bar_power, 0, LV_ANIM_OFF);
    lv_obj_set_pos(ui->timer_scr_bar_power, 149, 10);
    lv_obj_set_size(ui->timer_scr_bar_power, 38, 14);

    //Write style for timer_scr_bar_power, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->timer_scr_bar_power, 104, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->timer_scr_bar_power, lv_color_hex(0x009bff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->timer_scr_bar_power, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->timer_scr_bar_power, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->timer_scr_bar_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for timer_scr_bar_power, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->timer_scr_bar_power, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->timer_scr_bar_power, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->timer_scr_bar_power, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->timer_scr_bar_power, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //The custom code of timer_scr.


    //Update current screen layout.
    lv_obj_update_layout(ui->timer_scr);

    //Init events for screen.
    events_init_timer_scr(ui);
}
