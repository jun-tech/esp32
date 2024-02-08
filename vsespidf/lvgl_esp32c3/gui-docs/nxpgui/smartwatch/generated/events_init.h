/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


#ifndef EVENTS_INIT_H_
#define EVENTS_INIT_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"

void events_init(lv_ui *ui);

void events_init_home_analog(lv_ui *ui);
void events_init_home_digital(lv_ui *ui);
void events_init_message_info(lv_ui *ui);
void events_init_message_list(lv_ui *ui);
void events_init_standup(lv_ui *ui);
void events_init_car_lock(lv_ui *ui);
void events_init_car_start(lv_ui *ui);
void events_init_listening(lv_ui *ui);
void events_init_not_recognized(lv_ui *ui);
void events_init_recognized(lv_ui *ui);
void events_init_contact_list(lv_ui *ui);
void events_init_call(lv_ui *ui);
void events_init_weather(lv_ui *ui);
void events_init_weather_hour(lv_ui *ui);
void events_init_weather_week(lv_ui *ui);
void events_init_air_quality(lv_ui *ui);
void events_init_fitness(lv_ui *ui);
void events_init_music_player(lv_ui *ui);
void events_init_flight(lv_ui *ui);
void events_init_flight_info(lv_ui *ui);
void events_init_navigation(lv_ui *ui);
void events_init_position(lv_ui *ui);
void events_init_payment(lv_ui *ui);
void events_init_payment_info(lv_ui *ui);
void events_init_settings(lv_ui *ui);
void events_init_battery(lv_ui *ui);
void events_init_info(lv_ui *ui);
void events_init_find_device(lv_ui *ui);
void events_init_play_sound(lv_ui *ui);
void events_init_blood_oxygen(lv_ui *ui);
void events_init_ekg(lv_ui *ui);
void events_init_stress_level(lv_ui *ui);
void events_init_blood_pressure(lv_ui *ui);
void events_init_sleep(lv_ui *ui);
void events_init_step(lv_ui *ui);
void events_init_menstrual(lv_ui *ui);

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
