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


void setup_scr_play_sound(lv_ui *ui)
{
	//Write codes play_sound
	ui->play_sound = lv_obj_create(NULL);
	lv_obj_set_size(ui->play_sound, 240, 240);

	//Write style for play_sound, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->play_sound, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->play_sound, &_img_bg_2_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->play_sound, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes play_sound_right
	ui->play_sound_right = lv_img_create(ui->play_sound);
	lv_obj_add_flag(ui->play_sound_right, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->play_sound_right, &_img_arrow_right_alpha_9x32);
	lv_img_set_pivot(ui->play_sound_right, 50,50);
	lv_img_set_angle(ui->play_sound_right, 0);
	lv_obj_set_pos(ui->play_sound_right, 368, 172);
	lv_obj_set_size(ui->play_sound_right, 9, 32);
	lv_obj_add_flag(ui->play_sound_right, LV_OBJ_FLAG_FLOATING);

	//Write style for play_sound_right, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->play_sound_right, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes play_sound_left
	ui->play_sound_left = lv_img_create(ui->play_sound);
	lv_obj_add_flag(ui->play_sound_left, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->play_sound_left, &_img_arrow_left_alpha_9x32);
	lv_img_set_pivot(ui->play_sound_left, 50,50);
	lv_img_set_angle(ui->play_sound_left, 0);
	lv_obj_set_pos(ui->play_sound_left, 10, 172);
	lv_obj_set_size(ui->play_sound_left, 9, 32);
	lv_obj_add_flag(ui->play_sound_left, LV_OBJ_FLAG_FLOATING);

	//Write style for play_sound_left, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->play_sound_left, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes play_sound_home
	ui->play_sound_home = lv_img_create(ui->play_sound);
	lv_obj_add_flag(ui->play_sound_home, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->play_sound_home, &_text_home_alpha_36x48);
	lv_img_set_pivot(ui->play_sound_home, 50,50);
	lv_img_set_angle(ui->play_sound_home, 0);
	lv_obj_set_pos(ui->play_sound_home, 326, 260);
	lv_obj_set_size(ui->play_sound_home, 36, 48);
	lv_obj_add_flag(ui->play_sound_home, LV_OBJ_FLAG_FLOATING);

	//Write style for play_sound_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->play_sound_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes play_sound_img_find
	ui->play_sound_img_find = lv_img_create(ui->play_sound);
	lv_obj_add_flag(ui->play_sound_img_find, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->play_sound_img_find, &_img_find_device2_alpha_168x168);
	lv_img_set_pivot(ui->play_sound_img_find, 84,84);
	lv_img_set_angle(ui->play_sound_img_find, 0);
	lv_obj_set_pos(ui->play_sound_img_find, 112, 92);
	lv_obj_set_size(ui->play_sound_img_find, 168, 168);

	//Write style for play_sound_img_find, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->play_sound_img_find, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes play_sound_btn_cancel
	ui->play_sound_btn_cancel = lv_btn_create(ui->play_sound);
	ui->play_sound_btn_cancel_label = lv_label_create(ui->play_sound_btn_cancel);
	lv_label_set_text(ui->play_sound_btn_cancel_label, "CANCEL");
	lv_label_set_long_mode(ui->play_sound_btn_cancel_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->play_sound_btn_cancel_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->play_sound_btn_cancel, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->play_sound_btn_cancel, 126, 361);
	lv_obj_set_size(ui->play_sound_btn_cancel, 141, 54);

	//Write style for play_sound_btn_cancel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->play_sound_btn_cancel, 171, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->play_sound_btn_cancel, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->play_sound_btn_cancel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->play_sound_btn_cancel, 27, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->play_sound_btn_cancel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->play_sound_btn_cancel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->play_sound_btn_cancel, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->play_sound_btn_cancel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes play_sound_title
	ui->play_sound_title = lv_label_create(ui->play_sound);
	lv_label_set_text(ui->play_sound_title, "Playing Sound\n");
	lv_label_set_long_mode(ui->play_sound_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->play_sound_title, 32, -38);
	lv_obj_set_size(ui->play_sound_title, 329, 39);
	lv_obj_add_flag(ui->play_sound_title, LV_OBJ_FLAG_FLOATING);

	//Write style for play_sound_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->play_sound_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->play_sound_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->play_sound_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->play_sound_title, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->play_sound_title, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->play_sound_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->play_sound_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->play_sound_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->play_sound_title, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->play_sound_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->play_sound_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->play_sound_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->play_sound_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->play_sound);

	
	//Init events for screen.
	events_init_play_sound(ui);
}
