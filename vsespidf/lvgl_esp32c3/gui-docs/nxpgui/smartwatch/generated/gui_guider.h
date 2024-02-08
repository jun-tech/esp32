/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *home_analog;
	bool home_analog_del;
	lv_obj_t *home_analog_battery_arc;
	lv_obj_t *home_analog_step_arc;
	lv_obj_t *home_analog_analog_clock_1;
	lv_obj_t *home_analog_sport_icon;
	lv_obj_t *home_analog_nxp_log;
	lv_obj_t *home_analog_step_icon;
	lv_obj_t *home_analog_step_text;
	lv_obj_t *home_analog_temp_text;
	lv_obj_t *home_analog_weather_icon;
	lv_obj_t *home_analog_week_day;
	lv_obj_t *home_analog_date_text;
	lv_obj_t *home_analog_sport_text;
	lv_obj_t *home_analog_message_icon;
	lv_obj_t *home_analog_battery_icon;
	lv_obj_t *home_analog_battery_text;
	lv_obj_t *home_analog_dot_list;
	lv_obj_t *home_analog_message_text;
	lv_obj_t *home_analog_img_dot;
	lv_obj_t *home_digital;
	bool home_digital_del;
	lv_obj_t *home_digital_arc_step;
	lv_obj_t *home_digital_arc_flash;
	lv_obj_t *home_digital_img_nxpLogo;
	lv_obj_t *home_digital_img_stepIcon;
	lv_obj_t *home_digital_label_stepText;
	lv_obj_t *home_digital_label_weather1Text;
	lv_obj_t *home_digital_label_week;
	lv_obj_t *home_digital_label_date;
	lv_obj_t *home_digital_img_flash;
	lv_obj_t *home_digital_label_flashText;
	lv_obj_t *home_digital_img_dialDot;
	lv_obj_t *home_digital_label_min;
	lv_obj_t *home_digital_label_hour;
	lv_obj_t *home_digital_img_messageIcon;
	lv_obj_t *home_digital_img_sportIcon;
	lv_obj_t *home_digital_img_weather1Icon;
	lv_obj_t *home_digital_img_sportText;
	lv_obj_t *home_digital_img_messageText;
	lv_obj_t *home_digital_img_dot;
	lv_obj_t *message_info;
	bool message_info_del;
	lv_obj_t *message_info_app_icon;
	lv_obj_t *message_info_sender;
	lv_obj_t *message_info_message_text;
	lv_obj_t *message_info_left;
	lv_obj_t *message_info_right;
	lv_obj_t *message_info_time_text;
	lv_obj_t *message_info_ok_btn;
	lv_obj_t *message_info_home_text;
	lv_obj_t *message_list;
	bool message_list_del;
	lv_obj_t *message_list_cont_messagesList;
	lv_obj_t *message_list_label_12;
	lv_obj_t *message_list_label_11;
	lv_obj_t *message_list_label_10;
	lv_obj_t *message_list_img_7;
	lv_obj_t *message_list_label_9;
	lv_obj_t *message_list_label_15;
	lv_obj_t *message_list_label_8;
	lv_obj_t *message_list_label_7;
	lv_obj_t *message_list_app_icon;
	lv_obj_t *message_list_img_8;
	lv_obj_t *message_list_img_9;
	lv_obj_t *message_list_img_10;
	lv_obj_t *message_list_label_13;
	lv_obj_t *message_list_label_14;
	lv_obj_t *message_list_img_home;
	lv_obj_t *message_list_left;
	lv_obj_t *message_list_right;
	lv_obj_t *standup;
	bool standup_del;
	lv_obj_t *standup_stand_icon;
	lv_obj_t *standup_stand_text;
	lv_obj_t *standup_stand_time;
	lv_obj_t *standup_left;
	lv_obj_t *standup_right;
	lv_obj_t *standup_time_text;
	lv_obj_t *standup_ok_btn;
	lv_obj_t *standup_home_text;
	lv_obj_t *car_lock;
	bool car_lock_del;
	lv_obj_t *car_lock_car_icon;
	lv_obj_t *car_lock_car_text;
	lv_obj_t *car_lock_left;
	lv_obj_t *car_lock_right;
	lv_obj_t *car_lock_time_text;
	lv_obj_t *car_lock_home_text;
	lv_obj_t *car_lock_cont_1;
	lv_obj_t *car_lock_lock_icon2;
	lv_obj_t *car_lock_lock_icon1;
	lv_obj_t *car_start;
	bool car_start_del;
	lv_obj_t *car_start_car_icon;
	lv_obj_t *car_start_info_text;
	lv_obj_t *car_start_left;
	lv_obj_t *car_start_right;
	lv_obj_t *car_start_home;
	lv_obj_t *car_start_start_imgbtn;
	lv_obj_t *car_start_start_imgbtn_label;
	lv_obj_t *listening;
	bool listening_del;
	lv_obj_t *listening_listen_text;
	lv_obj_t *listening_left;
	lv_obj_t *listening_right;
	lv_obj_t *listening_home;
	lv_obj_t *listening_spinner_1;
	lv_obj_t *listening_mic_icon;
	lv_obj_t *not_recognized;
	bool not_recognized_del;
	lv_obj_t *not_recognized_left;
	lv_obj_t *not_recognized_right;
	lv_obj_t *not_recognized_home;
	lv_obj_t *not_recognized_command_text;
	lv_obj_t *not_recognized_no_mic_icon;
	lv_obj_t *recognized;
	bool recognized_del;
	lv_obj_t *recognized_left;
	lv_obj_t *recognized_home;
	lv_obj_t *recognized_command_text;
	lv_obj_t *recognized_done_mic;
	lv_obj_t *contact_list;
	bool contact_list_del;
	lv_obj_t *contact_list_cont_list;
	lv_obj_t *contact_list_cont_2;
	lv_obj_t *contact_list_img_3;
	lv_obj_t *contact_list_label_2;
	lv_obj_t *contact_list_label_3;
	lv_obj_t *contact_list_cont_3;
	lv_obj_t *contact_list_img_4;
	lv_obj_t *contact_list_label_5;
	lv_obj_t *contact_list_label_4;
	lv_obj_t *contact_list_cont_4;
	lv_obj_t *contact_list_img_5;
	lv_obj_t *contact_list_label_7;
	lv_obj_t *contact_list_label_6;
	lv_obj_t *contact_list_cont_5;
	lv_obj_t *contact_list_img_6;
	lv_obj_t *contact_list_label_9;
	lv_obj_t *contact_list_label_8;
	lv_obj_t *contact_list_img_home;
	lv_obj_t *contact_list_img_favorite;
	lv_obj_t *contact_list_label_title;
	lv_obj_t *call;
	bool call_del;
	lv_obj_t *call_img_8;
	lv_obj_t *call_arc_1;
	lv_obj_t *call_img_7;
	lv_obj_t *call_img_6;
	lv_obj_t *call_img_5;
	lv_obj_t *call_img_4;
	lv_obj_t *call_hang_up_btn;
	lv_obj_t *call_hang_up_btn_label;
	lv_obj_t *call_hang_up;
	lv_obj_t *call_caller;
	lv_obj_t *call_digital_clock_1;
	lv_obj_t *call_mute_btn;
	lv_obj_t *call_mute_btn_label;
	lv_obj_t *call_unmute_icon;
	lv_obj_t *call_mute_icon;
	lv_obj_t *weather;
	bool weather_del;
	lv_obj_t *weather_img_bgCloud;
	lv_obj_t *weather_img_select;
	lv_obj_t *weather_img_dialDot;
	lv_obj_t *weather_label_city;
	lv_obj_t *weather_label_temp;
	lv_obj_t *weather_img_icon;
	lv_obj_t *weather_label_maxMin;
	lv_obj_t *weather_img_dot;
	lv_obj_t *weather_img_home;
	lv_obj_t *weather_hour;
	bool weather_hour_del;
	lv_obj_t *weather_hour_hour_list;
	lv_obj_t *weather_hour_cont_14;
	lv_obj_t *weather_hour_img_33;
	lv_obj_t *weather_hour_label_27;
	lv_obj_t *weather_hour_label_26;
	lv_obj_t *weather_hour_img_32;
	lv_obj_t *weather_hour_cont_13;
	lv_obj_t *weather_hour_img_31;
	lv_obj_t *weather_hour_label_25;
	lv_obj_t *weather_hour_label_24;
	lv_obj_t *weather_hour_cont_12;
	lv_obj_t *weather_hour_img_30;
	lv_obj_t *weather_hour_label_23;
	lv_obj_t *weather_hour_label_22;
	lv_obj_t *weather_hour_cont_11;
	lv_obj_t *weather_hour_img_29;
	lv_obj_t *weather_hour_label_21;
	lv_obj_t *weather_hour_label_20;
	lv_obj_t *weather_hour_img_28;
	lv_obj_t *weather_hour_img_27;
	lv_obj_t *weather_hour_cont_10;
	lv_obj_t *weather_hour_img_26;
	lv_obj_t *weather_hour_label_19;
	lv_obj_t *weather_hour_label_18;
	lv_obj_t *weather_hour_cont_9;
	lv_obj_t *weather_hour_img_25;
	lv_obj_t *weather_hour_label_17;
	lv_obj_t *weather_hour_label_16;
	lv_obj_t *weather_hour_img_24;
	lv_obj_t *weather_hour_img_23;
	lv_obj_t *weather_hour_home;
	lv_obj_t *weather_hour_select_icon;
	lv_obj_t *weather_hour_title;
	lv_obj_t *weather_hour_left;
	lv_obj_t *weather_hour_right;
	lv_obj_t *weather_week;
	bool weather_week_del;
	lv_obj_t *weather_week_week_list;
	lv_obj_t *weather_week_cont_14;
	lv_obj_t *weather_week_img_33;
	lv_obj_t *weather_week_label_27;
	lv_obj_t *weather_week_label_26;
	lv_obj_t *weather_week_img_32;
	lv_obj_t *weather_week_cont_13;
	lv_obj_t *weather_week_img_31;
	lv_obj_t *weather_week_label_25;
	lv_obj_t *weather_week_label_24;
	lv_obj_t *weather_week_cont_12;
	lv_obj_t *weather_week_img_30;
	lv_obj_t *weather_week_label_23;
	lv_obj_t *weather_week_label_22;
	lv_obj_t *weather_week_cont_11;
	lv_obj_t *weather_week_img_29;
	lv_obj_t *weather_week_label_21;
	lv_obj_t *weather_week_label_20;
	lv_obj_t *weather_week_img_28;
	lv_obj_t *weather_week_img_27;
	lv_obj_t *weather_week_cont_10;
	lv_obj_t *weather_week_img_26;
	lv_obj_t *weather_week_label_19;
	lv_obj_t *weather_week_label_18;
	lv_obj_t *weather_week_cont_9;
	lv_obj_t *weather_week_img_25;
	lv_obj_t *weather_week_label_17;
	lv_obj_t *weather_week_label_16;
	lv_obj_t *weather_week_img_24;
	lv_obj_t *weather_week_img_23;
	lv_obj_t *weather_week_home;
	lv_obj_t *weather_week_select_icon;
	lv_obj_t *weather_week_week_title;
	lv_obj_t *weather_week_left;
	lv_obj_t *weather_week_right;
	lv_obj_t *air_quality;
	bool air_quality_del;
	lv_obj_t *air_quality_home;
	lv_obj_t *air_quality_select_icon;
	lv_obj_t *air_quality_air_title;
	lv_obj_t *air_quality_left;
	lv_obj_t *air_quality_airList_2;
	lv_obj_t *air_quality_line_12;
	lv_obj_t *air_quality_line_11;
	lv_obj_t *air_quality_line_10;
	lv_obj_t *air_quality_label_38;
	lv_obj_t *air_quality_label_37;
	lv_obj_t *air_quality_label_36;
	lv_obj_t *air_quality_label_35;
	lv_obj_t *air_quality_label_34;
	lv_obj_t *air_quality_label_33;
	lv_obj_t *air_quality_label_32;
	lv_obj_t *air_quality_label_31;
	lv_obj_t *air_quality_label_30;
	lv_obj_t *air_quality_airList_1;
	lv_obj_t *air_quality_line_9;
	lv_obj_t *air_quality_line_8;
	lv_obj_t *air_quality_line_7;
	lv_obj_t *air_quality_label_29;
	lv_obj_t *air_quality_label_28;
	lv_obj_t *air_quality_label_27;
	lv_obj_t *air_quality_label_26;
	lv_obj_t *air_quality_label_25;
	lv_obj_t *air_quality_label_24;
	lv_obj_t *air_quality_label_23;
	lv_obj_t *air_quality_label_22;
	lv_obj_t *air_quality_label_21;
	lv_obj_t *air_quality_ade_text;
	lv_obj_t *fitness;
	bool fitness_del;
	lv_obj_t *fitness_home;
	lv_obj_t *fitness_start_icon;
	lv_obj_t *fitness_title;
	lv_obj_t *fitness_calorie_arc;
	lv_obj_t *fitness_distance_arc;
	lv_obj_t *fitness_duration_arc;
	lv_obj_t *fitness_pluse_arc;
	lv_obj_t *fitness_pluse_icon;
	lv_obj_t *fitness_pulse_text;
	lv_obj_t *fitness_pulse_value;
	lv_obj_t *fitness_duration_icon;
	lv_obj_t *fitness_distance_value;
	lv_obj_t *fitness_duration_text;
	lv_obj_t *fitness_distance_icon;
	lv_obj_t *fitness_duration_value;
	lv_obj_t *fitness_distance_text;
	lv_obj_t *fitness_calorie_icon;
	lv_obj_t *fitness_calorie_value;
	lv_obj_t *fitness_calorie_text;
	lv_obj_t *fitness_img_menu;
	lv_obj_t *fitness_img_dot;
	lv_obj_t *music_player;
	bool music_player_del;
	lv_obj_t *music_player_arc_2;
	lv_obj_t *music_player_arc_1;
	lv_obj_t *music_player_img_volume;
	lv_obj_t *music_player_img_home;
	lv_obj_t *music_player_icon_home;
	lv_obj_t *music_player_singer;
	lv_obj_t *music_player_img_next;
	lv_obj_t *music_player_img_previous;
	lv_obj_t *music_player_song_name;
	lv_obj_t *music_player_duration;
	lv_obj_t *music_player_mode;
	lv_obj_t *music_player_btn_background;
	lv_obj_t *music_player_btn_background_label;
	lv_obj_t *music_player_img_puse;
	lv_obj_t *music_player_img_play;
	lv_obj_t *music_player_img_dot;
	lv_obj_t *music_player_img_menu;
	lv_obj_t *flight;
	bool flight_del;
	lv_obj_t *flight_home;
	lv_obj_t *flight_title;
	lv_obj_t *flight_flight_icon;
	lv_obj_t *flight_departure_time;
	lv_obj_t *flight_departure_date;
	lv_obj_t *flight_arrival_time;
	lv_obj_t *flight_flight_number;
	lv_obj_t *flight_arrival_date;
	lv_obj_t *flight_flight_seat;
	lv_obj_t *flight_label_13;
	lv_obj_t *flight_label_11;
	lv_obj_t *flight_img_2;
	lv_obj_t *flight_label_14;
	lv_obj_t *flight_label_12;
	lv_obj_t *flight_flight_location;
	lv_obj_t *flight_label_3;
	lv_obj_t *flight_label_1;
	lv_obj_t *flight_label_5;
	lv_obj_t *flight_label_4;
	lv_obj_t *flight_img_dot;
	lv_obj_t *flight_img_menu;
	lv_obj_t *flight_info;
	bool flight_info_del;
	lv_obj_t *flight_info_home;
	lv_obj_t *flight_info_title;
	lv_obj_t *flight_info_number_text;
	lv_obj_t *flight_info_flight_number;
	lv_obj_t *flight_info_left;
	lv_obj_t *flight_info_right;
	lv_obj_t *flight_info_gate_number;
	lv_obj_t *flight_info_gate_text;
	lv_obj_t *flight_info_seat_text;
	lv_obj_t *flight_info_seat_number;
	lv_obj_t *flight_info_qrcode;
	lv_obj_t *navigation;
	bool navigation_del;
	lv_obj_t *navigation_home;
	lv_obj_t *navigation_title;
	lv_obj_t *navigation_next_roadName;
	lv_obj_t *navigation_road_name;
	lv_obj_t *navigation_distance;
	lv_obj_t *navigation_distance_text;
	lv_obj_t *navigation_take_time_text;
	lv_obj_t *navigation_nav_icon;
	lv_obj_t *navigation_km_text;
	lv_obj_t *navigation_take_time;
	lv_obj_t *navigation_mins_text;
	lv_obj_t *navigation_indicator;
	lv_obj_t *navigation_label_4;
	lv_obj_t *navigation_label_5;
	lv_obj_t *navigation_img_dot;
	lv_obj_t *navigation_img_menu;
	lv_obj_t *position;
	bool position_del;
	lv_obj_t *position_home;
	lv_obj_t *position_title;
	lv_obj_t *position_location_icon;
	lv_obj_t *position_location_icon_label;
	lv_obj_t *position_bottom;
	lv_obj_t *position_label_1;
	lv_obj_t *position_img_1;
	lv_obj_t *position_left;
	lv_obj_t *position_right;
	lv_obj_t *payment;
	bool payment_del;
	lv_obj_t *payment_home;
	lv_obj_t *payment_title;
	lv_obj_t *payment_next_buy;
	lv_obj_t *payment_amount;
	lv_obj_t *payment_card_icon;
	lv_obj_t *payment_bank_info;
	lv_obj_t *payment_label_7;
	lv_obj_t *payment_label_6;
	lv_obj_t *payment_tail_number;
	lv_obj_t *payment_expiry_date;
	lv_obj_t *payment_img_dot;
	lv_obj_t *payment_img_menu;
	lv_obj_t *payment_img_select;
	lv_obj_t *payment_info;
	bool payment_info_del;
	lv_obj_t *payment_info_home;
	lv_obj_t *payment_info_title;
	lv_obj_t *payment_info_complete_icon;
	lv_obj_t *payment_info_pay_info;
	lv_obj_t *payment_info_label_11;
	lv_obj_t *payment_info_label_10;
	lv_obj_t *payment_info_label_12;
	lv_obj_t *payment_info_left;
	lv_obj_t *payment_info_right;
	lv_obj_t *settings;
	bool settings_del;
	lv_obj_t *settings_title;
	lv_obj_t *settings_setting_info;
	lv_obj_t *settings_label_1;
	lv_obj_t *settings_label_2;
	lv_obj_t *settings_label_3;
	lv_obj_t *settings_label_4;
	lv_obj_t *settings_label_5;
	lv_obj_t *settings_img_dot;
	lv_obj_t *settings_img_menu;
	lv_obj_t *settings_img_select;
	lv_obj_t *settings_home;
	lv_obj_t *battery;
	bool battery_del;
	lv_obj_t *battery_title;
	lv_obj_t *battery_setting_info;
	lv_obj_t *battery_label_10;
	lv_obj_t *battery_label_11;
	lv_obj_t *battery_img_1;
	lv_obj_t *battery_label_12;
	lv_obj_t *battery_img_2;
	lv_obj_t *battery_bar_1;
	lv_obj_t *battery_label_13;
	lv_obj_t *battery_img_3;
	lv_obj_t *battery_bar_2;
	lv_obj_t *battery_label_14;
	lv_obj_t *battery_label_15;
	lv_obj_t *battery_label_16;
	lv_obj_t *battery_right;
	lv_obj_t *battery_left;
	lv_obj_t *battery_home;
	lv_obj_t *info;
	bool info_del;
	lv_obj_t *info_title;
	lv_obj_t *info_setting_info;
	lv_obj_t *info_label_11;
	lv_obj_t *info_label_10;
	lv_obj_t *info_label_9;
	lv_obj_t *info_label_8;
	lv_obj_t *info_label_7;
	lv_obj_t *info_label_6;
	lv_obj_t *info_label_5;
	lv_obj_t *info_label_4;
	lv_obj_t *info_label_3;
	lv_obj_t *info_label_2;
	lv_obj_t *info_label_1;
	lv_obj_t *info_right;
	lv_obj_t *info_left;
	lv_obj_t *info_home;
	lv_obj_t *find_device;
	bool find_device_del;
	lv_obj_t *find_device_title;
	lv_obj_t *find_device_right;
	lv_obj_t *find_device_left;
	lv_obj_t *find_device_home;
	lv_obj_t *find_device_img_find;
	lv_obj_t *find_device_btn_start;
	lv_obj_t *find_device_btn_start_label;
	lv_obj_t *play_sound;
	bool play_sound_del;
	lv_obj_t *play_sound_right;
	lv_obj_t *play_sound_left;
	lv_obj_t *play_sound_home;
	lv_obj_t *play_sound_img_find;
	lv_obj_t *play_sound_btn_cancel;
	lv_obj_t *play_sound_btn_cancel_label;
	lv_obj_t *play_sound_title;
	lv_obj_t *blood_oxygen;
	bool blood_oxygen_del;
	lv_obj_t *blood_oxygen_arc_blood;
	lv_obj_t *blood_oxygen_home;
	lv_obj_t *blood_oxygen_title;
	lv_obj_t *blood_oxygen_label_blood;
	lv_obj_t *blood_oxygen_label_ago;
	lv_obj_t *blood_oxygen_water_icon;
	lv_obj_t *blood_oxygen_label_percentage;
	lv_obj_t *blood_oxygen_img_menu;
	lv_obj_t *blood_oxygen_img_dot;
	lv_obj_t *ekg;
	bool ekg_del;
	lv_obj_t *ekg_home;
	lv_obj_t *ekg_title;
	lv_obj_t *ekg_cont_1;
	lv_obj_t *ekg_label_bmp;
	lv_obj_t *ekg_label_pulse;
	lv_obj_t *ekg_img_healthy;
	lv_obj_t *ekg_cont_2;
	lv_obj_t *ekg_img_2;
	lv_obj_t *ekg_img_3;
	lv_obj_t *ekg_img_4;
	lv_obj_t *ekg_img_5;
	lv_obj_t *ekg_label_RR_text;
	lv_obj_t *ekg_label_count_text;
	lv_obj_t *ekg_label_RR_interval;
	lv_obj_t *ekg_label_count;
	lv_obj_t *stress_level;
	bool stress_level_del;
	lv_obj_t *stress_level_arc_stress;
	lv_obj_t *stress_level_home;
	lv_obj_t *stress_level_title;
	lv_obj_t *stress_level_label_ago;
	lv_obj_t *stress_level_stress_icon;
	lv_obj_t *stress_level_label_average;
	lv_obj_t *stress_level_img_2;
	lv_obj_t *stress_level_img_1;
	lv_obj_t *blood_pressure;
	bool blood_pressure_del;
	lv_obj_t *blood_pressure_arc_stress;
	lv_obj_t *blood_pressure_home;
	lv_obj_t *blood_pressure_title;
	lv_obj_t *blood_pressure_label_ago;
	lv_obj_t *blood_pressure_left;
	lv_obj_t *blood_pressure_right;
	lv_obj_t *blood_pressure_label_sys;
	lv_obj_t *blood_pressure_label_smmhg;
	lv_obj_t *blood_pressure_label_dmmhg;
	lv_obj_t *blood_pressure_label_dia;
	lv_obj_t *blood_pressure_cont_1;
	lv_obj_t *blood_pressure_label_bpm;
	lv_obj_t *blood_pressure_label_bpm_text;
	lv_obj_t *blood_pressure_icon_heart;
	lv_obj_t *sleep;
	bool sleep_del;
	lv_obj_t *sleep_home;
	lv_obj_t *sleep_title;
	lv_obj_t *sleep_left;
	lv_obj_t *sleep_right;
	lv_obj_t *sleep_cont_1;
	lv_obj_t *sleep_label_time;
	lv_obj_t *sleep_label_today;
	lv_obj_t *sleep_img_stages;
	lv_obj_t *sleep_label_stages;
	lv_obj_t *step;
	bool step_del;
	lv_obj_t *step_arc_step;
	lv_obj_t *step_home;
	lv_obj_t *step_label_current_steps;
	lv_obj_t *step_left;
	lv_obj_t *step_right;
	lv_obj_t *step_title;
	lv_obj_t *step_cont_1;
	lv_obj_t *step_label_goals_steps;
	lv_obj_t *step_label_goal;
	lv_obj_t *step_icon_step;
	lv_obj_t *menstrual;
	bool menstrual_del;
	lv_obj_t *menstrual_home;
	lv_obj_t *menstrual_left;
	lv_obj_t *menstrual_right;
	lv_obj_t *menstrual_title;
	lv_obj_t *menstrual_img_ovulation;
	lv_obj_t *menstrual_label_ovulation;
	lv_obj_t *menstrual_label_cycle;
	lv_obj_t *menstrual_label_days;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;

