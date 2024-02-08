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


void setup_scr_navigation(lv_ui *ui)
{
	//Write codes navigation
	ui->navigation = lv_obj_create(NULL);
	lv_obj_set_size(ui->navigation, 240, 240);

	//Write style for navigation, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->navigation, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->navigation, &_img_bg_2_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->navigation, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes navigation_home
	ui->navigation_home = lv_img_create(ui->navigation);
	lv_obj_add_flag(ui->navigation_home, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->navigation_home, &_text_home_alpha_36x48);
	lv_img_set_pivot(ui->navigation_home, 50,50);
	lv_img_set_angle(ui->navigation_home, 0);
	lv_obj_set_pos(ui->navigation_home, 326, 259);
	lv_obj_set_size(ui->navigation_home, 36, 48);
	lv_obj_add_flag(ui->navigation_home, LV_OBJ_FLAG_FLOATING);

	//Write style for navigation_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->navigation_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes navigation_title
	ui->navigation_title = lv_label_create(ui->navigation);
	lv_label_set_text(ui->navigation_title, "Navigation\n");
	lv_label_set_long_mode(ui->navigation_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->navigation_title, -3, -84);
	lv_obj_set_size(ui->navigation_title, 392, 75);
	lv_obj_add_flag(ui->navigation_title, LV_OBJ_FLAG_FLOATING);

	//Write style for navigation_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->navigation_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->navigation_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->navigation_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->navigation_title, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->navigation_title, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->navigation_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->navigation_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->navigation_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->navigation_title, 27, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->navigation_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->navigation_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->navigation_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->navigation_title, &_img_header_bg_392x75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->navigation_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor(ui->navigation_title, lv_color_hex(0x3155EE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor_opa(ui->navigation_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->navigation_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes navigation_next_roadName
	ui->navigation_next_roadName = lv_label_create(ui->navigation);
	lv_label_set_text(ui->navigation_next_roadName, "Next: West Higgins Rd.");
	lv_label_set_long_mode(ui->navigation_next_roadName, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->navigation_next_roadName, 97, 41);
	lv_obj_set_size(ui->navigation_next_roadName, 198, 17);

	//Write style for navigation_next_roadName, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->navigation_next_roadName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->navigation_next_roadName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->navigation_next_roadName, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->navigation_next_roadName, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->navigation_next_roadName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->navigation_next_roadName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->navigation_next_roadName, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->navigation_next_roadName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->navigation_next_roadName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->navigation_next_roadName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->navigation_next_roadName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->navigation_next_roadName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->navigation_next_roadName, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes navigation_road_name
	ui->navigation_road_name = lv_label_create(ui->navigation);
	lv_label_set_text(ui->navigation_road_name, "Ed Bluestein Blvd");
	lv_label_set_long_mode(ui->navigation_road_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->navigation_road_name, 75, 10);
	lv_obj_set_size(ui->navigation_road_name, 226, 31);

	//Write style for navigation_road_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->navigation_road_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->navigation_road_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->navigation_road_name, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->navigation_road_name, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->navigation_road_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->navigation_road_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->navigation_road_name, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->navigation_road_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->navigation_road_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->navigation_road_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->navigation_road_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->navigation_road_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->navigation_road_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes navigation_distance
	ui->navigation_distance = lv_label_create(ui->navigation);
	lv_label_set_text(ui->navigation_distance, "1.8");
	lv_label_set_long_mode(ui->navigation_distance, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->navigation_distance, 31, 187);
	lv_obj_set_size(ui->navigation_distance, 38, 31);

	//Write style for navigation_distance, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->navigation_distance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->navigation_distance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->navigation_distance, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->navigation_distance, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->navigation_distance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->navigation_distance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->navigation_distance, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->navigation_distance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->navigation_distance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->navigation_distance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->navigation_distance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->navigation_distance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->navigation_distance, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes navigation_distance_text
	ui->navigation_distance_text = lv_label_create(ui->navigation);
	lv_label_set_text(ui->navigation_distance_text, "DISTANCE");
	lv_label_set_long_mode(ui->navigation_distance_text, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->navigation_distance_text, 25, 164);
	lv_obj_set_size(ui->navigation_distance_text, 85, 21);

	//Write style for navigation_distance_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->navigation_distance_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->navigation_distance_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->navigation_distance_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->navigation_distance_text, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->navigation_distance_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->navigation_distance_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->navigation_distance_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->navigation_distance_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->navigation_distance_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->navigation_distance_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->navigation_distance_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->navigation_distance_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->navigation_distance_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes navigation_take_time_text
	ui->navigation_take_time_text = lv_label_create(ui->navigation);
	lv_label_set_text(ui->navigation_take_time_text, "TAKE TIME");
	lv_label_set_long_mode(ui->navigation_take_time_text, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->navigation_take_time_text, 269, 164);
	lv_obj_set_size(ui->navigation_take_time_text, 94, 17);

	//Write style for navigation_take_time_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->navigation_take_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->navigation_take_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->navigation_take_time_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->navigation_take_time_text, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->navigation_take_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->navigation_take_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->navigation_take_time_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->navigation_take_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->navigation_take_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->navigation_take_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->navigation_take_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->navigation_take_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->navigation_take_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes navigation_nav_icon
	ui->navigation_nav_icon = lv_img_create(ui->navigation);
	lv_obj_add_flag(ui->navigation_nav_icon, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->navigation_nav_icon, &_img_nav_1_alpha_107x122);
	lv_img_set_pivot(ui->navigation_nav_icon, 50,50);
	lv_img_set_angle(ui->navigation_nav_icon, 0);
	lv_obj_set_pos(ui->navigation_nav_icon, 139, 154);
	lv_obj_set_size(ui->navigation_nav_icon, 107, 122);

	//Write style for navigation_nav_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->navigation_nav_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes navigation_km_text
	ui->navigation_km_text = lv_label_create(ui->navigation);
	lv_label_set_text(ui->navigation_km_text, "km");
	lv_label_set_long_mode(ui->navigation_km_text, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->navigation_km_text, 69, 195);
	lv_obj_set_size(ui->navigation_km_text, 32, 15);

	//Write style for navigation_km_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->navigation_km_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->navigation_km_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->navigation_km_text, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->navigation_km_text, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->navigation_km_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->navigation_km_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->navigation_km_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->navigation_km_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->navigation_km_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->navigation_km_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->navigation_km_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->navigation_km_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->navigation_km_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes navigation_take_time
	ui->navigation_take_time = lv_label_create(ui->navigation);
	lv_label_set_text(ui->navigation_take_time, "45");
	lv_label_set_long_mode(ui->navigation_take_time, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->navigation_take_time, 269, 187);
	lv_obj_set_size(ui->navigation_take_time, 38, 31);

	//Write style for navigation_take_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->navigation_take_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->navigation_take_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->navigation_take_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->navigation_take_time, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->navigation_take_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->navigation_take_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->navigation_take_time, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->navigation_take_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->navigation_take_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->navigation_take_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->navigation_take_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->navigation_take_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->navigation_take_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes navigation_mins_text
	ui->navigation_mins_text = lv_label_create(ui->navigation);
	lv_label_set_text(ui->navigation_mins_text, "mins");
	lv_label_set_long_mode(ui->navigation_mins_text, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->navigation_mins_text, 307, 194);
	lv_obj_set_size(ui->navigation_mins_text, 48, 21);

	//Write style for navigation_mins_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->navigation_mins_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->navigation_mins_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->navigation_mins_text, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->navigation_mins_text, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->navigation_mins_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->navigation_mins_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->navigation_mins_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->navigation_mins_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->navigation_mins_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->navigation_mins_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->navigation_mins_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->navigation_mins_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->navigation_mins_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes navigation_indicator
	ui->navigation_indicator = lv_obj_create(ui->navigation);
	lv_obj_set_pos(ui->navigation_indicator, 92, 408);
	lv_obj_set_size(ui->navigation_indicator, 209, 88);
	lv_obj_set_scrollbar_mode(ui->navigation_indicator, LV_SCROLLBAR_MODE_OFF);

	//Write style for navigation_indicator, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->navigation_indicator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->navigation_indicator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->navigation_indicator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->navigation_indicator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->navigation_indicator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->navigation_indicator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->navigation_indicator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->navigation_indicator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes navigation_label_4
	ui->navigation_label_4 = lv_label_create(ui->navigation_indicator);
	lv_label_set_text(ui->navigation_label_4, "200m");
	lv_label_set_long_mode(ui->navigation_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->navigation_label_4, 55, 8);
	lv_obj_set_size(ui->navigation_label_4, 100, 31);

	//Write style for navigation_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->navigation_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->navigation_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->navigation_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->navigation_label_4, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->navigation_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->navigation_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->navigation_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->navigation_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->navigation_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->navigation_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->navigation_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->navigation_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->navigation_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes navigation_label_5
	ui->navigation_label_5 = lv_label_create(ui->navigation_indicator);
	lv_label_set_text(ui->navigation_label_5, "Turn Right");
	lv_label_set_long_mode(ui->navigation_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->navigation_label_5, 40, 44);
	lv_obj_set_size(ui->navigation_label_5, 133, 24);

	//Write style for navigation_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->navigation_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->navigation_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->navigation_label_5, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->navigation_label_5, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->navigation_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->navigation_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->navigation_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->navigation_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->navigation_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->navigation_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->navigation_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->navigation_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->navigation_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes navigation_img_dot
	ui->navigation_img_dot = lv_img_create(ui->navigation);
	lv_obj_add_flag(ui->navigation_img_dot, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->navigation_img_dot, &_dot_alpha_8x8);
	lv_img_set_pivot(ui->navigation_img_dot, 50,50);
	lv_img_set_angle(ui->navigation_img_dot, 0);
	lv_obj_set_pos(ui->navigation_img_dot, 370, 202);
	lv_obj_set_size(ui->navigation_img_dot, 8, 8);

	//Write style for navigation_img_dot, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->navigation_img_dot, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes navigation_img_menu
	ui->navigation_img_menu = lv_img_create(ui->navigation);
	lv_obj_add_flag(ui->navigation_img_menu, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->navigation_img_menu, &_img_menu_alpha_11x100);
	lv_img_set_pivot(ui->navigation_img_menu, 50,50);
	lv_img_set_angle(ui->navigation_img_menu, 0);
	lv_obj_set_pos(ui->navigation_img_menu, 365, 146);
	lv_obj_set_size(ui->navigation_img_menu, 11, 100);

	//Write style for navigation_img_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->navigation_img_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->navigation);

	
	//Init events for screen.
	events_init_navigation(ui);
}
