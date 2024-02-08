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


void setup_scr_position(lv_ui *ui)
{
	//Write codes position
	ui->position = lv_obj_create(NULL);
	lv_obj_set_size(ui->position, 240, 240);

	//Write style for position, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->position, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->position, &_img_map_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->position, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes position_home
	ui->position_home = lv_img_create(ui->position);
	lv_obj_add_flag(ui->position_home, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->position_home, &_text_home_alpha_36x48);
	lv_img_set_pivot(ui->position_home, 50,50);
	lv_img_set_angle(ui->position_home, 0);
	lv_obj_set_pos(ui->position_home, 319, 259);
	lv_obj_set_size(ui->position_home, 36, 48);
	lv_obj_add_flag(ui->position_home, LV_OBJ_FLAG_FLOATING);

	//Write style for position_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->position_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes position_title
	ui->position_title = lv_label_create(ui->position);
	lv_label_set_text(ui->position_title, "Your Position\n\n");
	lv_label_set_long_mode(ui->position_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->position_title, -3, -84);
	lv_obj_set_size(ui->position_title, 392, 75);
	lv_obj_add_flag(ui->position_title, LV_OBJ_FLAG_FLOATING);

	//Write style for position_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->position_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->position_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->position_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->position_title, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->position_title, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->position_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->position_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->position_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->position_title, 27, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->position_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->position_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->position_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->position_title, &_img_header_bg_392x75, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->position_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor(ui->position_title, lv_color_hex(0x3155EE), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_recolor_opa(ui->position_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->position_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes position_location_icon
	ui->position_location_icon = lv_btn_create(ui->position);
	ui->position_location_icon_label = lv_label_create(ui->position_location_icon);
	lv_label_set_text(ui->position_location_icon_label, "");
	lv_label_set_long_mode(ui->position_location_icon_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->position_location_icon_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->position_location_icon, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->position_location_icon, 186, 186);
	lv_obj_set_size(ui->position_location_icon, 20, 20);

	//Write style for position_location_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->position_location_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->position_location_icon, lv_color_hex(0x00E2FF), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->position_location_icon, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->position_location_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->position_location_icon, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->position_location_icon, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->position_location_icon, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->position_location_icon, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->position_location_icon, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->position_location_icon, 110, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->position_location_icon, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->position_location_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->position_location_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->position_location_icon, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->position_location_icon, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->position_location_icon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes position_bottom
	ui->position_bottom = lv_obj_create(ui->position);
	lv_obj_set_pos(ui->position_bottom, 96, 397);
	lv_obj_set_size(ui->position_bottom, 200, 200);
	lv_obj_set_scrollbar_mode(ui->position_bottom, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->position_bottom, LV_OBJ_FLAG_FLOATING);

	//Write style for position_bottom, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->position_bottom, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->position_bottom, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->position_bottom, 90, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->position_bottom, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->position_bottom, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->position_bottom, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->position_bottom, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->position_bottom, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->position_bottom, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes position_label_1
	ui->position_label_1 = lv_label_create(ui->position_bottom);
	lv_label_set_text(ui->position_label_1, "Turn Right\n200m\n");
	lv_label_set_long_mode(ui->position_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->position_label_1, 78, 42);
	lv_obj_set_size(ui->position_label_1, 91, 40);
	lv_obj_add_flag(ui->position_label_1, LV_OBJ_FLAG_FLOATING);

	//Write style for position_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->position_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->position_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->position_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->position_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->position_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->position_label_1, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->position_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->position_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->position_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->position_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->position_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->position_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->position_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes position_img_1
	ui->position_img_1 = lv_img_create(ui->position_bottom);
	lv_obj_add_flag(ui->position_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->position_img_1, &_img_small_nav_1_alpha_34x38);
	lv_img_set_pivot(ui->position_img_1, 50,50);
	lv_img_set_angle(ui->position_img_1, 0);
	lv_obj_set_pos(ui->position_img_1, 40, 39);
	lv_obj_set_size(ui->position_img_1, 34, 38);

	//Write style for position_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->position_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes position_left
	ui->position_left = lv_img_create(ui->position);
	lv_obj_add_flag(ui->position_left, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->position_left, &_img_arrow_left_alpha_9x32);
	lv_img_set_pivot(ui->position_left, 50,50);
	lv_img_set_angle(ui->position_left, 0);
	lv_obj_set_pos(ui->position_left, 10, 172);
	lv_obj_set_size(ui->position_left, 9, 32);
	lv_obj_add_flag(ui->position_left, LV_OBJ_FLAG_FLOATING);

	//Write style for position_left, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->position_left, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes position_right
	ui->position_right = lv_img_create(ui->position);
	lv_obj_add_flag(ui->position_right, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->position_right, &_img_arrow_right_alpha_9x32);
	lv_img_set_pivot(ui->position_right, 50,50);
	lv_img_set_angle(ui->position_right, 0);
	lv_obj_set_pos(ui->position_right, 368, 172);
	lv_obj_set_size(ui->position_right, 9, 32);
	lv_obj_add_flag(ui->position_right, LV_OBJ_FLAG_FLOATING);

	//Write style for position_right, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->position_right, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->position);

	
	//Init events for screen.
	events_init_position(ui);
}
