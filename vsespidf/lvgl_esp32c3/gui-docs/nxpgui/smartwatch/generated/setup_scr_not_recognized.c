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


void setup_scr_not_recognized(lv_ui *ui)
{
	//Write codes not_recognized
	ui->not_recognized = lv_obj_create(NULL);
	lv_obj_set_size(ui->not_recognized, 240, 240);

	//Write style for not_recognized, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->not_recognized, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->not_recognized, &_img_bg_2_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->not_recognized, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes not_recognized_left
	ui->not_recognized_left = lv_img_create(ui->not_recognized);
	lv_obj_add_flag(ui->not_recognized_left, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->not_recognized_left, &_img_arrow_left_alpha_9x32);
	lv_img_set_pivot(ui->not_recognized_left, 50,50);
	lv_img_set_angle(ui->not_recognized_left, 0);
	lv_obj_set_pos(ui->not_recognized_left, 10, 172);
	lv_obj_set_size(ui->not_recognized_left, 9, 32);

	//Write style for not_recognized_left, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->not_recognized_left, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes not_recognized_right
	ui->not_recognized_right = lv_img_create(ui->not_recognized);
	lv_obj_add_flag(ui->not_recognized_right, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->not_recognized_right, &_img_arrow_right_alpha_9x32);
	lv_img_set_pivot(ui->not_recognized_right, 50,50);
	lv_img_set_angle(ui->not_recognized_right, 0);
	lv_obj_set_pos(ui->not_recognized_right, 368, 172);
	lv_obj_set_size(ui->not_recognized_right, 9, 32);

	//Write style for not_recognized_right, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->not_recognized_right, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes not_recognized_home
	ui->not_recognized_home = lv_img_create(ui->not_recognized);
	lv_obj_add_flag(ui->not_recognized_home, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->not_recognized_home, &_text_home_alpha_36x48);
	lv_img_set_pivot(ui->not_recognized_home, 50,50);
	lv_img_set_angle(ui->not_recognized_home, 0);
	lv_obj_set_pos(ui->not_recognized_home, 319, 259);
	lv_obj_set_size(ui->not_recognized_home, 36, 48);

	//Write style for not_recognized_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->not_recognized_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes not_recognized_command_text
	ui->not_recognized_command_text = lv_label_create(ui->not_recognized);
	lv_label_set_text(ui->not_recognized_command_text, "Command not recognized");
	lv_label_set_long_mode(ui->not_recognized_command_text, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->not_recognized_command_text, 118, 336);
	lv_obj_set_size(ui->not_recognized_command_text, 157, 46);

	//Write style for not_recognized_command_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->not_recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->not_recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->not_recognized_command_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->not_recognized_command_text, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->not_recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->not_recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->not_recognized_command_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->not_recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->not_recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->not_recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->not_recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->not_recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->not_recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes not_recognized_no_mic_icon
	ui->not_recognized_no_mic_icon = lv_img_create(ui->not_recognized);
	lv_obj_add_flag(ui->not_recognized_no_mic_icon, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->not_recognized_no_mic_icon, &_img_mic_2_alpha_190x195);
	lv_img_set_pivot(ui->not_recognized_no_mic_icon, 50,50);
	lv_img_set_angle(ui->not_recognized_no_mic_icon, 0);
	lv_obj_set_pos(ui->not_recognized_no_mic_icon, 101, -202);
	lv_obj_set_size(ui->not_recognized_no_mic_icon, 190, 195);

	//Write style for not_recognized_no_mic_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->not_recognized_no_mic_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->not_recognized);

	
	//Init events for screen.
	events_init_not_recognized(ui);
}