void setup_scr_home_analog(lv_ui *ui);
void setup_scr_home_digital(lv_ui *ui);
void setup_scr_message_info(lv_ui *ui);
void setup_scr_message_list(lv_ui *ui);
void setup_scr_standup(lv_ui *ui);
void setup_scr_car_lock(lv_ui *ui);
void setup_scr_car_start(lv_ui *ui);
void setup_scr_listening(lv_ui *ui);
void setup_scr_not_recognized(lv_ui *ui);
void setup_scr_recognized(lv_ui *ui);
void setup_scr_contact_list(lv_ui *ui);
void setup_scr_call(lv_ui *ui);
void setup_scr_weather(lv_ui *ui);
void setup_scr_weather_hour(lv_ui *ui);
void setup_scr_weather_week(lv_ui *ui);
void setup_scr_air_quality(lv_ui *ui);
void setup_scr_fitness(lv_ui *ui);
void setup_scr_music_player(lv_ui *ui);
void setup_scr_flight(lv_ui *ui);
void setup_scr_flight_info(lv_ui *ui);
void setup_scr_navigation(lv_ui *ui);
void setup_scr_position(lv_ui *ui);
void setup_scr_payment(lv_ui *ui);
void setup_scr_payment_info(lv_ui *ui);
void setup_scr_settings(lv_ui *ui);
void setup_scr_battery(lv_ui *ui);
void setup_scr_info(lv_ui *ui);
void setup_scr_find_device(lv_ui *ui);
void setup_scr_play_sound(lv_ui *ui);
void setup_scr_blood_oxygen(lv_ui *ui);
void setup_scr_ekg(lv_ui *ui);
void setup_scr_stress_level(lv_ui *ui);
void setup_scr_blood_pressure(lv_ui *ui);
void setup_scr_sleep(lv_ui *ui);
void setup_scr_step(lv_ui *ui);
void setup_scr_menstrual(lv_ui *ui);

