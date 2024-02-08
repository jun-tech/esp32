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


void setup_scr_car_lock(lv_ui *ui)
{
	//Write codes car_lock
	ui->car_lock = lv_obj_create(NULL);
	lv_obj_set_size(ui->car_lock, 240, 240);

	//Write style for car_lock, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->car_lock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->car_lock, &_img_bg_2_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->car_lock, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes car_lock_car_icon
	ui->car_lock_car_icon = lv_img_create(ui->car_lock);
	lv_obj_add_flag(ui->car_lock_car_icon, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->car_lock_car_icon, &_img_car_alpha_84x84);
	lv_img_set_pivot(ui->car_lock_car_icon, 50,50);
	lv_img_set_angle(ui->car_lock_car_icon, 0);
	lv_obj_set_pos(ui->car_lock_car_icon, 154, -94);
	lv_obj_set_size(ui->car_lock_car_icon, 84, 84);

	//Write style for car_lock_car_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->car_lock_car_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes car_lock_car_text
	ui->car_lock_car_text = lv_label_create(ui->car_lock);
	lv_label_set_text(ui->car_lock_car_text, "Your car is in range");
	lv_label_set_long_mode(ui->car_lock_car_text, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->car_lock_car_text, 39, 123);
	lv_obj_set_size(ui->car_lock_car_text, 315, 32);

	//Write style for car_lock_car_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->car_lock_car_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->car_lock_car_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->car_lock_car_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->car_lock_car_text, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->car_lock_car_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->car_lock_car_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->car_lock_car_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->car_lock_car_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->car_lock_car_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->car_lock_car_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->car_lock_car_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->car_lock_car_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->car_lock_car_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes car_lock_left
	ui->car_lock_left = lv_img_create(ui->car_lock);
	lv_obj_add_flag(ui->car_lock_left, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->car_lock_left, &_img_arrow_left_alpha_9x32);
	lv_img_set_pivot(ui->car_lock_left, 50,50);
	lv_img_set_angle(ui->car_lock_left, 0);
	lv_obj_set_pos(ui->car_lock_left, 10, 172);
	lv_obj_set_size(ui->car_lock_left, 9, 32);

	//Write style for car_lock_left, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->car_lock_left, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes car_lock_right
	ui->car_lock_right = lv_img_create(ui->car_lock);
	lv_obj_add_flag(ui->car_lock_right, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->car_lock_right, &_img_arrow_right_alpha_9x32);
	lv_img_set_pivot(ui->car_lock_right, 50,50);
	lv_img_set_angle(ui->car_lock_right, 0);
	lv_obj_set_pos(ui->car_lock_right, 368, 172);
	lv_obj_set_size(ui->car_lock_right, 9, 32);

	//Write style for car_lock_right, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->car_lock_right, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes car_lock_time_text
	ui->car_lock_time_text = lv_label_create(ui->car_lock);
	lv_label_set_text(ui->car_lock_time_text, "1 min ago");
	lv_label_set_long_mode(ui->car_lock_time_text, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->car_lock_time_text, 146, 172);
	lv_obj_set_size(ui->car_lock_time_text, 100, 26);

	//Write style for car_lock_time_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->car_lock_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->car_lock_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->car_lock_time_text, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->car_lock_time_text, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->car_lock_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->car_lock_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->car_lock_time_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->car_lock_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->car_lock_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->car_lock_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->car_lock_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->car_lock_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->car_lock_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes car_lock_home_text
	ui->car_lock_home_text = lv_img_create(ui->car_lock);
	lv_obj_add_flag(ui->car_lock_home_text, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->car_lock_home_text, &_text_home_alpha_36x48);
	lv_img_set_pivot(ui->car_lock_home_text, 50,50);
	lv_img_set_angle(ui->car_lock_home_text, 0);
	lv_obj_set_pos(ui->car_lock_home_text, 319, 259);
	lv_obj_set_size(ui->car_lock_home_text, 36, 48);

	//Write style for car_lock_home_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->car_lock_home_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes car_lock_cont_1
	ui->car_lock_cont_1 = lv_obj_create(ui->car_lock);
	lv_obj_set_pos(ui->car_lock_cont_1, 78, 329);
	lv_obj_set_size(ui->car_lock_cont_1, 237, 181);
	lv_obj_set_scrollbar_mode(ui->car_lock_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for car_lock_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->car_lock_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->car_lock_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->car_lock_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->car_lock_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->car_lock_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->car_lock_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->car_lock_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->car_lock_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes car_lock_lock_icon2
	ui->car_lock_lock_icon2 = lv_img_create(ui->car_lock_cont_1);
	lv_obj_add_flag(ui->car_lock_lock_icon2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->car_lock_lock_icon2, &_img_car_lock_2_alpha_63x56);
	lv_img_set_pivot(ui->car_lock_lock_icon2, 50,50);
	lv_img_set_angle(ui->car_lock_lock_icon2, 0);
	lv_obj_set_pos(ui->car_lock_lock_icon2, 79, 60);
	lv_obj_set_size(ui->car_lock_lock_icon2, 63, 56);

	//Write style for car_lock_lock_icon2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->car_lock_lock_icon2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes car_lock_lock_icon1
	ui->car_lock_lock_icon1 = lv_img_create(ui->car_lock_cont_1);
	lv_obj_add_flag(ui->car_lock_lock_icon1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->car_lock_lock_icon1, &_img_car_lock_1_alpha_117x89);
	lv_img_set_pivot(ui->car_lock_lock_icon1, 50,50);
	lv_img_set_angle(ui->car_lock_lock_icon1, 0);
	lv_obj_set_pos(ui->car_lock_lock_icon1, 61, 77);
	lv_obj_set_size(ui->car_lock_lock_icon1, 117, 89);

	//Write style for car_lock_lock_icon1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->car_lock_lock_icon1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->car_lock);

	
	//Init events for screen.
	events_init_car_lock(ui);
}
