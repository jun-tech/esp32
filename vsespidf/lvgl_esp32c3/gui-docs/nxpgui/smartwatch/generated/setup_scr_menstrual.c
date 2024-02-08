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


void setup_scr_menstrual(lv_ui *ui)
{
	//Write codes menstrual
	ui->menstrual = lv_obj_create(NULL);
	lv_obj_set_size(ui->menstrual, 240, 240);

	//Write style for menstrual, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->menstrual, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->menstrual, &_img_bg_2_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->menstrual, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menstrual_home
	ui->menstrual_home = lv_img_create(ui->menstrual);
	lv_obj_add_flag(ui->menstrual_home, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->menstrual_home, &_text_home_alpha_36x48);
	lv_img_set_pivot(ui->menstrual_home, 50,50);
	lv_img_set_angle(ui->menstrual_home, 0);
	lv_obj_set_pos(ui->menstrual_home, 326, 260);
	lv_obj_set_size(ui->menstrual_home, 36, 48);

	//Write style for menstrual_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->menstrual_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menstrual_left
	ui->menstrual_left = lv_img_create(ui->menstrual);
	lv_obj_add_flag(ui->menstrual_left, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->menstrual_left, &_img_arrow_left_alpha_9x32);
	lv_img_set_pivot(ui->menstrual_left, 50,50);
	lv_img_set_angle(ui->menstrual_left, 0);
	lv_obj_set_pos(ui->menstrual_left, 10, 172);
	lv_obj_set_size(ui->menstrual_left, 9, 32);
	lv_obj_add_flag(ui->menstrual_left, LV_OBJ_FLAG_FLOATING);

	//Write style for menstrual_left, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->menstrual_left, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menstrual_right
	ui->menstrual_right = lv_img_create(ui->menstrual);
	lv_obj_add_flag(ui->menstrual_right, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->menstrual_right, &_img_arrow_right_alpha_9x32);
	lv_img_set_pivot(ui->menstrual_right, 50,50);
	lv_img_set_angle(ui->menstrual_right, 0);
	lv_obj_set_pos(ui->menstrual_right, 368, 172);
	lv_obj_set_size(ui->menstrual_right, 9, 32);
	lv_obj_add_flag(ui->menstrual_right, LV_OBJ_FLAG_FLOATING);

	//Write style for menstrual_right, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->menstrual_right, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menstrual_title
	ui->menstrual_title = lv_label_create(ui->menstrual);
	lv_label_set_text(ui->menstrual_title, "Step count");
	lv_label_set_long_mode(ui->menstrual_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->menstrual_title, 0, -84);
	lv_obj_set_size(ui->menstrual_title, 392, 75);
	lv_obj_add_flag(ui->menstrual_title, LV_OBJ_FLAG_FLOATING);

	//Write style for menstrual_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->menstrual_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menstrual_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menstrual_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menstrual_title, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->menstrual_title, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->menstrual_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menstrual_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->menstrual_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->menstrual_title, 27, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->menstrual_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->menstrual_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->menstrual_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->menstrual_title, &_img_header_bg_392x75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->menstrual_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor(ui->menstrual_title, lv_color_hex(0xBD1C39), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor_opa(ui->menstrual_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menstrual_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menstrual_img_ovulation
	ui->menstrual_img_ovulation = lv_img_create(ui->menstrual);
	lv_obj_add_flag(ui->menstrual_img_ovulation, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->menstrual_img_ovulation, &_img_menstrual_chart_alpha_221x227);
	lv_img_set_pivot(ui->menstrual_img_ovulation, 50,50);
	lv_img_set_angle(ui->menstrual_img_ovulation, 0);
	lv_obj_set_pos(ui->menstrual_img_ovulation, 86, 102);
	lv_obj_set_size(ui->menstrual_img_ovulation, 221, 227);

	//Write style for menstrual_img_ovulation, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->menstrual_img_ovulation, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menstrual_label_ovulation
	ui->menstrual_label_ovulation = lv_label_create(ui->menstrual);
	lv_label_set_text(ui->menstrual_label_ovulation, "Ovulation\n\n\n\n");
	lv_label_set_long_mode(ui->menstrual_label_ovulation, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->menstrual_label_ovulation, 121, 409);
	lv_obj_set_size(ui->menstrual_label_ovulation, 151, 38);

	//Write style for menstrual_label_ovulation, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->menstrual_label_ovulation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menstrual_label_ovulation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menstrual_label_ovulation, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menstrual_label_ovulation, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->menstrual_label_ovulation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->menstrual_label_ovulation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menstrual_label_ovulation, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->menstrual_label_ovulation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->menstrual_label_ovulation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->menstrual_label_ovulation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->menstrual_label_ovulation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->menstrual_label_ovulation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menstrual_label_ovulation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menstrual_label_cycle
	ui->menstrual_label_cycle = lv_label_create(ui->menstrual);
	lv_label_set_text(ui->menstrual_label_cycle, "CYCLE DAY");
	lv_label_set_long_mode(ui->menstrual_label_cycle, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->menstrual_label_cycle, 148, 19);
	lv_obj_set_size(ui->menstrual_label_cycle, 96, 24);

	//Write style for menstrual_label_cycle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->menstrual_label_cycle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menstrual_label_cycle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menstrual_label_cycle, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menstrual_label_cycle, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->menstrual_label_cycle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->menstrual_label_cycle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menstrual_label_cycle, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->menstrual_label_cycle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->menstrual_label_cycle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->menstrual_label_cycle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->menstrual_label_cycle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->menstrual_label_cycle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menstrual_label_cycle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menstrual_label_days
	ui->menstrual_label_days = lv_label_create(ui->menstrual);
	lv_label_set_text(ui->menstrual_label_days, "12");
	lv_label_set_long_mode(ui->menstrual_label_days, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->menstrual_label_days, 131, 164);
	lv_obj_set_size(ui->menstrual_label_days, 130, 102);

	//Write style for menstrual_label_days, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->menstrual_label_days, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menstrual_label_days, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menstrual_label_days, lv_color_hex(0x00DB0e), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menstrual_label_days, &lv_font_montserratMedium_100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->menstrual_label_days, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->menstrual_label_days, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menstrual_label_days, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->menstrual_label_days, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->menstrual_label_days, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->menstrual_label_days, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->menstrual_label_days, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->menstrual_label_days, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menstrual_label_days, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->menstrual);

	
	//Init events for screen.
	events_init_menstrual(ui);
}
