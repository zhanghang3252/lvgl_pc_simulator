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



void setup_scr_control_scr(lv_ui *ui)
{
    //Write codes control_scr
    ui->control_scr = lv_obj_create(NULL);
    lv_obj_set_size(ui->control_scr, 240, 280);
    lv_obj_set_scrollbar_mode(ui->control_scr, LV_SCROLLBAR_MODE_OFF);

    //Write style for control_scr, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->control_scr, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->control_scr, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->control_scr, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes control_scr_bar_1
    ui->control_scr_bar_1 = lv_bar_create(ui->control_scr);
    lv_obj_set_style_anim_time(ui->control_scr_bar_1, 1000, 0);
    lv_bar_set_mode(ui->control_scr_bar_1, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->control_scr_bar_1, 0, 100);
    lv_bar_set_value(ui->control_scr_bar_1, 0, LV_ANIM_OFF);
    lv_obj_set_pos(ui->control_scr_bar_1, 75, 16);
    lv_obj_set_size(ui->control_scr_bar_1, 90, 20);

    //Write style for control_scr_bar_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->control_scr_bar_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->control_scr_bar_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->control_scr_bar_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_scr_bar_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->control_scr_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for control_scr_bar_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->control_scr_bar_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->control_scr_bar_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->control_scr_bar_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_scr_bar_1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes control_scr_slider_1
    ui->control_scr_slider_1 = lv_slider_create(ui->control_scr);
    lv_slider_set_range(ui->control_scr_slider_1, 0, 100);
    lv_slider_set_mode(ui->control_scr_slider_1, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->control_scr_slider_1, 0, LV_ANIM_OFF);
    lv_obj_set_pos(ui->control_scr_slider_1, 32, 56);
    lv_obj_set_size(ui->control_scr_slider_1, 160, 8);

    //Write style for control_scr_slider_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->control_scr_slider_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->control_scr_slider_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->control_scr_slider_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_scr_slider_1, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->control_scr_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->control_scr_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for control_scr_slider_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->control_scr_slider_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->control_scr_slider_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->control_scr_slider_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_scr_slider_1, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for control_scr_slider_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->control_scr_slider_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->control_scr_slider_1, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->control_scr_slider_1, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_scr_slider_1, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes control_scr_ddlist_1
    ui->control_scr_ddlist_1 = lv_dropdown_create(ui->control_scr);
    lv_dropdown_set_options(ui->control_scr_ddlist_1, "list1\nlist2\nlist3\nlist4");
    lv_obj_set_pos(ui->control_scr_ddlist_1, 53, 80);
    lv_obj_set_size(ui->control_scr_ddlist_1, 130, 30);

    //Write style for control_scr_ddlist_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->control_scr_ddlist_1, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->control_scr_ddlist_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->control_scr_ddlist_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->control_scr_ddlist_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->control_scr_ddlist_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->control_scr_ddlist_1, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->control_scr_ddlist_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->control_scr_ddlist_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->control_scr_ddlist_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->control_scr_ddlist_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_scr_ddlist_1, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->control_scr_ddlist_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->control_scr_ddlist_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->control_scr_ddlist_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->control_scr_ddlist_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_control_scr_ddlist_1_extra_list_selected_checked
    static lv_style_t style_control_scr_ddlist_1_extra_list_selected_checked;
    ui_init_style(&style_control_scr_ddlist_1_extra_list_selected_checked);

    lv_style_set_border_width(&style_control_scr_ddlist_1_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_control_scr_ddlist_1_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_control_scr_ddlist_1_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_control_scr_ddlist_1_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_control_scr_ddlist_1_extra_list_selected_checked, 3);
    lv_style_set_bg_opa(&style_control_scr_ddlist_1_extra_list_selected_checked, 255);
    lv_style_set_bg_color(&style_control_scr_ddlist_1_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_control_scr_ddlist_1_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->control_scr_ddlist_1), &style_control_scr_ddlist_1_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_control_scr_ddlist_1_extra_list_main_default
    static lv_style_t style_control_scr_ddlist_1_extra_list_main_default;
    ui_init_style(&style_control_scr_ddlist_1_extra_list_main_default);

    lv_style_set_max_height(&style_control_scr_ddlist_1_extra_list_main_default, 90);
    lv_style_set_text_color(&style_control_scr_ddlist_1_extra_list_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_control_scr_ddlist_1_extra_list_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_control_scr_ddlist_1_extra_list_main_default, 255);
    lv_style_set_border_width(&style_control_scr_ddlist_1_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_control_scr_ddlist_1_extra_list_main_default, 255);
    lv_style_set_border_color(&style_control_scr_ddlist_1_extra_list_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_control_scr_ddlist_1_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_control_scr_ddlist_1_extra_list_main_default, 3);
    lv_style_set_bg_opa(&style_control_scr_ddlist_1_extra_list_main_default, 255);
    lv_style_set_bg_color(&style_control_scr_ddlist_1_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_control_scr_ddlist_1_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->control_scr_ddlist_1), &style_control_scr_ddlist_1_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_control_scr_ddlist_1_extra_list_scrollbar_default
    static lv_style_t style_control_scr_ddlist_1_extra_list_scrollbar_default;
    ui_init_style(&style_control_scr_ddlist_1_extra_list_scrollbar_default);

    lv_style_set_radius(&style_control_scr_ddlist_1_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_control_scr_ddlist_1_extra_list_scrollbar_default, 255);
    lv_style_set_bg_color(&style_control_scr_ddlist_1_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
    lv_style_set_bg_grad_dir(&style_control_scr_ddlist_1_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->control_scr_ddlist_1), &style_control_scr_ddlist_1_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes control_scr_cb_2
    ui->control_scr_cb_2 = lv_checkbox_create(ui->control_scr);
    lv_checkbox_set_text(ui->control_scr_cb_2, "checkbox");
    lv_obj_set_pos(ui->control_scr_cb_2, 53, 157);

    //Write style for control_scr_cb_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->control_scr_cb_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->control_scr_cb_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->control_scr_cb_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->control_scr_cb_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->control_scr_cb_2, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->control_scr_cb_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->control_scr_cb_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->control_scr_cb_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->control_scr_cb_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_scr_cb_2, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->control_scr_cb_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->control_scr_cb_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->control_scr_cb_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->control_scr_cb_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for control_scr_cb_2, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_all(ui->control_scr_cb_2, 3, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->control_scr_cb_2, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->control_scr_cb_2, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->control_scr_cb_2, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->control_scr_cb_2, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_scr_cb_2, 6, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->control_scr_cb_2, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->control_scr_cb_2, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->control_scr_cb_2, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes control_scr_cb_1
    ui->control_scr_cb_1 = lv_checkbox_create(ui->control_scr);
    lv_checkbox_set_text(ui->control_scr_cb_1, "checkbox");
    lv_obj_set_pos(ui->control_scr_cb_1, 53, 122);

    //Write style for control_scr_cb_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->control_scr_cb_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->control_scr_cb_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->control_scr_cb_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->control_scr_cb_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->control_scr_cb_1, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->control_scr_cb_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->control_scr_cb_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->control_scr_cb_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->control_scr_cb_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_scr_cb_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->control_scr_cb_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->control_scr_cb_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->control_scr_cb_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->control_scr_cb_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for control_scr_cb_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_all(ui->control_scr_cb_1, 3, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->control_scr_cb_1, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->control_scr_cb_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->control_scr_cb_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->control_scr_cb_1, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_scr_cb_1, 6, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->control_scr_cb_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->control_scr_cb_1, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->control_scr_cb_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes control_scr_spinbox_1
    ui->control_scr_spinbox_1 = lv_spinbox_create(ui->control_scr);
    lv_obj_set_pos(ui->control_scr_spinbox_1, 85, 197);
    lv_obj_set_width(ui->control_scr_spinbox_1, 70);
    lv_obj_set_height(ui->control_scr_spinbox_1, 40);
    lv_spinbox_set_digit_format(ui->control_scr_spinbox_1, 3, 3);
    lv_spinbox_set_range(ui->control_scr_spinbox_1, -999, 999);
    lv_coord_t control_scr_spinbox_1_h = lv_obj_get_height(ui->control_scr_spinbox_1);
    ui->control_scr_spinbox_1_btn = lv_btn_create(ui->control_scr);
    lv_obj_set_size(ui->control_scr_spinbox_1_btn, control_scr_spinbox_1_h, control_scr_spinbox_1_h);
    lv_obj_align_to(ui->control_scr_spinbox_1_btn, ui->control_scr_spinbox_1, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_set_style_bg_img_src(ui->control_scr_spinbox_1_btn, LV_SYMBOL_PLUS, 0);
    lv_obj_add_event_cb(ui->control_scr_spinbox_1_btn, lv_control_scr_spinbox_1_increment_event_cb, LV_EVENT_ALL, NULL);
    ui->control_scr_spinbox_1_btn_minus = lv_btn_create(ui->control_scr);
    lv_obj_set_size(ui->control_scr_spinbox_1_btn_minus, control_scr_spinbox_1_h, control_scr_spinbox_1_h);
    lv_obj_align_to(ui->control_scr_spinbox_1_btn_minus, ui->control_scr_spinbox_1, LV_ALIGN_OUT_LEFT_MID, -5, 0);
    lv_obj_set_style_bg_img_src(ui->control_scr_spinbox_1_btn_minus, LV_SYMBOL_MINUS, 0);
    lv_obj_add_event_cb(ui->control_scr_spinbox_1_btn_minus, lv_control_scr_spinbox_1_decrement_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_set_pos(ui->control_scr_spinbox_1, 85, 197);

    //Write style for control_scr_spinbox_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->control_scr_spinbox_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->control_scr_spinbox_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->control_scr_spinbox_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->control_scr_spinbox_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->control_scr_spinbox_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->control_scr_spinbox_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->control_scr_spinbox_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->control_scr_spinbox_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->control_scr_spinbox_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->control_scr_spinbox_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->control_scr_spinbox_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->control_scr_spinbox_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->control_scr_spinbox_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->control_scr_spinbox_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->control_scr_spinbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_scr_spinbox_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->control_scr_spinbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for control_scr_spinbox_1, Part: LV_PART_CURSOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->control_scr_spinbox_1, lv_color_hex(0xffffff), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->control_scr_spinbox_1, &lv_font_montserratMedium_12, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->control_scr_spinbox_1, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->control_scr_spinbox_1, 255, LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->control_scr_spinbox_1, lv_color_hex(0x2195f6), LV_PART_CURSOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->control_scr_spinbox_1, LV_GRAD_DIR_NONE, LV_PART_CURSOR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_control_scr_spinbox_1_extra_btns_main_default
    static lv_style_t style_control_scr_spinbox_1_extra_btns_main_default;
    ui_init_style(&style_control_scr_spinbox_1_extra_btns_main_default);

    lv_style_set_text_color(&style_control_scr_spinbox_1_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_control_scr_spinbox_1_extra_btns_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_control_scr_spinbox_1_extra_btns_main_default, 255);
    lv_style_set_bg_opa(&style_control_scr_spinbox_1_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_control_scr_spinbox_1_extra_btns_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_control_scr_spinbox_1_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_control_scr_spinbox_1_extra_btns_main_default, 0);
    lv_style_set_radius(&style_control_scr_spinbox_1_extra_btns_main_default, 5);
    lv_style_set_shadow_width(&style_control_scr_spinbox_1_extra_btns_main_default, 0);
    lv_obj_add_style(ui->control_scr_spinbox_1_btn, &style_control_scr_spinbox_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->control_scr_spinbox_1_btn_minus, &style_control_scr_spinbox_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of control_scr.


    //Update current screen layout.
    lv_obj_update_layout(ui->control_scr);

}
