/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"


static void home_analog_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: home_analog_nxp_log move_x
	  	lv_anim_t home_analog_nxp_log_anim_move_x;
	  	lv_anim_init(&home_analog_nxp_log_anim_move_x);
	  	lv_anim_set_var(&home_analog_nxp_log_anim_move_x, guider_ui.home_analog_nxp_log);
	  	lv_anim_set_time(&home_analog_nxp_log_anim_move_x, 800);
	  	lv_anim_set_delay(&home_analog_nxp_log_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&home_analog_nxp_log_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&home_analog_nxp_log_anim_move_x, lv_obj_get_x(guider_ui.home_analog_nxp_log), 291);
	  	lv_anim_set_path_cb(&home_analog_nxp_log_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&home_analog_nxp_log_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&home_analog_nxp_log_anim_move_x, 0);
	  	lv_anim_set_playback_time(&home_analog_nxp_log_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&home_analog_nxp_log_anim_move_x, 0);
		lv_anim_start(&home_analog_nxp_log_anim_move_x);
		//Write animation: home_analog_nxp_log move_y
	  	lv_anim_t home_analog_nxp_log_anim_move_y;
	  	lv_anim_init(&home_analog_nxp_log_anim_move_y);
	  	lv_anim_set_var(&home_analog_nxp_log_anim_move_y, guider_ui.home_analog_nxp_log);
	  	lv_anim_set_time(&home_analog_nxp_log_anim_move_y, 800);
	  	lv_anim_set_delay(&home_analog_nxp_log_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&home_analog_nxp_log_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&home_analog_nxp_log_anim_move_y, lv_obj_get_y(guider_ui.home_analog_nxp_log), 175);
	  	lv_anim_set_path_cb(&home_analog_nxp_log_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&home_analog_nxp_log_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&home_analog_nxp_log_anim_move_y, 0);
	  	lv_anim_set_playback_time(&home_analog_nxp_log_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&home_analog_nxp_log_anim_move_y, 0);
		lv_anim_start(&home_analog_nxp_log_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.home_digital_del == true) {
			          setup_scr_home_digital(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.home_digital, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.home_analog_del = true;
			    }
				if (guider_ui.home_analog_del)
			        guider_ui.home_analog_analog_clock_1 = NULL;
				break;
			}
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.contact_list_del == true) {
			          setup_scr_contact_list(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.contact_list, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.home_analog_del = true;
			    }
				if (guider_ui.home_analog_del)
			        guider_ui.home_analog_analog_clock_1 = NULL;
				break;
			}
			case LV_DIR_TOP:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.weather_del == true) {
			          setup_scr_weather(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.weather, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.home_analog_del = true;
			    }
				if (guider_ui.home_analog_del)
			        guider_ui.home_analog_analog_clock_1 = NULL;
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void home_analog_weather_icon_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.weather_del == true) {
	          setup_scr_weather(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.weather, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.home_analog_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void home_analog_sport_text_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.fitness_del == true) {
	          setup_scr_fitness(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.fitness, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.home_analog_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void home_analog_battery_text_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.battery_del == true) {
	          setup_scr_battery(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.battery, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.home_analog_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void home_analog_message_text_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.message_info_del == true) {
	          setup_scr_message_info(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.message_info, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.home_analog_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_home_analog(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->home_analog, home_analog_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->home_analog_weather_icon, home_analog_weather_icon_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->home_analog_sport_text, home_analog_sport_text_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->home_analog_battery_text, home_analog_battery_text_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->home_analog_message_text, home_analog_message_text_event_handler, LV_EVENT_ALL, NULL);
}
static void home_digital_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: home_digital_img_nxpLogo move_x
	  	lv_anim_t home_digital_img_nxpLogo_anim_move_x;
	  	lv_anim_init(&home_digital_img_nxpLogo_anim_move_x);
	  	lv_anim_set_var(&home_digital_img_nxpLogo_anim_move_x, guider_ui.home_digital_img_nxpLogo);
	  	lv_anim_set_time(&home_digital_img_nxpLogo_anim_move_x, 800);
	  	lv_anim_set_delay(&home_digital_img_nxpLogo_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&home_digital_img_nxpLogo_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&home_digital_img_nxpLogo_anim_move_x, lv_obj_get_x(guider_ui.home_digital_img_nxpLogo), 291);
	  	lv_anim_set_path_cb(&home_digital_img_nxpLogo_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&home_digital_img_nxpLogo_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&home_digital_img_nxpLogo_anim_move_x, 0);
	  	lv_anim_set_playback_time(&home_digital_img_nxpLogo_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&home_digital_img_nxpLogo_anim_move_x, 0);
		lv_anim_start(&home_digital_img_nxpLogo_anim_move_x);
		//Write animation: home_digital_img_nxpLogo move_y
	  	lv_anim_t home_digital_img_nxpLogo_anim_move_y;
	  	lv_anim_init(&home_digital_img_nxpLogo_anim_move_y);
	  	lv_anim_set_var(&home_digital_img_nxpLogo_anim_move_y, guider_ui.home_digital_img_nxpLogo);
	  	lv_anim_set_time(&home_digital_img_nxpLogo_anim_move_y, 800);
	  	lv_anim_set_delay(&home_digital_img_nxpLogo_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&home_digital_img_nxpLogo_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&home_digital_img_nxpLogo_anim_move_y, lv_obj_get_y(guider_ui.home_digital_img_nxpLogo), 175);
	  	lv_anim_set_path_cb(&home_digital_img_nxpLogo_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&home_digital_img_nxpLogo_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&home_digital_img_nxpLogo_anim_move_y, 0);
	  	lv_anim_set_playback_time(&home_digital_img_nxpLogo_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&home_digital_img_nxpLogo_anim_move_y, 0);
		lv_anim_start(&home_digital_img_nxpLogo_anim_move_y);
		//Write animation: home_digital_label_min move_x
	  	lv_anim_t home_digital_label_min_anim_move_x;
	  	lv_anim_init(&home_digital_label_min_anim_move_x);
	  	lv_anim_set_var(&home_digital_label_min_anim_move_x, guider_ui.home_digital_label_min);
	  	lv_anim_set_time(&home_digital_label_min_anim_move_x, 800);
	  	lv_anim_set_delay(&home_digital_label_min_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&home_digital_label_min_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&home_digital_label_min_anim_move_x, lv_obj_get_x(guider_ui.home_digital_label_min), 145);
	  	lv_anim_set_path_cb(&home_digital_label_min_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&home_digital_label_min_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&home_digital_label_min_anim_move_x, 0);
	  	lv_anim_set_playback_time(&home_digital_label_min_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&home_digital_label_min_anim_move_x, 0);
		lv_anim_start(&home_digital_label_min_anim_move_x);
		//Write animation: home_digital_label_min move_y
	  	lv_anim_t home_digital_label_min_anim_move_y;
	  	lv_anim_init(&home_digital_label_min_anim_move_y);
	  	lv_anim_set_var(&home_digital_label_min_anim_move_y, guider_ui.home_digital_label_min);
	  	lv_anim_set_time(&home_digital_label_min_anim_move_y, 800);
	  	lv_anim_set_delay(&home_digital_label_min_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&home_digital_label_min_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&home_digital_label_min_anim_move_y, lv_obj_get_y(guider_ui.home_digital_label_min), 208);
	  	lv_anim_set_path_cb(&home_digital_label_min_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&home_digital_label_min_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&home_digital_label_min_anim_move_y, 0);
	  	lv_anim_set_playback_time(&home_digital_label_min_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&home_digital_label_min_anim_move_y, 0);
		lv_anim_start(&home_digital_label_min_anim_move_y);
		//Write animation: home_digital_label_hour move_x
	  	lv_anim_t home_digital_label_hour_anim_move_x;
	  	lv_anim_init(&home_digital_label_hour_anim_move_x);
	  	lv_anim_set_var(&home_digital_label_hour_anim_move_x, guider_ui.home_digital_label_hour);
	  	lv_anim_set_time(&home_digital_label_hour_anim_move_x, 800);
	  	lv_anim_set_delay(&home_digital_label_hour_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&home_digital_label_hour_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&home_digital_label_hour_anim_move_x, lv_obj_get_x(guider_ui.home_digital_label_hour), 143);
	  	lv_anim_set_path_cb(&home_digital_label_hour_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&home_digital_label_hour_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&home_digital_label_hour_anim_move_x, 0);
	  	lv_anim_set_playback_time(&home_digital_label_hour_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&home_digital_label_hour_anim_move_x, 0);
		lv_anim_start(&home_digital_label_hour_anim_move_x);
		//Write animation: home_digital_label_hour move_y
	  	lv_anim_t home_digital_label_hour_anim_move_y;
	  	lv_anim_init(&home_digital_label_hour_anim_move_y);
	  	lv_anim_set_var(&home_digital_label_hour_anim_move_y, guider_ui.home_digital_label_hour);
	  	lv_anim_set_time(&home_digital_label_hour_anim_move_y, 800);
	  	lv_anim_set_delay(&home_digital_label_hour_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&home_digital_label_hour_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&home_digital_label_hour_anim_move_y, lv_obj_get_y(guider_ui.home_digital_label_hour), 82);
	  	lv_anim_set_path_cb(&home_digital_label_hour_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&home_digital_label_hour_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&home_digital_label_hour_anim_move_y, 0);
	  	lv_anim_set_playback_time(&home_digital_label_hour_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&home_digital_label_hour_anim_move_y, 0);
		lv_anim_start(&home_digital_label_hour_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.message_info_del == true) {
			          setup_scr_message_info(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.message_info, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.home_digital_del = true;
			    }
				break;
			}
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.home_analog_del == true) {
			          setup_scr_home_analog(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.home_digital_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void home_digital_img_weather1Icon_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.weather_del == true) {
	          setup_scr_weather(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.weather, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.home_digital_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_home_digital(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->home_digital, home_digital_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->home_digital_img_weather1Icon, home_digital_img_weather1Icon_event_handler, LV_EVENT_ALL, NULL);
}
static void message_info_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: message_info_app_icon move_x
	  	lv_anim_t message_info_app_icon_anim_move_x;
	  	lv_anim_init(&message_info_app_icon_anim_move_x);
	  	lv_anim_set_var(&message_info_app_icon_anim_move_x, guider_ui.message_info_app_icon);
	  	lv_anim_set_time(&message_info_app_icon_anim_move_x, 800);
	  	lv_anim_set_delay(&message_info_app_icon_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&message_info_app_icon_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&message_info_app_icon_anim_move_x, lv_obj_get_x(guider_ui.message_info_app_icon), 166);
	  	lv_anim_set_path_cb(&message_info_app_icon_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&message_info_app_icon_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&message_info_app_icon_anim_move_x, 0);
	  	lv_anim_set_playback_time(&message_info_app_icon_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&message_info_app_icon_anim_move_x, 0);
		lv_anim_start(&message_info_app_icon_anim_move_x);
		//Write animation: message_info_app_icon move_y
	  	lv_anim_t message_info_app_icon_anim_move_y;
	  	lv_anim_init(&message_info_app_icon_anim_move_y);
	  	lv_anim_set_var(&message_info_app_icon_anim_move_y, guider_ui.message_info_app_icon);
	  	lv_anim_set_time(&message_info_app_icon_anim_move_y, 800);
	  	lv_anim_set_delay(&message_info_app_icon_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&message_info_app_icon_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&message_info_app_icon_anim_move_y, lv_obj_get_y(guider_ui.message_info_app_icon), 30);
	  	lv_anim_set_path_cb(&message_info_app_icon_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&message_info_app_icon_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&message_info_app_icon_anim_move_y, 0);
	  	lv_anim_set_playback_time(&message_info_app_icon_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&message_info_app_icon_anim_move_y, 0);
		lv_anim_start(&message_info_app_icon_anim_move_y);
		//Write animation: message_info_sender move_x
	  	lv_anim_t message_info_sender_anim_move_x;
	  	lv_anim_init(&message_info_sender_anim_move_x);
	  	lv_anim_set_var(&message_info_sender_anim_move_x, guider_ui.message_info_sender);
	  	lv_anim_set_time(&message_info_sender_anim_move_x, 800);
	  	lv_anim_set_delay(&message_info_sender_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&message_info_sender_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&message_info_sender_anim_move_x, lv_obj_get_x(guider_ui.message_info_sender), 151);
	  	lv_anim_set_path_cb(&message_info_sender_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&message_info_sender_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&message_info_sender_anim_move_x, 0);
	  	lv_anim_set_playback_time(&message_info_sender_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&message_info_sender_anim_move_x, 0);
		lv_anim_start(&message_info_sender_anim_move_x);
		//Write animation: message_info_sender move_y
	  	lv_anim_t message_info_sender_anim_move_y;
	  	lv_anim_init(&message_info_sender_anim_move_y);
	  	lv_anim_set_var(&message_info_sender_anim_move_y, guider_ui.message_info_sender);
	  	lv_anim_set_time(&message_info_sender_anim_move_y, 800);
	  	lv_anim_set_delay(&message_info_sender_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&message_info_sender_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&message_info_sender_anim_move_y, lv_obj_get_y(guider_ui.message_info_sender), 107);
	  	lv_anim_set_path_cb(&message_info_sender_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&message_info_sender_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&message_info_sender_anim_move_y, 0);
	  	lv_anim_set_playback_time(&message_info_sender_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&message_info_sender_anim_move_y, 0);
		lv_anim_start(&message_info_sender_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.message_list_del == true) {
			          setup_scr_message_list(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.message_list, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.message_info_del = true;
			    }
				break;
			}
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.home_analog_del == true) {
			          setup_scr_home_analog(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.message_info_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void message_info_left_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_digital_del == true) {
	          setup_scr_home_digital(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_digital, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.message_info_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void message_info_right_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.message_list_del == true) {
	          setup_scr_message_list(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.message_list, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.message_info_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void message_info_ok_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.message_info_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void message_info_home_text_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.message_info_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_message_info(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->message_info, message_info_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->message_info_left, message_info_left_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->message_info_right, message_info_right_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->message_info_ok_btn, message_info_ok_btn_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->message_info_home_text, message_info_home_text_event_handler, LV_EVENT_ALL, NULL);
}
static void message_list_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: message_list_app_icon move_x
	  	lv_anim_t message_list_app_icon_anim_move_x;
	  	lv_anim_init(&message_list_app_icon_anim_move_x);
	  	lv_anim_set_var(&message_list_app_icon_anim_move_x, guider_ui.message_list_app_icon);
	  	lv_anim_set_time(&message_list_app_icon_anim_move_x, 800);
	  	lv_anim_set_delay(&message_list_app_icon_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&message_list_app_icon_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&message_list_app_icon_anim_move_x, lv_obj_get_x(guider_ui.message_list_app_icon), 133);
	  	lv_anim_set_path_cb(&message_list_app_icon_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&message_list_app_icon_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&message_list_app_icon_anim_move_x, 0);
	  	lv_anim_set_playback_time(&message_list_app_icon_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&message_list_app_icon_anim_move_x, 0);
		lv_anim_start(&message_list_app_icon_anim_move_x);
		//Write animation: message_list_app_icon move_y
	  	lv_anim_t message_list_app_icon_anim_move_y;
	  	lv_anim_init(&message_list_app_icon_anim_move_y);
	  	lv_anim_set_var(&message_list_app_icon_anim_move_y, guider_ui.message_list_app_icon);
	  	lv_anim_set_time(&message_list_app_icon_anim_move_y, 800);
	  	lv_anim_set_delay(&message_list_app_icon_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&message_list_app_icon_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&message_list_app_icon_anim_move_y, lv_obj_get_y(guider_ui.message_list_app_icon), 10);
	  	lv_anim_set_path_cb(&message_list_app_icon_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&message_list_app_icon_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&message_list_app_icon_anim_move_y, 0);
	  	lv_anim_set_playback_time(&message_list_app_icon_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&message_list_app_icon_anim_move_y, 0);
		lv_anim_start(&message_list_app_icon_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.standup_del == true) {
			          setup_scr_standup(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.standup, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.message_list_del = true;
			    }
				break;
			}
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.message_info_del == true) {
			          setup_scr_message_info(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.message_info, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.message_list_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void message_list_left_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.message_info_del == true) {
	          setup_scr_message_info(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.message_info, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.message_list_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void message_list_right_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.standup_del == true) {
	          setup_scr_standup(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.standup, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.message_list_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_message_list(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->message_list, message_list_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->message_list_left, message_list_left_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->message_list_right, message_list_right_event_handler, LV_EVENT_ALL, NULL);
}
static void standup_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: standup_stand_icon move_x
	  	lv_anim_t standup_stand_icon_anim_move_x;
	  	lv_anim_init(&standup_stand_icon_anim_move_x);
	  	lv_anim_set_var(&standup_stand_icon_anim_move_x, guider_ui.standup_stand_icon);
	  	lv_anim_set_time(&standup_stand_icon_anim_move_x, 800);
	  	lv_anim_set_delay(&standup_stand_icon_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&standup_stand_icon_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&standup_stand_icon_anim_move_x, lv_obj_get_x(guider_ui.standup_stand_icon), 154);
	  	lv_anim_set_path_cb(&standup_stand_icon_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&standup_stand_icon_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&standup_stand_icon_anim_move_x, 0);
	  	lv_anim_set_playback_time(&standup_stand_icon_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&standup_stand_icon_anim_move_x, 0);
		lv_anim_start(&standup_stand_icon_anim_move_x);
		//Write animation: standup_stand_icon move_y
	  	lv_anim_t standup_stand_icon_anim_move_y;
	  	lv_anim_init(&standup_stand_icon_anim_move_y);
	  	lv_anim_set_var(&standup_stand_icon_anim_move_y, guider_ui.standup_stand_icon);
	  	lv_anim_set_time(&standup_stand_icon_anim_move_y, 800);
	  	lv_anim_set_delay(&standup_stand_icon_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&standup_stand_icon_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&standup_stand_icon_anim_move_y, lv_obj_get_y(guider_ui.standup_stand_icon), 23);
	  	lv_anim_set_path_cb(&standup_stand_icon_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&standup_stand_icon_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&standup_stand_icon_anim_move_y, 0);
	  	lv_anim_set_playback_time(&standup_stand_icon_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&standup_stand_icon_anim_move_y, 0);
		lv_anim_start(&standup_stand_icon_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.car_lock_del == true) {
			          setup_scr_car_lock(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.car_lock, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.standup_del = true;
			    }
				break;
			}
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.contact_list_del == true) {
			          setup_scr_contact_list(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.contact_list, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.standup_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void standup_left_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.message_list_del == true) {
	          setup_scr_message_list(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.message_list, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.standup_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void standup_right_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.car_lock_del == true) {
	          setup_scr_car_lock(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.car_lock, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.standup_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void standup_ok_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.standup_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void standup_home_text_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.standup_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_standup(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->standup, standup_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->standup_left, standup_left_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->standup_right, standup_right_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->standup_ok_btn, standup_ok_btn_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->standup_home_text, standup_home_text_event_handler, LV_EVENT_ALL, NULL);
}
static void car_lock_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: car_lock_car_icon move_x
	  	lv_anim_t car_lock_car_icon_anim_move_x;
	  	lv_anim_init(&car_lock_car_icon_anim_move_x);
	  	lv_anim_set_var(&car_lock_car_icon_anim_move_x, guider_ui.car_lock_car_icon);
	  	lv_anim_set_time(&car_lock_car_icon_anim_move_x, 800);
	  	lv_anim_set_delay(&car_lock_car_icon_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&car_lock_car_icon_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&car_lock_car_icon_anim_move_x, lv_obj_get_x(guider_ui.car_lock_car_icon), 154);
	  	lv_anim_set_path_cb(&car_lock_car_icon_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&car_lock_car_icon_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&car_lock_car_icon_anim_move_x, 0);
	  	lv_anim_set_playback_time(&car_lock_car_icon_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&car_lock_car_icon_anim_move_x, 0);
		lv_anim_start(&car_lock_car_icon_anim_move_x);
		//Write animation: car_lock_car_icon move_y
	  	lv_anim_t car_lock_car_icon_anim_move_y;
	  	lv_anim_init(&car_lock_car_icon_anim_move_y);
	  	lv_anim_set_var(&car_lock_car_icon_anim_move_y, guider_ui.car_lock_car_icon);
	  	lv_anim_set_time(&car_lock_car_icon_anim_move_y, 800);
	  	lv_anim_set_delay(&car_lock_car_icon_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&car_lock_car_icon_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&car_lock_car_icon_anim_move_y, lv_obj_get_y(guider_ui.car_lock_car_icon), 23);
	  	lv_anim_set_path_cb(&car_lock_car_icon_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&car_lock_car_icon_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&car_lock_car_icon_anim_move_y, 0);
	  	lv_anim_set_playback_time(&car_lock_car_icon_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&car_lock_car_icon_anim_move_y, 0);
		lv_anim_start(&car_lock_car_icon_anim_move_y);
		//Write animation: car_lock_cont_1 move_x
	  	lv_anim_t car_lock_cont_1_anim_move_x;
	  	lv_anim_init(&car_lock_cont_1_anim_move_x);
	  	lv_anim_set_var(&car_lock_cont_1_anim_move_x, guider_ui.car_lock_cont_1);
	  	lv_anim_set_time(&car_lock_cont_1_anim_move_x, 800);
	  	lv_anim_set_delay(&car_lock_cont_1_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&car_lock_cont_1_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&car_lock_cont_1_anim_move_x, lv_obj_get_x(guider_ui.car_lock_cont_1), 78);
	  	lv_anim_set_path_cb(&car_lock_cont_1_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&car_lock_cont_1_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&car_lock_cont_1_anim_move_x, 0);
	  	lv_anim_set_playback_time(&car_lock_cont_1_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&car_lock_cont_1_anim_move_x, 0);
		lv_anim_start(&car_lock_cont_1_anim_move_x);
		//Write animation: car_lock_cont_1 move_y
	  	lv_anim_t car_lock_cont_1_anim_move_y;
	  	lv_anim_init(&car_lock_cont_1_anim_move_y);
	  	lv_anim_set_var(&car_lock_cont_1_anim_move_y, guider_ui.car_lock_cont_1);
	  	lv_anim_set_time(&car_lock_cont_1_anim_move_y, 800);
	  	lv_anim_set_delay(&car_lock_cont_1_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&car_lock_cont_1_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&car_lock_cont_1_anim_move_y, lv_obj_get_y(guider_ui.car_lock_cont_1), 193);
	  	lv_anim_set_path_cb(&car_lock_cont_1_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&car_lock_cont_1_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&car_lock_cont_1_anim_move_y, 0);
	  	lv_anim_set_playback_time(&car_lock_cont_1_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&car_lock_cont_1_anim_move_y, 0);
		lv_anim_start(&car_lock_cont_1_anim_move_y);
		//Write animation: car_lock_lock_icon2 move_x
	  	lv_anim_t car_lock_lock_icon2_anim_move_x;
	  	lv_anim_init(&car_lock_lock_icon2_anim_move_x);
	  	lv_anim_set_var(&car_lock_lock_icon2_anim_move_x, guider_ui.car_lock_lock_icon2);
	  	lv_anim_set_time(&car_lock_lock_icon2_anim_move_x, 200);
	  	lv_anim_set_delay(&car_lock_lock_icon2_anim_move_x, 800);
	  	lv_anim_set_exec_cb(&car_lock_lock_icon2_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&car_lock_lock_icon2_anim_move_x, lv_obj_get_x(guider_ui.car_lock_lock_icon2), 79);
	  	lv_anim_set_path_cb(&car_lock_lock_icon2_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&car_lock_lock_icon2_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&car_lock_lock_icon2_anim_move_x, 0);
	  	lv_anim_set_playback_time(&car_lock_lock_icon2_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&car_lock_lock_icon2_anim_move_x, 0);
		lv_anim_start(&car_lock_lock_icon2_anim_move_x);
		//Write animation: car_lock_lock_icon2 move_y
	  	lv_anim_t car_lock_lock_icon2_anim_move_y;
	  	lv_anim_init(&car_lock_lock_icon2_anim_move_y);
	  	lv_anim_set_var(&car_lock_lock_icon2_anim_move_y, guider_ui.car_lock_lock_icon2);
	  	lv_anim_set_time(&car_lock_lock_icon2_anim_move_y, 200);
	  	lv_anim_set_delay(&car_lock_lock_icon2_anim_move_y, 800);
	  	lv_anim_set_exec_cb(&car_lock_lock_icon2_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&car_lock_lock_icon2_anim_move_y, lv_obj_get_y(guider_ui.car_lock_lock_icon2), 30);
	  	lv_anim_set_path_cb(&car_lock_lock_icon2_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&car_lock_lock_icon2_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&car_lock_lock_icon2_anim_move_y, 0);
	  	lv_anim_set_playback_time(&car_lock_lock_icon2_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&car_lock_lock_icon2_anim_move_y, 0);
		lv_anim_start(&car_lock_lock_icon2_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.car_start_del == true) {
			          setup_scr_car_start(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.car_start, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.car_lock_del = true;
			    }
				break;
			}
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.standup_del == true) {
			          setup_scr_standup(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.standup, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.car_lock_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void car_lock_left_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.standup_del == true) {
	          setup_scr_standup(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.standup, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.car_lock_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void car_lock_right_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.car_start_del == true) {
	          setup_scr_car_start(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.car_start, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.car_lock_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void car_lock_home_text_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.car_lock_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_car_lock(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->car_lock, car_lock_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->car_lock_left, car_lock_left_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->car_lock_right, car_lock_right_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->car_lock_home_text, car_lock_home_text_event_handler, LV_EVENT_ALL, NULL);
}
static void car_start_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: car_start_start_imgbtn move_x
	  	lv_anim_t car_start_start_imgbtn_anim_move_x;
	  	lv_anim_init(&car_start_start_imgbtn_anim_move_x);
	  	lv_anim_set_var(&car_start_start_imgbtn_anim_move_x, guider_ui.car_start_start_imgbtn);
	  	lv_anim_set_time(&car_start_start_imgbtn_anim_move_x, 800);
	  	lv_anim_set_delay(&car_start_start_imgbtn_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&car_start_start_imgbtn_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&car_start_start_imgbtn_anim_move_x, lv_obj_get_x(guider_ui.car_start_start_imgbtn), 104);
	  	lv_anim_set_path_cb(&car_start_start_imgbtn_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&car_start_start_imgbtn_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&car_start_start_imgbtn_anim_move_x, 0);
	  	lv_anim_set_playback_time(&car_start_start_imgbtn_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&car_start_start_imgbtn_anim_move_x, 0);
		lv_anim_start(&car_start_start_imgbtn_anim_move_x);
		//Write animation: car_start_start_imgbtn move_y
	  	lv_anim_t car_start_start_imgbtn_anim_move_y;
	  	lv_anim_init(&car_start_start_imgbtn_anim_move_y);
	  	lv_anim_set_var(&car_start_start_imgbtn_anim_move_y, guider_ui.car_start_start_imgbtn);
	  	lv_anim_set_time(&car_start_start_imgbtn_anim_move_y, 800);
	  	lv_anim_set_delay(&car_start_start_imgbtn_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&car_start_start_imgbtn_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&car_start_start_imgbtn_anim_move_y, lv_obj_get_y(guider_ui.car_start_start_imgbtn), 179);
	  	lv_anim_set_path_cb(&car_start_start_imgbtn_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&car_start_start_imgbtn_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&car_start_start_imgbtn_anim_move_y, 0);
	  	lv_anim_set_playback_time(&car_start_start_imgbtn_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&car_start_start_imgbtn_anim_move_y, 0);
		lv_anim_start(&car_start_start_imgbtn_anim_move_y);
		//Write animation: car_start_car_icon move_x
	  	lv_anim_t car_start_car_icon_anim_move_x;
	  	lv_anim_init(&car_start_car_icon_anim_move_x);
	  	lv_anim_set_var(&car_start_car_icon_anim_move_x, guider_ui.car_start_car_icon);
	  	lv_anim_set_time(&car_start_car_icon_anim_move_x, 800);
	  	lv_anim_set_delay(&car_start_car_icon_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&car_start_car_icon_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&car_start_car_icon_anim_move_x, lv_obj_get_x(guider_ui.car_start_car_icon), 154);
	  	lv_anim_set_path_cb(&car_start_car_icon_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&car_start_car_icon_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&car_start_car_icon_anim_move_x, 0);
	  	lv_anim_set_playback_time(&car_start_car_icon_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&car_start_car_icon_anim_move_x, 0);
		lv_anim_start(&car_start_car_icon_anim_move_x);
		//Write animation: car_start_car_icon move_y
	  	lv_anim_t car_start_car_icon_anim_move_y;
	  	lv_anim_init(&car_start_car_icon_anim_move_y);
	  	lv_anim_set_var(&car_start_car_icon_anim_move_y, guider_ui.car_start_car_icon);
	  	lv_anim_set_time(&car_start_car_icon_anim_move_y, 800);
	  	lv_anim_set_delay(&car_start_car_icon_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&car_start_car_icon_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&car_start_car_icon_anim_move_y, lv_obj_get_y(guider_ui.car_start_car_icon), 23);
	  	lv_anim_set_path_cb(&car_start_car_icon_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&car_start_car_icon_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&car_start_car_icon_anim_move_y, 0);
	  	lv_anim_set_playback_time(&car_start_car_icon_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&car_start_car_icon_anim_move_y, 0);
		lv_anim_start(&car_start_car_icon_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.listening_del == true) {
			          setup_scr_listening(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.listening, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.car_start_del = true;
			    }
				break;
			}
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.car_lock_del == true) {
			          setup_scr_car_lock(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.car_lock, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.car_start_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void car_start_left_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.car_lock_del == true) {
	          setup_scr_car_lock(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.car_lock, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.car_start_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void car_start_right_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.listening_del == true) {
	          setup_scr_listening(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.listening, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.car_start_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void car_start_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.car_start_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_car_start(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->car_start, car_start_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->car_start_left, car_start_left_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->car_start_right, car_start_right_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->car_start_home, car_start_home_event_handler, LV_EVENT_ALL, NULL);
}
static void listening_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: listening_listen_text move_x
	  	lv_anim_t listening_listen_text_anim_move_x;
	  	lv_anim_init(&listening_listen_text_anim_move_x);
	  	lv_anim_set_var(&listening_listen_text_anim_move_x, guider_ui.listening_listen_text);
	  	lv_anim_set_time(&listening_listen_text_anim_move_x, 800);
	  	lv_anim_set_delay(&listening_listen_text_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&listening_listen_text_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&listening_listen_text_anim_move_x, lv_obj_get_x(guider_ui.listening_listen_text), 101);
	  	lv_anim_set_path_cb(&listening_listen_text_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&listening_listen_text_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&listening_listen_text_anim_move_x, 0);
	  	lv_anim_set_playback_time(&listening_listen_text_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&listening_listen_text_anim_move_x, 0);
		lv_anim_start(&listening_listen_text_anim_move_x);
		//Write animation: listening_listen_text move_y
	  	lv_anim_t listening_listen_text_anim_move_y;
	  	lv_anim_init(&listening_listen_text_anim_move_y);
	  	lv_anim_set_var(&listening_listen_text_anim_move_y, guider_ui.listening_listen_text);
	  	lv_anim_set_time(&listening_listen_text_anim_move_y, 800);
	  	lv_anim_set_delay(&listening_listen_text_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&listening_listen_text_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&listening_listen_text_anim_move_y, lv_obj_get_y(guider_ui.listening_listen_text), 307);
	  	lv_anim_set_path_cb(&listening_listen_text_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&listening_listen_text_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&listening_listen_text_anim_move_y, 0);
	  	lv_anim_set_playback_time(&listening_listen_text_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&listening_listen_text_anim_move_y, 0);
		lv_anim_start(&listening_listen_text_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.not_recognized_del == true) {
			          setup_scr_not_recognized(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.not_recognized, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.listening_del = true;
			    }
				break;
			}
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.car_start_del == true) {
			          setup_scr_car_start(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.car_start, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.listening_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void listening_left_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.car_start_del == true) {
	          setup_scr_car_start(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.car_start, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.listening_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void listening_right_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.not_recognized_del == true) {
	          setup_scr_not_recognized(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.not_recognized, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.listening_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void listening_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.listening_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_listening(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->listening, listening_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->listening_left, listening_left_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->listening_right, listening_right_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->listening_home, listening_home_event_handler, LV_EVENT_ALL, NULL);
}
static void not_recognized_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: not_recognized_no_mic_icon move_x
	  	lv_anim_t not_recognized_no_mic_icon_anim_move_x;
	  	lv_anim_init(&not_recognized_no_mic_icon_anim_move_x);
	  	lv_anim_set_var(&not_recognized_no_mic_icon_anim_move_x, guider_ui.not_recognized_no_mic_icon);
	  	lv_anim_set_time(&not_recognized_no_mic_icon_anim_move_x, 800);
	  	lv_anim_set_delay(&not_recognized_no_mic_icon_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&not_recognized_no_mic_icon_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&not_recognized_no_mic_icon_anim_move_x, lv_obj_get_x(guider_ui.not_recognized_no_mic_icon), 101);
	  	lv_anim_set_path_cb(&not_recognized_no_mic_icon_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&not_recognized_no_mic_icon_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&not_recognized_no_mic_icon_anim_move_x, 0);
	  	lv_anim_set_playback_time(&not_recognized_no_mic_icon_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&not_recognized_no_mic_icon_anim_move_x, 0);
		lv_anim_start(&not_recognized_no_mic_icon_anim_move_x);
		//Write animation: not_recognized_no_mic_icon move_y
	  	lv_anim_t not_recognized_no_mic_icon_anim_move_y;
	  	lv_anim_init(&not_recognized_no_mic_icon_anim_move_y);
	  	lv_anim_set_var(&not_recognized_no_mic_icon_anim_move_y, guider_ui.not_recognized_no_mic_icon);
	  	lv_anim_set_time(&not_recognized_no_mic_icon_anim_move_y, 800);
	  	lv_anim_set_delay(&not_recognized_no_mic_icon_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&not_recognized_no_mic_icon_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&not_recognized_no_mic_icon_anim_move_y, lv_obj_get_y(guider_ui.not_recognized_no_mic_icon), 72);
	  	lv_anim_set_path_cb(&not_recognized_no_mic_icon_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&not_recognized_no_mic_icon_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&not_recognized_no_mic_icon_anim_move_y, 0);
	  	lv_anim_set_playback_time(&not_recognized_no_mic_icon_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&not_recognized_no_mic_icon_anim_move_y, 0);
		lv_anim_start(&not_recognized_no_mic_icon_anim_move_y);
		//Write animation: not_recognized_command_text move_x
	  	lv_anim_t not_recognized_command_text_anim_move_x;
	  	lv_anim_init(&not_recognized_command_text_anim_move_x);
	  	lv_anim_set_var(&not_recognized_command_text_anim_move_x, guider_ui.not_recognized_command_text);
	  	lv_anim_set_time(&not_recognized_command_text_anim_move_x, 800);
	  	lv_anim_set_delay(&not_recognized_command_text_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&not_recognized_command_text_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&not_recognized_command_text_anim_move_x, lv_obj_get_x(guider_ui.not_recognized_command_text), 108);
	  	lv_anim_set_path_cb(&not_recognized_command_text_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&not_recognized_command_text_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&not_recognized_command_text_anim_move_x, 0);
	  	lv_anim_set_playback_time(&not_recognized_command_text_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&not_recognized_command_text_anim_move_x, 0);
		lv_anim_start(&not_recognized_command_text_anim_move_x);
		//Write animation: not_recognized_command_text move_y
	  	lv_anim_t not_recognized_command_text_anim_move_y;
	  	lv_anim_init(&not_recognized_command_text_anim_move_y);
	  	lv_anim_set_var(&not_recognized_command_text_anim_move_y, guider_ui.not_recognized_command_text);
	  	lv_anim_set_time(&not_recognized_command_text_anim_move_y, 800);
	  	lv_anim_set_delay(&not_recognized_command_text_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&not_recognized_command_text_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&not_recognized_command_text_anim_move_y, lv_obj_get_y(guider_ui.not_recognized_command_text), 307);
	  	lv_anim_set_path_cb(&not_recognized_command_text_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&not_recognized_command_text_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&not_recognized_command_text_anim_move_y, 0);
	  	lv_anim_set_playback_time(&not_recognized_command_text_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&not_recognized_command_text_anim_move_y, 0);
		lv_anim_start(&not_recognized_command_text_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.recognized_del == true) {
			          setup_scr_recognized(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.recognized, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.not_recognized_del = true;
			    }
				break;
			}
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.listening_del == true) {
			          setup_scr_listening(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.listening, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.not_recognized_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void not_recognized_left_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.listening_del == true) {
	          setup_scr_listening(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.listening, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.not_recognized_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void not_recognized_right_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.recognized_del == true) {
	          setup_scr_recognized(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.recognized, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.not_recognized_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_not_recognized(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->not_recognized, not_recognized_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->not_recognized_left, not_recognized_left_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->not_recognized_right, not_recognized_right_event_handler, LV_EVENT_ALL, NULL);
}
static void recognized_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: recognized_command_text move_x
	  	lv_anim_t recognized_command_text_anim_move_x;
	  	lv_anim_init(&recognized_command_text_anim_move_x);
	  	lv_anim_set_var(&recognized_command_text_anim_move_x, guider_ui.recognized_command_text);
	  	lv_anim_set_time(&recognized_command_text_anim_move_x, 800);
	  	lv_anim_set_delay(&recognized_command_text_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&recognized_command_text_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&recognized_command_text_anim_move_x, lv_obj_get_x(guider_ui.recognized_command_text), 137);
	  	lv_anim_set_path_cb(&recognized_command_text_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&recognized_command_text_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&recognized_command_text_anim_move_x, 0);
	  	lv_anim_set_playback_time(&recognized_command_text_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&recognized_command_text_anim_move_x, 0);
		lv_anim_start(&recognized_command_text_anim_move_x);
		//Write animation: recognized_command_text move_y
	  	lv_anim_t recognized_command_text_anim_move_y;
	  	lv_anim_init(&recognized_command_text_anim_move_y);
	  	lv_anim_set_var(&recognized_command_text_anim_move_y, guider_ui.recognized_command_text);
	  	lv_anim_set_time(&recognized_command_text_anim_move_y, 800);
	  	lv_anim_set_delay(&recognized_command_text_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&recognized_command_text_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&recognized_command_text_anim_move_y, lv_obj_get_y(guider_ui.recognized_command_text), 307);
	  	lv_anim_set_path_cb(&recognized_command_text_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&recognized_command_text_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&recognized_command_text_anim_move_y, 0);
	  	lv_anim_set_playback_time(&recognized_command_text_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&recognized_command_text_anim_move_y, 0);
		lv_anim_start(&recognized_command_text_anim_move_y);
		//Write animation: recognized_done_mic move_x
	  	lv_anim_t recognized_done_mic_anim_move_x;
	  	lv_anim_init(&recognized_done_mic_anim_move_x);
	  	lv_anim_set_var(&recognized_done_mic_anim_move_x, guider_ui.recognized_done_mic);
	  	lv_anim_set_time(&recognized_done_mic_anim_move_x, 800);
	  	lv_anim_set_delay(&recognized_done_mic_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&recognized_done_mic_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&recognized_done_mic_anim_move_x, lv_obj_get_x(guider_ui.recognized_done_mic), 101);
	  	lv_anim_set_path_cb(&recognized_done_mic_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&recognized_done_mic_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&recognized_done_mic_anim_move_x, 0);
	  	lv_anim_set_playback_time(&recognized_done_mic_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&recognized_done_mic_anim_move_x, 0);
		lv_anim_start(&recognized_done_mic_anim_move_x);
		//Write animation: recognized_done_mic move_y
	  	lv_anim_t recognized_done_mic_anim_move_y;
	  	lv_anim_init(&recognized_done_mic_anim_move_y);
	  	lv_anim_set_var(&recognized_done_mic_anim_move_y, guider_ui.recognized_done_mic);
	  	lv_anim_set_time(&recognized_done_mic_anim_move_y, 800);
	  	lv_anim_set_delay(&recognized_done_mic_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&recognized_done_mic_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&recognized_done_mic_anim_move_y, lv_obj_get_y(guider_ui.recognized_done_mic), 72);
	  	lv_anim_set_path_cb(&recognized_done_mic_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&recognized_done_mic_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&recognized_done_mic_anim_move_y, 0);
	  	lv_anim_set_playback_time(&recognized_done_mic_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&recognized_done_mic_anim_move_y, 0);
		lv_anim_start(&recognized_done_mic_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.home_analog_del == true) {
			          setup_scr_home_analog(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.recognized_del = true;
			    }
				break;
			}
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.not_recognized_del == true) {
			          setup_scr_not_recognized(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.not_recognized, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.recognized_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void recognized_left_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.not_recognized_del == true) {
	          setup_scr_not_recognized(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.not_recognized, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.recognized_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void recognized_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.recognized_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_recognized(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->recognized, recognized_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->recognized_left, recognized_left_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->recognized_home, recognized_home_event_handler, LV_EVENT_ALL, NULL);
}
static void contact_list_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: contact_list_label_title move_x
	  	lv_anim_t contact_list_label_title_anim_move_x;
	  	lv_anim_init(&contact_list_label_title_anim_move_x);
	  	lv_anim_set_var(&contact_list_label_title_anim_move_x, guider_ui.contact_list_label_title);
	  	lv_anim_set_time(&contact_list_label_title_anim_move_x, 800);
	  	lv_anim_set_delay(&contact_list_label_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&contact_list_label_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&contact_list_label_title_anim_move_x, lv_obj_get_x(guider_ui.contact_list_label_title), 0);
	  	lv_anim_set_path_cb(&contact_list_label_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&contact_list_label_title_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&contact_list_label_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&contact_list_label_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&contact_list_label_title_anim_move_x, 0);
		lv_anim_start(&contact_list_label_title_anim_move_x);
		//Write animation: contact_list_label_title move_y
	  	lv_anim_t contact_list_label_title_anim_move_y;
	  	lv_anim_init(&contact_list_label_title_anim_move_y);
	  	lv_anim_set_var(&contact_list_label_title_anim_move_y, guider_ui.contact_list_label_title);
	  	lv_anim_set_time(&contact_list_label_title_anim_move_y, 800);
	  	lv_anim_set_delay(&contact_list_label_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&contact_list_label_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&contact_list_label_title_anim_move_y, lv_obj_get_y(guider_ui.contact_list_label_title), 0);
	  	lv_anim_set_path_cb(&contact_list_label_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&contact_list_label_title_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&contact_list_label_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&contact_list_label_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&contact_list_label_title_anim_move_y, 0);
		lv_anim_start(&contact_list_label_title_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.home_analog_del == true) {
			          setup_scr_home_analog(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.contact_list_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void contact_list_cont_2_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.call_del == true) {
	          setup_scr_call(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.call, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.contact_list_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void contact_list_img_3_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.call_del == true) {
	          setup_scr_call(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.call, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.contact_list_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_contact_list(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->contact_list, contact_list_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->contact_list_cont_2, contact_list_cont_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->contact_list_img_3, contact_list_img_3_event_handler, LV_EVENT_ALL, NULL);
}
static void call_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: call_img_7 move_x
	  	lv_anim_t call_img_7_anim_move_x;
	  	lv_anim_init(&call_img_7_anim_move_x);
	  	lv_anim_set_var(&call_img_7_anim_move_x, guider_ui.call_img_7);
	  	lv_anim_set_time(&call_img_7_anim_move_x, 800);
	  	lv_anim_set_delay(&call_img_7_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&call_img_7_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&call_img_7_anim_move_x, lv_obj_get_x(guider_ui.call_img_7), 0);
	  	lv_anim_set_path_cb(&call_img_7_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&call_img_7_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&call_img_7_anim_move_x, 0);
	  	lv_anim_set_playback_time(&call_img_7_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&call_img_7_anim_move_x, 0);
		lv_anim_start(&call_img_7_anim_move_x);
		//Write animation: call_img_7 move_y
	  	lv_anim_t call_img_7_anim_move_y;
	  	lv_anim_init(&call_img_7_anim_move_y);
	  	lv_anim_set_var(&call_img_7_anim_move_y, guider_ui.call_img_7);
	  	lv_anim_set_time(&call_img_7_anim_move_y, 800);
	  	lv_anim_set_delay(&call_img_7_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&call_img_7_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&call_img_7_anim_move_y, lv_obj_get_y(guider_ui.call_img_7), 0);
	  	lv_anim_set_path_cb(&call_img_7_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&call_img_7_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&call_img_7_anim_move_y, 0);
	  	lv_anim_set_playback_time(&call_img_7_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&call_img_7_anim_move_y, 0);
		lv_anim_start(&call_img_7_anim_move_y);
		//Write animation: call_unmute_icon move_x
	  	lv_anim_t call_unmute_icon_anim_move_x;
	  	lv_anim_init(&call_unmute_icon_anim_move_x);
	  	lv_anim_set_var(&call_unmute_icon_anim_move_x, guider_ui.call_unmute_icon);
	  	lv_anim_set_time(&call_unmute_icon_anim_move_x, 800);
	  	lv_anim_set_delay(&call_unmute_icon_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&call_unmute_icon_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&call_unmute_icon_anim_move_x, lv_obj_get_x(guider_ui.call_unmute_icon), 180);
	  	lv_anim_set_path_cb(&call_unmute_icon_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&call_unmute_icon_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&call_unmute_icon_anim_move_x, 0);
	  	lv_anim_set_playback_time(&call_unmute_icon_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&call_unmute_icon_anim_move_x, 0);
		lv_anim_start(&call_unmute_icon_anim_move_x);
		//Write animation: call_unmute_icon move_y
	  	lv_anim_t call_unmute_icon_anim_move_y;
	  	lv_anim_init(&call_unmute_icon_anim_move_y);
	  	lv_anim_set_var(&call_unmute_icon_anim_move_y, guider_ui.call_unmute_icon);
	  	lv_anim_set_time(&call_unmute_icon_anim_move_y, 800);
	  	lv_anim_set_delay(&call_unmute_icon_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&call_unmute_icon_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&call_unmute_icon_anim_move_y, lv_obj_get_y(guider_ui.call_unmute_icon), 321);
	  	lv_anim_set_path_cb(&call_unmute_icon_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&call_unmute_icon_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&call_unmute_icon_anim_move_y, 0);
	  	lv_anim_set_playback_time(&call_unmute_icon_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&call_unmute_icon_anim_move_y, 0);
		lv_anim_start(&call_unmute_icon_anim_move_y);
		break;
	}
	default:
		break;
	}
}
static void call_img_6_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.call_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void call_hang_up_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.call_del = true;
	    }
		if (guider_ui.call_del)
	        guider_ui.call_digital_clock_1 = NULL;
		break;
	}
	default:
		break;
	}
}
static void call_unmute_icon_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_clear_flag(guider_ui.call_mute_icon, LV_OBJ_FLAG_HIDDEN);
		break;
	}
	default:
		break;
	}
}
static void call_mute_icon_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_clear_flag(guider_ui.call_unmute_icon, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.call_mute_icon, LV_OBJ_FLAG_HIDDEN);
		break;
	}
	default:
		break;
	}
}
void events_init_call(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->call, call_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->call_img_6, call_img_6_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->call_hang_up_btn, call_hang_up_btn_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->call_unmute_icon, call_unmute_icon_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->call_mute_icon, call_mute_icon_event_handler, LV_EVENT_ALL, NULL);
}
static void weather_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: weather_img_bgCloud move_x
	  	lv_anim_t weather_img_bgCloud_anim_move_x;
	  	lv_anim_init(&weather_img_bgCloud_anim_move_x);
	  	lv_anim_set_var(&weather_img_bgCloud_anim_move_x, guider_ui.weather_img_bgCloud);
	  	lv_anim_set_time(&weather_img_bgCloud_anim_move_x, 5000);
	  	lv_anim_set_delay(&weather_img_bgCloud_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&weather_img_bgCloud_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&weather_img_bgCloud_anim_move_x, lv_obj_get_x(guider_ui.weather_img_bgCloud), -194);
	  	lv_anim_set_path_cb(&weather_img_bgCloud_anim_move_x, &lv_anim_path_linear);
	  	lv_anim_set_repeat_count(&weather_img_bgCloud_anim_move_x, LV_ANIM_REPEAT_INFINITE);
	  	lv_anim_set_repeat_delay(&weather_img_bgCloud_anim_move_x, 0);
	  	lv_anim_set_playback_time(&weather_img_bgCloud_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&weather_img_bgCloud_anim_move_x, 0);
		lv_anim_start(&weather_img_bgCloud_anim_move_x);
		//Write animation: weather_img_bgCloud move_y
	  	lv_anim_t weather_img_bgCloud_anim_move_y;
	  	lv_anim_init(&weather_img_bgCloud_anim_move_y);
	  	lv_anim_set_var(&weather_img_bgCloud_anim_move_y, guider_ui.weather_img_bgCloud);
	  	lv_anim_set_time(&weather_img_bgCloud_anim_move_y, 5000);
	  	lv_anim_set_delay(&weather_img_bgCloud_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&weather_img_bgCloud_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&weather_img_bgCloud_anim_move_y, lv_obj_get_y(guider_ui.weather_img_bgCloud), 0);
	  	lv_anim_set_path_cb(&weather_img_bgCloud_anim_move_y, &lv_anim_path_linear);
	  	lv_anim_set_repeat_count(&weather_img_bgCloud_anim_move_y, LV_ANIM_REPEAT_INFINITE);
	  	lv_anim_set_repeat_delay(&weather_img_bgCloud_anim_move_y, 0);
	  	lv_anim_set_playback_time(&weather_img_bgCloud_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&weather_img_bgCloud_anim_move_y, 0);
		lv_anim_start(&weather_img_bgCloud_anim_move_y);
		//Write animation: weather_label_city move_x
	  	lv_anim_t weather_label_city_anim_move_x;
	  	lv_anim_init(&weather_label_city_anim_move_x);
	  	lv_anim_set_var(&weather_label_city_anim_move_x, guider_ui.weather_label_city);
	  	lv_anim_set_time(&weather_label_city_anim_move_x, 800);
	  	lv_anim_set_delay(&weather_label_city_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&weather_label_city_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&weather_label_city_anim_move_x, lv_obj_get_x(guider_ui.weather_label_city), 82);
	  	lv_anim_set_path_cb(&weather_label_city_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&weather_label_city_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&weather_label_city_anim_move_x, 0);
	  	lv_anim_set_playback_time(&weather_label_city_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&weather_label_city_anim_move_x, 0);
		lv_anim_start(&weather_label_city_anim_move_x);
		//Write animation: weather_label_city move_y
	  	lv_anim_t weather_label_city_anim_move_y;
	  	lv_anim_init(&weather_label_city_anim_move_y);
	  	lv_anim_set_var(&weather_label_city_anim_move_y, guider_ui.weather_label_city);
	  	lv_anim_set_time(&weather_label_city_anim_move_y, 800);
	  	lv_anim_set_delay(&weather_label_city_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&weather_label_city_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&weather_label_city_anim_move_y, lv_obj_get_y(guider_ui.weather_label_city), 30);
	  	lv_anim_set_path_cb(&weather_label_city_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&weather_label_city_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&weather_label_city_anim_move_y, 0);
	  	lv_anim_set_playback_time(&weather_label_city_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&weather_label_city_anim_move_y, 0);
		lv_anim_start(&weather_label_city_anim_move_y);
		//Write animation: weather_label_maxMin move_x
	  	lv_anim_t weather_label_maxMin_anim_move_x;
	  	lv_anim_init(&weather_label_maxMin_anim_move_x);
	  	lv_anim_set_var(&weather_label_maxMin_anim_move_x, guider_ui.weather_label_maxMin);
	  	lv_anim_set_time(&weather_label_maxMin_anim_move_x, 800);
	  	lv_anim_set_delay(&weather_label_maxMin_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&weather_label_maxMin_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&weather_label_maxMin_anim_move_x, lv_obj_get_x(guider_ui.weather_label_maxMin), 72);
	  	lv_anim_set_path_cb(&weather_label_maxMin_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&weather_label_maxMin_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&weather_label_maxMin_anim_move_x, 0);
	  	lv_anim_set_playback_time(&weather_label_maxMin_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&weather_label_maxMin_anim_move_x, 0);
		lv_anim_start(&weather_label_maxMin_anim_move_x);
		//Write animation: weather_label_maxMin move_y
	  	lv_anim_t weather_label_maxMin_anim_move_y;
	  	lv_anim_init(&weather_label_maxMin_anim_move_y);
	  	lv_anim_set_var(&weather_label_maxMin_anim_move_y, guider_ui.weather_label_maxMin);
	  	lv_anim_set_time(&weather_label_maxMin_anim_move_y, 800);
	  	lv_anim_set_delay(&weather_label_maxMin_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&weather_label_maxMin_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&weather_label_maxMin_anim_move_y, lv_obj_get_y(guider_ui.weather_label_maxMin), 293);
	  	lv_anim_set_path_cb(&weather_label_maxMin_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&weather_label_maxMin_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&weather_label_maxMin_anim_move_y, 0);
	  	lv_anim_set_playback_time(&weather_label_maxMin_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&weather_label_maxMin_anim_move_y, 0);
		lv_anim_start(&weather_label_maxMin_anim_move_y);
		//Write animation: weather_img_icon move_x
	  	lv_anim_t weather_img_icon_anim_move_x;
	  	lv_anim_init(&weather_img_icon_anim_move_x);
	  	lv_anim_set_var(&weather_img_icon_anim_move_x, guider_ui.weather_img_icon);
	  	lv_anim_set_time(&weather_img_icon_anim_move_x, 800);
	  	lv_anim_set_delay(&weather_img_icon_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&weather_img_icon_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&weather_img_icon_anim_move_x, lv_obj_get_x(guider_ui.weather_img_icon), 163);
	  	lv_anim_set_path_cb(&weather_img_icon_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&weather_img_icon_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&weather_img_icon_anim_move_x, 0);
	  	lv_anim_set_playback_time(&weather_img_icon_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&weather_img_icon_anim_move_x, 0);
		lv_anim_start(&weather_img_icon_anim_move_x);
		//Write animation: weather_img_icon move_y
	  	lv_anim_t weather_img_icon_anim_move_y;
	  	lv_anim_init(&weather_img_icon_anim_move_y);
	  	lv_anim_set_var(&weather_img_icon_anim_move_y, guider_ui.weather_img_icon);
	  	lv_anim_set_time(&weather_img_icon_anim_move_y, 800);
	  	lv_anim_set_delay(&weather_img_icon_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&weather_img_icon_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&weather_img_icon_anim_move_y, lv_obj_get_y(guider_ui.weather_img_icon), 227);
	  	lv_anim_set_path_cb(&weather_img_icon_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&weather_img_icon_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&weather_img_icon_anim_move_y, 0);
	  	lv_anim_set_playback_time(&weather_img_icon_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&weather_img_icon_anim_move_y, 0);
		lv_anim_start(&weather_img_icon_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.weather_hour_del == true) {
			          setup_scr_weather_hour(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.weather_hour, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.weather_del = true;
			    }
				break;
			}
			case LV_DIR_BOTTOM:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.home_analog_del == true) {
			          setup_scr_home_analog(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.weather_del = true;
			    }
				break;
			}
			case LV_DIR_TOP:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.fitness_del == true) {
			          setup_scr_fitness(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.fitness, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.weather_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
void events_init_weather(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->weather, weather_event_handler, LV_EVENT_ALL, NULL);
}
static void weather_hour_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: weather_hour_title move_x
	  	lv_anim_t weather_hour_title_anim_move_x;
	  	lv_anim_init(&weather_hour_title_anim_move_x);
	  	lv_anim_set_var(&weather_hour_title_anim_move_x, guider_ui.weather_hour_title);
	  	lv_anim_set_time(&weather_hour_title_anim_move_x, 800);
	  	lv_anim_set_delay(&weather_hour_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&weather_hour_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&weather_hour_title_anim_move_x, lv_obj_get_x(guider_ui.weather_hour_title), 0);
	  	lv_anim_set_path_cb(&weather_hour_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&weather_hour_title_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&weather_hour_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&weather_hour_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&weather_hour_title_anim_move_x, 0);
		lv_anim_start(&weather_hour_title_anim_move_x);
		//Write animation: weather_hour_title move_y
	  	lv_anim_t weather_hour_title_anim_move_y;
	  	lv_anim_init(&weather_hour_title_anim_move_y);
	  	lv_anim_set_var(&weather_hour_title_anim_move_y, guider_ui.weather_hour_title);
	  	lv_anim_set_time(&weather_hour_title_anim_move_y, 800);
	  	lv_anim_set_delay(&weather_hour_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&weather_hour_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&weather_hour_title_anim_move_y, lv_obj_get_y(guider_ui.weather_hour_title), 0);
	  	lv_anim_set_path_cb(&weather_hour_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&weather_hour_title_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&weather_hour_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&weather_hour_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&weather_hour_title_anim_move_y, 0);
		lv_anim_start(&weather_hour_title_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.weather_week_del == true) {
			          setup_scr_weather_week(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.weather_week, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.weather_hour_del = true;
			    }
				break;
			}
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.weather_del == true) {
			          setup_scr_weather(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.weather, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.weather_hour_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void weather_hour_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.weather_hour_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void weather_hour_left_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.weather_del == true) {
	          setup_scr_weather(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.weather, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.weather_hour_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void weather_hour_right_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.weather_week_del == true) {
	          setup_scr_weather_week(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.weather_week, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.weather_hour_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_weather_hour(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->weather_hour, weather_hour_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->weather_hour_home, weather_hour_home_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->weather_hour_left, weather_hour_left_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->weather_hour_right, weather_hour_right_event_handler, LV_EVENT_ALL, NULL);
}
static void weather_week_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: weather_week_week_title move_x
	  	lv_anim_t weather_week_week_title_anim_move_x;
	  	lv_anim_init(&weather_week_week_title_anim_move_x);
	  	lv_anim_set_var(&weather_week_week_title_anim_move_x, guider_ui.weather_week_week_title);
	  	lv_anim_set_time(&weather_week_week_title_anim_move_x, 800);
	  	lv_anim_set_delay(&weather_week_week_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&weather_week_week_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&weather_week_week_title_anim_move_x, lv_obj_get_x(guider_ui.weather_week_week_title), 0);
	  	lv_anim_set_path_cb(&weather_week_week_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&weather_week_week_title_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&weather_week_week_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&weather_week_week_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&weather_week_week_title_anim_move_x, 0);
		lv_anim_start(&weather_week_week_title_anim_move_x);
		//Write animation: weather_week_week_title move_y
	  	lv_anim_t weather_week_week_title_anim_move_y;
	  	lv_anim_init(&weather_week_week_title_anim_move_y);
	  	lv_anim_set_var(&weather_week_week_title_anim_move_y, guider_ui.weather_week_week_title);
	  	lv_anim_set_time(&weather_week_week_title_anim_move_y, 800);
	  	lv_anim_set_delay(&weather_week_week_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&weather_week_week_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&weather_week_week_title_anim_move_y, lv_obj_get_y(guider_ui.weather_week_week_title), 0);
	  	lv_anim_set_path_cb(&weather_week_week_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&weather_week_week_title_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&weather_week_week_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&weather_week_week_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&weather_week_week_title_anim_move_y, 0);
		lv_anim_start(&weather_week_week_title_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.air_quality_del == true) {
			          setup_scr_air_quality(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.air_quality, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.weather_week_del = true;
			    }
				break;
			}
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.weather_hour_del == true) {
			          setup_scr_weather_hour(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.weather_hour, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.weather_week_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void weather_week_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.weather_week_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void weather_week_left_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.weather_hour_del == true) {
	          setup_scr_weather_hour(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.weather_hour, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.weather_week_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void weather_week_right_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.air_quality_del == true) {
	          setup_scr_air_quality(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.air_quality, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.weather_week_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_weather_week(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->weather_week, weather_week_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->weather_week_home, weather_week_home_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->weather_week_left, weather_week_left_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->weather_week_right, weather_week_right_event_handler, LV_EVENT_ALL, NULL);
}
static void air_quality_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: air_quality_air_title move_x
	  	lv_anim_t air_quality_air_title_anim_move_x;
	  	lv_anim_init(&air_quality_air_title_anim_move_x);
	  	lv_anim_set_var(&air_quality_air_title_anim_move_x, guider_ui.air_quality_air_title);
	  	lv_anim_set_time(&air_quality_air_title_anim_move_x, 800);
	  	lv_anim_set_delay(&air_quality_air_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&air_quality_air_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&air_quality_air_title_anim_move_x, lv_obj_get_x(guider_ui.air_quality_air_title), 0);
	  	lv_anim_set_path_cb(&air_quality_air_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&air_quality_air_title_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&air_quality_air_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&air_quality_air_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&air_quality_air_title_anim_move_x, 0);
		lv_anim_start(&air_quality_air_title_anim_move_x);
		//Write animation: air_quality_air_title move_y
	  	lv_anim_t air_quality_air_title_anim_move_y;
	  	lv_anim_init(&air_quality_air_title_anim_move_y);
	  	lv_anim_set_var(&air_quality_air_title_anim_move_y, guider_ui.air_quality_air_title);
	  	lv_anim_set_time(&air_quality_air_title_anim_move_y, 800);
	  	lv_anim_set_delay(&air_quality_air_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&air_quality_air_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&air_quality_air_title_anim_move_y, lv_obj_get_y(guider_ui.air_quality_air_title), 0);
	  	lv_anim_set_path_cb(&air_quality_air_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&air_quality_air_title_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&air_quality_air_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&air_quality_air_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&air_quality_air_title_anim_move_y, 0);
		lv_anim_start(&air_quality_air_title_anim_move_y);
		//Write animation: air_quality_ade_text move_x
	  	lv_anim_t air_quality_ade_text_anim_move_x;
	  	lv_anim_init(&air_quality_ade_text_anim_move_x);
	  	lv_anim_set_var(&air_quality_ade_text_anim_move_x, guider_ui.air_quality_ade_text);
	  	lv_anim_set_time(&air_quality_ade_text_anim_move_x, 800);
	  	lv_anim_set_delay(&air_quality_ade_text_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&air_quality_ade_text_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&air_quality_ade_text_anim_move_x, lv_obj_get_x(guider_ui.air_quality_ade_text), 102);
	  	lv_anim_set_path_cb(&air_quality_ade_text_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&air_quality_ade_text_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&air_quality_ade_text_anim_move_x, 0);
	  	lv_anim_set_playback_time(&air_quality_ade_text_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&air_quality_ade_text_anim_move_x, 0);
		lv_anim_start(&air_quality_ade_text_anim_move_x);
		//Write animation: air_quality_ade_text move_y
	  	lv_anim_t air_quality_ade_text_anim_move_y;
	  	lv_anim_init(&air_quality_ade_text_anim_move_y);
	  	lv_anim_set_var(&air_quality_ade_text_anim_move_y, guider_ui.air_quality_ade_text);
	  	lv_anim_set_time(&air_quality_ade_text_anim_move_y, 800);
	  	lv_anim_set_delay(&air_quality_ade_text_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&air_quality_ade_text_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&air_quality_ade_text_anim_move_y, lv_obj_get_y(guider_ui.air_quality_ade_text), 315);
	  	lv_anim_set_path_cb(&air_quality_ade_text_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&air_quality_ade_text_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&air_quality_ade_text_anim_move_y, 0);
	  	lv_anim_set_playback_time(&air_quality_ade_text_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&air_quality_ade_text_anim_move_y, 0);
		lv_anim_start(&air_quality_ade_text_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.weather_week_del == true) {
			          setup_scr_weather_week(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.weather_week, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.air_quality_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void air_quality_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.air_quality_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void air_quality_left_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.weather_week_del == true) {
	          setup_scr_weather_week(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.weather_week, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.air_quality_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_air_quality(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->air_quality, air_quality_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->air_quality_home, air_quality_home_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->air_quality_left, air_quality_left_event_handler, LV_EVENT_ALL, NULL);
}
static void fitness_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: fitness_title move_x
	  	lv_anim_t fitness_title_anim_move_x;
	  	lv_anim_init(&fitness_title_anim_move_x);
	  	lv_anim_set_var(&fitness_title_anim_move_x, guider_ui.fitness_title);
	  	lv_anim_set_time(&fitness_title_anim_move_x, 800);
	  	lv_anim_set_delay(&fitness_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&fitness_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&fitness_title_anim_move_x, lv_obj_get_x(guider_ui.fitness_title), 0);
	  	lv_anim_set_path_cb(&fitness_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&fitness_title_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&fitness_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&fitness_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&fitness_title_anim_move_x, 0);
		lv_anim_start(&fitness_title_anim_move_x);
		//Write animation: fitness_title move_y
	  	lv_anim_t fitness_title_anim_move_y;
	  	lv_anim_init(&fitness_title_anim_move_y);
	  	lv_anim_set_var(&fitness_title_anim_move_y, guider_ui.fitness_title);
	  	lv_anim_set_time(&fitness_title_anim_move_y, 800);
	  	lv_anim_set_delay(&fitness_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&fitness_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&fitness_title_anim_move_y, lv_obj_get_y(guider_ui.fitness_title), 0);
	  	lv_anim_set_path_cb(&fitness_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&fitness_title_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&fitness_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&fitness_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&fitness_title_anim_move_y, 0);
		lv_anim_start(&fitness_title_anim_move_y);
		//Write animation: fitness_calorie_arc move_x
	  	lv_anim_t fitness_calorie_arc_anim_move_x;
	  	lv_anim_init(&fitness_calorie_arc_anim_move_x);
	  	lv_anim_set_var(&fitness_calorie_arc_anim_move_x, guider_ui.fitness_calorie_arc);
	  	lv_anim_set_time(&fitness_calorie_arc_anim_move_x, 500);
	  	lv_anim_set_delay(&fitness_calorie_arc_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&fitness_calorie_arc_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&fitness_calorie_arc_anim_move_x, lv_obj_get_x(guider_ui.fitness_calorie_arc), 7);
	  	lv_anim_set_path_cb(&fitness_calorie_arc_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&fitness_calorie_arc_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&fitness_calorie_arc_anim_move_x, 0);
	  	lv_anim_set_playback_time(&fitness_calorie_arc_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&fitness_calorie_arc_anim_move_x, 0);
		lv_anim_start(&fitness_calorie_arc_anim_move_x);
		//Write animation: fitness_calorie_arc move_y
	  	lv_anim_t fitness_calorie_arc_anim_move_y;
	  	lv_anim_init(&fitness_calorie_arc_anim_move_y);
	  	lv_anim_set_var(&fitness_calorie_arc_anim_move_y, guider_ui.fitness_calorie_arc);
	  	lv_anim_set_time(&fitness_calorie_arc_anim_move_y, 500);
	  	lv_anim_set_delay(&fitness_calorie_arc_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&fitness_calorie_arc_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&fitness_calorie_arc_anim_move_y, lv_obj_get_y(guider_ui.fitness_calorie_arc), 49);
	  	lv_anim_set_path_cb(&fitness_calorie_arc_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&fitness_calorie_arc_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&fitness_calorie_arc_anim_move_y, 0);
	  	lv_anim_set_playback_time(&fitness_calorie_arc_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&fitness_calorie_arc_anim_move_y, 0);
		lv_anim_start(&fitness_calorie_arc_anim_move_y);
		//Write animation: fitness_distance_arc move_x
	  	lv_anim_t fitness_distance_arc_anim_move_x;
	  	lv_anim_init(&fitness_distance_arc_anim_move_x);
	  	lv_anim_set_var(&fitness_distance_arc_anim_move_x, guider_ui.fitness_distance_arc);
	  	lv_anim_set_time(&fitness_distance_arc_anim_move_x, 500);
	  	lv_anim_set_delay(&fitness_distance_arc_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&fitness_distance_arc_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&fitness_distance_arc_anim_move_x, lv_obj_get_x(guider_ui.fitness_distance_arc), 32);
	  	lv_anim_set_path_cb(&fitness_distance_arc_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&fitness_distance_arc_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&fitness_distance_arc_anim_move_x, 0);
	  	lv_anim_set_playback_time(&fitness_distance_arc_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&fitness_distance_arc_anim_move_x, 0);
		lv_anim_start(&fitness_distance_arc_anim_move_x);
		//Write animation: fitness_distance_arc move_y
	  	lv_anim_t fitness_distance_arc_anim_move_y;
	  	lv_anim_init(&fitness_distance_arc_anim_move_y);
	  	lv_anim_set_var(&fitness_distance_arc_anim_move_y, guider_ui.fitness_distance_arc);
	  	lv_anim_set_time(&fitness_distance_arc_anim_move_y, 500);
	  	lv_anim_set_delay(&fitness_distance_arc_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&fitness_distance_arc_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&fitness_distance_arc_anim_move_y, lv_obj_get_y(guider_ui.fitness_distance_arc), 76);
	  	lv_anim_set_path_cb(&fitness_distance_arc_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&fitness_distance_arc_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&fitness_distance_arc_anim_move_y, 0);
	  	lv_anim_set_playback_time(&fitness_distance_arc_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&fitness_distance_arc_anim_move_y, 0);
		lv_anim_start(&fitness_distance_arc_anim_move_y);
		//Write animation: fitness_duration_arc move_x
	  	lv_anim_t fitness_duration_arc_anim_move_x;
	  	lv_anim_init(&fitness_duration_arc_anim_move_x);
	  	lv_anim_set_var(&fitness_duration_arc_anim_move_x, guider_ui.fitness_duration_arc);
	  	lv_anim_set_time(&fitness_duration_arc_anim_move_x, 500);
	  	lv_anim_set_delay(&fitness_duration_arc_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&fitness_duration_arc_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&fitness_duration_arc_anim_move_x, lv_obj_get_x(guider_ui.fitness_duration_arc), 57);
	  	lv_anim_set_path_cb(&fitness_duration_arc_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&fitness_duration_arc_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&fitness_duration_arc_anim_move_x, 0);
	  	lv_anim_set_playback_time(&fitness_duration_arc_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&fitness_duration_arc_anim_move_x, 0);
		lv_anim_start(&fitness_duration_arc_anim_move_x);
		//Write animation: fitness_duration_arc move_y
	  	lv_anim_t fitness_duration_arc_anim_move_y;
	  	lv_anim_init(&fitness_duration_arc_anim_move_y);
	  	lv_anim_set_var(&fitness_duration_arc_anim_move_y, guider_ui.fitness_duration_arc);
	  	lv_anim_set_time(&fitness_duration_arc_anim_move_y, 500);
	  	lv_anim_set_delay(&fitness_duration_arc_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&fitness_duration_arc_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&fitness_duration_arc_anim_move_y, lv_obj_get_y(guider_ui.fitness_duration_arc), 99);
	  	lv_anim_set_path_cb(&fitness_duration_arc_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&fitness_duration_arc_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&fitness_duration_arc_anim_move_y, 0);
	  	lv_anim_set_playback_time(&fitness_duration_arc_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&fitness_duration_arc_anim_move_y, 0);
		lv_anim_start(&fitness_duration_arc_anim_move_y);
		//Write animation: fitness_pluse_arc move_x
	  	lv_anim_t fitness_pluse_arc_anim_move_x;
	  	lv_anim_init(&fitness_pluse_arc_anim_move_x);
	  	lv_anim_set_var(&fitness_pluse_arc_anim_move_x, guider_ui.fitness_pluse_arc);
	  	lv_anim_set_time(&fitness_pluse_arc_anim_move_x, 500);
	  	lv_anim_set_delay(&fitness_pluse_arc_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&fitness_pluse_arc_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&fitness_pluse_arc_anim_move_x, lv_obj_get_x(guider_ui.fitness_pluse_arc), 82);
	  	lv_anim_set_path_cb(&fitness_pluse_arc_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&fitness_pluse_arc_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&fitness_pluse_arc_anim_move_x, 0);
	  	lv_anim_set_playback_time(&fitness_pluse_arc_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&fitness_pluse_arc_anim_move_x, 0);
		lv_anim_start(&fitness_pluse_arc_anim_move_x);
		//Write animation: fitness_pluse_arc move_y
	  	lv_anim_t fitness_pluse_arc_anim_move_y;
	  	lv_anim_init(&fitness_pluse_arc_anim_move_y);
	  	lv_anim_set_var(&fitness_pluse_arc_anim_move_y, guider_ui.fitness_pluse_arc);
	  	lv_anim_set_time(&fitness_pluse_arc_anim_move_y, 500);
	  	lv_anim_set_delay(&fitness_pluse_arc_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&fitness_pluse_arc_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&fitness_pluse_arc_anim_move_y, lv_obj_get_y(guider_ui.fitness_pluse_arc), 124);
	  	lv_anim_set_path_cb(&fitness_pluse_arc_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&fitness_pluse_arc_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&fitness_pluse_arc_anim_move_y, 0);
	  	lv_anim_set_playback_time(&fitness_pluse_arc_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&fitness_pluse_arc_anim_move_y, 0);
		lv_anim_start(&fitness_pluse_arc_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_BOTTOM:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.weather_del == true) {
			          setup_scr_weather(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.weather, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.fitness_del = true;
			    }
				break;
			}
			case LV_DIR_TOP:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.music_player_del == true) {
			          setup_scr_music_player(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.music_player, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.fitness_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void fitness_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.fitness_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_fitness(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->fitness, fitness_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->fitness_home, fitness_home_event_handler, LV_EVENT_ALL, NULL);
}
static void music_player_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_BOTTOM:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.fitness_del == true) {
			          setup_scr_fitness(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.fitness, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.music_player_del = true;
			    }
				break;
			}
			case LV_DIR_TOP:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.flight_del == true) {
			          setup_scr_flight(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.flight, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.music_player_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void music_player_img_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.music_player_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void music_player_img_puse_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_clear_flag(guider_ui.music_player_img_play, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.music_player_img_puse, LV_OBJ_FLAG_HIDDEN);
		break;
	}
	default:
		break;
	}
}
static void music_player_img_play_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_add_flag(guider_ui.music_player_img_play, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.music_player_img_puse, LV_OBJ_FLAG_HIDDEN);
		break;
	}
	default:
		break;
	}
}
void events_init_music_player(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->music_player, music_player_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->music_player_img_home, music_player_img_home_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->music_player_img_puse, music_player_img_puse_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->music_player_img_play, music_player_img_play_event_handler, LV_EVENT_ALL, NULL);
}
static void flight_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: flight_flight_location move_x
	  	lv_anim_t flight_flight_location_anim_move_x;
	  	lv_anim_init(&flight_flight_location_anim_move_x);
	  	lv_anim_set_var(&flight_flight_location_anim_move_x, guider_ui.flight_flight_location);
	  	lv_anim_set_time(&flight_flight_location_anim_move_x, 800);
	  	lv_anim_set_delay(&flight_flight_location_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&flight_flight_location_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&flight_flight_location_anim_move_x, lv_obj_get_x(guider_ui.flight_flight_location), 36);
	  	lv_anim_set_path_cb(&flight_flight_location_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&flight_flight_location_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&flight_flight_location_anim_move_x, 0);
	  	lv_anim_set_playback_time(&flight_flight_location_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&flight_flight_location_anim_move_x, 0);
		lv_anim_start(&flight_flight_location_anim_move_x);
		//Write animation: flight_flight_location move_y
	  	lv_anim_t flight_flight_location_anim_move_y;
	  	lv_anim_init(&flight_flight_location_anim_move_y);
	  	lv_anim_set_var(&flight_flight_location_anim_move_y, guider_ui.flight_flight_location);
	  	lv_anim_set_time(&flight_flight_location_anim_move_y, 800);
	  	lv_anim_set_delay(&flight_flight_location_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&flight_flight_location_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&flight_flight_location_anim_move_y, lv_obj_get_y(guider_ui.flight_flight_location), 86);
	  	lv_anim_set_path_cb(&flight_flight_location_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&flight_flight_location_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&flight_flight_location_anim_move_y, 0);
	  	lv_anim_set_playback_time(&flight_flight_location_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&flight_flight_location_anim_move_y, 0);
		lv_anim_start(&flight_flight_location_anim_move_y);
		//Write animation: flight_flight_seat move_x
	  	lv_anim_t flight_flight_seat_anim_move_x;
	  	lv_anim_init(&flight_flight_seat_anim_move_x);
	  	lv_anim_set_var(&flight_flight_seat_anim_move_x, guider_ui.flight_flight_seat);
	  	lv_anim_set_time(&flight_flight_seat_anim_move_x, 800);
	  	lv_anim_set_delay(&flight_flight_seat_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&flight_flight_seat_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&flight_flight_seat_anim_move_x, lv_obj_get_x(guider_ui.flight_flight_seat), 64);
	  	lv_anim_set_path_cb(&flight_flight_seat_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&flight_flight_seat_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&flight_flight_seat_anim_move_x, 0);
	  	lv_anim_set_playback_time(&flight_flight_seat_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&flight_flight_seat_anim_move_x, 0);
		lv_anim_start(&flight_flight_seat_anim_move_x);
		//Write animation: flight_flight_seat move_y
	  	lv_anim_t flight_flight_seat_anim_move_y;
	  	lv_anim_init(&flight_flight_seat_anim_move_y);
	  	lv_anim_set_var(&flight_flight_seat_anim_move_y, guider_ui.flight_flight_seat);
	  	lv_anim_set_time(&flight_flight_seat_anim_move_y, 800);
	  	lv_anim_set_delay(&flight_flight_seat_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&flight_flight_seat_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&flight_flight_seat_anim_move_y, lv_obj_get_y(guider_ui.flight_flight_seat), 295);
	  	lv_anim_set_path_cb(&flight_flight_seat_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&flight_flight_seat_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&flight_flight_seat_anim_move_y, 0);
	  	lv_anim_set_playback_time(&flight_flight_seat_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&flight_flight_seat_anim_move_y, 0);
		lv_anim_start(&flight_flight_seat_anim_move_y);
		//Write animation: flight_title move_x
	  	lv_anim_t flight_title_anim_move_x;
	  	lv_anim_init(&flight_title_anim_move_x);
	  	lv_anim_set_var(&flight_title_anim_move_x, guider_ui.flight_title);
	  	lv_anim_set_time(&flight_title_anim_move_x, 800);
	  	lv_anim_set_delay(&flight_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&flight_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&flight_title_anim_move_x, lv_obj_get_x(guider_ui.flight_title), 0);
	  	lv_anim_set_path_cb(&flight_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&flight_title_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&flight_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&flight_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&flight_title_anim_move_x, 0);
		lv_anim_start(&flight_title_anim_move_x);
		//Write animation: flight_title move_y
	  	lv_anim_t flight_title_anim_move_y;
	  	lv_anim_init(&flight_title_anim_move_y);
	  	lv_anim_set_var(&flight_title_anim_move_y, guider_ui.flight_title);
	  	lv_anim_set_time(&flight_title_anim_move_y, 800);
	  	lv_anim_set_delay(&flight_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&flight_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&flight_title_anim_move_y, lv_obj_get_y(guider_ui.flight_title), 0);
	  	lv_anim_set_path_cb(&flight_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&flight_title_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&flight_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&flight_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&flight_title_anim_move_y, 0);
		lv_anim_start(&flight_title_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.flight_info_del == true) {
			          setup_scr_flight_info(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.flight_info, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.flight_del = true;
			    }
				break;
			}
			case LV_DIR_BOTTOM:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.music_player_del == true) {
			          setup_scr_music_player(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.music_player, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.flight_del = true;
			    }
				break;
			}
			case LV_DIR_TOP:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.navigation_del == true) {
			          setup_scr_navigation(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.navigation, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.flight_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void flight_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.flight_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_flight(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->flight, flight_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->flight_home, flight_home_event_handler, LV_EVENT_ALL, NULL);
}
static void flight_info_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: flight_info_title move_x
	  	lv_anim_t flight_info_title_anim_move_x;
	  	lv_anim_init(&flight_info_title_anim_move_x);
	  	lv_anim_set_var(&flight_info_title_anim_move_x, guider_ui.flight_info_title);
	  	lv_anim_set_time(&flight_info_title_anim_move_x, 800);
	  	lv_anim_set_delay(&flight_info_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&flight_info_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&flight_info_title_anim_move_x, lv_obj_get_x(guider_ui.flight_info_title), 0);
	  	lv_anim_set_path_cb(&flight_info_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&flight_info_title_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&flight_info_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&flight_info_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&flight_info_title_anim_move_x, 0);
		lv_anim_start(&flight_info_title_anim_move_x);
		//Write animation: flight_info_title move_y
	  	lv_anim_t flight_info_title_anim_move_y;
	  	lv_anim_init(&flight_info_title_anim_move_y);
	  	lv_anim_set_var(&flight_info_title_anim_move_y, guider_ui.flight_info_title);
	  	lv_anim_set_time(&flight_info_title_anim_move_y, 800);
	  	lv_anim_set_delay(&flight_info_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&flight_info_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&flight_info_title_anim_move_y, lv_obj_get_y(guider_ui.flight_info_title), 0);
	  	lv_anim_set_path_cb(&flight_info_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&flight_info_title_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&flight_info_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&flight_info_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&flight_info_title_anim_move_y, 0);
		lv_anim_start(&flight_info_title_anim_move_y);
		//Write animation: flight_info_qrcode move_x
	  	lv_anim_t flight_info_qrcode_anim_move_x;
	  	lv_anim_init(&flight_info_qrcode_anim_move_x);
	  	lv_anim_set_var(&flight_info_qrcode_anim_move_x, guider_ui.flight_info_qrcode);
	  	lv_anim_set_time(&flight_info_qrcode_anim_move_x, 800);
	  	lv_anim_set_delay(&flight_info_qrcode_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&flight_info_qrcode_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&flight_info_qrcode_anim_move_x, lv_obj_get_x(guider_ui.flight_info_qrcode), 93);
	  	lv_anim_set_path_cb(&flight_info_qrcode_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&flight_info_qrcode_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&flight_info_qrcode_anim_move_x, 0);
	  	lv_anim_set_playback_time(&flight_info_qrcode_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&flight_info_qrcode_anim_move_x, 0);
		lv_anim_start(&flight_info_qrcode_anim_move_x);
		//Write animation: flight_info_qrcode move_y
	  	lv_anim_t flight_info_qrcode_anim_move_y;
	  	lv_anim_init(&flight_info_qrcode_anim_move_y);
	  	lv_anim_set_var(&flight_info_qrcode_anim_move_y, guider_ui.flight_info_qrcode);
	  	lv_anim_set_time(&flight_info_qrcode_anim_move_y, 800);
	  	lv_anim_set_delay(&flight_info_qrcode_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&flight_info_qrcode_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&flight_info_qrcode_anim_move_y, lv_obj_get_y(guider_ui.flight_info_qrcode), 144);
	  	lv_anim_set_path_cb(&flight_info_qrcode_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&flight_info_qrcode_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&flight_info_qrcode_anim_move_y, 0);
	  	lv_anim_set_playback_time(&flight_info_qrcode_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&flight_info_qrcode_anim_move_y, 0);
		lv_anim_start(&flight_info_qrcode_anim_move_y);
		//Write animation: flight_info_flight_number move_x
	  	lv_anim_t flight_info_flight_number_anim_move_x;
	  	lv_anim_init(&flight_info_flight_number_anim_move_x);
	  	lv_anim_set_var(&flight_info_flight_number_anim_move_x, guider_ui.flight_info_flight_number);
	  	lv_anim_set_time(&flight_info_flight_number_anim_move_x, 800);
	  	lv_anim_set_delay(&flight_info_flight_number_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&flight_info_flight_number_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&flight_info_flight_number_anim_move_x, lv_obj_get_x(guider_ui.flight_info_flight_number), 129);
	  	lv_anim_set_path_cb(&flight_info_flight_number_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&flight_info_flight_number_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&flight_info_flight_number_anim_move_x, 0);
	  	lv_anim_set_playback_time(&flight_info_flight_number_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&flight_info_flight_number_anim_move_x, 0);
		lv_anim_start(&flight_info_flight_number_anim_move_x);
		//Write animation: flight_info_flight_number move_y
	  	lv_anim_t flight_info_flight_number_anim_move_y;
	  	lv_anim_init(&flight_info_flight_number_anim_move_y);
	  	lv_anim_set_var(&flight_info_flight_number_anim_move_y, guider_ui.flight_info_flight_number);
	  	lv_anim_set_time(&flight_info_flight_number_anim_move_y, 800);
	  	lv_anim_set_delay(&flight_info_flight_number_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&flight_info_flight_number_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&flight_info_flight_number_anim_move_y, lv_obj_get_y(guider_ui.flight_info_flight_number), 102);
	  	lv_anim_set_path_cb(&flight_info_flight_number_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&flight_info_flight_number_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&flight_info_flight_number_anim_move_y, 0);
	  	lv_anim_set_playback_time(&flight_info_flight_number_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&flight_info_flight_number_anim_move_y, 0);
		lv_anim_start(&flight_info_flight_number_anim_move_y);
		//Write animation: flight_info_number_text move_x
	  	lv_anim_t flight_info_number_text_anim_move_x;
	  	lv_anim_init(&flight_info_number_text_anim_move_x);
	  	lv_anim_set_var(&flight_info_number_text_anim_move_x, guider_ui.flight_info_number_text);
	  	lv_anim_set_time(&flight_info_number_text_anim_move_x, 800);
	  	lv_anim_set_delay(&flight_info_number_text_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&flight_info_number_text_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&flight_info_number_text_anim_move_x, lv_obj_get_x(guider_ui.flight_info_number_text), 120);
	  	lv_anim_set_path_cb(&flight_info_number_text_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&flight_info_number_text_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&flight_info_number_text_anim_move_x, 0);
	  	lv_anim_set_playback_time(&flight_info_number_text_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&flight_info_number_text_anim_move_x, 0);
		lv_anim_start(&flight_info_number_text_anim_move_x);
		//Write animation: flight_info_number_text move_y
	  	lv_anim_t flight_info_number_text_anim_move_y;
	  	lv_anim_init(&flight_info_number_text_anim_move_y);
	  	lv_anim_set_var(&flight_info_number_text_anim_move_y, guider_ui.flight_info_number_text);
	  	lv_anim_set_time(&flight_info_number_text_anim_move_y, 800);
	  	lv_anim_set_delay(&flight_info_number_text_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&flight_info_number_text_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&flight_info_number_text_anim_move_y, lv_obj_get_y(guider_ui.flight_info_number_text), 85);
	  	lv_anim_set_path_cb(&flight_info_number_text_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&flight_info_number_text_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&flight_info_number_text_anim_move_y, 0);
	  	lv_anim_set_playback_time(&flight_info_number_text_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&flight_info_number_text_anim_move_y, 0);
		lv_anim_start(&flight_info_number_text_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.flight_del == true) {
			          setup_scr_flight(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.flight, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.flight_info_del = true;
			    }
				break;
			}
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.flight_del == true) {
			          setup_scr_flight(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.flight, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.flight_info_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void flight_info_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.flight_info_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_flight_info(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->flight_info, flight_info_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->flight_info_home, flight_info_home_event_handler, LV_EVENT_ALL, NULL);
}
static void navigation_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: navigation_indicator move_x
	  	lv_anim_t navigation_indicator_anim_move_x;
	  	lv_anim_init(&navigation_indicator_anim_move_x);
	  	lv_anim_set_var(&navigation_indicator_anim_move_x, guider_ui.navigation_indicator);
	  	lv_anim_set_time(&navigation_indicator_anim_move_x, 800);
	  	lv_anim_set_delay(&navigation_indicator_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&navigation_indicator_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&navigation_indicator_anim_move_x, lv_obj_get_x(guider_ui.navigation_indicator), 88);
	  	lv_anim_set_path_cb(&navigation_indicator_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&navigation_indicator_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&navigation_indicator_anim_move_x, 0);
	  	lv_anim_set_playback_time(&navigation_indicator_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&navigation_indicator_anim_move_x, 0);
		lv_anim_start(&navigation_indicator_anim_move_x);
		//Write animation: navigation_indicator move_y
	  	lv_anim_t navigation_indicator_anim_move_y;
	  	lv_anim_init(&navigation_indicator_anim_move_y);
	  	lv_anim_set_var(&navigation_indicator_anim_move_y, guider_ui.navigation_indicator);
	  	lv_anim_set_time(&navigation_indicator_anim_move_y, 800);
	  	lv_anim_set_delay(&navigation_indicator_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&navigation_indicator_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&navigation_indicator_anim_move_y, lv_obj_get_y(guider_ui.navigation_indicator), 291);
	  	lv_anim_set_path_cb(&navigation_indicator_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&navigation_indicator_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&navigation_indicator_anim_move_y, 0);
	  	lv_anim_set_playback_time(&navigation_indicator_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&navigation_indicator_anim_move_y, 0);
		lv_anim_start(&navigation_indicator_anim_move_y);
		//Write animation: navigation_road_name move_x
	  	lv_anim_t navigation_road_name_anim_move_x;
	  	lv_anim_init(&navigation_road_name_anim_move_x);
	  	lv_anim_set_var(&navigation_road_name_anim_move_x, guider_ui.navigation_road_name);
	  	lv_anim_set_time(&navigation_road_name_anim_move_x, 800);
	  	lv_anim_set_delay(&navigation_road_name_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&navigation_road_name_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&navigation_road_name_anim_move_x, lv_obj_get_x(guider_ui.navigation_road_name), 83);
	  	lv_anim_set_path_cb(&navigation_road_name_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&navigation_road_name_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&navigation_road_name_anim_move_x, 0);
	  	lv_anim_set_playback_time(&navigation_road_name_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&navigation_road_name_anim_move_x, 0);
		lv_anim_start(&navigation_road_name_anim_move_x);
		//Write animation: navigation_road_name move_y
	  	lv_anim_t navigation_road_name_anim_move_y;
	  	lv_anim_init(&navigation_road_name_anim_move_y);
	  	lv_anim_set_var(&navigation_road_name_anim_move_y, guider_ui.navigation_road_name);
	  	lv_anim_set_time(&navigation_road_name_anim_move_y, 800);
	  	lv_anim_set_delay(&navigation_road_name_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&navigation_road_name_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&navigation_road_name_anim_move_y, lv_obj_get_y(guider_ui.navigation_road_name), 89);
	  	lv_anim_set_path_cb(&navigation_road_name_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&navigation_road_name_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&navigation_road_name_anim_move_y, 0);
	  	lv_anim_set_playback_time(&navigation_road_name_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&navigation_road_name_anim_move_y, 0);
		lv_anim_start(&navigation_road_name_anim_move_y);
		//Write animation: navigation_next_roadName move_x
	  	lv_anim_t navigation_next_roadName_anim_move_x;
	  	lv_anim_init(&navigation_next_roadName_anim_move_x);
	  	lv_anim_set_var(&navigation_next_roadName_anim_move_x, guider_ui.navigation_next_roadName);
	  	lv_anim_set_time(&navigation_next_roadName_anim_move_x, 800);
	  	lv_anim_set_delay(&navigation_next_roadName_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&navigation_next_roadName_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&navigation_next_roadName_anim_move_x, lv_obj_get_x(guider_ui.navigation_next_roadName), 93);
	  	lv_anim_set_path_cb(&navigation_next_roadName_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&navigation_next_roadName_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&navigation_next_roadName_anim_move_x, 0);
	  	lv_anim_set_playback_time(&navigation_next_roadName_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&navigation_next_roadName_anim_move_x, 0);
		lv_anim_start(&navigation_next_roadName_anim_move_x);
		//Write animation: navigation_next_roadName move_y
	  	lv_anim_t navigation_next_roadName_anim_move_y;
	  	lv_anim_init(&navigation_next_roadName_anim_move_y);
	  	lv_anim_set_var(&navigation_next_roadName_anim_move_y, guider_ui.navigation_next_roadName);
	  	lv_anim_set_time(&navigation_next_roadName_anim_move_y, 800);
	  	lv_anim_set_delay(&navigation_next_roadName_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&navigation_next_roadName_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&navigation_next_roadName_anim_move_y, lv_obj_get_y(guider_ui.navigation_next_roadName), 120);
	  	lv_anim_set_path_cb(&navigation_next_roadName_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&navigation_next_roadName_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&navigation_next_roadName_anim_move_y, 0);
	  	lv_anim_set_playback_time(&navigation_next_roadName_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&navigation_next_roadName_anim_move_y, 0);
		lv_anim_start(&navigation_next_roadName_anim_move_y);
		//Write animation: navigation_title move_x
	  	lv_anim_t navigation_title_anim_move_x;
	  	lv_anim_init(&navigation_title_anim_move_x);
	  	lv_anim_set_var(&navigation_title_anim_move_x, guider_ui.navigation_title);
	  	lv_anim_set_time(&navigation_title_anim_move_x, 800);
	  	lv_anim_set_delay(&navigation_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&navigation_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&navigation_title_anim_move_x, lv_obj_get_x(guider_ui.navigation_title), 0);
	  	lv_anim_set_path_cb(&navigation_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&navigation_title_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&navigation_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&navigation_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&navigation_title_anim_move_x, 0);
		lv_anim_start(&navigation_title_anim_move_x);
		//Write animation: navigation_title move_y
	  	lv_anim_t navigation_title_anim_move_y;
	  	lv_anim_init(&navigation_title_anim_move_y);
	  	lv_anim_set_var(&navigation_title_anim_move_y, guider_ui.navigation_title);
	  	lv_anim_set_time(&navigation_title_anim_move_y, 800);
	  	lv_anim_set_delay(&navigation_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&navigation_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&navigation_title_anim_move_y, lv_obj_get_y(guider_ui.navigation_title), 0);
	  	lv_anim_set_path_cb(&navigation_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&navigation_title_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&navigation_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&navigation_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&navigation_title_anim_move_y, 0);
		lv_anim_start(&navigation_title_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_BOTTOM:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.flight_del == true) {
			          setup_scr_flight(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.flight, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.navigation_del = true;
			    }
				break;
			}
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.position_del == true) {
			          setup_scr_position(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.position, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.navigation_del = true;
			    }
				break;
			}
			case LV_DIR_TOP:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.payment_del == true) {
			          setup_scr_payment(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.payment, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.navigation_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void navigation_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.navigation_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_navigation(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->navigation, navigation_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->navigation_home, navigation_home_event_handler, LV_EVENT_ALL, NULL);
}
static void position_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: position_bottom move_x
	  	lv_anim_t position_bottom_anim_move_x;
	  	lv_anim_init(&position_bottom_anim_move_x);
	  	lv_anim_set_var(&position_bottom_anim_move_x, guider_ui.position_bottom);
	  	lv_anim_set_time(&position_bottom_anim_move_x, 800);
	  	lv_anim_set_delay(&position_bottom_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&position_bottom_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&position_bottom_anim_move_x, lv_obj_get_x(guider_ui.position_bottom), 96);
	  	lv_anim_set_path_cb(&position_bottom_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&position_bottom_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&position_bottom_anim_move_x, 0);
	  	lv_anim_set_playback_time(&position_bottom_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&position_bottom_anim_move_x, 0);
		lv_anim_start(&position_bottom_anim_move_x);
		//Write animation: position_bottom move_y
	  	lv_anim_t position_bottom_anim_move_y;
	  	lv_anim_init(&position_bottom_anim_move_y);
	  	lv_anim_set_var(&position_bottom_anim_move_y, guider_ui.position_bottom);
	  	lv_anim_set_time(&position_bottom_anim_move_y, 800);
	  	lv_anim_set_delay(&position_bottom_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&position_bottom_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&position_bottom_anim_move_y, lv_obj_get_y(guider_ui.position_bottom), 290);
	  	lv_anim_set_path_cb(&position_bottom_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&position_bottom_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&position_bottom_anim_move_y, 0);
	  	lv_anim_set_playback_time(&position_bottom_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&position_bottom_anim_move_y, 0);
		lv_anim_start(&position_bottom_anim_move_y);
		//Write animation: position_title move_x
	  	lv_anim_t position_title_anim_move_x;
	  	lv_anim_init(&position_title_anim_move_x);
	  	lv_anim_set_var(&position_title_anim_move_x, guider_ui.position_title);
	  	lv_anim_set_time(&position_title_anim_move_x, 800);
	  	lv_anim_set_delay(&position_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&position_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&position_title_anim_move_x, lv_obj_get_x(guider_ui.position_title), 0);
	  	lv_anim_set_path_cb(&position_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&position_title_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&position_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&position_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&position_title_anim_move_x, 0);
		lv_anim_start(&position_title_anim_move_x);
		//Write animation: position_title move_y
	  	lv_anim_t position_title_anim_move_y;
	  	lv_anim_init(&position_title_anim_move_y);
	  	lv_anim_set_var(&position_title_anim_move_y, guider_ui.position_title);
	  	lv_anim_set_time(&position_title_anim_move_y, 800);
	  	lv_anim_set_delay(&position_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&position_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&position_title_anim_move_y, lv_obj_get_y(guider_ui.position_title), 0);
	  	lv_anim_set_path_cb(&position_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&position_title_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&position_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&position_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&position_title_anim_move_y, 0);
		lv_anim_start(&position_title_anim_move_y);
		lv_obj_clear_flag(guider_ui.position_location_icon, LV_OBJ_FLAG_CLICKABLE);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.navigation_del == true) {
			          setup_scr_navigation(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.navigation, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.position_del = true;
			    }
				break;
			}
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.navigation_del == true) {
			          setup_scr_navigation(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.navigation, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.position_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void position_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.position_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_position(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->position, position_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->position_home, position_home_event_handler, LV_EVENT_ALL, NULL);
}
static void payment_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: payment_bank_info move_x
	  	lv_anim_t payment_bank_info_anim_move_x;
	  	lv_anim_init(&payment_bank_info_anim_move_x);
	  	lv_anim_set_var(&payment_bank_info_anim_move_x, guider_ui.payment_bank_info);
	  	lv_anim_set_time(&payment_bank_info_anim_move_x, 800);
	  	lv_anim_set_delay(&payment_bank_info_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&payment_bank_info_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&payment_bank_info_anim_move_x, lv_obj_get_x(guider_ui.payment_bank_info), 63);
	  	lv_anim_set_path_cb(&payment_bank_info_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&payment_bank_info_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&payment_bank_info_anim_move_x, 0);
	  	lv_anim_set_playback_time(&payment_bank_info_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&payment_bank_info_anim_move_x, 0);
		lv_anim_start(&payment_bank_info_anim_move_x);
		//Write animation: payment_bank_info move_y
	  	lv_anim_t payment_bank_info_anim_move_y;
	  	lv_anim_init(&payment_bank_info_anim_move_y);
	  	lv_anim_set_var(&payment_bank_info_anim_move_y, guider_ui.payment_bank_info);
	  	lv_anim_set_time(&payment_bank_info_anim_move_y, 800);
	  	lv_anim_set_delay(&payment_bank_info_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&payment_bank_info_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&payment_bank_info_anim_move_y, lv_obj_get_y(guider_ui.payment_bank_info), 313);
	  	lv_anim_set_path_cb(&payment_bank_info_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&payment_bank_info_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&payment_bank_info_anim_move_y, 0);
	  	lv_anim_set_playback_time(&payment_bank_info_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&payment_bank_info_anim_move_y, 0);
		lv_anim_start(&payment_bank_info_anim_move_y);
		//Write animation: payment_amount move_x
	  	lv_anim_t payment_amount_anim_move_x;
	  	lv_anim_init(&payment_amount_anim_move_x);
	  	lv_anim_set_var(&payment_amount_anim_move_x, guider_ui.payment_amount);
	  	lv_anim_set_time(&payment_amount_anim_move_x, 1000);
	  	lv_anim_set_delay(&payment_amount_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&payment_amount_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&payment_amount_anim_move_x, lv_obj_get_x(guider_ui.payment_amount), 92);
	  	lv_anim_set_path_cb(&payment_amount_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&payment_amount_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&payment_amount_anim_move_x, 0);
	  	lv_anim_set_playback_time(&payment_amount_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&payment_amount_anim_move_x, 0);
		lv_anim_start(&payment_amount_anim_move_x);
		//Write animation: payment_amount move_y
	  	lv_anim_t payment_amount_anim_move_y;
	  	lv_anim_init(&payment_amount_anim_move_y);
	  	lv_anim_set_var(&payment_amount_anim_move_y, guider_ui.payment_amount);
	  	lv_anim_set_time(&payment_amount_anim_move_y, 1000);
	  	lv_anim_set_delay(&payment_amount_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&payment_amount_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&payment_amount_anim_move_y, lv_obj_get_y(guider_ui.payment_amount), 101);
	  	lv_anim_set_path_cb(&payment_amount_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&payment_amount_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&payment_amount_anim_move_y, 0);
	  	lv_anim_set_playback_time(&payment_amount_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&payment_amount_anim_move_y, 0);
		lv_anim_start(&payment_amount_anim_move_y);
		//Write animation: payment_next_buy move_x
	  	lv_anim_t payment_next_buy_anim_move_x;
	  	lv_anim_init(&payment_next_buy_anim_move_x);
	  	lv_anim_set_var(&payment_next_buy_anim_move_x, guider_ui.payment_next_buy);
	  	lv_anim_set_time(&payment_next_buy_anim_move_x, 800);
	  	lv_anim_set_delay(&payment_next_buy_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&payment_next_buy_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&payment_next_buy_anim_move_x, lv_obj_get_x(guider_ui.payment_next_buy), 130);
	  	lv_anim_set_path_cb(&payment_next_buy_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&payment_next_buy_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&payment_next_buy_anim_move_x, 0);
	  	lv_anim_set_playback_time(&payment_next_buy_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&payment_next_buy_anim_move_x, 0);
		lv_anim_start(&payment_next_buy_anim_move_x);
		//Write animation: payment_next_buy move_y
	  	lv_anim_t payment_next_buy_anim_move_y;
	  	lv_anim_init(&payment_next_buy_anim_move_y);
	  	lv_anim_set_var(&payment_next_buy_anim_move_y, guider_ui.payment_next_buy);
	  	lv_anim_set_time(&payment_next_buy_anim_move_y, 800);
	  	lv_anim_set_delay(&payment_next_buy_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&payment_next_buy_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&payment_next_buy_anim_move_y, lv_obj_get_y(guider_ui.payment_next_buy), 84);
	  	lv_anim_set_path_cb(&payment_next_buy_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&payment_next_buy_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&payment_next_buy_anim_move_y, 0);
	  	lv_anim_set_playback_time(&payment_next_buy_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&payment_next_buy_anim_move_y, 0);
		lv_anim_start(&payment_next_buy_anim_move_y);
		//Write animation: payment_title move_x
	  	lv_anim_t payment_title_anim_move_x;
	  	lv_anim_init(&payment_title_anim_move_x);
	  	lv_anim_set_var(&payment_title_anim_move_x, guider_ui.payment_title);
	  	lv_anim_set_time(&payment_title_anim_move_x, 800);
	  	lv_anim_set_delay(&payment_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&payment_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&payment_title_anim_move_x, lv_obj_get_x(guider_ui.payment_title), 0);
	  	lv_anim_set_path_cb(&payment_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&payment_title_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&payment_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&payment_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&payment_title_anim_move_x, 0);
		lv_anim_start(&payment_title_anim_move_x);
		//Write animation: payment_title move_y
	  	lv_anim_t payment_title_anim_move_y;
	  	lv_anim_init(&payment_title_anim_move_y);
	  	lv_anim_set_var(&payment_title_anim_move_y, guider_ui.payment_title);
	  	lv_anim_set_time(&payment_title_anim_move_y, 800);
	  	lv_anim_set_delay(&payment_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&payment_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&payment_title_anim_move_y, lv_obj_get_y(guider_ui.payment_title), 0);
	  	lv_anim_set_path_cb(&payment_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&payment_title_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&payment_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&payment_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&payment_title_anim_move_y, 0);
		lv_anim_start(&payment_title_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_BOTTOM:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.navigation_del == true) {
			          setup_scr_navigation(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.navigation, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.payment_del = true;
			    }
				break;
			}
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.payment_info_del == true) {
			          setup_scr_payment_info(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.payment_info, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.payment_del = true;
			    }
				break;
			}
			case LV_DIR_TOP:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.settings_del == true) {
			          setup_scr_settings(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.settings, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.payment_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void payment_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.payment_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_payment(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->payment, payment_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->payment_home, payment_home_event_handler, LV_EVENT_ALL, NULL);
}
static void payment_info_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: payment_info_pay_info move_x
	  	lv_anim_t payment_info_pay_info_anim_move_x;
	  	lv_anim_init(&payment_info_pay_info_anim_move_x);
	  	lv_anim_set_var(&payment_info_pay_info_anim_move_x, guider_ui.payment_info_pay_info);
	  	lv_anim_set_time(&payment_info_pay_info_anim_move_x, 800);
	  	lv_anim_set_delay(&payment_info_pay_info_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&payment_info_pay_info_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&payment_info_pay_info_anim_move_x, lv_obj_get_x(guider_ui.payment_info_pay_info), 69);
	  	lv_anim_set_path_cb(&payment_info_pay_info_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&payment_info_pay_info_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&payment_info_pay_info_anim_move_x, 0);
	  	lv_anim_set_playback_time(&payment_info_pay_info_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&payment_info_pay_info_anim_move_x, 0);
		lv_anim_start(&payment_info_pay_info_anim_move_x);
		//Write animation: payment_info_pay_info move_y
	  	lv_anim_t payment_info_pay_info_anim_move_y;
	  	lv_anim_init(&payment_info_pay_info_anim_move_y);
	  	lv_anim_set_var(&payment_info_pay_info_anim_move_y, guider_ui.payment_info_pay_info);
	  	lv_anim_set_time(&payment_info_pay_info_anim_move_y, 800);
	  	lv_anim_set_delay(&payment_info_pay_info_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&payment_info_pay_info_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&payment_info_pay_info_anim_move_y, lv_obj_get_y(guider_ui.payment_info_pay_info), 246);
	  	lv_anim_set_path_cb(&payment_info_pay_info_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&payment_info_pay_info_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&payment_info_pay_info_anim_move_y, 0);
	  	lv_anim_set_playback_time(&payment_info_pay_info_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&payment_info_pay_info_anim_move_y, 0);
		lv_anim_start(&payment_info_pay_info_anim_move_y);
		//Write animation: payment_info_title move_x
	  	lv_anim_t payment_info_title_anim_move_x;
	  	lv_anim_init(&payment_info_title_anim_move_x);
	  	lv_anim_set_var(&payment_info_title_anim_move_x, guider_ui.payment_info_title);
	  	lv_anim_set_time(&payment_info_title_anim_move_x, 800);
	  	lv_anim_set_delay(&payment_info_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&payment_info_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&payment_info_title_anim_move_x, lv_obj_get_x(guider_ui.payment_info_title), 0);
	  	lv_anim_set_path_cb(&payment_info_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&payment_info_title_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&payment_info_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&payment_info_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&payment_info_title_anim_move_x, 0);
		lv_anim_start(&payment_info_title_anim_move_x);
		//Write animation: payment_info_title move_y
	  	lv_anim_t payment_info_title_anim_move_y;
	  	lv_anim_init(&payment_info_title_anim_move_y);
	  	lv_anim_set_var(&payment_info_title_anim_move_y, guider_ui.payment_info_title);
	  	lv_anim_set_time(&payment_info_title_anim_move_y, 800);
	  	lv_anim_set_delay(&payment_info_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&payment_info_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&payment_info_title_anim_move_y, lv_obj_get_y(guider_ui.payment_info_title), 0);
	  	lv_anim_set_path_cb(&payment_info_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&payment_info_title_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&payment_info_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&payment_info_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&payment_info_title_anim_move_y, 0);
		lv_anim_start(&payment_info_title_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.payment_del == true) {
			          setup_scr_payment(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.payment, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.payment_info_del = true;
			    }
				break;
			}
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.payment_del == true) {
			          setup_scr_payment(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.payment, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.payment_info_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void payment_info_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.payment_info_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_payment_info(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->payment_info, payment_info_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->payment_info_home, payment_info_home_event_handler, LV_EVENT_ALL, NULL);
}
static void settings_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: settings_setting_info move_x
	  	lv_anim_t settings_setting_info_anim_move_x;
	  	lv_anim_init(&settings_setting_info_anim_move_x);
	  	lv_anim_set_var(&settings_setting_info_anim_move_x, guider_ui.settings_setting_info);
	  	lv_anim_set_time(&settings_setting_info_anim_move_x, 800);
	  	lv_anim_set_delay(&settings_setting_info_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&settings_setting_info_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&settings_setting_info_anim_move_x, lv_obj_get_x(guider_ui.settings_setting_info), 64);
	  	lv_anim_set_path_cb(&settings_setting_info_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&settings_setting_info_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&settings_setting_info_anim_move_x, 0);
	  	lv_anim_set_playback_time(&settings_setting_info_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&settings_setting_info_anim_move_x, 0);
		lv_anim_start(&settings_setting_info_anim_move_x);
		//Write animation: settings_setting_info move_y
	  	lv_anim_t settings_setting_info_anim_move_y;
	  	lv_anim_init(&settings_setting_info_anim_move_y);
	  	lv_anim_set_var(&settings_setting_info_anim_move_y, guider_ui.settings_setting_info);
	  	lv_anim_set_time(&settings_setting_info_anim_move_y, 800);
	  	lv_anim_set_delay(&settings_setting_info_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&settings_setting_info_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&settings_setting_info_anim_move_y, lv_obj_get_y(guider_ui.settings_setting_info), 89);
	  	lv_anim_set_path_cb(&settings_setting_info_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&settings_setting_info_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&settings_setting_info_anim_move_y, 0);
	  	lv_anim_set_playback_time(&settings_setting_info_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&settings_setting_info_anim_move_y, 0);
		lv_anim_start(&settings_setting_info_anim_move_y);
		//Write animation: settings_title move_x
	  	lv_anim_t settings_title_anim_move_x;
	  	lv_anim_init(&settings_title_anim_move_x);
	  	lv_anim_set_var(&settings_title_anim_move_x, guider_ui.settings_title);
	  	lv_anim_set_time(&settings_title_anim_move_x, 800);
	  	lv_anim_set_delay(&settings_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&settings_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&settings_title_anim_move_x, lv_obj_get_x(guider_ui.settings_title), 0);
	  	lv_anim_set_path_cb(&settings_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&settings_title_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&settings_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&settings_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&settings_title_anim_move_x, 0);
		lv_anim_start(&settings_title_anim_move_x);
		//Write animation: settings_title move_y
	  	lv_anim_t settings_title_anim_move_y;
	  	lv_anim_init(&settings_title_anim_move_y);
	  	lv_anim_set_var(&settings_title_anim_move_y, guider_ui.settings_title);
	  	lv_anim_set_time(&settings_title_anim_move_y, 800);
	  	lv_anim_set_delay(&settings_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&settings_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&settings_title_anim_move_y, lv_obj_get_y(guider_ui.settings_title), 0);
	  	lv_anim_set_path_cb(&settings_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&settings_title_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&settings_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&settings_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&settings_title_anim_move_y, 0);
		lv_anim_start(&settings_title_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_BOTTOM:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.payment_del == true) {
			          setup_scr_payment(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.payment, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.settings_del = true;
			    }
				break;
			}
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.battery_del == true) {
			          setup_scr_battery(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.battery, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.settings_del = true;
			    }
				break;
			}
			case LV_DIR_TOP:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.blood_oxygen_del == true) {
			          setup_scr_blood_oxygen(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.blood_oxygen, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.settings_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void settings_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.settings_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_settings(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->settings, settings_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_home, settings_home_event_handler, LV_EVENT_ALL, NULL);
}
static void battery_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: battery_setting_info move_x
	  	lv_anim_t battery_setting_info_anim_move_x;
	  	lv_anim_init(&battery_setting_info_anim_move_x);
	  	lv_anim_set_var(&battery_setting_info_anim_move_x, guider_ui.battery_setting_info);
	  	lv_anim_set_time(&battery_setting_info_anim_move_x, 800);
	  	lv_anim_set_delay(&battery_setting_info_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&battery_setting_info_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&battery_setting_info_anim_move_x, lv_obj_get_x(guider_ui.battery_setting_info), 24);
	  	lv_anim_set_path_cb(&battery_setting_info_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&battery_setting_info_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&battery_setting_info_anim_move_x, 0);
	  	lv_anim_set_playback_time(&battery_setting_info_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&battery_setting_info_anim_move_x, 0);
		lv_anim_start(&battery_setting_info_anim_move_x);
		//Write animation: battery_setting_info move_y
	  	lv_anim_t battery_setting_info_anim_move_y;
	  	lv_anim_init(&battery_setting_info_anim_move_y);
	  	lv_anim_set_var(&battery_setting_info_anim_move_y, guider_ui.battery_setting_info);
	  	lv_anim_set_time(&battery_setting_info_anim_move_y, 800);
	  	lv_anim_set_delay(&battery_setting_info_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&battery_setting_info_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&battery_setting_info_anim_move_y, lv_obj_get_y(guider_ui.battery_setting_info), 84);
	  	lv_anim_set_path_cb(&battery_setting_info_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&battery_setting_info_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&battery_setting_info_anim_move_y, 0);
	  	lv_anim_set_playback_time(&battery_setting_info_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&battery_setting_info_anim_move_y, 0);
		lv_anim_start(&battery_setting_info_anim_move_y);
		//Write animation: battery_title move_x
	  	lv_anim_t battery_title_anim_move_x;
	  	lv_anim_init(&battery_title_anim_move_x);
	  	lv_anim_set_var(&battery_title_anim_move_x, guider_ui.battery_title);
	  	lv_anim_set_time(&battery_title_anim_move_x, 800);
	  	lv_anim_set_delay(&battery_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&battery_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&battery_title_anim_move_x, lv_obj_get_x(guider_ui.battery_title), 0);
	  	lv_anim_set_path_cb(&battery_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&battery_title_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&battery_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&battery_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&battery_title_anim_move_x, 0);
		lv_anim_start(&battery_title_anim_move_x);
		//Write animation: battery_title move_y
	  	lv_anim_t battery_title_anim_move_y;
	  	lv_anim_init(&battery_title_anim_move_y);
	  	lv_anim_set_var(&battery_title_anim_move_y, guider_ui.battery_title);
	  	lv_anim_set_time(&battery_title_anim_move_y, 800);
	  	lv_anim_set_delay(&battery_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&battery_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&battery_title_anim_move_y, lv_obj_get_y(guider_ui.battery_title), 0);
	  	lv_anim_set_path_cb(&battery_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&battery_title_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&battery_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&battery_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&battery_title_anim_move_y, 0);
		lv_anim_start(&battery_title_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.settings_del == true) {
			          setup_scr_settings(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.settings, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.battery_del = true;
			    }
				break;
			}
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.info_del == true) {
			          setup_scr_info(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.info, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.battery_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void battery_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.battery_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_battery(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->battery, battery_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->battery_home, battery_home_event_handler, LV_EVENT_ALL, NULL);
}
static void info_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: info_setting_info move_x
	  	lv_anim_t info_setting_info_anim_move_x;
	  	lv_anim_init(&info_setting_info_anim_move_x);
	  	lv_anim_set_var(&info_setting_info_anim_move_x, guider_ui.info_setting_info);
	  	lv_anim_set_time(&info_setting_info_anim_move_x, 800);
	  	lv_anim_set_delay(&info_setting_info_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&info_setting_info_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&info_setting_info_anim_move_x, lv_obj_get_x(guider_ui.info_setting_info), 63);
	  	lv_anim_set_path_cb(&info_setting_info_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&info_setting_info_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&info_setting_info_anim_move_x, 0);
	  	lv_anim_set_playback_time(&info_setting_info_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&info_setting_info_anim_move_x, 0);
		lv_anim_start(&info_setting_info_anim_move_x);
		//Write animation: info_setting_info move_y
	  	lv_anim_t info_setting_info_anim_move_y;
	  	lv_anim_init(&info_setting_info_anim_move_y);
	  	lv_anim_set_var(&info_setting_info_anim_move_y, guider_ui.info_setting_info);
	  	lv_anim_set_time(&info_setting_info_anim_move_y, 800);
	  	lv_anim_set_delay(&info_setting_info_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&info_setting_info_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&info_setting_info_anim_move_y, lv_obj_get_y(guider_ui.info_setting_info), 83);
	  	lv_anim_set_path_cb(&info_setting_info_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&info_setting_info_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&info_setting_info_anim_move_y, 0);
	  	lv_anim_set_playback_time(&info_setting_info_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&info_setting_info_anim_move_y, 0);
		lv_anim_start(&info_setting_info_anim_move_y);
		//Write animation: info_title move_x
	  	lv_anim_t info_title_anim_move_x;
	  	lv_anim_init(&info_title_anim_move_x);
	  	lv_anim_set_var(&info_title_anim_move_x, guider_ui.info_title);
	  	lv_anim_set_time(&info_title_anim_move_x, 800);
	  	lv_anim_set_delay(&info_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&info_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&info_title_anim_move_x, lv_obj_get_x(guider_ui.info_title), 0);
	  	lv_anim_set_path_cb(&info_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&info_title_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&info_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&info_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&info_title_anim_move_x, 0);
		lv_anim_start(&info_title_anim_move_x);
		//Write animation: info_title move_y
	  	lv_anim_t info_title_anim_move_y;
	  	lv_anim_init(&info_title_anim_move_y);
	  	lv_anim_set_var(&info_title_anim_move_y, guider_ui.info_title);
	  	lv_anim_set_time(&info_title_anim_move_y, 800);
	  	lv_anim_set_delay(&info_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&info_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&info_title_anim_move_y, lv_obj_get_y(guider_ui.info_title), 0);
	  	lv_anim_set_path_cb(&info_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&info_title_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&info_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&info_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&info_title_anim_move_y, 0);
		lv_anim_start(&info_title_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.battery_del == true) {
			          setup_scr_battery(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.battery, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.info_del = true;
			    }
				break;
			}
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.find_device_del == true) {
			          setup_scr_find_device(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.find_device, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.info_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void info_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.info_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_info(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->info, info_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->info_home, info_home_event_handler, LV_EVENT_ALL, NULL);
}
static void find_device_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: find_device_title move_x
	  	lv_anim_t find_device_title_anim_move_x;
	  	lv_anim_init(&find_device_title_anim_move_x);
	  	lv_anim_set_var(&find_device_title_anim_move_x, guider_ui.find_device_title);
	  	lv_anim_set_time(&find_device_title_anim_move_x, 800);
	  	lv_anim_set_delay(&find_device_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&find_device_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&find_device_title_anim_move_x, lv_obj_get_x(guider_ui.find_device_title), 0);
	  	lv_anim_set_path_cb(&find_device_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&find_device_title_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&find_device_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&find_device_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&find_device_title_anim_move_x, 0);
		lv_anim_start(&find_device_title_anim_move_x);
		//Write animation: find_device_title move_y
	  	lv_anim_t find_device_title_anim_move_y;
	  	lv_anim_init(&find_device_title_anim_move_y);
	  	lv_anim_set_var(&find_device_title_anim_move_y, guider_ui.find_device_title);
	  	lv_anim_set_time(&find_device_title_anim_move_y, 800);
	  	lv_anim_set_delay(&find_device_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&find_device_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&find_device_title_anim_move_y, lv_obj_get_y(guider_ui.find_device_title), 0);
	  	lv_anim_set_path_cb(&find_device_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&find_device_title_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&find_device_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&find_device_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&find_device_title_anim_move_y, 0);
		lv_anim_start(&find_device_title_anim_move_y);
		//Write animation: find_device_btn_start move_x
	  	lv_anim_t find_device_btn_start_anim_move_x;
	  	lv_anim_init(&find_device_btn_start_anim_move_x);
	  	lv_anim_set_var(&find_device_btn_start_anim_move_x, guider_ui.find_device_btn_start);
	  	lv_anim_set_time(&find_device_btn_start_anim_move_x, 800);
	  	lv_anim_set_delay(&find_device_btn_start_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&find_device_btn_start_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&find_device_btn_start_anim_move_x, lv_obj_get_x(guider_ui.find_device_btn_start), 131);
	  	lv_anim_set_path_cb(&find_device_btn_start_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&find_device_btn_start_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&find_device_btn_start_anim_move_x, 0);
	  	lv_anim_set_playback_time(&find_device_btn_start_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&find_device_btn_start_anim_move_x, 0);
		lv_anim_start(&find_device_btn_start_anim_move_x);
		//Write animation: find_device_btn_start move_y
	  	lv_anim_t find_device_btn_start_anim_move_y;
	  	lv_anim_init(&find_device_btn_start_anim_move_y);
	  	lv_anim_set_var(&find_device_btn_start_anim_move_y, guider_ui.find_device_btn_start);
	  	lv_anim_set_time(&find_device_btn_start_anim_move_y, 800);
	  	lv_anim_set_delay(&find_device_btn_start_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&find_device_btn_start_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&find_device_btn_start_anim_move_y, lv_obj_get_y(guider_ui.find_device_btn_start), 308);
	  	lv_anim_set_path_cb(&find_device_btn_start_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&find_device_btn_start_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&find_device_btn_start_anim_move_y, 0);
	  	lv_anim_set_playback_time(&find_device_btn_start_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&find_device_btn_start_anim_move_y, 0);
		lv_anim_start(&find_device_btn_start_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.info_del == true) {
			          setup_scr_info(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.info, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.find_device_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void find_device_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.find_device_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void find_device_btn_start_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.play_sound_del == true) {
	          setup_scr_play_sound(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.play_sound, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.find_device_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_find_device(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->find_device, find_device_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->find_device_home, find_device_home_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->find_device_btn_start, find_device_btn_start_event_handler, LV_EVENT_ALL, NULL);
}
static void play_sound_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: play_sound_btn_cancel move_x
	  	lv_anim_t play_sound_btn_cancel_anim_move_x;
	  	lv_anim_init(&play_sound_btn_cancel_anim_move_x);
	  	lv_anim_set_var(&play_sound_btn_cancel_anim_move_x, guider_ui.play_sound_btn_cancel);
	  	lv_anim_set_time(&play_sound_btn_cancel_anim_move_x, 800);
	  	lv_anim_set_delay(&play_sound_btn_cancel_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&play_sound_btn_cancel_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&play_sound_btn_cancel_anim_move_x, lv_obj_get_x(guider_ui.play_sound_btn_cancel), 126);
	  	lv_anim_set_path_cb(&play_sound_btn_cancel_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&play_sound_btn_cancel_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&play_sound_btn_cancel_anim_move_x, 0);
	  	lv_anim_set_playback_time(&play_sound_btn_cancel_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&play_sound_btn_cancel_anim_move_x, 0);
		lv_anim_start(&play_sound_btn_cancel_anim_move_x);
		//Write animation: play_sound_btn_cancel move_y
	  	lv_anim_t play_sound_btn_cancel_anim_move_y;
	  	lv_anim_init(&play_sound_btn_cancel_anim_move_y);
	  	lv_anim_set_var(&play_sound_btn_cancel_anim_move_y, guider_ui.play_sound_btn_cancel);
	  	lv_anim_set_time(&play_sound_btn_cancel_anim_move_y, 800);
	  	lv_anim_set_delay(&play_sound_btn_cancel_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&play_sound_btn_cancel_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&play_sound_btn_cancel_anim_move_y, lv_obj_get_y(guider_ui.play_sound_btn_cancel), 308);
	  	lv_anim_set_path_cb(&play_sound_btn_cancel_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&play_sound_btn_cancel_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&play_sound_btn_cancel_anim_move_y, 0);
	  	lv_anim_set_playback_time(&play_sound_btn_cancel_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&play_sound_btn_cancel_anim_move_y, 0);
		lv_anim_start(&play_sound_btn_cancel_anim_move_y);
		//Write animation: play_sound_title move_x
	  	lv_anim_t play_sound_title_anim_move_x;
	  	lv_anim_init(&play_sound_title_anim_move_x);
	  	lv_anim_set_var(&play_sound_title_anim_move_x, guider_ui.play_sound_title);
	  	lv_anim_set_time(&play_sound_title_anim_move_x, 800);
	  	lv_anim_set_delay(&play_sound_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&play_sound_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&play_sound_title_anim_move_x, lv_obj_get_x(guider_ui.play_sound_title), 32);
	  	lv_anim_set_path_cb(&play_sound_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&play_sound_title_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&play_sound_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&play_sound_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&play_sound_title_anim_move_x, 0);
		lv_anim_start(&play_sound_title_anim_move_x);
		//Write animation: play_sound_title move_y
	  	lv_anim_t play_sound_title_anim_move_y;
	  	lv_anim_init(&play_sound_title_anim_move_y);
	  	lv_anim_set_var(&play_sound_title_anim_move_y, guider_ui.play_sound_title);
	  	lv_anim_set_time(&play_sound_title_anim_move_y, 800);
	  	lv_anim_set_delay(&play_sound_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&play_sound_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&play_sound_title_anim_move_y, lv_obj_get_y(guider_ui.play_sound_title), 35);
	  	lv_anim_set_path_cb(&play_sound_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&play_sound_title_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&play_sound_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&play_sound_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&play_sound_title_anim_move_y, 0);
		lv_anim_start(&play_sound_title_anim_move_y);
		//Write animation: play_sound_img_find img_zoom
	  	lv_anim_t play_sound_img_find_anim_img_zoom;
	  	lv_anim_init(&play_sound_img_find_anim_img_zoom);
	  	lv_anim_set_var(&play_sound_img_find_anim_img_zoom, guider_ui.play_sound_img_find);
	  	lv_anim_set_time(&play_sound_img_find_anim_img_zoom, 500);
	  	lv_anim_set_delay(&play_sound_img_find_anim_img_zoom, 0);
	  	lv_anim_set_exec_cb(&play_sound_img_find_anim_img_zoom, (lv_anim_exec_xcb_t)lv_img_set_zoom);
		lv_anim_set_values(&play_sound_img_find_anim_img_zoom, lv_img_get_zoom(guider_ui.play_sound_img_find), 331);
	  	lv_anim_set_path_cb(&play_sound_img_find_anim_img_zoom, &lv_anim_path_ease_in);
	  	lv_anim_set_repeat_count(&play_sound_img_find_anim_img_zoom, LV_ANIM_REPEAT_INFINITE);
	  	lv_anim_set_repeat_delay(&play_sound_img_find_anim_img_zoom, 0);
	  	lv_anim_set_playback_time(&play_sound_img_find_anim_img_zoom, 500);
	  	lv_anim_set_playback_delay(&play_sound_img_find_anim_img_zoom, 0);
		lv_anim_start(&play_sound_img_find_anim_img_zoom);
		break;
	}
	default:
		break;
	}
}
static void play_sound_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.play_sound_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void play_sound_btn_cancel_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.find_device_del == true) {
	          setup_scr_find_device(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.find_device, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.play_sound_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_play_sound(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->play_sound, play_sound_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->play_sound_home, play_sound_home_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->play_sound_btn_cancel, play_sound_btn_cancel_event_handler, LV_EVENT_ALL, NULL);
}
static void blood_oxygen_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: blood_oxygen_title move_x
	  	lv_anim_t blood_oxygen_title_anim_move_x;
	  	lv_anim_init(&blood_oxygen_title_anim_move_x);
	  	lv_anim_set_var(&blood_oxygen_title_anim_move_x, guider_ui.blood_oxygen_title);
	  	lv_anim_set_time(&blood_oxygen_title_anim_move_x, 800);
	  	lv_anim_set_delay(&blood_oxygen_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&blood_oxygen_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&blood_oxygen_title_anim_move_x, lv_obj_get_x(guider_ui.blood_oxygen_title), 0);
	  	lv_anim_set_path_cb(&blood_oxygen_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&blood_oxygen_title_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&blood_oxygen_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&blood_oxygen_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&blood_oxygen_title_anim_move_x, 0);
		lv_anim_start(&blood_oxygen_title_anim_move_x);
		//Write animation: blood_oxygen_title move_y
	  	lv_anim_t blood_oxygen_title_anim_move_y;
	  	lv_anim_init(&blood_oxygen_title_anim_move_y);
	  	lv_anim_set_var(&blood_oxygen_title_anim_move_y, guider_ui.blood_oxygen_title);
	  	lv_anim_set_time(&blood_oxygen_title_anim_move_y, 800);
	  	lv_anim_set_delay(&blood_oxygen_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&blood_oxygen_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&blood_oxygen_title_anim_move_y, lv_obj_get_y(guider_ui.blood_oxygen_title), 0);
	  	lv_anim_set_path_cb(&blood_oxygen_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&blood_oxygen_title_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&blood_oxygen_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&blood_oxygen_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&blood_oxygen_title_anim_move_y, 0);
		lv_anim_start(&blood_oxygen_title_anim_move_y);
		//Write animation: blood_oxygen_arc_blood move_x
	  	lv_anim_t blood_oxygen_arc_blood_anim_move_x;
	  	lv_anim_init(&blood_oxygen_arc_blood_anim_move_x);
	  	lv_anim_set_var(&blood_oxygen_arc_blood_anim_move_x, guider_ui.blood_oxygen_arc_blood);
	  	lv_anim_set_time(&blood_oxygen_arc_blood_anim_move_x, 800);
	  	lv_anim_set_delay(&blood_oxygen_arc_blood_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&blood_oxygen_arc_blood_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&blood_oxygen_arc_blood_anim_move_x, lv_obj_get_x(guider_ui.blood_oxygen_arc_blood), 11);
	  	lv_anim_set_path_cb(&blood_oxygen_arc_blood_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&blood_oxygen_arc_blood_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&blood_oxygen_arc_blood_anim_move_x, 0);
	  	lv_anim_set_playback_time(&blood_oxygen_arc_blood_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&blood_oxygen_arc_blood_anim_move_x, 0);
		lv_anim_start(&blood_oxygen_arc_blood_anim_move_x);
		//Write animation: blood_oxygen_arc_blood move_y
	  	lv_anim_t blood_oxygen_arc_blood_anim_move_y;
	  	lv_anim_init(&blood_oxygen_arc_blood_anim_move_y);
	  	lv_anim_set_var(&blood_oxygen_arc_blood_anim_move_y, guider_ui.blood_oxygen_arc_blood);
	  	lv_anim_set_time(&blood_oxygen_arc_blood_anim_move_y, 800);
	  	lv_anim_set_delay(&blood_oxygen_arc_blood_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&blood_oxygen_arc_blood_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&blood_oxygen_arc_blood_anim_move_y, lv_obj_get_y(guider_ui.blood_oxygen_arc_blood), 11);
	  	lv_anim_set_path_cb(&blood_oxygen_arc_blood_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&blood_oxygen_arc_blood_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&blood_oxygen_arc_blood_anim_move_y, 0);
	  	lv_anim_set_playback_time(&blood_oxygen_arc_blood_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&blood_oxygen_arc_blood_anim_move_y, 0);
		lv_anim_start(&blood_oxygen_arc_blood_anim_move_y);
		//Write animation: blood_oxygen_label_ago move_x
	  	lv_anim_t blood_oxygen_label_ago_anim_move_x;
	  	lv_anim_init(&blood_oxygen_label_ago_anim_move_x);
	  	lv_anim_set_var(&blood_oxygen_label_ago_anim_move_x, guider_ui.blood_oxygen_label_ago);
	  	lv_anim_set_time(&blood_oxygen_label_ago_anim_move_x, 800);
	  	lv_anim_set_delay(&blood_oxygen_label_ago_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&blood_oxygen_label_ago_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&blood_oxygen_label_ago_anim_move_x, lv_obj_get_x(guider_ui.blood_oxygen_label_ago), 123);
	  	lv_anim_set_path_cb(&blood_oxygen_label_ago_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&blood_oxygen_label_ago_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&blood_oxygen_label_ago_anim_move_x, 0);
	  	lv_anim_set_playback_time(&blood_oxygen_label_ago_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&blood_oxygen_label_ago_anim_move_x, 0);
		lv_anim_start(&blood_oxygen_label_ago_anim_move_x);
		//Write animation: blood_oxygen_label_ago move_y
	  	lv_anim_t blood_oxygen_label_ago_anim_move_y;
	  	lv_anim_init(&blood_oxygen_label_ago_anim_move_y);
	  	lv_anim_set_var(&blood_oxygen_label_ago_anim_move_y, guider_ui.blood_oxygen_label_ago);
	  	lv_anim_set_time(&blood_oxygen_label_ago_anim_move_y, 800);
	  	lv_anim_set_delay(&blood_oxygen_label_ago_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&blood_oxygen_label_ago_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&blood_oxygen_label_ago_anim_move_y, lv_obj_get_y(guider_ui.blood_oxygen_label_ago), 260);
	  	lv_anim_set_path_cb(&blood_oxygen_label_ago_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&blood_oxygen_label_ago_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&blood_oxygen_label_ago_anim_move_y, 0);
	  	lv_anim_set_playback_time(&blood_oxygen_label_ago_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&blood_oxygen_label_ago_anim_move_y, 0);
		lv_anim_start(&blood_oxygen_label_ago_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_BOTTOM:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.settings_del == true) {
			          setup_scr_settings(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.settings, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.blood_oxygen_del = true;
			    }
				break;
			}
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.ekg_del == true) {
			          setup_scr_ekg(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.ekg, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.blood_oxygen_del = true;
			    }
				break;
			}
			case LV_DIR_TOP:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.home_analog_del == true) {
			          setup_scr_home_analog(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.blood_oxygen_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void blood_oxygen_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.blood_oxygen_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_blood_oxygen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->blood_oxygen, blood_oxygen_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->blood_oxygen_home, blood_oxygen_home_event_handler, LV_EVENT_ALL, NULL);
}
static void ekg_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		lv_obj_clear_flag(guider_ui.ekg_cont_2, LV_OBJ_FLAG_CLICKABLE);
		lv_obj_clear_flag(guider_ui.ekg_cont_2, LV_OBJ_FLAG_SCROLLABLE);
		//Write animation: ekg_cont_2 move_x
	  	lv_anim_t ekg_cont_2_anim_move_x;
	  	lv_anim_init(&ekg_cont_2_anim_move_x);
	  	lv_anim_set_var(&ekg_cont_2_anim_move_x, guider_ui.ekg_cont_2);
	  	lv_anim_set_time(&ekg_cont_2_anim_move_x, 700);
	  	lv_anim_set_delay(&ekg_cont_2_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&ekg_cont_2_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&ekg_cont_2_anim_move_x, lv_obj_get_x(guider_ui.ekg_cont_2), -127);
	  	lv_anim_set_path_cb(&ekg_cont_2_anim_move_x, &lv_anim_path_linear);
	  	lv_anim_set_repeat_count(&ekg_cont_2_anim_move_x, LV_ANIM_REPEAT_INFINITE);
	  	lv_anim_set_repeat_delay(&ekg_cont_2_anim_move_x, 0);
	  	lv_anim_set_playback_time(&ekg_cont_2_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&ekg_cont_2_anim_move_x, 0);
		lv_anim_start(&ekg_cont_2_anim_move_x);
		//Write animation: ekg_cont_2 move_y
	  	lv_anim_t ekg_cont_2_anim_move_y;
	  	lv_anim_init(&ekg_cont_2_anim_move_y);
	  	lv_anim_set_var(&ekg_cont_2_anim_move_y, guider_ui.ekg_cont_2);
	  	lv_anim_set_time(&ekg_cont_2_anim_move_y, 700);
	  	lv_anim_set_delay(&ekg_cont_2_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&ekg_cont_2_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&ekg_cont_2_anim_move_y, lv_obj_get_y(guider_ui.ekg_cont_2), 135);
	  	lv_anim_set_path_cb(&ekg_cont_2_anim_move_y, &lv_anim_path_linear);
	  	lv_anim_set_repeat_count(&ekg_cont_2_anim_move_y, LV_ANIM_REPEAT_INFINITE);
	  	lv_anim_set_repeat_delay(&ekg_cont_2_anim_move_y, 0);
	  	lv_anim_set_playback_time(&ekg_cont_2_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&ekg_cont_2_anim_move_y, 0);
		lv_anim_start(&ekg_cont_2_anim_move_y);
		//Write animation: ekg_cont_1 move_x
	  	lv_anim_t ekg_cont_1_anim_move_x;
	  	lv_anim_init(&ekg_cont_1_anim_move_x);
	  	lv_anim_set_var(&ekg_cont_1_anim_move_x, guider_ui.ekg_cont_1);
	  	lv_anim_set_time(&ekg_cont_1_anim_move_x, 800);
	  	lv_anim_set_delay(&ekg_cont_1_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&ekg_cont_1_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&ekg_cont_1_anim_move_x, lv_obj_get_x(guider_ui.ekg_cont_1), 106);
	  	lv_anim_set_path_cb(&ekg_cont_1_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&ekg_cont_1_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&ekg_cont_1_anim_move_x, 0);
	  	lv_anim_set_playback_time(&ekg_cont_1_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&ekg_cont_1_anim_move_x, 0);
		lv_anim_start(&ekg_cont_1_anim_move_x);
		//Write animation: ekg_cont_1 move_y
	  	lv_anim_t ekg_cont_1_anim_move_y;
	  	lv_anim_init(&ekg_cont_1_anim_move_y);
	  	lv_anim_set_var(&ekg_cont_1_anim_move_y, guider_ui.ekg_cont_1);
	  	lv_anim_set_time(&ekg_cont_1_anim_move_y, 800);
	  	lv_anim_set_delay(&ekg_cont_1_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&ekg_cont_1_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&ekg_cont_1_anim_move_y, lv_obj_get_y(guider_ui.ekg_cont_1), 294);
	  	lv_anim_set_path_cb(&ekg_cont_1_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&ekg_cont_1_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&ekg_cont_1_anim_move_y, 0);
	  	lv_anim_set_playback_time(&ekg_cont_1_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&ekg_cont_1_anim_move_y, 0);
		lv_anim_start(&ekg_cont_1_anim_move_y);
		//Write animation: ekg_title move_x
	  	lv_anim_t ekg_title_anim_move_x;
	  	lv_anim_init(&ekg_title_anim_move_x);
	  	lv_anim_set_var(&ekg_title_anim_move_x, guider_ui.ekg_title);
	  	lv_anim_set_time(&ekg_title_anim_move_x, 800);
	  	lv_anim_set_delay(&ekg_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&ekg_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&ekg_title_anim_move_x, lv_obj_get_x(guider_ui.ekg_title), 0);
	  	lv_anim_set_path_cb(&ekg_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&ekg_title_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&ekg_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&ekg_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&ekg_title_anim_move_x, 0);
		lv_anim_start(&ekg_title_anim_move_x);
		//Write animation: ekg_title move_y
	  	lv_anim_t ekg_title_anim_move_y;
	  	lv_anim_init(&ekg_title_anim_move_y);
	  	lv_anim_set_var(&ekg_title_anim_move_y, guider_ui.ekg_title);
	  	lv_anim_set_time(&ekg_title_anim_move_y, 800);
	  	lv_anim_set_delay(&ekg_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&ekg_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&ekg_title_anim_move_y, lv_obj_get_y(guider_ui.ekg_title), 0);
	  	lv_anim_set_path_cb(&ekg_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&ekg_title_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&ekg_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&ekg_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&ekg_title_anim_move_y, 0);
		lv_anim_start(&ekg_title_anim_move_y);
		//Write animation: ekg_img_healthy img_zoom
	  	lv_anim_t ekg_img_healthy_anim_img_zoom;
	  	lv_anim_init(&ekg_img_healthy_anim_img_zoom);
	  	lv_anim_set_var(&ekg_img_healthy_anim_img_zoom, guider_ui.ekg_img_healthy);
	  	lv_anim_set_time(&ekg_img_healthy_anim_img_zoom, 500);
	  	lv_anim_set_delay(&ekg_img_healthy_anim_img_zoom, 0);
	  	lv_anim_set_exec_cb(&ekg_img_healthy_anim_img_zoom, (lv_anim_exec_xcb_t)lv_img_set_zoom);
		lv_anim_set_values(&ekg_img_healthy_anim_img_zoom, lv_img_get_zoom(guider_ui.ekg_img_healthy), 372);
	  	lv_anim_set_path_cb(&ekg_img_healthy_anim_img_zoom, &lv_anim_path_ease_in);
	  	lv_anim_set_repeat_count(&ekg_img_healthy_anim_img_zoom, LV_ANIM_REPEAT_INFINITE);
	  	lv_anim_set_repeat_delay(&ekg_img_healthy_anim_img_zoom, 0);
	  	lv_anim_set_playback_time(&ekg_img_healthy_anim_img_zoom, 500);
	  	lv_anim_set_playback_delay(&ekg_img_healthy_anim_img_zoom, 0);
		lv_anim_start(&ekg_img_healthy_anim_img_zoom);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.blood_oxygen_del == true) {
			          setup_scr_blood_oxygen(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.blood_oxygen, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.ekg_del = true;
			    }
				break;
			}
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.stress_level_del == true) {
			          setup_scr_stress_level(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.stress_level, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.ekg_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void ekg_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.ekg_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_ekg(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->ekg, ekg_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->ekg_home, ekg_home_event_handler, LV_EVENT_ALL, NULL);
}
static void stress_level_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: stress_level_title move_x
	  	lv_anim_t stress_level_title_anim_move_x;
	  	lv_anim_init(&stress_level_title_anim_move_x);
	  	lv_anim_set_var(&stress_level_title_anim_move_x, guider_ui.stress_level_title);
	  	lv_anim_set_time(&stress_level_title_anim_move_x, 800);
	  	lv_anim_set_delay(&stress_level_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&stress_level_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&stress_level_title_anim_move_x, lv_obj_get_x(guider_ui.stress_level_title), 0);
	  	lv_anim_set_path_cb(&stress_level_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&stress_level_title_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&stress_level_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&stress_level_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&stress_level_title_anim_move_x, 0);
		lv_anim_start(&stress_level_title_anim_move_x);
		//Write animation: stress_level_title move_y
	  	lv_anim_t stress_level_title_anim_move_y;
	  	lv_anim_init(&stress_level_title_anim_move_y);
	  	lv_anim_set_var(&stress_level_title_anim_move_y, guider_ui.stress_level_title);
	  	lv_anim_set_time(&stress_level_title_anim_move_y, 800);
	  	lv_anim_set_delay(&stress_level_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&stress_level_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&stress_level_title_anim_move_y, lv_obj_get_y(guider_ui.stress_level_title), 0);
	  	lv_anim_set_path_cb(&stress_level_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&stress_level_title_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&stress_level_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&stress_level_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&stress_level_title_anim_move_y, 0);
		lv_anim_start(&stress_level_title_anim_move_y);
		//Write animation: stress_level_label_average move_x
	  	lv_anim_t stress_level_label_average_anim_move_x;
	  	lv_anim_init(&stress_level_label_average_anim_move_x);
	  	lv_anim_set_var(&stress_level_label_average_anim_move_x, guider_ui.stress_level_label_average);
	  	lv_anim_set_time(&stress_level_label_average_anim_move_x, 800);
	  	lv_anim_set_delay(&stress_level_label_average_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&stress_level_label_average_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&stress_level_label_average_anim_move_x, lv_obj_get_x(guider_ui.stress_level_label_average), 127);
	  	lv_anim_set_path_cb(&stress_level_label_average_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&stress_level_label_average_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&stress_level_label_average_anim_move_x, 0);
	  	lv_anim_set_playback_time(&stress_level_label_average_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&stress_level_label_average_anim_move_x, 0);
		lv_anim_start(&stress_level_label_average_anim_move_x);
		//Write animation: stress_level_label_average move_y
	  	lv_anim_t stress_level_label_average_anim_move_y;
	  	lv_anim_init(&stress_level_label_average_anim_move_y);
	  	lv_anim_set_var(&stress_level_label_average_anim_move_y, guider_ui.stress_level_label_average);
	  	lv_anim_set_time(&stress_level_label_average_anim_move_y, 800);
	  	lv_anim_set_delay(&stress_level_label_average_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&stress_level_label_average_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&stress_level_label_average_anim_move_y, lv_obj_get_y(guider_ui.stress_level_label_average), 286);
	  	lv_anim_set_path_cb(&stress_level_label_average_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&stress_level_label_average_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&stress_level_label_average_anim_move_y, 0);
	  	lv_anim_set_playback_time(&stress_level_label_average_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&stress_level_label_average_anim_move_y, 0);
		lv_anim_start(&stress_level_label_average_anim_move_y);
		//Write animation: stress_level_label_ago move_x
	  	lv_anim_t stress_level_label_ago_anim_move_x;
	  	lv_anim_init(&stress_level_label_ago_anim_move_x);
	  	lv_anim_set_var(&stress_level_label_ago_anim_move_x, guider_ui.stress_level_label_ago);
	  	lv_anim_set_time(&stress_level_label_ago_anim_move_x, 800);
	  	lv_anim_set_delay(&stress_level_label_ago_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&stress_level_label_ago_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&stress_level_label_ago_anim_move_x, lv_obj_get_x(guider_ui.stress_level_label_ago), 133);
	  	lv_anim_set_path_cb(&stress_level_label_ago_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&stress_level_label_ago_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&stress_level_label_ago_anim_move_x, 0);
	  	lv_anim_set_playback_time(&stress_level_label_ago_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&stress_level_label_ago_anim_move_x, 0);
		lv_anim_start(&stress_level_label_ago_anim_move_x);
		//Write animation: stress_level_label_ago move_y
	  	lv_anim_t stress_level_label_ago_anim_move_y;
	  	lv_anim_init(&stress_level_label_ago_anim_move_y);
	  	lv_anim_set_var(&stress_level_label_ago_anim_move_y, guider_ui.stress_level_label_ago);
	  	lv_anim_set_time(&stress_level_label_ago_anim_move_y, 800);
	  	lv_anim_set_delay(&stress_level_label_ago_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&stress_level_label_ago_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&stress_level_label_ago_anim_move_y, lv_obj_get_y(guider_ui.stress_level_label_ago), 88);
	  	lv_anim_set_path_cb(&stress_level_label_ago_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&stress_level_label_ago_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&stress_level_label_ago_anim_move_y, 0);
	  	lv_anim_set_playback_time(&stress_level_label_ago_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&stress_level_label_ago_anim_move_y, 0);
		lv_anim_start(&stress_level_label_ago_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.ekg_del == true) {
			          setup_scr_ekg(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.ekg, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.stress_level_del = true;
			    }
				break;
			}
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.blood_pressure_del == true) {
			          setup_scr_blood_pressure(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.blood_pressure, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.stress_level_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void stress_level_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.stress_level_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_stress_level(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->stress_level, stress_level_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->stress_level_home, stress_level_home_event_handler, LV_EVENT_ALL, NULL);
}
static void blood_pressure_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: blood_pressure_cont_1 move_x
	  	lv_anim_t blood_pressure_cont_1_anim_move_x;
	  	lv_anim_init(&blood_pressure_cont_1_anim_move_x);
	  	lv_anim_set_var(&blood_pressure_cont_1_anim_move_x, guider_ui.blood_pressure_cont_1);
	  	lv_anim_set_time(&blood_pressure_cont_1_anim_move_x, 800);
	  	lv_anim_set_delay(&blood_pressure_cont_1_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&blood_pressure_cont_1_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&blood_pressure_cont_1_anim_move_x, lv_obj_get_x(guider_ui.blood_pressure_cont_1), 119);
	  	lv_anim_set_path_cb(&blood_pressure_cont_1_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&blood_pressure_cont_1_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&blood_pressure_cont_1_anim_move_x, 0);
	  	lv_anim_set_playback_time(&blood_pressure_cont_1_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&blood_pressure_cont_1_anim_move_x, 0);
		lv_anim_start(&blood_pressure_cont_1_anim_move_x);
		//Write animation: blood_pressure_cont_1 move_y
	  	lv_anim_t blood_pressure_cont_1_anim_move_y;
	  	lv_anim_init(&blood_pressure_cont_1_anim_move_y);
	  	lv_anim_set_var(&blood_pressure_cont_1_anim_move_y, guider_ui.blood_pressure_cont_1);
	  	lv_anim_set_time(&blood_pressure_cont_1_anim_move_y, 800);
	  	lv_anim_set_delay(&blood_pressure_cont_1_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&blood_pressure_cont_1_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&blood_pressure_cont_1_anim_move_y, lv_obj_get_y(guider_ui.blood_pressure_cont_1), 298);
	  	lv_anim_set_path_cb(&blood_pressure_cont_1_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&blood_pressure_cont_1_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&blood_pressure_cont_1_anim_move_y, 0);
	  	lv_anim_set_playback_time(&blood_pressure_cont_1_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&blood_pressure_cont_1_anim_move_y, 0);
		lv_anim_start(&blood_pressure_cont_1_anim_move_y);
		//Write animation: blood_pressure_arc_stress move_x
	  	lv_anim_t blood_pressure_arc_stress_anim_move_x;
	  	lv_anim_init(&blood_pressure_arc_stress_anim_move_x);
	  	lv_anim_set_var(&blood_pressure_arc_stress_anim_move_x, guider_ui.blood_pressure_arc_stress);
	  	lv_anim_set_time(&blood_pressure_arc_stress_anim_move_x, 800);
	  	lv_anim_set_delay(&blood_pressure_arc_stress_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&blood_pressure_arc_stress_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&blood_pressure_arc_stress_anim_move_x, lv_obj_get_x(guider_ui.blood_pressure_arc_stress), 11);
	  	lv_anim_set_path_cb(&blood_pressure_arc_stress_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&blood_pressure_arc_stress_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&blood_pressure_arc_stress_anim_move_x, 0);
	  	lv_anim_set_playback_time(&blood_pressure_arc_stress_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&blood_pressure_arc_stress_anim_move_x, 0);
		lv_anim_start(&blood_pressure_arc_stress_anim_move_x);
		//Write animation: blood_pressure_arc_stress move_y
	  	lv_anim_t blood_pressure_arc_stress_anim_move_y;
	  	lv_anim_init(&blood_pressure_arc_stress_anim_move_y);
	  	lv_anim_set_var(&blood_pressure_arc_stress_anim_move_y, guider_ui.blood_pressure_arc_stress);
	  	lv_anim_set_time(&blood_pressure_arc_stress_anim_move_y, 800);
	  	lv_anim_set_delay(&blood_pressure_arc_stress_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&blood_pressure_arc_stress_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&blood_pressure_arc_stress_anim_move_y, lv_obj_get_y(guider_ui.blood_pressure_arc_stress), 11);
	  	lv_anim_set_path_cb(&blood_pressure_arc_stress_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&blood_pressure_arc_stress_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&blood_pressure_arc_stress_anim_move_y, 0);
	  	lv_anim_set_playback_time(&blood_pressure_arc_stress_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&blood_pressure_arc_stress_anim_move_y, 0);
		lv_anim_start(&blood_pressure_arc_stress_anim_move_y);
		//Write animation: blood_pressure_title move_x
	  	lv_anim_t blood_pressure_title_anim_move_x;
	  	lv_anim_init(&blood_pressure_title_anim_move_x);
	  	lv_anim_set_var(&blood_pressure_title_anim_move_x, guider_ui.blood_pressure_title);
	  	lv_anim_set_time(&blood_pressure_title_anim_move_x, 800);
	  	lv_anim_set_delay(&blood_pressure_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&blood_pressure_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&blood_pressure_title_anim_move_x, lv_obj_get_x(guider_ui.blood_pressure_title), 0);
	  	lv_anim_set_path_cb(&blood_pressure_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&blood_pressure_title_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&blood_pressure_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&blood_pressure_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&blood_pressure_title_anim_move_x, 0);
		lv_anim_start(&blood_pressure_title_anim_move_x);
		//Write animation: blood_pressure_title move_y
	  	lv_anim_t blood_pressure_title_anim_move_y;
	  	lv_anim_init(&blood_pressure_title_anim_move_y);
	  	lv_anim_set_var(&blood_pressure_title_anim_move_y, guider_ui.blood_pressure_title);
	  	lv_anim_set_time(&blood_pressure_title_anim_move_y, 800);
	  	lv_anim_set_delay(&blood_pressure_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&blood_pressure_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&blood_pressure_title_anim_move_y, lv_obj_get_y(guider_ui.blood_pressure_title), 0);
	  	lv_anim_set_path_cb(&blood_pressure_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&blood_pressure_title_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&blood_pressure_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&blood_pressure_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&blood_pressure_title_anim_move_y, 0);
		lv_anim_start(&blood_pressure_title_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.stress_level_del == true) {
			          setup_scr_stress_level(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.stress_level, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.blood_pressure_del = true;
			    }
				break;
			}
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.sleep_del == true) {
			          setup_scr_sleep(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.sleep, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.blood_pressure_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void blood_pressure_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.blood_pressure_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_blood_pressure(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->blood_pressure, blood_pressure_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->blood_pressure_home, blood_pressure_home_event_handler, LV_EVENT_ALL, NULL);
}
static void sleep_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: sleep_cont_1 move_x
	  	lv_anim_t sleep_cont_1_anim_move_x;
	  	lv_anim_init(&sleep_cont_1_anim_move_x);
	  	lv_anim_set_var(&sleep_cont_1_anim_move_x, guider_ui.sleep_cont_1);
	  	lv_anim_set_time(&sleep_cont_1_anim_move_x, 800);
	  	lv_anim_set_delay(&sleep_cont_1_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&sleep_cont_1_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&sleep_cont_1_anim_move_x, lv_obj_get_x(guider_ui.sleep_cont_1), 111);
	  	lv_anim_set_path_cb(&sleep_cont_1_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&sleep_cont_1_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&sleep_cont_1_anim_move_x, 0);
	  	lv_anim_set_playback_time(&sleep_cont_1_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&sleep_cont_1_anim_move_x, 0);
		lv_anim_start(&sleep_cont_1_anim_move_x);
		//Write animation: sleep_cont_1 move_y
	  	lv_anim_t sleep_cont_1_anim_move_y;
	  	lv_anim_init(&sleep_cont_1_anim_move_y);
	  	lv_anim_set_var(&sleep_cont_1_anim_move_y, guider_ui.sleep_cont_1);
	  	lv_anim_set_time(&sleep_cont_1_anim_move_y, 800);
	  	lv_anim_set_delay(&sleep_cont_1_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&sleep_cont_1_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&sleep_cont_1_anim_move_y, lv_obj_get_y(guider_ui.sleep_cont_1), 302);
	  	lv_anim_set_path_cb(&sleep_cont_1_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&sleep_cont_1_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&sleep_cont_1_anim_move_y, 0);
	  	lv_anim_set_playback_time(&sleep_cont_1_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&sleep_cont_1_anim_move_y, 0);
		lv_anim_start(&sleep_cont_1_anim_move_y);
		//Write animation: sleep_label_stages move_x
	  	lv_anim_t sleep_label_stages_anim_move_x;
	  	lv_anim_init(&sleep_label_stages_anim_move_x);
	  	lv_anim_set_var(&sleep_label_stages_anim_move_x, guider_ui.sleep_label_stages);
	  	lv_anim_set_time(&sleep_label_stages_anim_move_x, 800);
	  	lv_anim_set_delay(&sleep_label_stages_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&sleep_label_stages_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&sleep_label_stages_anim_move_x, lv_obj_get_x(guider_ui.sleep_label_stages), 112);
	  	lv_anim_set_path_cb(&sleep_label_stages_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&sleep_label_stages_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&sleep_label_stages_anim_move_x, 0);
	  	lv_anim_set_playback_time(&sleep_label_stages_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&sleep_label_stages_anim_move_x, 0);
		lv_anim_start(&sleep_label_stages_anim_move_x);
		//Write animation: sleep_label_stages move_y
	  	lv_anim_t sleep_label_stages_anim_move_y;
	  	lv_anim_init(&sleep_label_stages_anim_move_y);
	  	lv_anim_set_var(&sleep_label_stages_anim_move_y, guider_ui.sleep_label_stages);
	  	lv_anim_set_time(&sleep_label_stages_anim_move_y, 800);
	  	lv_anim_set_delay(&sleep_label_stages_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&sleep_label_stages_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&sleep_label_stages_anim_move_y, lv_obj_get_y(guider_ui.sleep_label_stages), 78);
	  	lv_anim_set_path_cb(&sleep_label_stages_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&sleep_label_stages_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&sleep_label_stages_anim_move_y, 0);
	  	lv_anim_set_playback_time(&sleep_label_stages_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&sleep_label_stages_anim_move_y, 0);
		lv_anim_start(&sleep_label_stages_anim_move_y);
		//Write animation: sleep_title move_x
	  	lv_anim_t sleep_title_anim_move_x;
	  	lv_anim_init(&sleep_title_anim_move_x);
	  	lv_anim_set_var(&sleep_title_anim_move_x, guider_ui.sleep_title);
	  	lv_anim_set_time(&sleep_title_anim_move_x, 800);
	  	lv_anim_set_delay(&sleep_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&sleep_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&sleep_title_anim_move_x, lv_obj_get_x(guider_ui.sleep_title), 0);
	  	lv_anim_set_path_cb(&sleep_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&sleep_title_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&sleep_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&sleep_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&sleep_title_anim_move_x, 0);
		lv_anim_start(&sleep_title_anim_move_x);
		//Write animation: sleep_title move_y
	  	lv_anim_t sleep_title_anim_move_y;
	  	lv_anim_init(&sleep_title_anim_move_y);
	  	lv_anim_set_var(&sleep_title_anim_move_y, guider_ui.sleep_title);
	  	lv_anim_set_time(&sleep_title_anim_move_y, 800);
	  	lv_anim_set_delay(&sleep_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&sleep_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&sleep_title_anim_move_y, lv_obj_get_y(guider_ui.sleep_title), 0);
	  	lv_anim_set_path_cb(&sleep_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&sleep_title_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&sleep_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&sleep_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&sleep_title_anim_move_y, 0);
		lv_anim_start(&sleep_title_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.blood_pressure_del == true) {
			          setup_scr_blood_pressure(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.blood_pressure, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.sleep_del = true;
			    }
				break;
			}
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.step_del == true) {
			          setup_scr_step(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.step, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.sleep_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void sleep_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.sleep_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_sleep(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->sleep, sleep_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->sleep_home, sleep_home_event_handler, LV_EVENT_ALL, NULL);
}
static void step_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: step_cont_1 move_x
	  	lv_anim_t step_cont_1_anim_move_x;
	  	lv_anim_init(&step_cont_1_anim_move_x);
	  	lv_anim_set_var(&step_cont_1_anim_move_x, guider_ui.step_cont_1);
	  	lv_anim_set_time(&step_cont_1_anim_move_x, 800);
	  	lv_anim_set_delay(&step_cont_1_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&step_cont_1_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&step_cont_1_anim_move_x, lv_obj_get_x(guider_ui.step_cont_1), 111);
	  	lv_anim_set_path_cb(&step_cont_1_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&step_cont_1_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&step_cont_1_anim_move_x, 0);
	  	lv_anim_set_playback_time(&step_cont_1_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&step_cont_1_anim_move_x, 0);
		lv_anim_start(&step_cont_1_anim_move_x);
		//Write animation: step_cont_1 move_y
	  	lv_anim_t step_cont_1_anim_move_y;
	  	lv_anim_init(&step_cont_1_anim_move_y);
	  	lv_anim_set_var(&step_cont_1_anim_move_y, guider_ui.step_cont_1);
	  	lv_anim_set_time(&step_cont_1_anim_move_y, 800);
	  	lv_anim_set_delay(&step_cont_1_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&step_cont_1_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&step_cont_1_anim_move_y, lv_obj_get_y(guider_ui.step_cont_1), 260);
	  	lv_anim_set_path_cb(&step_cont_1_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&step_cont_1_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&step_cont_1_anim_move_y, 0);
	  	lv_anim_set_playback_time(&step_cont_1_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&step_cont_1_anim_move_y, 0);
		lv_anim_start(&step_cont_1_anim_move_y);
		//Write animation: step_title move_x
	  	lv_anim_t step_title_anim_move_x;
	  	lv_anim_init(&step_title_anim_move_x);
	  	lv_anim_set_var(&step_title_anim_move_x, guider_ui.step_title);
	  	lv_anim_set_time(&step_title_anim_move_x, 800);
	  	lv_anim_set_delay(&step_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&step_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&step_title_anim_move_x, lv_obj_get_x(guider_ui.step_title), 0);
	  	lv_anim_set_path_cb(&step_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&step_title_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&step_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&step_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&step_title_anim_move_x, 0);
		lv_anim_start(&step_title_anim_move_x);
		//Write animation: step_title move_y
	  	lv_anim_t step_title_anim_move_y;
	  	lv_anim_init(&step_title_anim_move_y);
	  	lv_anim_set_var(&step_title_anim_move_y, guider_ui.step_title);
	  	lv_anim_set_time(&step_title_anim_move_y, 800);
	  	lv_anim_set_delay(&step_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&step_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&step_title_anim_move_y, lv_obj_get_y(guider_ui.step_title), 0);
	  	lv_anim_set_path_cb(&step_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&step_title_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&step_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&step_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&step_title_anim_move_y, 0);
		lv_anim_start(&step_title_anim_move_y);
		//Write animation: step_icon_step move_x
	  	lv_anim_t step_icon_step_anim_move_x;
	  	lv_anim_init(&step_icon_step_anim_move_x);
	  	lv_anim_set_var(&step_icon_step_anim_move_x, guider_ui.step_icon_step);
	  	lv_anim_set_time(&step_icon_step_anim_move_x, 800);
	  	lv_anim_set_delay(&step_icon_step_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&step_icon_step_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&step_icon_step_anim_move_x, lv_obj_get_x(guider_ui.step_icon_step), 182);
	  	lv_anim_set_path_cb(&step_icon_step_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&step_icon_step_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&step_icon_step_anim_move_x, 0);
	  	lv_anim_set_playback_time(&step_icon_step_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&step_icon_step_anim_move_x, 0);
		lv_anim_start(&step_icon_step_anim_move_x);
		//Write animation: step_icon_step move_y
	  	lv_anim_t step_icon_step_anim_move_y;
	  	lv_anim_init(&step_icon_step_anim_move_y);
	  	lv_anim_set_var(&step_icon_step_anim_move_y, guider_ui.step_icon_step);
	  	lv_anim_set_time(&step_icon_step_anim_move_y, 800);
	  	lv_anim_set_delay(&step_icon_step_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&step_icon_step_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&step_icon_step_anim_move_y, lv_obj_get_y(guider_ui.step_icon_step), 93);
	  	lv_anim_set_path_cb(&step_icon_step_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&step_icon_step_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&step_icon_step_anim_move_y, 0);
	  	lv_anim_set_playback_time(&step_icon_step_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&step_icon_step_anim_move_y, 0);
		lv_anim_start(&step_icon_step_anim_move_y);
		//Write animation: step_arc_step move_x
	  	lv_anim_t step_arc_step_anim_move_x;
	  	lv_anim_init(&step_arc_step_anim_move_x);
	  	lv_anim_set_var(&step_arc_step_anim_move_x, guider_ui.step_arc_step);
	  	lv_anim_set_time(&step_arc_step_anim_move_x, 800);
	  	lv_anim_set_delay(&step_arc_step_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&step_arc_step_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&step_arc_step_anim_move_x, lv_obj_get_x(guider_ui.step_arc_step), 11);
	  	lv_anim_set_path_cb(&step_arc_step_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&step_arc_step_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&step_arc_step_anim_move_x, 0);
	  	lv_anim_set_playback_time(&step_arc_step_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&step_arc_step_anim_move_x, 0);
		lv_anim_start(&step_arc_step_anim_move_x);
		//Write animation: step_arc_step move_y
	  	lv_anim_t step_arc_step_anim_move_y;
	  	lv_anim_init(&step_arc_step_anim_move_y);
	  	lv_anim_set_var(&step_arc_step_anim_move_y, guider_ui.step_arc_step);
	  	lv_anim_set_time(&step_arc_step_anim_move_y, 800);
	  	lv_anim_set_delay(&step_arc_step_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&step_arc_step_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&step_arc_step_anim_move_y, lv_obj_get_y(guider_ui.step_arc_step), 11);
	  	lv_anim_set_path_cb(&step_arc_step_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&step_arc_step_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&step_arc_step_anim_move_y, 0);
	  	lv_anim_set_playback_time(&step_arc_step_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&step_arc_step_anim_move_y, 0);
		lv_anim_start(&step_arc_step_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.sleep_del == true) {
			          setup_scr_sleep(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.sleep, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.step_del = true;
			    }
				break;
			}
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.menstrual_del == true) {
			          setup_scr_menstrual(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.menstrual, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.step_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
void events_init_step(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->step, step_event_handler, LV_EVENT_ALL, NULL);
}
static void menstrual_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		//Write animation: menstrual_label_cycle move_x
	  	lv_anim_t menstrual_label_cycle_anim_move_x;
	  	lv_anim_init(&menstrual_label_cycle_anim_move_x);
	  	lv_anim_set_var(&menstrual_label_cycle_anim_move_x, guider_ui.menstrual_label_cycle);
	  	lv_anim_set_time(&menstrual_label_cycle_anim_move_x, 800);
	  	lv_anim_set_delay(&menstrual_label_cycle_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&menstrual_label_cycle_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&menstrual_label_cycle_anim_move_x, lv_obj_get_x(guider_ui.menstrual_label_cycle), 148);
	  	lv_anim_set_path_cb(&menstrual_label_cycle_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&menstrual_label_cycle_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&menstrual_label_cycle_anim_move_x, 0);
	  	lv_anim_set_playback_time(&menstrual_label_cycle_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&menstrual_label_cycle_anim_move_x, 0);
		lv_anim_start(&menstrual_label_cycle_anim_move_x);
		//Write animation: menstrual_label_cycle move_y
	  	lv_anim_t menstrual_label_cycle_anim_move_y;
	  	lv_anim_init(&menstrual_label_cycle_anim_move_y);
	  	lv_anim_set_var(&menstrual_label_cycle_anim_move_y, guider_ui.menstrual_label_cycle);
	  	lv_anim_set_time(&menstrual_label_cycle_anim_move_y, 800);
	  	lv_anim_set_delay(&menstrual_label_cycle_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&menstrual_label_cycle_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&menstrual_label_cycle_anim_move_y, lv_obj_get_y(guider_ui.menstrual_label_cycle), 78);
	  	lv_anim_set_path_cb(&menstrual_label_cycle_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&menstrual_label_cycle_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&menstrual_label_cycle_anim_move_y, 0);
	  	lv_anim_set_playback_time(&menstrual_label_cycle_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&menstrual_label_cycle_anim_move_y, 0);
		lv_anim_start(&menstrual_label_cycle_anim_move_y);
		//Write animation: menstrual_label_ovulation move_x
	  	lv_anim_t menstrual_label_ovulation_anim_move_x;
	  	lv_anim_init(&menstrual_label_ovulation_anim_move_x);
	  	lv_anim_set_var(&menstrual_label_ovulation_anim_move_x, guider_ui.menstrual_label_ovulation);
	  	lv_anim_set_time(&menstrual_label_ovulation_anim_move_x, 800);
	  	lv_anim_set_delay(&menstrual_label_ovulation_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&menstrual_label_ovulation_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&menstrual_label_ovulation_anim_move_x, lv_obj_get_x(guider_ui.menstrual_label_ovulation), 121);
	  	lv_anim_set_path_cb(&menstrual_label_ovulation_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&menstrual_label_ovulation_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&menstrual_label_ovulation_anim_move_x, 0);
	  	lv_anim_set_playback_time(&menstrual_label_ovulation_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&menstrual_label_ovulation_anim_move_x, 0);
		lv_anim_start(&menstrual_label_ovulation_anim_move_x);
		//Write animation: menstrual_label_ovulation move_y
	  	lv_anim_t menstrual_label_ovulation_anim_move_y;
	  	lv_anim_init(&menstrual_label_ovulation_anim_move_y);
	  	lv_anim_set_var(&menstrual_label_ovulation_anim_move_y, guider_ui.menstrual_label_ovulation);
	  	lv_anim_set_time(&menstrual_label_ovulation_anim_move_y, 800);
	  	lv_anim_set_delay(&menstrual_label_ovulation_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&menstrual_label_ovulation_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&menstrual_label_ovulation_anim_move_y, lv_obj_get_y(guider_ui.menstrual_label_ovulation), 327);
	  	lv_anim_set_path_cb(&menstrual_label_ovulation_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&menstrual_label_ovulation_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&menstrual_label_ovulation_anim_move_y, 0);
	  	lv_anim_set_playback_time(&menstrual_label_ovulation_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&menstrual_label_ovulation_anim_move_y, 0);
		lv_anim_start(&menstrual_label_ovulation_anim_move_y);
		//Write animation: menstrual_title move_x
	  	lv_anim_t menstrual_title_anim_move_x;
	  	lv_anim_init(&menstrual_title_anim_move_x);
	  	lv_anim_set_var(&menstrual_title_anim_move_x, guider_ui.menstrual_title);
	  	lv_anim_set_time(&menstrual_title_anim_move_x, 800);
	  	lv_anim_set_delay(&menstrual_title_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&menstrual_title_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&menstrual_title_anim_move_x, lv_obj_get_x(guider_ui.menstrual_title), 0);
	  	lv_anim_set_path_cb(&menstrual_title_anim_move_x, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&menstrual_title_anim_move_x, 1);
	  	lv_anim_set_repeat_delay(&menstrual_title_anim_move_x, 0);
	  	lv_anim_set_playback_time(&menstrual_title_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&menstrual_title_anim_move_x, 0);
		lv_anim_start(&menstrual_title_anim_move_x);
		//Write animation: menstrual_title move_y
	  	lv_anim_t menstrual_title_anim_move_y;
	  	lv_anim_init(&menstrual_title_anim_move_y);
	  	lv_anim_set_var(&menstrual_title_anim_move_y, guider_ui.menstrual_title);
	  	lv_anim_set_time(&menstrual_title_anim_move_y, 800);
	  	lv_anim_set_delay(&menstrual_title_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&menstrual_title_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&menstrual_title_anim_move_y, lv_obj_get_y(guider_ui.menstrual_title), 0);
	  	lv_anim_set_path_cb(&menstrual_title_anim_move_y, &lv_anim_path_bounce);
	  	lv_anim_set_repeat_count(&menstrual_title_anim_move_y, 1);
	  	lv_anim_set_repeat_delay(&menstrual_title_anim_move_y, 0);
	  	lv_anim_set_playback_time(&menstrual_title_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&menstrual_title_anim_move_y, 0);
		lv_anim_start(&menstrual_title_anim_move_y);
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_LEFT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.blood_oxygen_del == true) {
			          setup_scr_blood_oxygen(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.blood_oxygen, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.menstrual_del = true;
			    }
				break;
			}
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				//Write the load screen code.
			    lv_obj_t * act_scr = lv_scr_act();
			    lv_disp_t * d = lv_obj_get_disp(act_scr);
			    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			        if (guider_ui.step_del == true) {
			          setup_scr_step(&guider_ui);
			        }
			        lv_scr_load_anim(guider_ui.step, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
			        guider_ui.menstrual_del = true;
			    }
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void menstrual_home_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.home_analog_del == true) {
	          setup_scr_home_analog(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, true);
	        guider_ui.menstrual_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_menstrual(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->menstrual, menstrual_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->menstrual_home, menstrual_home_event_handler, LV_EVENT_ALL, NULL);
}

void events_init(lv_ui *ui)
{

}