LV_IMG_DECLARE(_img_bg_analog_240x240);
LV_IMG_DECLARE(_img_clockwise_hour_alpha_18x98);
LV_IMG_DECLARE(_img_clockwise_min_alpha_18x157);
LV_IMG_DECLARE(_img_clockwise_sec_alpha_31x180);
LV_IMG_DECLARE(_icn_sport_alpha_12x24);
LV_IMG_DECLARE(_img_nxp_alpha_65x20);
LV_IMG_DECLARE(_icn_step_red_alpha_17x21);
LV_IMG_DECLARE(_icn_weather_1_alpha_41x33);
LV_IMG_DECLARE(_text_sport_alpha_50x50);
LV_IMG_DECLARE(_icn_message_alpha_25x25);
LV_IMG_DECLARE(_icn_flash_blue_alpha_17x21);
LV_IMG_DECLARE(_img_menu_alpha_11x117);
LV_IMG_DECLARE(_text_message_alpha_70x70);
LV_IMG_DECLARE(_dot_alpha_8x8);

LV_IMG_DECLARE(_img_bg_digital_240x240);
LV_IMG_DECLARE(_img_nxp_alpha_65x20);
LV_IMG_DECLARE(_icn_step_red_alpha_17x21);
LV_IMG_DECLARE(_icn_flash_blue_alpha_17x21);
LV_IMG_DECLARE(_img_menu_alpha_11x117);
LV_IMG_DECLARE(_icn_message_alpha_25x25);
LV_IMG_DECLARE(_icn_sport_alpha_12x24);
LV_IMG_DECLARE(_icn_weather_1_alpha_41x33);
LV_IMG_DECLARE(_text_sport_alpha_50x50);
LV_IMG_DECLARE(_text_message_alpha_70x70);
LV_IMG_DECLARE(_dot_alpha_8x8);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_icn_whatsapp_alpha_60x60);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_img_arrow_right_alpha_9x32);
LV_IMG_DECLARE(_text_home_alpha_36x48);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_icn_insta_alpha_36x36);
LV_IMG_DECLARE(_icn_whatsapp_alpha_39x39);
LV_IMG_DECLARE(_img_line_2_alpha_250x2);
LV_IMG_DECLARE(_img_line_1_alpha_232x2);
LV_IMG_DECLARE(_icn_insta_alpha_36x36);
LV_IMG_DECLARE(_text_home_alpha_36x48);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_img_arrow_right_alpha_9x32);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_img_stand_up_alpha_84x84);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_img_arrow_right_alpha_9x32);
LV_IMG_DECLARE(_text_home_alpha_36x48);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_img_car_alpha_84x84);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_img_arrow_right_alpha_9x32);
LV_IMG_DECLARE(_text_home_alpha_36x48);
LV_IMG_DECLARE(_img_car_lock_2_alpha_63x56);
LV_IMG_DECLARE(_img_car_lock_1_alpha_117x89);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_img_car_alpha_84x84);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_img_arrow_right_alpha_9x32);
LV_IMG_DECLARE(_text_home_alpha_36x48);
LV_IMG_DECLARE(_img_red_btn_alpha_184x184);
LV_IMG_DECLARE(_img_green_btn_alpha_184x184);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_img_arrow_right_alpha_9x32);
LV_IMG_DECLARE(_text_home_alpha_36x48);
LV_IMG_DECLARE(_img_mic_1_alpha_190x195);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_img_arrow_right_alpha_9x32);
LV_IMG_DECLARE(_text_home_alpha_36x48);
LV_IMG_DECLARE(_img_mic_2_alpha_190x195);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_text_home_alpha_36x48);
LV_IMG_DECLARE(_img_mic_3_alpha_190x195);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_img_avatar_1_alpha_61x61);
LV_IMG_DECLARE(_img_avatar_2_alpha_61x61);
LV_IMG_DECLARE(_img_avatar_3_alpha_61x61);
LV_IMG_DECLARE(_img_avatar_4_alpha_61x59);
LV_IMG_DECLARE(_text_home_alpha_38x49);
LV_IMG_DECLARE(_text_favorites_alpha_56x78);

