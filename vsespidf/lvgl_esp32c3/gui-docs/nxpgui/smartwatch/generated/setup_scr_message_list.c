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


void setup_scr_message_list(lv_ui *ui)
{
	//Write codes message_list
	ui->message_list = lv_obj_create(NULL);
	lv_obj_set_size(ui->message_list, 240, 240);

	//Write style for message_list, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->message_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->message_list, &_img_bg_2_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->message_list, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_list_cont_messagesList
	ui->message_list_cont_messagesList = lv_obj_create(ui->message_list);
	lv_obj_set_pos(ui->message_list_cont_messagesList, 46, 7);
	lv_obj_set_size(ui->message_list_cont_messagesList, 300, 461);
	lv_obj_set_scrollbar_mode(ui->message_list_cont_messagesList, LV_SCROLLBAR_MODE_AUTO);

	//Write style for message_list_cont_messagesList, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->message_list_cont_messagesList, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->message_list_cont_messagesList, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->message_list_cont_messagesList, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->message_list_cont_messagesList, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->message_list_cont_messagesList, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->message_list_cont_messagesList, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->message_list_cont_messagesList, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->message_list_cont_messagesList, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_list_label_12
	ui->message_list_label_12 = lv_label_create(ui->message_list_cont_messagesList);
	lv_label_set_text(ui->message_list_label_12, "09:25");
	lv_label_set_long_mode(ui->message_list_label_12, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->message_list_label_12, 95, 275);
	lv_obj_set_size(ui->message_list_label_12, 100, 19);

	//Write style for message_list_label_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->message_list_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->message_list_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->message_list_label_12, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->message_list_label_12, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->message_list_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->message_list_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->message_list_label_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->message_list_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->message_list_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->message_list_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->message_list_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->message_list_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->message_list_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_list_label_11
	ui->message_list_label_11 = lv_label_create(ui->message_list_cont_messagesList);
	lv_label_set_text(ui->message_list_label_11, "Liked your photo");
	lv_label_set_long_mode(ui->message_list_label_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->message_list_label_11, 59, 249);
	lv_obj_set_size(ui->message_list_label_11, 185, 20);

	//Write style for message_list_label_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->message_list_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->message_list_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->message_list_label_11, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->message_list_label_11, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->message_list_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->message_list_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->message_list_label_11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->message_list_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->message_list_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->message_list_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->message_list_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->message_list_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->message_list_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_list_label_10
	ui->message_list_label_10 = lv_label_create(ui->message_list_cont_messagesList);
	lv_label_set_text(ui->message_list_label_10, "Sabrina");
	lv_label_set_long_mode(ui->message_list_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->message_list_label_10, 81, 218);
	lv_obj_set_size(ui->message_list_label_10, 129, 32);

	//Write style for message_list_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->message_list_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->message_list_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->message_list_label_10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->message_list_label_10, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->message_list_label_10, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->message_list_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->message_list_label_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->message_list_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->message_list_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->message_list_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->message_list_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->message_list_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->message_list_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_list_img_7
	ui->message_list_img_7 = lv_img_create(ui->message_list_cont_messagesList);
	lv_obj_add_flag(ui->message_list_img_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->message_list_img_7, &_icn_insta_alpha_36x36);
	lv_img_set_pivot(ui->message_list_img_7, 50,50);
	lv_img_set_angle(ui->message_list_img_7, 0);
	lv_obj_set_pos(ui->message_list_img_7, 131, 172);
	lv_obj_set_size(ui->message_list_img_7, 36, 36);

	//Write style for message_list_img_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->message_list_img_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_list_label_9
	ui->message_list_label_9 = lv_label_create(ui->message_list_cont_messagesList);
	lv_label_set_text(ui->message_list_label_9, "1 min ago");
	lv_label_set_long_mode(ui->message_list_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->message_list_label_9, 101, 123);
	lv_obj_set_size(ui->message_list_label_9, 100, 26);

	//Write style for message_list_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->message_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->message_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->message_list_label_9, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->message_list_label_9, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->message_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->message_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->message_list_label_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->message_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->message_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->message_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->message_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->message_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->message_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_list_label_15
	ui->message_list_label_15 = lv_label_create(ui->message_list_cont_messagesList);
	lv_label_set_text(ui->message_list_label_15, "5 min ago");
	lv_label_set_long_mode(ui->message_list_label_15, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->message_list_label_15, 94, 430);
	lv_obj_set_size(ui->message_list_label_15, 100, 26);

	//Write style for message_list_label_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->message_list_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->message_list_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->message_list_label_15, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->message_list_label_15, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->message_list_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->message_list_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->message_list_label_15, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->message_list_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->message_list_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->message_list_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->message_list_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->message_list_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->message_list_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_list_label_8
	ui->message_list_label_8 = lv_label_create(ui->message_list_cont_messagesList);
	lv_label_set_text(ui->message_list_label_8, "How are you? I will meet with...");
	lv_label_set_long_mode(ui->message_list_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->message_list_label_8, 34, 96);
	lv_obj_set_size(ui->message_list_label_8, 248, 20);

	//Write style for message_list_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->message_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->message_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->message_list_label_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->message_list_label_8, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->message_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->message_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->message_list_label_8, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->message_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->message_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->message_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->message_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->message_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->message_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_list_label_7
	ui->message_list_label_7 = lv_label_create(ui->message_list_cont_messagesList);
	lv_label_set_text(ui->message_list_label_7, "Elena");
	lv_label_set_long_mode(ui->message_list_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->message_list_label_7, 109, 59);
	lv_obj_set_size(ui->message_list_label_7, 90, 32);

	//Write style for message_list_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->message_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->message_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->message_list_label_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->message_list_label_7, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->message_list_label_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->message_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->message_list_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->message_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->message_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->message_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->message_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->message_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->message_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_list_app_icon
	ui->message_list_app_icon = lv_img_create(ui->message_list_cont_messagesList);
	lv_obj_add_flag(ui->message_list_app_icon, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->message_list_app_icon, &_icn_whatsapp_alpha_39x39);
	lv_img_set_pivot(ui->message_list_app_icon, 50,50);
	lv_img_set_angle(ui->message_list_app_icon, 0);
	lv_obj_set_pos(ui->message_list_app_icon, 139, -56);
	lv_obj_set_size(ui->message_list_app_icon, 39, 39);

	//Write style for message_list_app_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->message_list_app_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_list_img_8
	ui->message_list_img_8 = lv_img_create(ui->message_list_cont_messagesList);
	lv_obj_add_flag(ui->message_list_img_8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->message_list_img_8, &_img_line_2_alpha_250x2);
	lv_img_set_pivot(ui->message_list_img_8, 50,50);
	lv_img_set_angle(ui->message_list_img_8, 0);
	lv_obj_set_pos(ui->message_list_img_8, 16, 156);
	lv_obj_set_size(ui->message_list_img_8, 250, 2);

	//Write style for message_list_img_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->message_list_img_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_list_img_9
	ui->message_list_img_9 = lv_img_create(ui->message_list_cont_messagesList);
	lv_obj_add_flag(ui->message_list_img_9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->message_list_img_9, &_img_line_1_alpha_232x2);
	lv_img_set_pivot(ui->message_list_img_9, 50,50);
	lv_img_set_angle(ui->message_list_img_9, 0);
	lv_obj_set_pos(ui->message_list_img_9, 40, 311);
	lv_obj_set_size(ui->message_list_img_9, 232, 2);

	//Write style for message_list_img_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->message_list_img_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_list_img_10
	ui->message_list_img_10 = lv_img_create(ui->message_list_cont_messagesList);
	lv_obj_add_flag(ui->message_list_img_10, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->message_list_img_10, &_icn_insta_alpha_36x36);
	lv_img_set_pivot(ui->message_list_img_10, 50,50);
	lv_img_set_angle(ui->message_list_img_10, 0);
	lv_obj_set_pos(ui->message_list_img_10, 131, 334);
	lv_obj_set_size(ui->message_list_img_10, 36, 36);

	//Write style for message_list_img_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->message_list_img_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_list_label_13
	ui->message_list_label_13 = lv_label_create(ui->message_list_cont_messagesList);
	lv_label_set_text(ui->message_list_label_13, "Monk");
	lv_label_set_long_mode(ui->message_list_label_13, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->message_list_label_13, 103, 376);
	lv_obj_set_size(ui->message_list_label_13, 90, 32);

	//Write style for message_list_label_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->message_list_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->message_list_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->message_list_label_13, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->message_list_label_13, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->message_list_label_13, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->message_list_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->message_list_label_13, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->message_list_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->message_list_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->message_list_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->message_list_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->message_list_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->message_list_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_list_label_14
	ui->message_list_label_14 = lv_label_create(ui->message_list_cont_messagesList);
	lv_label_set_text(ui->message_list_label_14, "Do you like to play basketball? ");
	lv_label_set_long_mode(ui->message_list_label_14, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->message_list_label_14, 33, 406);
	lv_obj_set_size(ui->message_list_label_14, 248, 20);

	//Write style for message_list_label_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->message_list_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->message_list_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->message_list_label_14, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->message_list_label_14, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->message_list_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->message_list_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->message_list_label_14, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->message_list_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->message_list_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->message_list_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->message_list_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->message_list_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->message_list_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_list_img_home
	ui->message_list_img_home = lv_img_create(ui->message_list);
	lv_obj_add_flag(ui->message_list_img_home, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->message_list_img_home, &_text_home_alpha_36x48);
	lv_img_set_pivot(ui->message_list_img_home, 50,50);
	lv_img_set_angle(ui->message_list_img_home, 0);
	lv_obj_set_pos(ui->message_list_img_home, 319, 259);
	lv_obj_set_size(ui->message_list_img_home, 36, 48);
	lv_obj_add_flag(ui->message_list_img_home, LV_OBJ_FLAG_FLOATING);

	//Write style for message_list_img_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->message_list_img_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_list_left
	ui->message_list_left = lv_img_create(ui->message_list);
	lv_obj_add_flag(ui->message_list_left, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->message_list_left, &_img_arrow_left_alpha_9x32);
	lv_img_set_pivot(ui->message_list_left, 50,50);
	lv_img_set_angle(ui->message_list_left, 0);
	lv_obj_set_pos(ui->message_list_left, 10, 165);
	lv_obj_set_size(ui->message_list_left, 9, 32);
	lv_obj_add_flag(ui->message_list_left, LV_OBJ_FLAG_FLOATING);

	//Write style for message_list_left, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->message_list_left, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes message_list_right
	ui->message_list_right = lv_img_create(ui->message_list);
	lv_obj_add_flag(ui->message_list_right, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->message_list_right, &_img_arrow_right_alpha_9x32);
	lv_img_set_pivot(ui->message_list_right, 50,50);
	lv_img_set_angle(ui->message_list_right, 0);
	lv_obj_set_pos(ui->message_list_right, 368, 165);
	lv_obj_set_size(ui->message_list_right, 9, 32);
	lv_obj_add_flag(ui->message_list_right, LV_OBJ_FLAG_FLOATING);

	//Write style for message_list_right, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->message_list_right, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->message_list);

	
	//Init events for screen.
	events_init_message_list(ui);
}
