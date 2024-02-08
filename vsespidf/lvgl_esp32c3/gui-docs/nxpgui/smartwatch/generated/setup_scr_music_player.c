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


void setup_scr_music_player(lv_ui *ui)
{
	//Write codes music_player
	ui->music_player = lv_obj_create(NULL);
	lv_obj_set_size(ui->music_player, 240, 240);

	//Write style for music_player, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->music_player, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->music_player, &_img_audio_album_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->music_player, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes music_player_arc_2
	ui->music_player_arc_2 = lv_arc_create(ui->music_player);
	lv_arc_set_mode(ui->music_player_arc_2, LV_ARC_MODE_NORMAL);
	lv_arc_set_range(ui->music_player_arc_2, 0, 100);
	lv_arc_set_bg_angles(ui->music_player_arc_2, 0, 172);
	lv_arc_set_angles(ui->music_player_arc_2, 0, 149);
	lv_arc_set_rotation(ui->music_player_arc_2, 160);
	lv_obj_set_pos(ui->music_player_arc_2, 11, 11);
	lv_obj_set_size(ui->music_player_arc_2, 370, 370);
	lv_obj_add_flag(ui->music_player_arc_2, LV_OBJ_FLAG_ADV_HITTEST);

	//Write style for music_player_arc_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->music_player_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->music_player_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->music_player_arc_2, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->music_player_arc_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->music_player_arc_2, lv_color_hex(0x777777), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->music_player_arc_2, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->music_player_arc_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->music_player_arc_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->music_player_arc_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->music_player_arc_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->music_player_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for music_player_arc_2, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->music_player_arc_2, 12, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->music_player_arc_2, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->music_player_arc_2, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for music_player_arc_2, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->music_player_arc_2, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->music_player_arc_2, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->music_player_arc_2, 6, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes music_player_arc_1
	ui->music_player_arc_1 = lv_arc_create(ui->music_player);
	lv_arc_set_mode(ui->music_player_arc_1, LV_ARC_MODE_NORMAL);
	lv_arc_set_range(ui->music_player_arc_1, 0, 100);
	lv_arc_set_bg_angles(ui->music_player_arc_1, 46, 142);
	lv_arc_set_angles(ui->music_player_arc_1, 46, 87);
	lv_arc_set_rotation(ui->music_player_arc_1, 0);
	lv_obj_set_pos(ui->music_player_arc_1, 11, 11);
	lv_obj_set_size(ui->music_player_arc_1, 370, 370);
	lv_obj_add_flag(ui->music_player_arc_1, LV_OBJ_FLAG_ADV_HITTEST);

	//Write style for music_player_arc_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->music_player_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->music_player_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->music_player_arc_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->music_player_arc_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->music_player_arc_1, lv_color_hex(0x777777), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->music_player_arc_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->music_player_arc_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->music_player_arc_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->music_player_arc_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->music_player_arc_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->music_player_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for music_player_arc_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->music_player_arc_1, 12, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->music_player_arc_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->music_player_arc_1, lv_color_hex(0x08ce08), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for music_player_arc_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->music_player_arc_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->music_player_arc_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes music_player_img_volume
	ui->music_player_img_volume = lv_img_create(ui->music_player);
	lv_obj_add_flag(ui->music_player_img_volume, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->music_player_img_volume, &_text_volume_alpha_27x71);
	lv_img_set_pivot(ui->music_player_img_volume, 0,0);
	lv_img_set_angle(ui->music_player_img_volume, -340);
	lv_obj_set_pos(ui->music_player_img_volume, 66, 294);
	lv_obj_set_size(ui->music_player_img_volume, 27, 71);

	//Write style for music_player_img_volume, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->music_player_img_volume, 187, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes music_player_img_home
	ui->music_player_img_home = lv_img_create(ui->music_player);
	lv_obj_add_flag(ui->music_player_img_home, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->music_player_img_home, &_text_home_alpha_36x48);
	lv_img_set_pivot(ui->music_player_img_home, 50,50);
	lv_img_set_angle(ui->music_player_img_home, 0);
	lv_obj_set_pos(ui->music_player_img_home, 332, 259);
	lv_obj_set_size(ui->music_player_img_home, 36, 48);

	//Write style for music_player_img_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->music_player_img_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes music_player_icon_home
	ui->music_player_icon_home = lv_img_create(ui->music_player);
	lv_obj_add_flag(ui->music_player_icon_home, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->music_player_icon_home, &_icn_home_alpha_26x24);
	lv_img_set_pivot(ui->music_player_icon_home, 50,50);
	lv_img_set_angle(ui->music_player_icon_home, 0);
	lv_obj_set_pos(ui->music_player_icon_home, 316, 259);
	lv_obj_set_size(ui->music_player_icon_home, 26, 24);

	//Write style for music_player_icon_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->music_player_icon_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes music_player_singer
	ui->music_player_singer = lv_label_create(ui->music_player);
	lv_label_set_text(ui->music_player_singer, "Erica Smith");
	lv_label_set_long_mode(ui->music_player_singer, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->music_player_singer, 83, 53);
	lv_obj_set_size(ui->music_player_singer, 227, 41);

	//Write style for music_player_singer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->music_player_singer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->music_player_singer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->music_player_singer, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->music_player_singer, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->music_player_singer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->music_player_singer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->music_player_singer, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->music_player_singer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->music_player_singer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->music_player_singer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->music_player_singer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->music_player_singer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->music_player_singer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes music_player_img_next
	ui->music_player_img_next = lv_img_create(ui->music_player);
	lv_obj_add_flag(ui->music_player_img_next, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->music_player_img_next, &_icn_audio_next_alpha_17x26);
	lv_img_set_pivot(ui->music_player_img_next, 50,50);
	lv_img_set_angle(ui->music_player_img_next, 0);
	lv_obj_set_pos(ui->music_player_img_next, 305, 183);
	lv_obj_set_size(ui->music_player_img_next, 17, 26);

	//Write style for music_player_img_next, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->music_player_img_next, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes music_player_img_previous
	ui->music_player_img_previous = lv_img_create(ui->music_player);
	lv_obj_add_flag(ui->music_player_img_previous, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->music_player_img_previous, &_icn_audio_back_alpha_17x26);
	lv_img_set_pivot(ui->music_player_img_previous, 50,50);
	lv_img_set_angle(ui->music_player_img_previous, 0);
	lv_obj_set_pos(ui->music_player_img_previous, 70, 183);
	lv_obj_set_size(ui->music_player_img_previous, 17, 26);

	//Write style for music_player_img_previous, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->music_player_img_previous, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes music_player_song_name
	ui->music_player_song_name = lv_label_create(ui->music_player);
	lv_label_set_text(ui->music_player_song_name, "Dance on the room");
	lv_label_set_long_mode(ui->music_player_song_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->music_player_song_name, 70, 88);
	lv_obj_set_size(ui->music_player_song_name, 252, 33);

	//Write style for music_player_song_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->music_player_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->music_player_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->music_player_song_name, lv_color_hex(0xbdbdbd), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->music_player_song_name, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->music_player_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->music_player_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->music_player_song_name, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->music_player_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->music_player_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->music_player_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->music_player_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->music_player_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->music_player_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes music_player_duration
	ui->music_player_duration = lv_label_create(ui->music_player);
	lv_label_set_text(ui->music_player_duration, "01:24 | 02:15");
	lv_label_set_long_mode(ui->music_player_duration, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->music_player_duration, 105, 252);
	lv_obj_set_size(ui->music_player_duration, 183, 27);

	//Write style for music_player_duration, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->music_player_duration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->music_player_duration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->music_player_duration, lv_color_hex(0xbdbdbd), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->music_player_duration, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->music_player_duration, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->music_player_duration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->music_player_duration, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->music_player_duration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->music_player_duration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->music_player_duration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->music_player_duration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->music_player_duration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->music_player_duration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes music_player_mode
	ui->music_player_mode = lv_img_create(ui->music_player);
	lv_obj_add_flag(ui->music_player_mode, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->music_player_mode, &_icn_audio_rnd_alpha_33x29);
	lv_img_set_pivot(ui->music_player_mode, 50,50);
	lv_img_set_angle(ui->music_player_mode, 0);
	lv_obj_set_pos(ui->music_player_mode, 180, 307);
	lv_obj_set_size(ui->music_player_mode, 33, 29);

	//Write style for music_player_mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->music_player_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes music_player_btn_background
	ui->music_player_btn_background = lv_btn_create(ui->music_player);
	ui->music_player_btn_background_label = lv_label_create(ui->music_player_btn_background);
	lv_label_set_text(ui->music_player_btn_background_label, "");
	lv_label_set_long_mode(ui->music_player_btn_background_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->music_player_btn_background_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->music_player_btn_background, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->music_player_btn_background, 146, 146);
	lv_obj_set_size(ui->music_player_btn_background, 100, 100);

	//Write style for music_player_btn_background, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->music_player_btn_background, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->music_player_btn_background, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->music_player_btn_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->music_player_btn_background, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->music_player_btn_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->music_player_btn_background, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->music_player_btn_background, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->music_player_btn_background, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes music_player_img_puse
	ui->music_player_img_puse = lv_img_create(ui->music_player);
	lv_obj_add_flag(ui->music_player_img_puse, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->music_player_img_puse, &_img_pause_alpha_24x38);
	lv_img_set_pivot(ui->music_player_img_puse, 50,50);
	lv_img_set_angle(ui->music_player_img_puse, 0);
	lv_obj_set_pos(ui->music_player_img_puse, 184, 177);
	lv_obj_set_size(ui->music_player_img_puse, 24, 38);

	//Write style for music_player_img_puse, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->music_player_img_puse, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes music_player_img_play
	ui->music_player_img_play = lv_img_create(ui->music_player);
	lv_obj_add_flag(ui->music_player_img_play, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->music_player_img_play, &_icn_audio_play_alpha_40x48);
	lv_img_set_pivot(ui->music_player_img_play, 50,50);
	lv_img_set_angle(ui->music_player_img_play, 0);
	lv_obj_set_pos(ui->music_player_img_play, 176, 172);
	lv_obj_set_size(ui->music_player_img_play, 40, 48);
	lv_obj_add_flag(ui->music_player_img_play, LV_OBJ_FLAG_HIDDEN);

	//Write style for music_player_img_play, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->music_player_img_play, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes music_player_img_dot
	ui->music_player_img_dot = lv_img_create(ui->music_player);
	lv_obj_add_flag(ui->music_player_img_dot, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->music_player_img_dot, &_dot_alpha_8x8);
	lv_img_set_pivot(ui->music_player_img_dot, 50,50);
	lv_img_set_angle(ui->music_player_img_dot, 0);
	lv_obj_set_pos(ui->music_player_img_dot, 370, 179);
	lv_obj_set_size(ui->music_player_img_dot, 8, 8);

	//Write style for music_player_img_dot, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->music_player_img_dot, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes music_player_img_menu
	ui->music_player_img_menu = lv_img_create(ui->music_player);
	lv_obj_add_flag(ui->music_player_img_menu, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->music_player_img_menu, &_img_menu_alpha_11x100);
	lv_img_set_pivot(ui->music_player_img_menu, 50,50);
	lv_img_set_angle(ui->music_player_img_menu, 0);
	lv_obj_set_pos(ui->music_player_img_menu, 365, 146);
	lv_obj_set_size(ui->music_player_img_menu, 11, 100);

	//Write style for music_player_img_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->music_player_img_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->music_player);

	
	//Init events for screen.
	events_init_music_player(ui);
}