LV_IMG_DECLARE(_img_header_bg_392x75);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_text_volume_alpha_27x73);
LV_IMG_DECLARE(_img_call_erica_alpha_392x251);
LV_IMG_DECLARE(_text_home_alpha_36x48);
LV_IMG_DECLARE(_icn_home_alpha_26x23);
LV_IMG_DECLARE(_text_endcall_alpha_26x34);
LV_IMG_DECLARE(_icn_phone_alpha_26x20);
LV_IMG_DECLARE(_icn_unmute_alpha_32x32);
LV_IMG_DECLARE(_icn_mute_alpha_32x32);

LV_IMG_DECLARE(_img_sun_240x240);
LV_IMG_DECLARE(_img_cloud_alpha_586x392);
LV_IMG_DECLARE(_text_select_alpha_43x57);
LV_IMG_DECLARE(_img_menu_alpha_11x117);
LV_IMG_DECLARE(_icn_big_weather_cloud_alpha_66x50);
LV_IMG_DECLARE(_dot_alpha_8x8);
LV_IMG_DECLARE(_text_home_alpha_36x48);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_icn_small_weather_1_alpha_42x32);
LV_IMG_DECLARE(_img_line_2_alpha_279x2);
LV_IMG_DECLARE(_icn_small_weather_2_alpha_41x38);
LV_IMG_DECLARE(_icn_small_weather_2_alpha_41x38);
LV_IMG_DECLARE(_icn_small_weather_2_alpha_41x38);
LV_IMG_DECLARE(_img_line_2_alpha_279x2);
LV_IMG_DECLARE(_img_line_2_alpha_279x2);
LV_IMG_DECLARE(_icn_small_weather_1_alpha_42x32);
LV_IMG_DECLARE(_icn_small_weather_1_alpha_42x32);
LV_IMG_DECLARE(_img_line_2_alpha_279x2);
LV_IMG_DECLARE(_img_line_2_alpha_279x2);
LV_IMG_DECLARE(_text_home_alpha_36x48);
LV_IMG_DECLARE(_text_select_alpha_43x57);

