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



void setup_scr_led_scr(lv_ui *ui)
{
    printf("setup_scr_led_scr\n");

    //Write codes led_scr
    ui->led_scr = lv_obj_create(NULL);
    lv_obj_set_size(ui->led_scr, 240, 280);
    lv_obj_set_scrollbar_mode(ui->led_scr, LV_SCROLLBAR_MODE_OFF);

    //Write style for led_scr, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->led_scr, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->led_scr, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->led_scr, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes led_scr_btn_open
    ui->led_scr_btn_open = lv_btn_create(ui->led_scr);
    ui->led_scr_btn_open_label = lv_label_create(ui->led_scr_btn_open);
    lv_label_set_text(ui->led_scr_btn_open_label, "open");
    lv_label_set_long_mode(ui->led_scr_btn_open_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->led_scr_btn_open_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->led_scr_btn_open, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->led_scr_btn_open_label, LV_PCT(100));
    lv_obj_set_pos(ui->led_scr_btn_open, 16, 191);
    lv_obj_set_size(ui->led_scr_btn_open, 100, 50);

    //Write style for led_scr_btn_open, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->led_scr_btn_open, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->led_scr_btn_open, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->led_scr_btn_open, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->led_scr_btn_open, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->led_scr_btn_open, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->led_scr_btn_open, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->led_scr_btn_open, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->led_scr_btn_open, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->led_scr_btn_open, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->led_scr_btn_open, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes led_scr_btn_close
    ui->led_scr_btn_close = lv_btn_create(ui->led_scr);
    ui->led_scr_btn_close_label = lv_label_create(ui->led_scr_btn_close);
    lv_label_set_text(ui->led_scr_btn_close_label, "close");
    lv_label_set_long_mode(ui->led_scr_btn_close_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->led_scr_btn_close_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->led_scr_btn_close, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->led_scr_btn_close_label, LV_PCT(100));
    lv_obj_set_pos(ui->led_scr_btn_close, 130, 191);
    lv_obj_set_size(ui->led_scr_btn_close, 100, 50);

    //Write style for led_scr_btn_close, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->led_scr_btn_close, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->led_scr_btn_close, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->led_scr_btn_close, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->led_scr_btn_close, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->led_scr_btn_close, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->led_scr_btn_close, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->led_scr_btn_close, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->led_scr_btn_close, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->led_scr_btn_close, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->led_scr_btn_close, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes led_scr_led_1
    ui->led_scr_led_1 = lv_led_create(ui->led_scr);
    lv_led_set_brightness(ui->led_scr_led_1, 0);
    lv_led_set_color(ui->led_scr_led_1, lv_color_hex(0x2195f6));
    lv_obj_set_pos(ui->led_scr_led_1, 100, 95);
    lv_obj_set_size(ui->led_scr_led_1, 50, 50);

    //The custom code of led_scr.


    //Update current screen layout.
    lv_obj_update_layout(ui->led_scr);

    //Init events for screen.
    events_init_led_scr(ui);
}
