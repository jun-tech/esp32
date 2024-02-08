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


void setup_scr_recognized(lv_ui *ui)
{
	//Write codes recognized
	ui->recognized = lv_obj_create(NULL);
	lv_obj_set_size(ui->recognized, 240, 240);

	//Write style for recognized, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->recognized, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->recognized, &_img_bg_2_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->recognized, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes recognized_left
	ui->recognized_left = lv_img_create(ui->recognized);
	lv_obj_add_flag(ui->recognized_left, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->recognized_left, &_img_arrow_left_alpha_9x32);
	lv_img_set_pivot(ui->recognized_left, 50,50);
	lv_img_set_angle(ui->recognized_left, 0);
	lv_obj_set_pos(ui->recognized_left, 10, 172);
	lv_obj_set_size(ui->recognized_left, 9, 32);

	//Write style for recognized_left, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->recognized_left, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes recognized_home
	ui->recognized_home = lv_img_create(ui->recognized);
	lv_obj_add_flag(ui->recognized_home, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->recognized_home, &_text_home_alpha_36x48);
	lv_img_set_pivot(ui->recognized_home, 50,50);
	lv_img_set_angle(ui->recognized_home, 0);
	lv_obj_set_pos(ui->recognized_home, 319, 259);
	lv_obj_set_size(ui->recognized_home, 36, 48);

	//Write style for recognized_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->recognized_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes recognized_command_text
	ui->recognized_command_text = lv_label_create(ui->recognized);
	lv_label_set_text(ui->recognized_command_text, "Command recognized");
	lv_label_set_long_mode(ui->recognized_command_text, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->recognized_command_text, 137, 337);
	lv_obj_set_size(ui->recognized_command_text, 119, 46);

	//Write style for recognized_command_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->recognized_command_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->recognized_command_text, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->recognized_command_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes recognized_done_mic
	ui->recognized_done_mic = lv_img_create(ui->recognized);
	lv_obj_add_flag(ui->recognized_done_mic, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->recognized_done_mic, &_img_mic_3_alpha_190x195);
	lv_img_set_pivot(ui->recognized_done_mic, 50,50);
	lv_img_set_angle(ui->recognized_done_mic, 0);
	lv_obj_set_pos(ui->recognized_done_mic, 101, -204);
	lv_obj_set_size(ui->recognized_done_mic, 190, 195);

	//Write style for recognized_done_mic, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->recognized_done_mic, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->recognized);

	
	//Init events for screen.
	events_init_recognized(ui);
}
