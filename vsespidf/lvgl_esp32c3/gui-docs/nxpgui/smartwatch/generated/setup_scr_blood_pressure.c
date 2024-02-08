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


void setup_scr_blood_pressure(lv_ui *ui)
{
	//Write codes blood_pressure
	ui->blood_pressure = lv_obj_create(NULL);
	lv_obj_set_size(ui->blood_pressure, 240, 240);

	//Write style for blood_pressure, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->blood_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->blood_pressure, &_img_bg_2_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->blood_pressure, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes blood_pressure_arc_stress
	ui->blood_pressure_arc_stress = lv_arc_create(ui->blood_pressure);
	lv_arc_set_mode(ui->blood_pressure_arc_stress, LV_ARC_MODE_NORMAL);
	lv_arc_set_range(ui->blood_pressure_arc_stress, 0, 100);
	lv_arc_set_bg_angles(ui->blood_pressure_arc_stress, 48, 212);
	lv_arc_set_angles(ui->blood_pressure_arc_stress, 48, 190);
	lv_arc_set_rotation(ui->blood_pressure_arc_stress, 0);
	lv_obj_set_pos(ui->blood_pressure_arc_stress, 11, 135);
	lv_obj_set_size(ui->blood_pressure_arc_stress, 370, 370);

	//Write style for blood_pressure_arc_stress, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->blood_pressure_arc_stress, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->blood_pressure_arc_stress, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->blood_pressure_arc_stress, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->blood_pressure_arc_stress, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->blood_pressure_arc_stress, lv_color_hex(0x29CE08), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->blood_pressure_arc_stress, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->blood_pressure_arc_stress, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->blood_pressure_arc_stress, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->blood_pressure_arc_stress, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->blood_pressure_arc_stress, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->blood_pressure_arc_stress, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for blood_pressure_arc_stress, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->blood_pressure_arc_stress, 15, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->blood_pressure_arc_stress, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->blood_pressure_arc_stress, lv_color_hex(0x29CE08), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for blood_pressure_arc_stress, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->blood_pressure_arc_stress, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->blood_pressure_arc_stress, lv_color_hex(0xFFFFFF), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->blood_pressure_arc_stress, 4, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes blood_pressure_home
	ui->blood_pressure_home = lv_img_create(ui->blood_pressure);
	lv_obj_add_flag(ui->blood_pressure_home, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->blood_pressure_home, &_text_home_alpha_36x48);
	lv_img_set_pivot(ui->blood_pressure_home, 50,50);
	lv_img_set_angle(ui->blood_pressure_home, 0);
	lv_obj_set_pos(ui->blood_pressure_home, 326, 260);
	lv_obj_set_size(ui->blood_pressure_home, 36, 48);

	//Write style for blood_pressure_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->blood_pressure_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes blood_pressure_title
	ui->blood_pressure_title = lv_label_create(ui->blood_pressure);
	lv_label_set_text(ui->blood_pressure_title, "Blood\nPressure");
	lv_label_set_long_mode(ui->blood_pressure_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->blood_pressure_title, 0, -84);
	lv_obj_set_size(ui->blood_pressure_title, 392, 75);
	lv_obj_add_flag(ui->blood_pressure_title, LV_OBJ_FLAG_FLOATING);

	//Write style for blood_pressure_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->blood_pressure_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->blood_pressure_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->blood_pressure_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->blood_pressure_title, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->blood_pressure_title, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->blood_pressure_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->blood_pressure_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->blood_pressure_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->blood_pressure_title, 13, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->blood_pressure_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->blood_pressure_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->blood_pressure_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->blood_pressure_title, &_img_header_bg_392x75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->blood_pressure_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor(ui->blood_pressure_title, lv_color_hex(0xBD1C39), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor_opa(ui->blood_pressure_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->blood_pressure_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes blood_pressure_label_ago
	ui->blood_pressure_label_ago = lv_label_create(ui->blood_pressure);
	lv_label_set_text(ui->blood_pressure_label_ago, "130\n 80");
	lv_label_set_long_mode(ui->blood_pressure_label_ago, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->blood_pressure_label_ago, 138, 78);
	lv_obj_set_size(ui->blood_pressure_label_ago, 194, 201);

	//Write style for blood_pressure_label_ago, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->blood_pressure_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->blood_pressure_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->blood_pressure_label_ago, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->blood_pressure_label_ago, &lv_font_montserratMedium_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->blood_pressure_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->blood_pressure_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->blood_pressure_label_ago, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->blood_pressure_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->blood_pressure_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->blood_pressure_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->blood_pressure_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->blood_pressure_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->blood_pressure_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes blood_pressure_left
	ui->blood_pressure_left = lv_img_create(ui->blood_pressure);
	lv_obj_add_flag(ui->blood_pressure_left, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->blood_pressure_left, &_img_arrow_left_alpha_9x32);
	lv_img_set_pivot(ui->blood_pressure_left, 50,50);
	lv_img_set_angle(ui->blood_pressure_left, 0);
	lv_obj_set_pos(ui->blood_pressure_left, 9, 172);
	lv_obj_set_size(ui->blood_pressure_left, 9, 32);
	lv_obj_add_flag(ui->blood_pressure_left, LV_OBJ_FLAG_FLOATING);

	//Write style for blood_pressure_left, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->blood_pressure_left, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes blood_pressure_right
	ui->blood_pressure_right = lv_img_create(ui->blood_pressure);
	lv_obj_add_flag(ui->blood_pressure_right, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->blood_pressure_right, &_img_arrow_right_alpha_9x32);
	lv_img_set_pivot(ui->blood_pressure_right, 50,50);
	lv_img_set_angle(ui->blood_pressure_right, 0);
	lv_obj_set_pos(ui->blood_pressure_right, 368, 172);
	lv_obj_set_size(ui->blood_pressure_right, 9, 32);
	lv_obj_add_flag(ui->blood_pressure_right, LV_OBJ_FLAG_FLOATING);

	//Write style for blood_pressure_right, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->blood_pressure_right, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes blood_pressure_label_sys
	ui->blood_pressure_label_sys = lv_label_create(ui->blood_pressure);
	lv_label_set_text(ui->blood_pressure_label_sys, "SYS\n\n\n\n\n");
	lv_label_set_long_mode(ui->blood_pressure_label_sys, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->blood_pressure_label_sys, 55, 120);
	lv_obj_set_size(ui->blood_pressure_label_sys, 61, 31);

	//Write style for blood_pressure_label_sys, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->blood_pressure_label_sys, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->blood_pressure_label_sys, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->blood_pressure_label_sys, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->blood_pressure_label_sys, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->blood_pressure_label_sys, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->blood_pressure_label_sys, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->blood_pressure_label_sys, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->blood_pressure_label_sys, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->blood_pressure_label_sys, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->blood_pressure_label_sys, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->blood_pressure_label_sys, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->blood_pressure_label_sys, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->blood_pressure_label_sys, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes blood_pressure_label_smmhg
	ui->blood_pressure_label_smmhg = lv_label_create(ui->blood_pressure);
	lv_label_set_text(ui->blood_pressure_label_smmhg, "mmHg");
	lv_label_set_long_mode(ui->blood_pressure_label_smmhg, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->blood_pressure_label_smmhg, 55, 151);
	lv_obj_set_size(ui->blood_pressure_label_smmhg, 69, 19);

	//Write style for blood_pressure_label_smmhg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->blood_pressure_label_smmhg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->blood_pressure_label_smmhg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->blood_pressure_label_smmhg, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->blood_pressure_label_smmhg, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->blood_pressure_label_smmhg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->blood_pressure_label_smmhg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->blood_pressure_label_smmhg, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->blood_pressure_label_smmhg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->blood_pressure_label_smmhg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->blood_pressure_label_smmhg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->blood_pressure_label_smmhg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->blood_pressure_label_smmhg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->blood_pressure_label_smmhg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes blood_pressure_label_dmmhg
	ui->blood_pressure_label_dmmhg = lv_label_create(ui->blood_pressure);
	lv_label_set_text(ui->blood_pressure_label_dmmhg, "mmHg");
	lv_label_set_long_mode(ui->blood_pressure_label_dmmhg, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->blood_pressure_label_dmmhg, 55, 247);
	lv_obj_set_size(ui->blood_pressure_label_dmmhg, 69, 19);

	//Write style for blood_pressure_label_dmmhg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->blood_pressure_label_dmmhg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->blood_pressure_label_dmmhg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->blood_pressure_label_dmmhg, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->blood_pressure_label_dmmhg, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->blood_pressure_label_dmmhg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->blood_pressure_label_dmmhg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->blood_pressure_label_dmmhg, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->blood_pressure_label_dmmhg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->blood_pressure_label_dmmhg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->blood_pressure_label_dmmhg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->blood_pressure_label_dmmhg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->blood_pressure_label_dmmhg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->blood_pressure_label_dmmhg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes blood_pressure_label_dia
	ui->blood_pressure_label_dia = lv_label_create(ui->blood_pressure);
	lv_label_set_text(ui->blood_pressure_label_dia, "DIA\n\n\n\n\n");
	lv_label_set_long_mode(ui->blood_pressure_label_dia, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->blood_pressure_label_dia, 55, 216);
	lv_obj_set_size(ui->blood_pressure_label_dia, 61, 31);

	//Write style for blood_pressure_label_dia, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->blood_pressure_label_dia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->blood_pressure_label_dia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->blood_pressure_label_dia, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->blood_pressure_label_dia, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->blood_pressure_label_dia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->blood_pressure_label_dia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->blood_pressure_label_dia, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->blood_pressure_label_dia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->blood_pressure_label_dia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->blood_pressure_label_dia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->blood_pressure_label_dia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->blood_pressure_label_dia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->blood_pressure_label_dia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes blood_pressure_cont_1
	ui->blood_pressure_cont_1 = lv_obj_create(ui->blood_pressure);
	lv_obj_set_pos(ui->blood_pressure_cont_1, 111, 298);
	lv_obj_set_size(ui->blood_pressure_cont_1, 170, 56);
	lv_obj_set_scrollbar_mode(ui->blood_pressure_cont_1, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->blood_pressure_cont_1, LV_OBJ_FLAG_FLOATING);

	//Write style for blood_pressure_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->blood_pressure_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->blood_pressure_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->blood_pressure_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->blood_pressure_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->blood_pressure_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->blood_pressure_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->blood_pressure_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->blood_pressure_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes blood_pressure_label_bpm
	ui->blood_pressure_label_bpm = lv_label_create(ui->blood_pressure_cont_1);
	lv_label_set_text(ui->blood_pressure_label_bpm, "67\n\n\n\n\n");
	lv_label_set_long_mode(ui->blood_pressure_label_bpm, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->blood_pressure_label_bpm, 66, 17);
	lv_obj_set_size(ui->blood_pressure_label_bpm, 33, 23);

	//Write style for blood_pressure_label_bpm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->blood_pressure_label_bpm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->blood_pressure_label_bpm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->blood_pressure_label_bpm, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->blood_pressure_label_bpm, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->blood_pressure_label_bpm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->blood_pressure_label_bpm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->blood_pressure_label_bpm, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->blood_pressure_label_bpm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->blood_pressure_label_bpm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->blood_pressure_label_bpm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->blood_pressure_label_bpm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->blood_pressure_label_bpm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->blood_pressure_label_bpm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes blood_pressure_label_bpm_text
	ui->blood_pressure_label_bpm_text = lv_label_create(ui->blood_pressure_cont_1);
	lv_label_set_text(ui->blood_pressure_label_bpm_text, "bpm");
	lv_label_set_long_mode(ui->blood_pressure_label_bpm_text, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->blood_pressure_label_bpm_text, 98, 26);
	lv_obj_set_size(ui->blood_pressure_label_bpm_text, 49, 19);

	//Write style for blood_pressure_label_bpm_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->blood_pressure_label_bpm_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->blood_pressure_label_bpm_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->blood_pressure_label_bpm_text, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->blood_pressure_label_bpm_text, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->blood_pressure_label_bpm_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->blood_pressure_label_bpm_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->blood_pressure_label_bpm_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->blood_pressure_label_bpm_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->blood_pressure_label_bpm_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->blood_pressure_label_bpm_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->blood_pressure_label_bpm_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->blood_pressure_label_bpm_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->blood_pressure_label_bpm_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes blood_pressure_icon_heart
	ui->blood_pressure_icon_heart = lv_img_create(ui->blood_pressure_cont_1);
	lv_obj_add_flag(ui->blood_pressure_icon_heart, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->blood_pressure_icon_heart, &_icn_heart_alpha_28x24);
	lv_img_set_pivot(ui->blood_pressure_icon_heart, 50,50);
	lv_img_set_angle(ui->blood_pressure_icon_heart, 0);
	lv_obj_set_pos(ui->blood_pressure_icon_heart, 25, 17);
	lv_obj_set_size(ui->blood_pressure_icon_heart, 28, 24);

	//Write style for blood_pressure_icon_heart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->blood_pressure_icon_heart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->blood_pressure);

	
	//Init events for screen.
	events_init_blood_pressure(ui);
}
