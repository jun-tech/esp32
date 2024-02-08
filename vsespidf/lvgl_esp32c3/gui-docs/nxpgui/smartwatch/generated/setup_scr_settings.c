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


void setup_scr_settings(lv_ui *ui)
{
	//Write codes settings
	ui->settings = lv_obj_create(NULL);
	lv_obj_set_size(ui->settings, 240, 240);

	//Write style for settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->settings, &_img_bg_2_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->settings, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_title
	ui->settings_title = lv_label_create(ui->settings);
	lv_label_set_text(ui->settings_title, "Settings\n");
	lv_label_set_long_mode(ui->settings_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->settings_title, 0, -83);
	lv_obj_set_size(ui->settings_title, 392, 75);
	lv_obj_add_flag(ui->settings_title, LV_OBJ_FLAG_FLOATING);

	//Write style for settings_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->settings_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->settings_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->settings_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->settings_title, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->settings_title, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->settings_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->settings_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->settings_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->settings_title, 27, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->settings_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->settings_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->settings_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->settings_title, &_img_header_bg_392x75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->settings_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor(ui->settings_title, lv_color_hex(0xD5D2D5), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor_opa(ui->settings_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->settings_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_setting_info
	ui->settings_setting_info = lv_obj_create(ui->settings);
	lv_obj_set_pos(ui->settings_setting_info, 64, 225);
	lv_obj_set_size(ui->settings_setting_info, 265, 294);
	lv_obj_set_scrollbar_mode(ui->settings_setting_info, LV_SCROLLBAR_MODE_OFF);

	//Write style for settings_setting_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->settings_setting_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->settings_setting_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->settings_setting_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->settings_setting_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->settings_setting_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->settings_setting_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->settings_setting_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->settings_setting_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_1
	ui->settings_label_1 = lv_label_create(ui->settings_setting_info);
	lv_label_set_text(ui->settings_label_1, "Wifi");
	lv_label_set_long_mode(ui->settings_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->settings_label_1, 35, 15);
	lv_obj_set_size(ui->settings_label_1, 190, 37);

	//Write style for settings_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->settings_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->settings_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->settings_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->settings_label_1, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->settings_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->settings_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->settings_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->settings_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->settings_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->settings_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->settings_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->settings_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->settings_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_2
	ui->settings_label_2 = lv_label_create(ui->settings_setting_info);
	lv_label_set_text(ui->settings_label_2, "Bluetooth");
	lv_label_set_long_mode(ui->settings_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->settings_label_2, 35, 70);
	lv_obj_set_size(ui->settings_label_2, 190, 37);

	//Write style for settings_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->settings_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->settings_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->settings_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->settings_label_2, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->settings_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->settings_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->settings_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->settings_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->settings_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->settings_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->settings_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->settings_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->settings_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_3
	ui->settings_label_3 = lv_label_create(ui->settings_setting_info);
	lv_label_set_text(ui->settings_label_3, "NFC");
	lv_label_set_long_mode(ui->settings_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->settings_label_3, 35, 125);
	lv_obj_set_size(ui->settings_label_3, 190, 37);

	//Write style for settings_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->settings_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->settings_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->settings_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->settings_label_3, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->settings_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->settings_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->settings_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->settings_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->settings_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->settings_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->settings_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->settings_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->settings_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_4
	ui->settings_label_4 = lv_label_create(ui->settings_setting_info);
	lv_label_set_text(ui->settings_label_4, "Find you phone");
	lv_label_set_long_mode(ui->settings_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->settings_label_4, 8, 181);
	lv_obj_set_size(ui->settings_label_4, 247, 43);

	//Write style for settings_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->settings_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->settings_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->settings_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->settings_label_4, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->settings_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->settings_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->settings_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->settings_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->settings_label_4, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->settings_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->settings_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->settings_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->settings_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_label_5
	ui->settings_label_5 = lv_label_create(ui->settings_setting_info);
	lv_label_set_text(ui->settings_label_5, "More settings");
	lv_label_set_long_mode(ui->settings_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->settings_label_5, 10, 247);
	lv_obj_set_size(ui->settings_label_5, 247, 37);

	//Write style for settings_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->settings_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->settings_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->settings_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->settings_label_5, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->settings_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->settings_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->settings_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->settings_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->settings_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->settings_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->settings_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->settings_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->settings_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_img_dot
	ui->settings_img_dot = lv_img_create(ui->settings);
	lv_obj_add_flag(ui->settings_img_dot, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_dot, &_dot_alpha_8x8);
	lv_img_set_pivot(ui->settings_img_dot, 50,50);
	lv_img_set_angle(ui->settings_img_dot, 0);
	lv_obj_set_pos(ui->settings_img_dot, 367, 226);
	lv_obj_set_size(ui->settings_img_dot, 8, 8);

	//Write style for settings_img_dot, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->settings_img_dot, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_img_menu
	ui->settings_img_menu = lv_img_create(ui->settings);
	lv_obj_add_flag(ui->settings_img_menu, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_menu, &_img_menu_alpha_11x100);
	lv_img_set_pivot(ui->settings_img_menu, 50,50);
	lv_img_set_angle(ui->settings_img_menu, 0);
	lv_obj_set_pos(ui->settings_img_menu, 365, 146);
	lv_obj_set_size(ui->settings_img_menu, 11, 100);

	//Write style for settings_img_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->settings_img_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_img_select
	ui->settings_img_select = lv_img_create(ui->settings);
	lv_obj_add_flag(ui->settings_img_select, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_img_select, &_text_select_alpha_43x57);
	lv_img_set_pivot(ui->settings_img_select, 50,50);
	lv_img_set_angle(ui->settings_img_select, 80);
	lv_obj_set_pos(ui->settings_img_select, 323, 69);
	lv_obj_set_size(ui->settings_img_select, 43, 57);

	//Write style for settings_img_select, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->settings_img_select, 163, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes settings_home
	ui->settings_home = lv_img_create(ui->settings);
	lv_obj_add_flag(ui->settings_home, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->settings_home, &_text_home_alpha_36x48);
	lv_img_set_pivot(ui->settings_home, 50,50);
	lv_img_set_angle(ui->settings_home, 0);
	lv_obj_set_pos(ui->settings_home, 330, 260);
	lv_obj_set_size(ui->settings_home, 36, 48);

	//Write style for settings_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->settings_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->settings);

	
	//Init events for screen.
	events_init_settings(ui);
}
