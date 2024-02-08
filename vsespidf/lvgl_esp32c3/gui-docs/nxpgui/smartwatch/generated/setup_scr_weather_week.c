/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"


void setup_scr_weather_week(lv_ui *ui)
{
	//Write codes weather_week
	ui->weather_week = lv_obj_create(NULL);
	lv_obj_set_size(ui->weather_week, 240, 240);

	//Write style for weather_week, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->weather_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->weather_week, &_img_bg_2_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->weather_week, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_week_list
	ui->weather_week_week_list = lv_obj_create(ui->weather_week);
	lv_obj_set_pos(ui->weather_week_week_list, 46, 75);
	lv_obj_set_size(ui->weather_week_week_list, 300, 477);
	lv_obj_set_scrollbar_mode(ui->weather_week_week_list, LV_SCROLLBAR_MODE_OFF);

	//Write style for weather_week_week_list, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_week_week_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_week_week_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_week_week_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_week_week_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_week_week_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_week_week_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_week_week_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_week_week_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_cont_14
	ui->weather_week_cont_14 = lv_obj_create(ui->weather_week_week_list);
	lv_obj_set_pos(ui->weather_week_cont_14, 2, 34);
	lv_obj_set_size(ui->weather_week_cont_14, 286, 45);
	lv_obj_set_scrollbar_mode(ui->weather_week_cont_14, LV_SCROLLBAR_MODE_OFF);

	//Write style for weather_week_cont_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_week_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_week_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_week_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_week_cont_14, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_week_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_week_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_week_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_week_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_img_33
	ui->weather_week_img_33 = lv_img_create(ui->weather_week_cont_14);
	lv_obj_add_flag(ui->weather_week_img_33, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->weather_week_img_33, &_icn_small_weather_3_alpha_30x32);
	lv_img_set_pivot(ui->weather_week_img_33, 50,50);
	lv_img_set_angle(ui->weather_week_img_33, 0);
	lv_obj_set_pos(ui->weather_week_img_33, 100, 0);
	lv_obj_set_size(ui->weather_week_img_33, 30, 32);

	//Write style for weather_week_img_33, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->weather_week_img_33, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_label_27
	ui->weather_week_label_27 = lv_label_create(ui->weather_week_cont_14);
	lv_label_set_text(ui->weather_week_label_27, "Today");
	lv_label_set_long_mode(ui->weather_week_label_27, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->weather_week_label_27, 10, 5);
	lv_obj_set_size(ui->weather_week_label_27, 77, 32);

	//Write style for weather_week_label_27, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_week_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_week_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->weather_week_label_27, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->weather_week_label_27, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->weather_week_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->weather_week_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->weather_week_label_27, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_week_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_week_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_week_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_week_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_week_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_week_label_27, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_label_26
	ui->weather_week_label_26 = lv_label_create(ui->weather_week_cont_14);
	lv_label_set_text(ui->weather_week_label_26, "28°-30°");
	lv_label_set_long_mode(ui->weather_week_label_26, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->weather_week_label_26, 163, 2);
	lv_obj_set_size(ui->weather_week_label_26, 111, 32);

	//Write style for weather_week_label_26, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_week_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_week_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->weather_week_label_26, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->weather_week_label_26, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->weather_week_label_26, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->weather_week_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->weather_week_label_26, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_week_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_week_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_week_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_week_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_week_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_week_label_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_img_32
	ui->weather_week_img_32 = lv_img_create(ui->weather_week_week_list);
	lv_obj_add_flag(ui->weather_week_img_32, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->weather_week_img_32, &_img_line_2_alpha_279x2);
	lv_img_set_pivot(ui->weather_week_img_32, 50,50);
	lv_img_set_angle(ui->weather_week_img_32, 0);
	lv_obj_set_pos(ui->weather_week_img_32, 11, 84);
	lv_obj_set_size(ui->weather_week_img_32, 279, 2);

	//Write style for weather_week_img_32, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->weather_week_img_32, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_cont_13
	ui->weather_week_cont_13 = lv_obj_create(ui->weather_week_week_list);
	lv_obj_set_pos(ui->weather_week_cont_13, 2, 99);
	lv_obj_set_size(ui->weather_week_cont_13, 286, 46);
	lv_obj_set_scrollbar_mode(ui->weather_week_cont_13, LV_SCROLLBAR_MODE_OFF);

	//Write style for weather_week_cont_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_week_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_week_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_week_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_week_cont_13, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_week_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_week_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_week_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_week_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_img_31
	ui->weather_week_img_31 = lv_img_create(ui->weather_week_cont_13);
	lv_obj_add_flag(ui->weather_week_img_31, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->weather_week_img_31, &_icn_small_weather_1_alpha_42x32);
	lv_img_set_pivot(ui->weather_week_img_31, 50,50);
	lv_img_set_angle(ui->weather_week_img_31, 0);
	lv_obj_set_pos(ui->weather_week_img_31, 100, 0);
	lv_obj_set_size(ui->weather_week_img_31, 42, 32);

	//Write style for weather_week_img_31, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->weather_week_img_31, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_label_25
	ui->weather_week_label_25 = lv_label_create(ui->weather_week_cont_13);
	lv_label_set_text(ui->weather_week_label_25, "Friday");
	lv_label_set_long_mode(ui->weather_week_label_25, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->weather_week_label_25, 10, 5);
	lv_obj_set_size(ui->weather_week_label_25, 94, 32);

	//Write style for weather_week_label_25, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_week_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_week_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->weather_week_label_25, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->weather_week_label_25, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->weather_week_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->weather_week_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->weather_week_label_25, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_week_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_week_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_week_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_week_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_week_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_week_label_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_label_24
	ui->weather_week_label_24 = lv_label_create(ui->weather_week_cont_13);
	lv_label_set_text(ui->weather_week_label_24, "28°-32°");
	lv_label_set_long_mode(ui->weather_week_label_24, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->weather_week_label_24, 163, 2);
	lv_obj_set_size(ui->weather_week_label_24, 111, 32);

	//Write style for weather_week_label_24, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_week_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_week_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->weather_week_label_24, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->weather_week_label_24, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->weather_week_label_24, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->weather_week_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->weather_week_label_24, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_week_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_week_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_week_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_week_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_week_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_week_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_cont_12
	ui->weather_week_cont_12 = lv_obj_create(ui->weather_week_week_list);
	lv_obj_set_pos(ui->weather_week_cont_12, 3, 231);
	lv_obj_set_size(ui->weather_week_cont_12, 286, 45);
	lv_obj_set_scrollbar_mode(ui->weather_week_cont_12, LV_SCROLLBAR_MODE_OFF);

	//Write style for weather_week_cont_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_week_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_week_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_week_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_week_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_week_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_week_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_week_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_week_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_img_30
	ui->weather_week_img_30 = lv_img_create(ui->weather_week_cont_12);
	lv_obj_add_flag(ui->weather_week_img_30, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->weather_week_img_30, &_icn_small_weather_2_alpha_41x38);
	lv_img_set_pivot(ui->weather_week_img_30, 50,50);
	lv_img_set_angle(ui->weather_week_img_30, 0);
	lv_obj_set_pos(ui->weather_week_img_30, 100, 1);
	lv_obj_set_size(ui->weather_week_img_30, 41, 38);

	//Write style for weather_week_img_30, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->weather_week_img_30, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_label_23
	ui->weather_week_label_23 = lv_label_create(ui->weather_week_cont_12);
	lv_label_set_text(ui->weather_week_label_23, "Sunday");
	lv_label_set_long_mode(ui->weather_week_label_23, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->weather_week_label_23, 10, 5);
	lv_obj_set_size(ui->weather_week_label_23, 95, 32);

	//Write style for weather_week_label_23, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_week_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_week_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->weather_week_label_23, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->weather_week_label_23, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->weather_week_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->weather_week_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->weather_week_label_23, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_week_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_week_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_week_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_week_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_week_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_week_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_label_22
	ui->weather_week_label_22 = lv_label_create(ui->weather_week_cont_12);
	lv_label_set_text(ui->weather_week_label_22, "22°-25°");
	lv_label_set_long_mode(ui->weather_week_label_22, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->weather_week_label_22, 163, 2);
	lv_obj_set_size(ui->weather_week_label_22, 111, 32);

	//Write style for weather_week_label_22, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_week_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_week_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->weather_week_label_22, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->weather_week_label_22, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->weather_week_label_22, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->weather_week_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->weather_week_label_22, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_week_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_week_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_week_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_week_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_week_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_week_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_cont_11
	ui->weather_week_cont_11 = lv_obj_create(ui->weather_week_week_list);
	lv_obj_set_pos(ui->weather_week_cont_11, 3, 163);
	lv_obj_set_size(ui->weather_week_cont_11, 286, 45);
	lv_obj_set_scrollbar_mode(ui->weather_week_cont_11, LV_SCROLLBAR_MODE_OFF);

	//Write style for weather_week_cont_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_week_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_week_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_week_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_week_cont_11, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_week_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_week_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_week_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_week_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_img_29
	ui->weather_week_img_29 = lv_img_create(ui->weather_week_cont_11);
	lv_obj_add_flag(ui->weather_week_img_29, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->weather_week_img_29, &_icn_small_weather_1_alpha_42x32);
	lv_img_set_pivot(ui->weather_week_img_29, 50,50);
	lv_img_set_angle(ui->weather_week_img_29, 0);
	lv_obj_set_pos(ui->weather_week_img_29, 100, 0);
	lv_obj_set_size(ui->weather_week_img_29, 42, 32);

	//Write style for weather_week_img_29, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->weather_week_img_29, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_label_21
	ui->weather_week_label_21 = lv_label_create(ui->weather_week_cont_11);
	lv_label_set_text(ui->weather_week_label_21, "Saturday");
	lv_label_set_long_mode(ui->weather_week_label_21, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->weather_week_label_21, 10, 5);
	lv_obj_set_size(ui->weather_week_label_21, 94, 32);

	//Write style for weather_week_label_21, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_week_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_week_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->weather_week_label_21, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->weather_week_label_21, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->weather_week_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->weather_week_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->weather_week_label_21, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_week_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_week_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_week_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_week_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_week_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_week_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_label_20
	ui->weather_week_label_20 = lv_label_create(ui->weather_week_cont_11);
	lv_label_set_text(ui->weather_week_label_20, "26°-30°");
	lv_label_set_long_mode(ui->weather_week_label_20, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->weather_week_label_20, 163, 2);
	lv_obj_set_size(ui->weather_week_label_20, 111, 32);

	//Write style for weather_week_label_20, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_week_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_week_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->weather_week_label_20, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->weather_week_label_20, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->weather_week_label_20, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->weather_week_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->weather_week_label_20, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_week_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_week_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_week_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_week_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_week_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_week_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_img_28
	ui->weather_week_img_28 = lv_img_create(ui->weather_week_week_list);
	lv_obj_add_flag(ui->weather_week_img_28, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->weather_week_img_28, &_img_line_2_alpha_279x2);
	lv_img_set_pivot(ui->weather_week_img_28, 50,50);
	lv_img_set_angle(ui->weather_week_img_28, 0);
	lv_obj_set_pos(ui->weather_week_img_28, 3, 216);
	lv_obj_set_size(ui->weather_week_img_28, 279, 2);

	//Write style for weather_week_img_28, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->weather_week_img_28, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_img_27
	ui->weather_week_img_27 = lv_img_create(ui->weather_week_week_list);
	lv_obj_add_flag(ui->weather_week_img_27, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->weather_week_img_27, &_img_line_2_alpha_279x2);
	lv_img_set_pivot(ui->weather_week_img_27, 50,50);
	lv_img_set_angle(ui->weather_week_img_27, 0);
	lv_obj_set_pos(ui->weather_week_img_27, 6, 152);
	lv_obj_set_size(ui->weather_week_img_27, 279, 2);

	//Write style for weather_week_img_27, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->weather_week_img_27, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_cont_10
	ui->weather_week_cont_10 = lv_obj_create(ui->weather_week_week_list);
	lv_obj_set_pos(ui->weather_week_cont_10, 3, 355);
	lv_obj_set_size(ui->weather_week_cont_10, 286, 45);
	lv_obj_set_scrollbar_mode(ui->weather_week_cont_10, LV_SCROLLBAR_MODE_OFF);

	//Write style for weather_week_cont_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_week_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_week_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_week_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_week_cont_10, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_week_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_week_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_week_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_week_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_img_26
	ui->weather_week_img_26 = lv_img_create(ui->weather_week_cont_10);
	lv_obj_add_flag(ui->weather_week_img_26, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->weather_week_img_26, &_icn_small_weather_3_alpha_30x32);
	lv_img_set_pivot(ui->weather_week_img_26, 50,50);
	lv_img_set_angle(ui->weather_week_img_26, 0);
	lv_obj_set_pos(ui->weather_week_img_26, 100, 3);
	lv_obj_set_size(ui->weather_week_img_26, 30, 32);

	//Write style for weather_week_img_26, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->weather_week_img_26, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_label_19
	ui->weather_week_label_19 = lv_label_create(ui->weather_week_cont_10);
	lv_label_set_text(ui->weather_week_label_19, "Tuesday");
	lv_label_set_long_mode(ui->weather_week_label_19, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->weather_week_label_19, 10, 5);
	lv_obj_set_size(ui->weather_week_label_19, 95, 32);

	//Write style for weather_week_label_19, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_week_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_week_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->weather_week_label_19, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->weather_week_label_19, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->weather_week_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->weather_week_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->weather_week_label_19, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_week_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_week_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_week_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_week_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_week_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_week_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_label_18
	ui->weather_week_label_18 = lv_label_create(ui->weather_week_cont_10);
	lv_label_set_text(ui->weather_week_label_18, "30°-35°");
	lv_label_set_long_mode(ui->weather_week_label_18, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->weather_week_label_18, 163, 2);
	lv_obj_set_size(ui->weather_week_label_18, 111, 32);

	//Write style for weather_week_label_18, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_week_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_week_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->weather_week_label_18, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->weather_week_label_18, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->weather_week_label_18, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->weather_week_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->weather_week_label_18, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_week_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_week_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_week_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_week_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_week_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_week_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_cont_9
	ui->weather_week_cont_9 = lv_obj_create(ui->weather_week_week_list);
	lv_obj_set_pos(ui->weather_week_cont_9, 3, 298);
	lv_obj_set_size(ui->weather_week_cont_9, 286, 45);
	lv_obj_set_scrollbar_mode(ui->weather_week_cont_9, LV_SCROLLBAR_MODE_OFF);

	//Write style for weather_week_cont_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_week_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_week_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_week_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_week_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_week_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_week_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_week_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_week_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_img_25
	ui->weather_week_img_25 = lv_img_create(ui->weather_week_cont_9);
	lv_obj_add_flag(ui->weather_week_img_25, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->weather_week_img_25, &_icn_small_weather_1_alpha_42x32);
	lv_img_set_pivot(ui->weather_week_img_25, 50,50);
	lv_img_set_angle(ui->weather_week_img_25, 0);
	lv_obj_set_pos(ui->weather_week_img_25, 100, 0);
	lv_obj_set_size(ui->weather_week_img_25, 42, 32);

	//Write style for weather_week_img_25, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->weather_week_img_25, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_label_17
	ui->weather_week_label_17 = lv_label_create(ui->weather_week_cont_9);
	lv_label_set_text(ui->weather_week_label_17, "Mayday");
	lv_label_set_long_mode(ui->weather_week_label_17, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->weather_week_label_17, 10, 5);
	lv_obj_set_size(ui->weather_week_label_17, 95, 32);

	//Write style for weather_week_label_17, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_week_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_week_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->weather_week_label_17, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->weather_week_label_17, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->weather_week_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->weather_week_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->weather_week_label_17, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_week_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_week_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_week_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_week_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_week_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_week_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_label_16
	ui->weather_week_label_16 = lv_label_create(ui->weather_week_cont_9);
	lv_label_set_text(ui->weather_week_label_16, "22°-27°");
	lv_label_set_long_mode(ui->weather_week_label_16, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->weather_week_label_16, 163, 2);
	lv_obj_set_size(ui->weather_week_label_16, 111, 32);

	//Write style for weather_week_label_16, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_week_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_week_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->weather_week_label_16, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->weather_week_label_16, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->weather_week_label_16, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->weather_week_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->weather_week_label_16, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_week_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_week_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_week_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_week_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_week_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_week_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_img_24
	ui->weather_week_img_24 = lv_img_create(ui->weather_week_week_list);
	lv_obj_add_flag(ui->weather_week_img_24, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->weather_week_img_24, &_img_line_2_alpha_279x2);
	lv_img_set_pivot(ui->weather_week_img_24, 50,50);
	lv_img_set_angle(ui->weather_week_img_24, 0);
	lv_obj_set_pos(ui->weather_week_img_24, 3, 282);
	lv_obj_set_size(ui->weather_week_img_24, 279, 2);

	//Write style for weather_week_img_24, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->weather_week_img_24, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_img_23
	ui->weather_week_img_23 = lv_img_create(ui->weather_week_week_list);
	lv_obj_add_flag(ui->weather_week_img_23, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->weather_week_img_23, &_img_line_2_alpha_279x2);
	lv_img_set_pivot(ui->weather_week_img_23, 50,50);
	lv_img_set_angle(ui->weather_week_img_23, 0);
	lv_obj_set_pos(ui->weather_week_img_23, 3, 345);
	lv_obj_set_size(ui->weather_week_img_23, 279, 2);

	//Write style for weather_week_img_23, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->weather_week_img_23, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_home
	ui->weather_week_home = lv_img_create(ui->weather_week);
	lv_obj_add_flag(ui->weather_week_home, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->weather_week_home, &_text_home_alpha_36x48);
	lv_img_set_pivot(ui->weather_week_home, 50,50);
	lv_img_set_angle(ui->weather_week_home, 0);
	lv_obj_set_pos(ui->weather_week_home, 319, 259);
	lv_obj_set_size(ui->weather_week_home, 36, 48);
	lv_obj_add_flag(ui->weather_week_home, LV_OBJ_FLAG_FLOATING);

	//Write style for weather_week_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->weather_week_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_select_icon
	ui->weather_week_select_icon = lv_img_create(ui->weather_week);
	lv_obj_add_flag(ui->weather_week_select_icon, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->weather_week_select_icon, &_text_select_alpha_43x57);
	lv_img_set_pivot(ui->weather_week_select_icon, 50,50);
	lv_img_set_angle(ui->weather_week_select_icon, 80);
	lv_obj_set_pos(ui->weather_week_select_icon, 321, 76);
	lv_obj_set_size(ui->weather_week_select_icon, 43, 57);
	lv_obj_add_flag(ui->weather_week_select_icon, LV_OBJ_FLAG_FLOATING);

	//Write style for weather_week_select_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->weather_week_select_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_week_title
	ui->weather_week_week_title = lv_label_create(ui->weather_week);
	lv_label_set_text(ui->weather_week_week_title, "Week forecast");
	lv_label_set_long_mode(ui->weather_week_week_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->weather_week_week_title, 0, -75);
	lv_obj_set_size(ui->weather_week_week_title, 392, 75);
	lv_obj_add_flag(ui->weather_week_week_title, LV_OBJ_FLAG_FLOATING);

	//Write style for weather_week_week_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_week_week_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_week_week_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->weather_week_week_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->weather_week_week_title, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->weather_week_week_title, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->weather_week_week_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->weather_week_week_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_week_week_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_week_week_title, 27, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_week_week_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_week_week_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_week_week_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->weather_week_week_title, &_img_header_bg_392x75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->weather_week_week_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor(ui->weather_week_week_title, lv_color_hex(0x1099e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor_opa(ui->weather_week_week_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_week_week_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_left
	ui->weather_week_left = lv_img_create(ui->weather_week);
	lv_obj_add_flag(ui->weather_week_left, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->weather_week_left, &_img_arrow_left_alpha_9x32);
	lv_img_set_pivot(ui->weather_week_left, 50,50);
	lv_img_set_angle(ui->weather_week_left, 0);
	lv_obj_set_pos(ui->weather_week_left, 10, 172);
	lv_obj_set_size(ui->weather_week_left, 9, 32);
	lv_obj_add_flag(ui->weather_week_left, LV_OBJ_FLAG_FLOATING);

	//Write style for weather_week_left, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->weather_week_left, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_week_right
	ui->weather_week_right = lv_img_create(ui->weather_week);
	lv_obj_add_flag(ui->weather_week_right, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->weather_week_right, &_img_arrow_right_alpha_9x32);
	lv_img_set_pivot(ui->weather_week_right, 50,50);
	lv_img_set_angle(ui->weather_week_right, 0);
	lv_obj_set_pos(ui->weather_week_right, 368, 172);
	lv_obj_set_size(ui->weather_week_right, 9, 32);
	lv_obj_add_flag(ui->weather_week_right, LV_OBJ_FLAG_FLOATING);

	//Write style for weather_week_right, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->weather_week_right, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->weather_week);

	
	//Init events for screen.
	events_init_weather_week(ui);
}
