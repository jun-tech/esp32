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


void setup_scr_listening(lv_ui *ui)
{
	//Write codes listening
	ui->listening = lv_obj_create(NULL);
	lv_obj_set_size(ui->listening, 240, 240);

	//Write style for listening, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->listening, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->listening, &_img_bg_2_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->listening, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes listening_listen_text
	ui->listening_listen_text = lv_label_create(ui->listening);
	lv_label_set_text(ui->listening_listen_text, "Listening...");
	lv_label_set_long_mode(ui->listening_listen_text, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->listening_listen_text, 94, 357);
	lv_obj_set_size(ui->listening_listen_text, 190, 29);

	//Write style for listening_listen_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->listening_listen_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->listening_listen_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->listening_listen_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->listening_listen_text, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->listening_listen_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->listening_listen_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->listening_listen_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->listening_listen_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->listening_listen_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->listening_listen_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->listening_listen_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->listening_listen_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->listening_listen_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes listening_left
	ui->listening_left = lv_img_create(ui->listening);
	lv_obj_add_flag(ui->listening_left, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->listening_left, &_img_arrow_left_alpha_9x32);
	lv_img_set_pivot(ui->listening_left, 50,50);
	lv_img_set_angle(ui->listening_left, 0);
	lv_obj_set_pos(ui->listening_left, 10, 172);
	lv_obj_set_size(ui->listening_left, 9, 32);

	//Write style for listening_left, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->listening_left, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes listening_right
	ui->listening_right = lv_img_create(ui->listening);
	lv_obj_add_flag(ui->listening_right, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->listening_right, &_img_arrow_right_alpha_9x32);
	lv_img_set_pivot(ui->listening_right, 50,50);
	lv_img_set_angle(ui->listening_right, 0);
	lv_obj_set_pos(ui->listening_right, 368, 172);
	lv_obj_set_size(ui->listening_right, 9, 32);

	//Write style for listening_right, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->listening_right, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes listening_home
	ui->listening_home = lv_img_create(ui->listening);
	lv_obj_add_flag(ui->listening_home, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->listening_home, &_text_home_alpha_36x48);
	lv_img_set_pivot(ui->listening_home, 50,50);
	lv_img_set_angle(ui->listening_home, 0);
	lv_obj_set_pos(ui->listening_home, 319, 259);
	lv_obj_set_size(ui->listening_home, 36, 48);

	//Write style for listening_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->listening_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes listening_spinner_1
	ui->listening_spinner_1 = lv_spinner_create(ui->listening, 1000, 90);
	lv_obj_set_pos(ui->listening_spinner_1, 86, 55);
	lv_obj_set_size(ui->listening_spinner_1, 220, 220);

	//Write style for listening_spinner_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_pad_top(ui->listening_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->listening_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->listening_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->listening_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->listening_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->listening_spinner_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->listening_spinner_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->listening_spinner_1, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->listening_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for listening_spinner_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->listening_spinner_1, 7, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->listening_spinner_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->listening_spinner_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes listening_mic_icon
	ui->listening_mic_icon = lv_img_create(ui->listening);
	lv_obj_add_flag(ui->listening_mic_icon, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->listening_mic_icon, &_img_mic_1_alpha_190x195);
	lv_img_set_pivot(ui->listening_mic_icon, 50,50);
	lv_img_set_angle(ui->listening_mic_icon, 0);
	lv_obj_set_pos(ui->listening_mic_icon, 101, 64);
	lv_obj_set_size(ui->listening_mic_icon, 190, 195);

	//Write style for listening_mic_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->listening_mic_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->listening);

	
	//Init events for screen.
	events_init_listening(ui);
}
