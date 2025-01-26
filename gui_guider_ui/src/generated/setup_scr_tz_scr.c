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
#include "gui_guider_ui/src/custom/custom.h"



void setup_scr_tz_scr(lv_ui *ui)
{
    printf("setup_scr_tz_scr\n");
    //Write codes tz_scr
    ui->tz_scr = lv_obj_create(NULL);
    lv_obj_set_size(ui->tz_scr, 240, 280);
    lv_obj_set_scrollbar_mode(ui->tz_scr, LV_SCROLLBAR_MODE_AUTO);

    //Write style for tz_scr, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->tz_scr, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->tz_scr, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->tz_scr, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tz_scr_img_1
    ui->tz_scr_img_1 = lv_img_create(ui->tz_scr);
    lv_obj_add_flag(ui->tz_scr_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->tz_scr_img_1, &_xs_alpha_50x50);
    lv_img_set_pivot(ui->tz_scr_img_1, 50,50);
    lv_img_set_angle(ui->tz_scr_img_1, 0);
    lv_obj_set_pos(ui->tz_scr_img_1, 90, 115);
    lv_obj_set_size(ui->tz_scr_img_1, 50, 50);

    //Write style for tz_scr_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->tz_scr_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->tz_scr_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tz_scr_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->tz_scr_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes tz_scr_label_message
    ui->tz_scr_label_message = lv_label_create(ui->tz_scr);
    lv_label_set_text(ui->tz_scr_label_message, "no message");
    lv_label_set_long_mode(ui->tz_scr_label_message, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->tz_scr_label_message, 53, 168);
    lv_obj_set_size(ui->tz_scr_label_message, 145, 20);

    //Write style for tz_scr_label_message, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->tz_scr_label_message, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->tz_scr_label_message, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->tz_scr_label_message, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->tz_scr_label_message, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->tz_scr_label_message, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->tz_scr_label_message, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->tz_scr_label_message, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->tz_scr_label_message, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->tz_scr_label_message, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->tz_scr_label_message, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->tz_scr_label_message, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->tz_scr_label_message, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->tz_scr_label_message, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->tz_scr_label_message, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of tz_scr.


    //Update current screen layout.
    lv_obj_update_layout(ui->tz_scr);

    //Init events for screen.
    // events_init_tz_scr(ui);
}
