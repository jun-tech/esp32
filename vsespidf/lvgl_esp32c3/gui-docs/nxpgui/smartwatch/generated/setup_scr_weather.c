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


void setup_scr_weather(lv_ui *ui)
{
	//Write codes weather
	ui->weather = lv_obj_create(NULL);
	lv_obj_set_size(ui->weather, 240, 240);

	//Write style for weather, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->weather, &_img_sun_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->weather, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_img_bgCloud
	ui->weather_img_bgCloud = lv_img_create(ui->weather);
	lv_obj_add_flag(ui->weather_img_bgCloud, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->weather_img_bgCloud, &_img_cloud_alpha_586x392);
	lv_img_set_pivot(ui->weather_img_bgCloud, 50,50);
	lv_img_set_angle(ui->weather_img_bgCloud, 0);
	lv_obj_set_pos(ui->weather_img_bgCloud, 0, 0);
	lv_obj_set_size(ui->weather_img_bgCloud, 586, 392);
	lv_obj_add_flag(ui->weather_img_bgCloud, LV_OBJ_FLAG_FLOATING);

	//Write style for weather_img_bgCloud, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->weather_img_bgCloud, 143, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_img_select
	ui->weather_img_select = lv_img_create(ui->weather);
	lv_obj_add_flag(ui->weather_img_select, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->weather_img_select, &_text_select_alpha_43x57);
	lv_img_set_pivot(ui->weather_img_select, 50,50);
	lv_img_set_angle(ui->weather_img_select, 80);
	lv_obj_set_pos(ui->weather_img_select, 322, 69);
	lv_obj_set_size(ui->weather_img_select, 43, 57);

	//Write style for weather_img_select, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->weather_img_select, 163, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_img_dialDot
	ui->weather_img_dialDot = lv_img_create(ui->weather);
	lv_obj_add_flag(ui->weather_img_dialDot, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->weather_img_dialDot, &_img_menu_alpha_11x117);
	lv_img_set_pivot(ui->weather_img_dialDot, 50,50);
	lv_img_set_angle(ui->weather_img_dialDot, 0);
	lv_obj_set_pos(ui->weather_img_dialDot, 365, 140);
	lv_obj_set_size(ui->weather_img_dialDot, 11, 117);

	//Write style for weather_img_dialDot, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->weather_img_dialDot, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_label_city
	ui->weather_label_city = lv_label_create(ui->weather);
	lv_label_set_text(ui->weather_label_city, "New York");
	lv_label_set_long_mode(ui->weather_label_city, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->weather_label_city, 82, -39);
	lv_obj_set_size(ui->weather_label_city, 229, 39);

	//Write style for weather_label_city, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_label_city, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_label_city, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->weather_label_city, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->weather_label_city, &lv_font_montserratMedium_40, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->weather_label_city, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->weather_label_city, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->weather_label_city, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_label_city, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_label_city, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_label_city, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_label_city, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_label_city, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_label_city, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_label_temp
	ui->weather_label_temp = lv_label_create(ui->weather);
	lv_label_set_text(ui->weather_label_temp, "23°");
	lv_label_set_long_mode(ui->weather_label_temp, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->weather_label_temp, 86, 69);
	lv_obj_set_size(ui->weather_label_temp, 250, 150);

	//Write style for weather_label_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->weather_label_temp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->weather_label_temp, &lv_font_montserratMedium_150, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->weather_label_temp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->weather_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->weather_label_temp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_img_icon
	ui->weather_img_icon = lv_img_create(ui->weather);
	lv_obj_add_flag(ui->weather_img_icon, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->weather_img_icon, &_icn_big_weather_cloud_alpha_66x50);
	lv_img_set_pivot(ui->weather_img_icon, 50,50);
	lv_img_set_angle(ui->weather_img_icon, 0);
	lv_obj_set_pos(ui->weather_img_icon, 163, 400);
	lv_obj_set_size(ui->weather_img_icon, 66, 50);

	//Write style for weather_img_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->weather_img_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_label_maxMin
	ui->weather_label_maxMin = lv_label_create(ui->weather);
	lv_label_set_text(ui->weather_label_maxMin, "Monstly sunny\n Max:28° Min:21°");
	lv_label_set_long_mode(ui->weather_label_maxMin, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->weather_label_maxMin, 72, 400);
	lv_obj_set_size(ui->weather_label_maxMin, 249, 47);

	//Write style for weather_label_maxMin, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->weather_label_maxMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->weather_label_maxMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->weather_label_maxMin, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->weather_label_maxMin, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->weather_label_maxMin, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->weather_label_maxMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->weather_label_maxMin, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->weather_label_maxMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->weather_label_maxMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->weather_label_maxMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->weather_label_maxMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->weather_label_maxMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->weather_label_maxMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_img_dot
	ui->weather_img_dot = lv_img_create(ui->weather);
	lv_obj_add_flag(ui->weather_img_dot, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->weather_img_dot, &_dot_alpha_8x8);
	lv_img_set_pivot(ui->weather_img_dot, 50,50);
	lv_img_set_angle(ui->weather_img_dot, 0);
	lv_obj_set_pos(ui->weather_img_dot, 366, 153);
	lv_obj_set_size(ui->weather_img_dot, 8, 8);

	//Write style for weather_img_dot, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->weather_img_dot, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes weather_img_home
	ui->weather_img_home = lv_img_create(ui->weather);
	lv_obj_add_flag(ui->weather_img_home, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->weather_img_home, &_text_home_alpha_36x48);
	lv_img_set_pivot(ui->weather_img_home, 50,50);
	lv_img_set_angle(ui->weather_img_home, 10);
	lv_obj_set_pos(ui->weather_img_home, 322, 270);
	lv_obj_set_size(ui->weather_img_home, 36, 48);

	//Write style for weather_img_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->weather_img_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->weather);

	
	//Init events for screen.
	events_init_weather(ui);
}
