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


void setup_scr_payment(lv_ui *ui)
{
	//Write codes payment
	ui->payment = lv_obj_create(NULL);
	lv_obj_set_size(ui->payment, 240, 240);

	//Write style for payment, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->payment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->payment, &_img_bg_2_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->payment, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_home
	ui->payment_home = lv_img_create(ui->payment);
	lv_obj_add_flag(ui->payment_home, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->payment_home, &_text_home_alpha_36x48);
	lv_img_set_pivot(ui->payment_home, 50,50);
	lv_img_set_angle(ui->payment_home, 0);
	lv_obj_set_pos(ui->payment_home, 331, 260);
	lv_obj_set_size(ui->payment_home, 36, 48);
	lv_obj_add_flag(ui->payment_home, LV_OBJ_FLAG_FLOATING);

	//Write style for payment_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->payment_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_title
	ui->payment_title = lv_label_create(ui->payment);
	lv_label_set_text(ui->payment_title, "Payment\n");
	lv_label_set_long_mode(ui->payment_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->payment_title, 0, -91);
	lv_obj_set_size(ui->payment_title, 392, 75);
	lv_obj_add_flag(ui->payment_title, LV_OBJ_FLAG_FLOATING);

	//Write style for payment_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->payment_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->payment_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->payment_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->payment_title, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->payment_title, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->payment_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->payment_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->payment_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->payment_title, 27, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->payment_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->payment_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->payment_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->payment_title, &_img_header_bg_392x75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->payment_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor(ui->payment_title, lv_color_hex(0x6B309C), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor_opa(ui->payment_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->payment_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_next_buy
	ui->payment_next_buy = lv_label_create(ui->payment);
	lv_label_set_text(ui->payment_next_buy, "Next: Buy a car.");
	lv_label_set_long_mode(ui->payment_next_buy, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->payment_next_buy, 130, 8);
	lv_obj_set_size(ui->payment_next_buy, 132, 17);

	//Write style for payment_next_buy, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->payment_next_buy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->payment_next_buy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->payment_next_buy, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->payment_next_buy, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->payment_next_buy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->payment_next_buy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->payment_next_buy, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->payment_next_buy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->payment_next_buy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->payment_next_buy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->payment_next_buy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->payment_next_buy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->payment_next_buy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_amount
	ui->payment_amount = lv_label_create(ui->payment);
	lv_label_set_text(ui->payment_amount, "$ 18 8666.49");
	lv_label_set_long_mode(ui->payment_amount, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->payment_amount, 92, 25);
	lv_obj_set_size(ui->payment_amount, 192, 31);

	//Write style for payment_amount, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->payment_amount, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->payment_amount, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->payment_amount, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->payment_amount, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->payment_amount, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->payment_amount, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->payment_amount, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->payment_amount, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->payment_amount, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->payment_amount, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->payment_amount, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->payment_amount, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->payment_amount, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_card_icon
	ui->payment_card_icon = lv_img_create(ui->payment);
	lv_obj_add_flag(ui->payment_card_icon, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->payment_card_icon, &_img_card_1_alpha_266x167);
	lv_img_set_pivot(ui->payment_card_icon, 50,50);
	lv_img_set_angle(ui->payment_card_icon, 0);
	lv_obj_set_pos(ui->payment_card_icon, 55, 141);
	lv_obj_set_size(ui->payment_card_icon, 266, 167);

	//Write style for payment_card_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->payment_card_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_bank_info
	ui->payment_bank_info = lv_obj_create(ui->payment);
	lv_obj_set_pos(ui->payment_bank_info, 63, 400);
	lv_obj_set_size(ui->payment_bank_info, 267, 69);
	lv_obj_set_scrollbar_mode(ui->payment_bank_info, LV_SCROLLBAR_MODE_OFF);

	//Write style for payment_bank_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->payment_bank_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->payment_bank_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->payment_bank_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->payment_bank_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->payment_bank_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->payment_bank_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->payment_bank_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->payment_bank_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_label_7
	ui->payment_label_7 = lv_label_create(ui->payment_bank_info);
	lv_label_set_text(ui->payment_label_7, "Brendon Slade");
	lv_label_set_long_mode(ui->payment_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->payment_label_7, 54, 9);
	lv_obj_set_size(ui->payment_label_7, 182, 31);

	//Write style for payment_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->payment_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->payment_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->payment_label_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->payment_label_7, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->payment_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->payment_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->payment_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->payment_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->payment_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->payment_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->payment_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->payment_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->payment_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_label_6
	ui->payment_label_6 = lv_label_create(ui->payment_bank_info);
	lv_label_set_text(ui->payment_label_6, "NXP Bank Co.");
	lv_label_set_long_mode(ui->payment_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->payment_label_6, 40, 39);
	lv_obj_set_size(ui->payment_label_6, 197, 24);

	//Write style for payment_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->payment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->payment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->payment_label_6, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->payment_label_6, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->payment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->payment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->payment_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->payment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->payment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->payment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->payment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->payment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->payment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_tail_number
	ui->payment_tail_number = lv_label_create(ui->payment);
	lv_label_set_text(ui->payment_tail_number, "4242");
	lv_label_set_long_mode(ui->payment_tail_number, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->payment_tail_number, 251, 215);
	lv_obj_set_size(ui->payment_tail_number, 47, 18);

	//Write style for payment_tail_number, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->payment_tail_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->payment_tail_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->payment_tail_number, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->payment_tail_number, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->payment_tail_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->payment_tail_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->payment_tail_number, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->payment_tail_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->payment_tail_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->payment_tail_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->payment_tail_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->payment_tail_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->payment_tail_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_expiry_date
	ui->payment_expiry_date = lv_label_create(ui->payment);
	lv_label_set_text(ui->payment_expiry_date, "25/12");
	lv_label_set_long_mode(ui->payment_expiry_date, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->payment_expiry_date, 72, 281);
	lv_obj_set_size(ui->payment_expiry_date, 47, 18);

	//Write style for payment_expiry_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->payment_expiry_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->payment_expiry_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->payment_expiry_date, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->payment_expiry_date, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->payment_expiry_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->payment_expiry_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->payment_expiry_date, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->payment_expiry_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->payment_expiry_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->payment_expiry_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->payment_expiry_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->payment_expiry_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->payment_expiry_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_img_dot
	ui->payment_img_dot = lv_img_create(ui->payment);
	lv_obj_add_flag(ui->payment_img_dot, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->payment_img_dot, &_dot_alpha_8x8);
	lv_img_set_pivot(ui->payment_img_dot, 50,50);
	lv_img_set_angle(ui->payment_img_dot, 0);
	lv_obj_set_pos(ui->payment_img_dot, 370, 214);
	lv_obj_set_size(ui->payment_img_dot, 8, 8);

	//Write style for payment_img_dot, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->payment_img_dot, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_img_menu
	ui->payment_img_menu = lv_img_create(ui->payment);
	lv_obj_add_flag(ui->payment_img_menu, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->payment_img_menu, &_img_menu_alpha_11x100);
	lv_img_set_pivot(ui->payment_img_menu, 50,50);
	lv_img_set_angle(ui->payment_img_menu, 0);
	lv_obj_set_pos(ui->payment_img_menu, 365, 146);
	lv_obj_set_size(ui->payment_img_menu, 11, 100);

	//Write style for payment_img_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->payment_img_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes payment_img_select
	ui->payment_img_select = lv_img_create(ui->payment);
	lv_obj_add_flag(ui->payment_img_select, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->payment_img_select, &_text_select_alpha_43x57);
	lv_img_set_pivot(ui->payment_img_select, 50,50);
	lv_img_set_angle(ui->payment_img_select, 80);
	lv_obj_set_pos(ui->payment_img_select, 322, 69);
	lv_obj_set_size(ui->payment_img_select, 43, 57);

	//Write style for payment_img_select, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->payment_img_select, 163, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->payment);

	
	//Init events for screen.
	events_init_payment(ui);
}
