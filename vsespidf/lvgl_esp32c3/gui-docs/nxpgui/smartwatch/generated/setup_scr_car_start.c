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


void setup_scr_car_start(lv_ui *ui)
{
	//Write codes car_start
	ui->car_start = lv_obj_create(NULL);
	lv_obj_set_size(ui->car_start, 240, 240);

	//Write style for car_start, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->car_start, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->car_start, &_img_bg_2_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->car_start, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes car_start_car_icon
	ui->car_start_car_icon = lv_img_create(ui->car_start);
	lv_obj_add_flag(ui->car_start_car_icon, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->car_start_car_icon, &_img_car_alpha_84x84);
	lv_img_set_pivot(ui->car_start_car_icon, 50,50);
	lv_img_set_angle(ui->car_start_car_icon, 0);
	lv_obj_set_pos(ui->car_start_car_icon, 154, -107);
	lv_obj_set_size(ui->car_start_car_icon, 84, 84);

	//Write style for car_start_car_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->car_start_car_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes car_start_info_text
	ui->car_start_info_text = lv_label_create(ui->car_start);
	lv_label_set_text(ui->car_start_info_text, "Press and Hold for Remote start");
	lv_label_set_long_mode(ui->car_start_info_text, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->car_start_info_text, 100, 120);
	lv_obj_set_size(ui->car_start_info_text, 193, 52);

	//Write style for car_start_info_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->car_start_info_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->car_start_info_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->car_start_info_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->car_start_info_text, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->car_start_info_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->car_start_info_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->car_start_info_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->car_start_info_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->car_start_info_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->car_start_info_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->car_start_info_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->car_start_info_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->car_start_info_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes car_start_left
	ui->car_start_left = lv_img_create(ui->car_start);
	lv_obj_add_flag(ui->car_start_left, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->car_start_left, &_img_arrow_left_alpha_9x32);
	lv_img_set_pivot(ui->car_start_left, 50,50);
	lv_img_set_angle(ui->car_start_left, 0);
	lv_obj_set_pos(ui->car_start_left, 10, 172);
	lv_obj_set_size(ui->car_start_left, 9, 32);

	//Write style for car_start_left, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->car_start_left, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes car_start_right
	ui->car_start_right = lv_img_create(ui->car_start);
	lv_obj_add_flag(ui->car_start_right, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->car_start_right, &_img_arrow_right_alpha_9x32);
	lv_img_set_pivot(ui->car_start_right, 50,50);
	lv_img_set_angle(ui->car_start_right, 0);
	lv_obj_set_pos(ui->car_start_right, 368, 172);
	lv_obj_set_size(ui->car_start_right, 9, 32);

	//Write style for car_start_right, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->car_start_right, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes car_start_home
	ui->car_start_home = lv_img_create(ui->car_start);
	lv_obj_add_flag(ui->car_start_home, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->car_start_home, &_text_home_alpha_36x48);
	lv_img_set_pivot(ui->car_start_home, 50,50);
	lv_img_set_angle(ui->car_start_home, 0);
	lv_obj_set_pos(ui->car_start_home, 319, 259);
	lv_obj_set_size(ui->car_start_home, 36, 48);

	//Write style for car_start_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->car_start_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes car_start_start_imgbtn
	ui->car_start_start_imgbtn = lv_imgbtn_create(ui->car_start);
	lv_obj_add_flag(ui->car_start_start_imgbtn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->car_start_start_imgbtn, LV_IMGBTN_STATE_RELEASED, NULL, &_img_red_btn_alpha_184x184, NULL);
	lv_imgbtn_set_src(ui->car_start_start_imgbtn, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_img_green_btn_alpha_184x184, NULL);
	ui->car_start_start_imgbtn_label = lv_label_create(ui->car_start_start_imgbtn);
	lv_label_set_text(ui->car_start_start_imgbtn_label, "START");
	lv_label_set_long_mode(ui->car_start_start_imgbtn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->car_start_start_imgbtn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->car_start_start_imgbtn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->car_start_start_imgbtn, 104, 404);
	lv_obj_set_size(ui->car_start_start_imgbtn, 184, 184);

	//Write style for car_start_start_imgbtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->car_start_start_imgbtn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->car_start_start_imgbtn, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->car_start_start_imgbtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->car_start_start_imgbtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for car_start_start_imgbtn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->car_start_start_imgbtn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->car_start_start_imgbtn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->car_start_start_imgbtn, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->car_start_start_imgbtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for car_start_start_imgbtn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->car_start_start_imgbtn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->car_start_start_imgbtn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->car_start_start_imgbtn, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->car_start_start_imgbtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for car_start_start_imgbtn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->car_start_start_imgbtn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Update current screen layout.
	lv_obj_update_layout(ui->car_start);

	
	//Init events for screen.
	events_init_car_start(ui);
}