LV_IMG_DECLARE(_img_header_bg_392x75);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_img_arrow_right_alpha_9x32);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_icn_small_weather_3_alpha_30x32);
LV_IMG_DECLARE(_img_line_2_alpha_279x2);
LV_IMG_DECLARE(_icn_small_weather_1_alpha_42x32);
LV_IMG_DECLARE(_icn_small_weather_2_alpha_41x38);
LV_IMG_DECLARE(_icn_small_weather_1_alpha_42x32);
LV_IMG_DECLARE(_img_line_2_alpha_279x2);
LV_IMG_DECLARE(_img_line_2_alpha_279x2);
LV_IMG_DECLARE(_icn_small_weather_3_alpha_30x32);
LV_IMG_DECLARE(_icn_small_weather_1_alpha_42x32);
LV_IMG_DECLARE(_img_line_2_alpha_279x2);
LV_IMG_DECLARE(_img_line_2_alpha_279x2);
LV_IMG_DECLARE(_text_home_alpha_36x48);
LV_IMG_DECLARE(_text_select_alpha_43x57);

LV_IMG_DECLARE(_img_header_bg_392x75);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_img_arrow_right_alpha_9x32);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_text_home_alpha_36x48);
LV_IMG_DECLARE(_text_select_alpha_43x57);

