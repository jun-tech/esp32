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


void setup_scr_message_info(lv_ui *ui)
{
	//Write codes message_info
	ui->message_info = lv_obj_create(NULL);
	lv_obj_set_size(ui->message_info, 240, 240);

	//Write style for message_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->message_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->message_info, &_img_bg_2_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->message_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_info_app_icon
	ui->message_info_app_icon = lv_img_create(ui->message_info);
	lv_obj_add_flag(ui->message_info_app_icon, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->message_info_app_icon, &_icn_whatsapp_alpha_60x60);
	lv_img_set_pivot(ui->message_info_app_icon, 50,50);
	lv_img_set_angle(ui->message_info_app_icon, 0);
	lv_obj_set_pos(ui->message_info_app_icon, 166, -72);
	lv_obj_set_size(ui->message_info_app_icon, 60, 60);

	//Write style for message_info_app_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->message_info_app_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_info_sender
	ui->message_info_sender = lv_label_create(ui->message_info);
	lv_label_set_text(ui->message_info_sender, "Elena");
	lv_label_set_long_mode(ui->message_info_sender, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->message_info_sender, 151, 7);
	lv_obj_set_size(ui->message_info_sender, 90, 32);

	//Write style for message_info_sender, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->message_info_sender, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->message_info_sender, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->message_info_sender, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->message_info_sender, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->message_info_sender, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->message_info_sender, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->message_info_sender, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->message_info_sender, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->message_info_sender, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->message_info_sender, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->message_info_sender, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->message_info_sender, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->message_info_sender, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_info_message_text
	ui->message_info_message_text = lv_label_create(ui->message_info);
	lv_label_set_text(ui->message_info_message_text, "How are you? I will meet with Brendon. And you? ");
	lv_label_set_long_mode(ui->message_info_message_text, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->message_info_message_text, 45, 159);
	lv_obj_set_size(ui->message_info_message_text, 303, 45);

	//Write style for message_info_message_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->message_info_message_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->message_info_message_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->message_info_message_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->message_info_message_text, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->message_info_message_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->message_info_message_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->message_info_message_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->message_info_message_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->message_info_message_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->message_info_message_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->message_info_message_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->message_info_message_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->message_info_message_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_info_left
	ui->message_info_left = lv_img_create(ui->message_info);
	lv_obj_add_flag(ui->message_info_left, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->message_info_left, &_img_arrow_left_alpha_9x32);
	lv_img_set_pivot(ui->message_info_left, 50,50);
	lv_img_set_angle(ui->message_info_left, 0);
	lv_obj_set_pos(ui->message_info_left, 10, 165);
	lv_obj_set_size(ui->message_info_left, 9, 32);

	//Write style for message_info_left, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->message_info_left, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_info_right
	ui->message_info_right = lv_img_create(ui->message_info);
	lv_obj_add_flag(ui->message_info_right, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->message_info_right, &_img_arrow_right_alpha_9x32);
	lv_img_set_pivot(ui->message_info_right, 50,50);
	lv_img_set_angle(ui->message_info_right, 0);
	lv_obj_set_pos(ui->message_info_right, 368, 165);
	lv_obj_set_size(ui->message_info_right, 9, 32);

	//Write style for message_info_right, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->message_info_right, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_info_time_text
	ui->message_info_time_text = lv_label_create(ui->message_info);
	lv_label_set_text(ui->message_info_time_text, "1 min ago");
	lv_label_set_long_mode(ui->message_info_time_text, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->message_info_time_text, 146, 242);
	lv_obj_set_size(ui->message_info_time_text, 100, 26);

	//Write style for message_info_time_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->message_info_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->message_info_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->message_info_time_text, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->message_info_time_text, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->message_info_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->message_info_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->message_info_time_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->message_info_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->message_info_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->message_info_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->message_info_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->message_info_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->message_info_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_info_ok_btn
	ui->message_info_ok_btn = lv_label_create(ui->message_info);
	lv_label_set_text(ui->message_info_ok_btn, "OK");
	lv_label_set_long_mode(ui->message_info_ok_btn, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->message_info_ok_btn, 110, 300);
	lv_obj_set_size(ui->message_info_ok_btn, 172, 49);
	lv_obj_add_flag(ui->message_info_ok_btn, LV_OBJ_FLAG_CLICKABLE);

	//Write style for message_info_ok_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->message_info_ok_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->message_info_ok_btn, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->message_info_ok_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->message_info_ok_btn, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->message_info_ok_btn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->message_info_ok_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->message_info_ok_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->message_info_ok_btn, 105, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->message_info_ok_btn, lv_color_hex(0x414041), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->message_info_ok_btn, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->message_info_ok_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->message_info_ok_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->message_info_ok_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->message_info_ok_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_info_home_text
	ui->message_info_home_text = lv_img_create(ui->message_info);
	lv_obj_add_flag(ui->message_info_home_text, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->message_info_home_text, &_text_home_alpha_36x48);
	lv_img_set_pivot(ui->message_info_home_text, 50,50);
	lv_img_set_angle(ui->message_info_home_text, 0);
	lv_obj_set_pos(ui->message_info_home_text, 319, 259);
	lv_obj_set_size(ui->message_info_home_text, 36, 48);

	//Write style for message_info_home_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->message_info_home_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->message_info);

	
	//Init events for screen.
	events_init_message_info(ui);
}
