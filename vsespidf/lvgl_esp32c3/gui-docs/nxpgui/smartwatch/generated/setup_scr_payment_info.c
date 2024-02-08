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


void setup_scr_payment_info(lv_ui *ui)
{
	//Write codes payment_info
	ui->payment_info = lv_obj_create(NULL);
	lv_obj_set_size(ui->payment_info, 240, 240);

	//Write style for payment_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->payment_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->payment_info, &_img_bg_2_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->payment_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_info_home
	ui->payment_info_home = lv_img_create(ui->payment_info);
	lv_obj_add_flag(ui->payment_info_home, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->payment_info_home, &_text_home_alpha_36x48);
	lv_img_set_pivot(ui->payment_info_home, 50,50);
	lv_img_set_angle(ui->payment_info_home, 0);
	lv_obj_set_pos(ui->payment_info_home, 326, 260);
	lv_obj_set_size(ui->payment_info_home, 36, 48);

	//Write style for payment_info_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->payment_info_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_info_title
	ui->payment_info_title = lv_label_create(ui->payment_info);
	lv_label_set_text(ui->payment_info_title, "Payment\n");
	lv_label_set_long_mode(ui->payment_info_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->payment_info_title, 0, -89);
	lv_obj_set_size(ui->payment_info_title, 392, 75);
	lv_obj_add_flag(ui->payment_info_title, LV_OBJ_FLAG_FLOATING);

	//Write style for payment_info_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->payment_info_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->payment_info_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->payment_info_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->payment_info_title, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->payment_info_title, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->payment_info_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->payment_info_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->payment_info_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->payment_info_title, 27, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->payment_info_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->payment_info_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->payment_info_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->payment_info_title, &_img_header_bg_392x75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->payment_info_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor(ui->payment_info_title, lv_color_hex(0x6B309C), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor_opa(ui->payment_info_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->payment_info_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_info_complete_icon
	ui->payment_info_complete_icon = lv_img_create(ui->payment_info);
	lv_obj_add_flag(ui->payment_info_complete_icon, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->payment_info_complete_icon, &_img_payment_ok_alpha_126x125);
	lv_img_set_pivot(ui->payment_info_complete_icon, 50,50);
	lv_img_set_angle(ui->payment_info_complete_icon, 0);
	lv_obj_set_pos(ui->payment_info_complete_icon, 133, 89);
	lv_obj_set_size(ui->payment_info_complete_icon, 126, 125);

	//Write style for payment_info_complete_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->payment_info_complete_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_info_pay_info
	ui->payment_info_pay_info = lv_obj_create(ui->payment_info);
	lv_obj_set_pos(ui->payment_info_pay_info, 62, 402);
	lv_obj_set_size(ui->payment_info_pay_info, 255, 123);
	lv_obj_set_scrollbar_mode(ui->payment_info_pay_info, LV_SCROLLBAR_MODE_OFF);

	//Write style for payment_info_pay_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->payment_info_pay_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->payment_info_pay_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->payment_info_pay_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->payment_info_pay_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->payment_info_pay_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->payment_info_pay_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->payment_info_pay_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->payment_info_pay_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_info_label_11
	ui->payment_info_label_11 = lv_label_create(ui->payment_info_pay_info);
	lv_label_set_text(ui->payment_info_label_11, "Payment Complete");
	lv_label_set_long_mode(ui->payment_info_label_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->payment_info_label_11, 49, 19);
	lv_obj_set_size(ui->payment_info_label_11, 165, 23);

	//Write style for payment_info_label_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->payment_info_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->payment_info_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->payment_info_label_11, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->payment_info_label_11, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->payment_info_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->payment_info_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->payment_info_label_11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->payment_info_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->payment_info_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->payment_info_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->payment_info_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->payment_info_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->payment_info_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_info_label_10
	ui->payment_info_label_10 = lv_label_create(ui->payment_info_pay_info);
	lv_label_set_text(ui->payment_info_label_10, "TOTAL AMOUNT");
	lv_label_set_long_mode(ui->payment_info_label_10, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->payment_info_label_10, 31, 57);
	lv_obj_set_size(ui->payment_info_label_10, 197, 20);

	//Write style for payment_info_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->payment_info_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->payment_info_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->payment_info_label_10, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->payment_info_label_10, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->payment_info_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->payment_info_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->payment_info_label_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->payment_info_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->payment_info_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->payment_info_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->payment_info_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->payment_info_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->payment_info_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_info_label_12
	ui->payment_info_label_12 = lv_label_create(ui->payment_info_pay_info);
	lv_label_set_text(ui->payment_info_label_12, "$ 199.00");
	lv_label_set_long_mode(ui->payment_info_label_12, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->payment_info_label_12, 46, 83);
	lv_obj_set_size(ui->payment_info_label_12, 165, 27);

	//Write style for payment_info_label_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->payment_info_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->payment_info_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->payment_info_label_12, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->payment_info_label_12, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->payment_info_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->payment_info_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->payment_info_label_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->payment_info_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->payment_info_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->payment_info_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->payment_info_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->payment_info_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->payment_info_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_info_left
	ui->payment_info_left = lv_img_create(ui->payment_info);
	lv_obj_add_flag(ui->payment_info_left, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->payment_info_left, &_img_arrow_left_alpha_9x32);
	lv_img_set_pivot(ui->payment_info_left, 50,50);
	lv_img_set_angle(ui->payment_info_left, 0);
	lv_obj_set_pos(ui->payment_info_left, 10, 172);
	lv_obj_set_size(ui->payment_info_left, 9, 32);
	lv_obj_add_flag(ui->payment_info_left, LV_OBJ_FLAG_FLOATING);

	//Write style for payment_info_left, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->payment_info_left, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_info_right
	ui->payment_info_right = lv_img_create(ui->payment_info);
	lv_obj_add_flag(ui->payment_info_right, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->payment_info_right, &_img_arrow_right_alpha_9x32);
	lv_img_set_pivot(ui->payment_info_right, 50,50);
	lv_img_set_angle(ui->payment_info_right, 0);
	lv_obj_set_pos(ui->payment_info_right, 368, 172);
	lv_obj_set_size(ui->payment_info_right, 9, 32);
	lv_obj_add_flag(ui->payment_info_right, LV_OBJ_FLAG_FLOATING);

	//Write style for payment_info_right, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->payment_info_right, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->payment_info);

	
	//Init events for screen.
	events_init_payment_info(ui);
}