LV_IMG_DECLARE(_img_header_bg_392x75);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_text_home_alpha_36x48);
LV_IMG_DECLARE(_text_start_stop_alpha_43x57);

LV_IMG_DECLARE(_img_header_bg_392x75);
LV_IMG_DECLARE(_icn_small_pulse_alpha_25x22);
LV_IMG_DECLARE(_icn_small_time_alpha_25x25);
LV_IMG_DECLARE(_icn_small_pos_alpha_19x25);
LV_IMG_DECLARE(_icn_small_burn_alpha_21x24);
LV_IMG_DECLARE(_img_menu_alpha_11x100);
LV_IMG_DECLARE(_dot_alpha_8x8);

LV_IMG_DECLARE(_img_audio_album_240x240);
LV_IMG_DECLARE(_text_volume_alpha_27x71);
LV_IMG_DECLARE(_text_home_alpha_36x48);
LV_IMG_DECLARE(_icn_home_alpha_26x24);
LV_IMG_DECLARE(_icn_audio_next_alpha_17x26);
LV_IMG_DECLARE(_icn_audio_back_alpha_17x26);
LV_IMG_DECLARE(_icn_audio_rnd_alpha_33x29);
LV_IMG_DECLARE(_img_pause_alpha_24x38);
LV_IMG_DECLARE(_icn_audio_play_alpha_40x48);
LV_IMG_DECLARE(_dot_alpha_8x8);
LV_IMG_DECLARE(_img_menu_alpha_11x100);

