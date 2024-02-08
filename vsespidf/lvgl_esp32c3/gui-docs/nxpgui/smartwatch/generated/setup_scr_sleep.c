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


void setup_scr_sleep(lv_ui *ui)
{
	//Write codes sleep
	ui->sleep = lv_obj_create(NULL);
	lv_obj_set_size(ui->sleep, 240, 240);

	//Write style for sleep, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->sleep, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->sleep, &_img_bg_health_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->sleep, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sleep_home
	ui->sleep_home = lv_img_create(ui->sleep);
	lv_obj_add_flag(ui->sleep_home, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sleep_home, &_text_home_alpha_36x48);
	lv_img_set_pivot(ui->sleep_home, 50,50);
	lv_img_set_angle(ui->sleep_home, 0);
	lv_obj_set_pos(ui->sleep_home, 326, 260);
	lv_obj_set_size(ui->sleep_home, 36, 48);

	//Write style for sleep_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->sleep_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sleep_title
	ui->sleep_title = lv_label_create(ui->sleep);
	lv_label_set_text(ui->sleep_title, "Sleep monitor");
	lv_label_set_long_mode(ui->sleep_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->sleep_title, 0, -84);
	lv_obj_set_size(ui->sleep_title, 392, 75);
	lv_obj_add_flag(ui->sleep_title, LV_OBJ_FLAG_FLOATING);

	//Write style for sleep_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->sleep_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->sleep_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->sleep_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->sleep_title, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->sleep_title, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->sleep_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->sleep_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->sleep_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->sleep_title, 27, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->sleep_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->sleep_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->sleep_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->sleep_title, &_img_header_bg_392x75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->sleep_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor(ui->sleep_title, lv_color_hex(0xBD1C39), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor_opa(ui->sleep_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->sleep_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sleep_left
	ui->sleep_left = lv_img_create(ui->sleep);
	lv_obj_add_flag(ui->sleep_left, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sleep_left, &_img_arrow_left_alpha_9x32);
	lv_img_set_pivot(ui->sleep_left, 50,50);
	lv_img_set_angle(ui->sleep_left, 0);
	lv_obj_set_pos(ui->sleep_left, 10, 172);
	lv_obj_set_size(ui->sleep_left, 9, 32);
	lv_obj_add_flag(ui->sleep_left, LV_OBJ_FLAG_FLOATING);

	//Write style for sleep_left, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->sleep_left, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sleep_right
	ui->sleep_right = lv_img_create(ui->sleep);
	lv_obj_add_flag(ui->sleep_right, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sleep_right, &_img_arrow_right_alpha_9x32);
	lv_img_set_pivot(ui->sleep_right, 50,50);
	lv_img_set_angle(ui->sleep_right, 0);
	lv_obj_set_pos(ui->sleep_right, 368, 172);
	lv_obj_set_size(ui->sleep_right, 9, 32);
	lv_obj_add_flag(ui->sleep_right, LV_OBJ_FLAG_FLOATING);

	//Write style for sleep_right, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->sleep_right, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sleep_cont_1
	ui->sleep_cont_1 = lv_obj_create(ui->sleep);
	lv_obj_set_pos(ui->sleep_cont_1, 111, 384);
	lv_obj_set_size(ui->sleep_cont_1, 170, 83);
	lv_obj_set_scrollbar_mode(ui->sleep_cont_1, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->sleep_cont_1, LV_OBJ_FLAG_FLOATING);

	//Write style for sleep_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->sleep_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->sleep_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->sleep_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->sleep_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->sleep_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->sleep_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->sleep_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->sleep_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sleep_label_time
	ui->sleep_label_time = lv_label_create(ui->sleep_cont_1);
	lv_label_set_text(ui->sleep_label_time, "17:25\n\n\n\n\n");
	lv_label_set_long_mode(ui->sleep_label_time, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->sleep_label_time, 53, 36);
	lv_obj_set_size(ui->sleep_label_time, 81, 34);

	//Write style for sleep_label_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->sleep_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->sleep_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->sleep_label_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->sleep_label_time, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->sleep_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->sleep_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->sleep_label_time, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->sleep_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->sleep_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->sleep_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->sleep_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->sleep_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->sleep_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sleep_label_today
	ui->sleep_label_today = lv_label_create(ui->sleep_cont_1);
	lv_label_set_text(ui->sleep_label_today, "TODAY");
	lv_label_set_long_mode(ui->sleep_label_today, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->sleep_label_today, 59, 15);
	lv_obj_set_size(ui->sleep_label_today, 69, 20);

	//Write style for sleep_label_today, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->sleep_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->sleep_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->sleep_label_today, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->sleep_label_today, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->sleep_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->sleep_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->sleep_label_today, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->sleep_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->sleep_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->sleep_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->sleep_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->sleep_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->sleep_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sleep_img_stages
	ui->sleep_img_stages = lv_img_create(ui->sleep);
	lv_obj_add_flag(ui->sleep_img_stages, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->sleep_img_stages, &_img_chart_sleep_alpha_336x135);
	lv_img_set_pivot(ui->sleep_img_stages, 50,50);
	lv_img_set_angle(ui->sleep_img_stages, 0);
	lv_obj_set_pos(ui->sleep_img_stages, 28, 121);
	lv_obj_set_size(ui->sleep_img_stages, 336, 135);

	//Write style for sleep_img_stages, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->sleep_img_stages, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes sleep_label_stages
	ui->sleep_label_stages = lv_label_create(ui->sleep);
	lv_label_set_text(ui->sleep_label_stages, "Sleep stages");
	lv_label_set_long_mode(ui->sleep_label_stages, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->sleep_label_stages, 112, 10);
	lv_obj_set_size(ui->sleep_label_stages, 168, 33);

	//Write style for sleep_label_stages, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->sleep_label_stages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->sleep_label_stages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->sleep_label_stages, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->sleep_label_stages, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->sleep_label_stages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->sleep_label_stages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->sleep_label_stages, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->sleep_label_stages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->sleep_label_stages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->sleep_label_stages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->sleep_label_stages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->sleep_label_stages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->sleep_label_stages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->sleep);

	
	//Init events for screen.
	events_init_sleep(ui);
}
