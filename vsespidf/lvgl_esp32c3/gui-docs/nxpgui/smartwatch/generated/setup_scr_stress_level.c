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


void setup_scr_stress_level(lv_ui *ui)
{
	//Write codes stress_level
	ui->stress_level = lv_obj_create(NULL);
	lv_obj_set_size(ui->stress_level, 240, 240);

	//Write style for stress_level, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->stress_level, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->stress_level, &_img_bg_2_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->stress_level, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes stress_level_arc_stress
	ui->stress_level_arc_stress = lv_arc_create(ui->stress_level);
	lv_arc_set_mode(ui->stress_level_arc_stress, LV_ARC_MODE_NORMAL);
	lv_arc_set_range(ui->stress_level_arc_stress, 0, 100);
	lv_arc_set_bg_angles(ui->stress_level_arc_stress, 48, 212);
	lv_arc_set_angles(ui->stress_level_arc_stress, 48, 190);
	lv_arc_set_rotation(ui->stress_level_arc_stress, 0);
	lv_obj_set_pos(ui->stress_level_arc_stress, 11, 11);
	lv_obj_set_size(ui->stress_level_arc_stress, 370, 370);

	//Write style for stress_level_arc_stress, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->stress_level_arc_stress, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->stress_level_arc_stress, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->stress_level_arc_stress, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->stress_level_arc_stress, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->stress_level_arc_stress, lv_color_hex(0x29CE08), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->stress_level_arc_stress, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->stress_level_arc_stress, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->stress_level_arc_stress, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->stress_level_arc_stress, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->stress_level_arc_stress, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->stress_level_arc_stress, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for stress_level_arc_stress, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->stress_level_arc_stress, 15, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->stress_level_arc_stress, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->stress_level_arc_stress, lv_color_hex(0x29CE08), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for stress_level_arc_stress, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->stress_level_arc_stress, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->stress_level_arc_stress, lv_color_hex(0xFFFFFF), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->stress_level_arc_stress, 4, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes stress_level_home
	ui->stress_level_home = lv_img_create(ui->stress_level);
	lv_obj_add_flag(ui->stress_level_home, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->stress_level_home, &_text_home_alpha_36x48);
	lv_img_set_pivot(ui->stress_level_home, 50,50);
	lv_img_set_angle(ui->stress_level_home, 0);
	lv_obj_set_pos(ui->stress_level_home, 326, 260);
	lv_obj_set_size(ui->stress_level_home, 36, 48);

	//Write style for stress_level_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->stress_level_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes stress_level_title
	ui->stress_level_title = lv_label_create(ui->stress_level);
	lv_label_set_text(ui->stress_level_title, "Stress level");
	lv_label_set_long_mode(ui->stress_level_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->stress_level_title, 0, -84);
	lv_obj_set_size(ui->stress_level_title, 392, 75);
	lv_obj_add_flag(ui->stress_level_title, LV_OBJ_FLAG_FLOATING);

	//Write style for stress_level_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->stress_level_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->stress_level_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->stress_level_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->stress_level_title, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->stress_level_title, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->stress_level_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->stress_level_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->stress_level_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->stress_level_title, 27, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->stress_level_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->stress_level_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->stress_level_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->stress_level_title, &_img_header_bg_392x75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->stress_level_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor(ui->stress_level_title, lv_color_hex(0xBD1C39), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor_opa(ui->stress_level_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->stress_level_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes stress_level_label_ago
	ui->stress_level_label_ago = lv_label_create(ui->stress_level);
	lv_label_set_text(ui->stress_level_label_ago, "1 min ago");
	lv_label_set_long_mode(ui->stress_level_label_ago, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->stress_level_label_ago, 133, 23);
	lv_obj_set_size(ui->stress_level_label_ago, 127, 32);

	//Write style for stress_level_label_ago, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->stress_level_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->stress_level_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->stress_level_label_ago, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->stress_level_label_ago, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->stress_level_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->stress_level_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->stress_level_label_ago, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->stress_level_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->stress_level_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->stress_level_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->stress_level_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->stress_level_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->stress_level_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes stress_level_stress_icon
	ui->stress_level_stress_icon = lv_img_create(ui->stress_level);
	lv_obj_add_flag(ui->stress_level_stress_icon, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->stress_level_stress_icon, &_img_stress_level_alpha_67x105);
	lv_img_set_pivot(ui->stress_level_stress_icon, 50,50);
	lv_img_set_angle(ui->stress_level_stress_icon, 0);
	lv_obj_set_pos(ui->stress_level_stress_icon, 163, 136);
	lv_obj_set_size(ui->stress_level_stress_icon, 67, 105);

	//Write style for stress_level_stress_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->stress_level_stress_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes stress_level_label_average
	ui->stress_level_label_average = lv_label_create(ui->stress_level);
	lv_label_set_text(ui->stress_level_label_average, "Average");
	lv_label_set_long_mode(ui->stress_level_label_average, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->stress_level_label_average, 127, 340);
	lv_obj_set_size(ui->stress_level_label_average, 139, 41);

	//Write style for stress_level_label_average, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->stress_level_label_average, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->stress_level_label_average, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->stress_level_label_average, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->stress_level_label_average, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->stress_level_label_average, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->stress_level_label_average, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->stress_level_label_average, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->stress_level_label_average, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->stress_level_label_average, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->stress_level_label_average, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->stress_level_label_average, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->stress_level_label_average, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->stress_level_label_average, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes stress_level_img_2
	ui->stress_level_img_2 = lv_img_create(ui->stress_level);
	lv_obj_add_flag(ui->stress_level_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->stress_level_img_2, &_img_arrow_left_alpha_9x32);
	lv_img_set_pivot(ui->stress_level_img_2, 50,50);
	lv_img_set_angle(ui->stress_level_img_2, 0);
	lv_obj_set_pos(ui->stress_level_img_2, 8, 172);
	lv_obj_set_size(ui->stress_level_img_2, 9, 32);
	lv_obj_add_flag(ui->stress_level_img_2, LV_OBJ_FLAG_FLOATING);

	//Write style for stress_level_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->stress_level_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes stress_level_img_1
	ui->stress_level_img_1 = lv_img_create(ui->stress_level);
	lv_obj_add_flag(ui->stress_level_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->stress_level_img_1, &_img_arrow_right_alpha_9x32);
	lv_img_set_pivot(ui->stress_level_img_1, 50,50);
	lv_img_set_angle(ui->stress_level_img_1, 0);
	lv_obj_set_pos(ui->stress_level_img_1, 368, 172);
	lv_obj_set_size(ui->stress_level_img_1, 9, 32);
	lv_obj_add_flag(ui->stress_level_img_1, LV_OBJ_FLAG_FLOATING);

	//Write style for stress_level_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->stress_level_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->stress_level);

	
	//Init events for screen.
	events_init_stress_level(ui);
}