LV_IMG_DECLARE(_img_bg_travel_240x240);
LV_IMG_DECLARE(_text_home_alpha_36x48);

LV_IMG_DECLARE(_img_header_bg_392x75);
LV_IMG_DECLARE(_img_plane_2_alpha_335x48);
LV_IMG_DECLARE(_img_line_3_alpha_2x87);
LV_IMG_DECLARE(_dot_alpha_8x8);
LV_IMG_DECLARE(_img_menu_alpha_11x100);

LV_IMG_DECLARE(_img_bg_travel_240x240);
LV_IMG_DECLARE(_text_home_alpha_36x48);

LV_IMG_DECLARE(_img_header_bg_392x75);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_img_arrow_right_alpha_9x32);
LV_IMG_DECLARE(_img_qr_code_alpha_207x243);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_text_home_alpha_36x48);

LV_IMG_DECLARE(_img_header_bg_392x75);
LV_IMG_DECLARE(_img_nav_1_alpha_107x122);
LV_IMG_DECLARE(_dot_alpha_8x8);
LV_IMG_DECLARE(_img_menu_alpha_11x100);

LV_IMG_DECLARE(_img_map_240x240);
LV_IMG_DECLARE(_text_home_alpha_36x48);

LV_IMG_DECLARE(_img_header_bg_392x75);
LV_IMG_DECLARE(_img_small_nav_1_alpha_34x38);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_img_arrow_right_alpha_9x32);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_text_home_alpha_36x48);

