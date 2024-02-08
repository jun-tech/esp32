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


void ui_init_style(lv_style_t * style)
{
  if (style->prop_cnt > 1)
    lv_style_reset(style);
  else
    lv_style_init(style);
}

void init_scr_del_flag(lv_ui *ui)
{
  
	ui->home_analog_del = true;
	ui->home_digital_del = true;
	ui->message_info_del = true;
	ui->message_list_del = true;
	ui->standup_del = true;
	ui->car_lock_del = true;
	ui->car_start_del = true;
	ui->listening_del = true;
	ui->not_recognized_del = true;
	ui->recognized_del = true;
	ui->contact_list_del = true;
	ui->call_del = true;
	ui->weather_del = true;
	ui->weather_hour_del = true;
	ui->weather_week_del = true;
	ui->air_quality_del = true;
	ui->fitness_del = true;
	ui->music_player_del = true;
	ui->flight_del = true;
	ui->flight_info_del = true;
	ui->navigation_del = true;
	ui->position_del = true;
	ui->payment_del = true;
	ui->payment_info_del = true;
	ui->settings_del = true;
	ui->battery_del = true;
	ui->info_del = true;
	ui->find_device_del = true;
	ui->play_sound_del = true;
	ui->blood_oxygen_del = true;
	ui->ekg_del = true;
	ui->stress_level_del = true;
	ui->blood_pressure_del = true;
	ui->sleep_del = true;
	ui->step_del = true;
	ui->menstrual_del = true;
}

void setup_ui(lv_ui *ui)
{
  init_scr_del_flag(ui);
  setup_scr_home_analog(ui);
  lv_scr_load(ui->home_analog);
}
