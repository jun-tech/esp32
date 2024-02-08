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


void setup_scr_contact_list(lv_ui *ui)
{
	//Write codes contact_list
	ui->contact_list = lv_obj_create(NULL);
	lv_obj_set_size(ui->contact_list, 240, 240);
	lv_obj_add_flag(ui->contact_list, LV_OBJ_FLAG_FLOATING);

	//Write style for contact_list, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->contact_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->contact_list, &_img_bg_2_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->contact_list, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes contact_list_cont_list
	ui->contact_list_cont_list = lv_obj_create(ui->contact_list);
	lv_obj_set_pos(ui->contact_list_cont_list, 46, 75);
	lv_obj_set_size(ui->contact_list_cont_list, 300, 385);
	lv_obj_set_scrollbar_mode(ui->contact_list_cont_list, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->contact_list_cont_list, LV_OBJ_FLAG_SCROLLABLE);

	//Write style for contact_list_cont_list, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->contact_list_cont_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->contact_list_cont_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->contact_list_cont_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->contact_list_cont_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->contact_list_cont_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->contact_list_cont_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->contact_list_cont_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->contact_list_cont_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes contact_list_cont_2
	ui->contact_list_cont_2 = lv_obj_create(ui->contact_list_cont_list);
	lv_obj_set_pos(ui->contact_list_cont_2, 0, 0);
	lv_obj_set_size(ui->contact_list_cont_2, 300, 75);
	lv_obj_set_scrollbar_mode(ui->contact_list_cont_2, LV_SCROLLBAR_MODE_OFF);

	//Write style for contact_list_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->contact_list_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->contact_list_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->contact_list_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->contact_list_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->contact_list_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->contact_list_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->contact_list_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->contact_list_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes contact_list_img_3
	ui->contact_list_img_3 = lv_img_create(ui->contact_list_cont_2);
	lv_obj_add_flag(ui->contact_list_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->contact_list_img_3, &_img_avatar_1_alpha_61x61);
	lv_img_set_pivot(ui->contact_list_img_3, 50,50);
	lv_img_set_angle(ui->contact_list_img_3, 0);
	lv_obj_set_pos(ui->contact_list_img_3, 21, 3);
	lv_obj_set_size(ui->contact_list_img_3, 61, 61);

	//Write style for contact_list_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->contact_list_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes contact_list_label_2
	ui->contact_list_label_2 = lv_label_create(ui->contact_list_cont_2);
	lv_label_set_text(ui->contact_list_label_2, "Erica Smith");
	lv_label_set_long_mode(ui->contact_list_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->contact_list_label_2, 91, 12);
	lv_obj_set_size(ui->contact_list_label_2, 182, 32);

	//Write style for contact_list_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->contact_list_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->contact_list_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->contact_list_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->contact_list_label_2, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->contact_list_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->contact_list_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->contact_list_label_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->contact_list_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->contact_list_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->contact_list_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->contact_list_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->contact_list_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->contact_list_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes contact_list_label_3
	ui->contact_list_label_3 = lv_label_create(ui->contact_list_cont_2);
	lv_label_set_text(ui->contact_list_label_3, "00 555 4588 5652");
	lv_label_set_long_mode(ui->contact_list_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->contact_list_label_3, 91, 45);
	lv_obj_set_size(ui->contact_list_label_3, 180, 21);

	//Write style for contact_list_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->contact_list_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->contact_list_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->contact_list_label_3, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->contact_list_label_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->contact_list_label_3, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->contact_list_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->contact_list_label_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->contact_list_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->contact_list_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->contact_list_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->contact_list_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->contact_list_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->contact_list_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes contact_list_cont_3
	ui->contact_list_cont_3 = lv_obj_create(ui->contact_list_cont_list);
	lv_obj_set_pos(ui->contact_list_cont_3, 0, 91);
	lv_obj_set_size(ui->contact_list_cont_3, 300, 75);
	lv_obj_set_scrollbar_mode(ui->contact_list_cont_3, LV_SCROLLBAR_MODE_OFF);

	//Write style for contact_list_cont_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->contact_list_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->contact_list_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->contact_list_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->contact_list_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->contact_list_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->contact_list_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->contact_list_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->contact_list_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes contact_list_img_4
	ui->contact_list_img_4 = lv_img_create(ui->contact_list_cont_3);
	lv_obj_add_flag(ui->contact_list_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->contact_list_img_4, &_img_avatar_2_alpha_61x61);
	lv_img_set_pivot(ui->contact_list_img_4, 50,50);
	lv_img_set_angle(ui->contact_list_img_4, 0);
	lv_obj_set_pos(ui->contact_list_img_4, 21, 3);
	lv_obj_set_size(ui->contact_list_img_4, 61, 61);

	//Write style for contact_list_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->contact_list_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes contact_list_label_5
	ui->contact_list_label_5 = lv_label_create(ui->contact_list_cont_3);
	lv_label_set_text(ui->contact_list_label_5, "Sabrina Bird");
	lv_label_set_long_mode(ui->contact_list_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->contact_list_label_5, 91, 12);
	lv_obj_set_size(ui->contact_list_label_5, 186, 32);

	//Write style for contact_list_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->contact_list_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->contact_list_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->contact_list_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->contact_list_label_5, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->contact_list_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->contact_list_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->contact_list_label_5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->contact_list_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->contact_list_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->contact_list_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->contact_list_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->contact_list_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->contact_list_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes contact_list_label_4
	ui->contact_list_label_4 = lv_label_create(ui->contact_list_cont_3);
	lv_label_set_text(ui->contact_list_label_4, "00 555 7764 2258");
	lv_label_set_long_mode(ui->contact_list_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->contact_list_label_4, 91, 45);
	lv_obj_set_size(ui->contact_list_label_4, 180, 21);

	//Write style for contact_list_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->contact_list_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->contact_list_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->contact_list_label_4, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->contact_list_label_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->contact_list_label_4, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->contact_list_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->contact_list_label_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->contact_list_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->contact_list_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->contact_list_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->contact_list_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->contact_list_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->contact_list_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes contact_list_cont_4
	ui->contact_list_cont_4 = lv_obj_create(ui->contact_list_cont_list);
	lv_obj_set_pos(ui->contact_list_cont_4, 0, 180);
	lv_obj_set_size(ui->contact_list_cont_4, 300, 75);
	lv_obj_set_scrollbar_mode(ui->contact_list_cont_4, LV_SCROLLBAR_MODE_OFF);

	//Write style for contact_list_cont_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->contact_list_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->contact_list_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->contact_list_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->contact_list_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->contact_list_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->contact_list_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->contact_list_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->contact_list_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes contact_list_img_5
	ui->contact_list_img_5 = lv_img_create(ui->contact_list_cont_4);
	lv_obj_add_flag(ui->contact_list_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->contact_list_img_5, &_img_avatar_3_alpha_61x61);
	lv_img_set_pivot(ui->contact_list_img_5, 50,50);
	lv_img_set_angle(ui->contact_list_img_5, 0);
	lv_obj_set_pos(ui->contact_list_img_5, 21, 3);
	lv_obj_set_size(ui->contact_list_img_5, 61, 61);

	//Write style for contact_list_img_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->contact_list_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes contact_list_label_7
	ui->contact_list_label_7 = lv_label_create(ui->contact_list_cont_4);
	lv_label_set_text(ui->contact_list_label_7, "Thomas End");
	lv_label_set_long_mode(ui->contact_list_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->contact_list_label_7, 91, 12);
	lv_obj_set_size(ui->contact_list_label_7, 186, 32);

	//Write style for contact_list_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->contact_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->contact_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->contact_list_label_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->contact_list_label_7, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->contact_list_label_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->contact_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->contact_list_label_7, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->contact_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->contact_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->contact_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->contact_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->contact_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->contact_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes contact_list_label_6
	ui->contact_list_label_6 = lv_label_create(ui->contact_list_cont_4);
	lv_label_set_text(ui->contact_list_label_6, "00 555 3679 4669");
	lv_label_set_long_mode(ui->contact_list_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->contact_list_label_6, 91, 45);
	lv_obj_set_size(ui->contact_list_label_6, 180, 21);

	//Write style for contact_list_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->contact_list_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->contact_list_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->contact_list_label_6, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->contact_list_label_6, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->contact_list_label_6, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->contact_list_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->contact_list_label_6, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->contact_list_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->contact_list_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->contact_list_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->contact_list_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->contact_list_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->contact_list_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes contact_list_cont_5
	ui->contact_list_cont_5 = lv_obj_create(ui->contact_list_cont_list);
	lv_obj_set_pos(ui->contact_list_cont_5, 0, 264);
	lv_obj_set_size(ui->contact_list_cont_5, 300, 75);
	lv_obj_set_scrollbar_mode(ui->contact_list_cont_5, LV_SCROLLBAR_MODE_OFF);

	//Write style for contact_list_cont_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->contact_list_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->contact_list_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->contact_list_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->contact_list_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->contact_list_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->contact_list_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->contact_list_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->contact_list_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes contact_list_img_6
	ui->contact_list_img_6 = lv_img_create(ui->contact_list_cont_5);
	lv_obj_add_flag(ui->contact_list_img_6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->contact_list_img_6, &_img_avatar_4_alpha_61x59);
	lv_img_set_pivot(ui->contact_list_img_6, 50,50);
	lv_img_set_angle(ui->contact_list_img_6, 0);
	lv_obj_set_pos(ui->contact_list_img_6, 21, 3);
	lv_obj_set_size(ui->contact_list_img_6, 61, 59);

	//Write style for contact_list_img_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->contact_list_img_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes contact_list_label_9
	ui->contact_list_label_9 = lv_label_create(ui->contact_list_cont_5);
	lv_label_set_text(ui->contact_list_label_9, "Elena Kovats");
	lv_label_set_long_mode(ui->contact_list_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->contact_list_label_9, 91, 12);
	lv_obj_set_size(ui->contact_list_label_9, 191, 32);

	//Write style for contact_list_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->contact_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->contact_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->contact_list_label_9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->contact_list_label_9, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->contact_list_label_9, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->contact_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->contact_list_label_9, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->contact_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->contact_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->contact_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->contact_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->contact_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->contact_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes contact_list_label_8
	ui->contact_list_label_8 = lv_label_create(ui->contact_list_cont_5);
	lv_label_set_text(ui->contact_list_label_8, "00 222 4584 2332");
	lv_label_set_long_mode(ui->contact_list_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->contact_list_label_8, 91, 45);
	lv_obj_set_size(ui->contact_list_label_8, 180, 21);

	//Write style for contact_list_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->contact_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->contact_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->contact_list_label_8, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->contact_list_label_8, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->contact_list_label_8, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->contact_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->contact_list_label_8, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->contact_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->contact_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->contact_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->contact_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->contact_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->contact_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes contact_list_img_home
	ui->contact_list_img_home = lv_img_create(ui->contact_list);
	lv_obj_add_flag(ui->contact_list_img_home, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->contact_list_img_home, &_text_home_alpha_38x49);
	lv_img_set_pivot(ui->contact_list_img_home, 50,50);
	lv_img_set_angle(ui->contact_list_img_home, 0);
	lv_obj_set_pos(ui->contact_list_img_home, 321, 255);
	lv_obj_set_size(ui->contact_list_img_home, 38, 49);
	lv_obj_add_flag(ui->contact_list_img_home, LV_OBJ_FLAG_FLOATING);

	//Write style for contact_list_img_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->contact_list_img_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes contact_list_img_favorite
	ui->contact_list_img_favorite = lv_img_create(ui->contact_list);
	lv_obj_add_flag(ui->contact_list_img_favorite, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->contact_list_img_favorite, &_text_favorites_alpha_56x78);
	lv_img_set_pivot(ui->contact_list_img_favorite, 50,50);
	lv_img_set_angle(ui->contact_list_img_favorite, 80);
	lv_obj_set_pos(ui->contact_list_img_favorite, 321, 76);
	lv_obj_set_size(ui->contact_list_img_favorite, 56, 78);
	lv_obj_add_flag(ui->contact_list_img_favorite, LV_OBJ_FLAG_FLOATING);

	//Write style for contact_list_img_favorite, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->contact_list_img_favorite, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes contact_list_label_title
	ui->contact_list_label_title = lv_label_create(ui->contact_list);
	lv_label_set_text(ui->contact_list_label_title, "Contact List");
	lv_label_set_long_mode(ui->contact_list_label_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->contact_list_label_title, 0, -75);
	lv_obj_set_size(ui->contact_list_label_title, 392, 75);
	lv_obj_add_flag(ui->contact_list_label_title, LV_OBJ_FLAG_FLOATING);

	//Write style for contact_list_label_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->contact_list_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->contact_list_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->contact_list_label_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->contact_list_label_title, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->contact_list_label_title, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->contact_list_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->contact_list_label_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->contact_list_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->contact_list_label_title, 27, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->contact_list_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->contact_list_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->contact_list_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->contact_list_label_title, &_img_header_bg_392x75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->contact_list_label_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor(ui->contact_list_label_title, lv_color_hex(0x1099e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor_opa(ui->contact_list_label_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->contact_list_label_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->contact_list);

	
	//Init events for screen.
	events_init_contact_list(ui);
}