LV_IMG_DECLARE(_img_header_bg_392x75);
LV_IMG_DECLARE(_img_card_1_alpha_266x167);
LV_IMG_DECLARE(_dot_alpha_8x8);
LV_IMG_DECLARE(_img_menu_alpha_11x100);
LV_IMG_DECLARE(_text_select_alpha_43x57);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_text_home_alpha_36x48);

LV_IMG_DECLARE(_img_header_bg_392x75);
LV_IMG_DECLARE(_img_payment_ok_alpha_126x125);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_img_arrow_right_alpha_9x32);

LV_IMG_DECLARE(_img_bg_2_240x240);

LV_IMG_DECLARE(_img_header_bg_392x75);
LV_IMG_DECLARE(_dot_alpha_8x8);
LV_IMG_DECLARE(_img_menu_alpha_11x100);
LV_IMG_DECLARE(_text_select_alpha_43x57);
LV_IMG_DECLARE(_text_home_alpha_36x48);

LV_IMG_DECLARE(_img_bg_2_240x240);

LV_IMG_DECLARE(_img_header_bg_392x75);
LV_IMG_DECLARE(_img_chart_battery_alpha_323x83);
LV_IMG_DECLARE(_icn_fitness_alpha_40x40);
LV_IMG_DECLARE(_icn_travel_alpha_40x40);
LV_IMG_DECLARE(_img_arrow_right_alpha_9x32);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_text_home_alpha_36x48);

LV_IMG_DECLARE(_img_bg_2_240x240);

LV_IMG_DECLARE(_img_header_bg_392x75);
LV_IMG_DECLARE(_img_arrow_right_alpha_9x32);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_text_home_alpha_36x48);

LV_IMG_DECLARE(_img_bg_2_240x240);

LV_IMG_DECLARE(_img_header_bg_392x75);
LV_IMG_DECLARE(_img_arrow_right_alpha_9x32);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_text_home_alpha_36x48);
LV_IMG_DECLARE(_img_find_device_alpha_116x114);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_img_arrow_right_alpha_9x32);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_text_home_alpha_36x48);
LV_IMG_DECLARE(_img_find_device2_alpha_168x168);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_text_home_alpha_36x48);

LV_IMG_DECLARE(_img_header_bg_392x75);
LV_IMG_DECLARE(_icn_water_alpha_32x44);
LV_IMG_DECLARE(_img_menu_alpha_11x100);
LV_IMG_DECLARE(_dot_alpha_8x8);

LV_IMG_DECLARE(_img_bg_health_240x240);
LV_IMG_DECLARE(_text_home_alpha_36x48);

LV_IMG_DECLARE(_img_header_bg_392x75);
LV_IMG_DECLARE(_img_heart_alpha_51x43);
LV_IMG_DECLARE(_img_ekg_alpha_128x113);
LV_IMG_DECLARE(_img_ekg_alpha_128x113);
LV_IMG_DECLARE(_img_ekg_alpha_128x113);
LV_IMG_DECLARE(_img_ekg_alpha_128x113);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_text_home_alpha_36x48);

LV_IMG_DECLARE(_img_header_bg_392x75);
LV_IMG_DECLARE(_img_stress_level_alpha_67x105);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_img_arrow_right_alpha_9x32);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_text_home_alpha_36x48);

LV_IMG_DECLARE(_img_header_bg_392x75);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_img_arrow_right_alpha_9x32);
LV_IMG_DECLARE(_icn_heart_alpha_28x24);

LV_IMG_DECLARE(_img_bg_health_240x240);
LV_IMG_DECLARE(_text_home_alpha_36x48);

LV_IMG_DECLARE(_img_header_bg_392x75);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_img_arrow_right_alpha_9x32);
LV_IMG_DECLARE(_img_chart_sleep_alpha_336x135);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_text_home_alpha_36x48);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_img_arrow_right_alpha_9x32);

LV_IMG_DECLARE(_img_header_bg_392x75);
LV_IMG_DECLARE(_img_step_small_alpha_28x45);

LV_IMG_DECLARE(_img_bg_2_240x240);
LV_IMG_DECLARE(_text_home_alpha_36x48);
LV_IMG_DECLARE(_img_arrow_left_alpha_9x32);
LV_IMG_DECLARE(_img_arrow_right_alpha_9x32);

LV_IMG_DECLARE(_img_header_bg_392x75);
LV_IMG_DECLARE(_img_menstrual_chart_alpha_221x227);

LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_22)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_110)
LV_FONT_DECLARE(lv_font_montserratMedium_120)
LV_FONT_DECLARE(lv_font_montserratMedium_26)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_montserratMedium_30)
LV_FONT_DECLARE(lv_font_montserratMedium_24)
LV_FONT_DECLARE(lv_font_montserratMedium_40)
LV_FONT_DECLARE(lv_font_montserratMedium_150)
LV_FONT_DECLARE(lv_font_montserratMedium_18)
LV_FONT_DECLARE(lv_font_montserratMedium_100)


#ifdef __cplusplus
}
#endif
#endif
