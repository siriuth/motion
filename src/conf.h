/*   This file is part of Motion.
 *
 *   Motion is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   Motion is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Motion.  If not, see <https://www.gnu.org/licenses/>.
 */

/*
 * conf.h
 *   Originally written for the dproxy package by Matthew Pratt.
 *   Copyright 2000 Jeroen Vreeken (pe1rxq@chello.nl)
 */

#ifndef _INCLUDE_CONF_H
#define _INCLUDE_CONF_H

typedef
enum tagTIMELAPSE_MODE
    {
        TIMELAPSE_MODE_MANUAL           = 0,
        TIMELAPSE_MODE_DAILY            = 1,
        TIMELAPSE_MODE_HOURLY           = 2,
        TIMELAPSE_MODE_WEEKLY_SUNDAY    = 3,
        TIMELAPSE_MODE_WEEKLY_MONDAY    = 4,
        TIMELAPSE_MODE_MONTHLY          = 5
    } 	TIMELAPSE_MODE;

typedef
enum tagPICTURE_OUTPUT
    {
        PICTURE_OUTPUT_OFF       = 0,
        PICTURE_OUTPUT_ON        = 1,
        PICTURE_OUTPUT_FIRST     = 2,
        PICTURE_OUTPUT_BEST      = 3,
        PICTURE_OUTPUT_CENTER    = 4
    } 	PICTURE_OUTPUT;

typedef
enum tagLOCATE_MOTION_MODE
    {
        LOCATE_MOTION_MODE_OFF       = 0,
        LOCATE_MOTION_MODE_ON        = 1,
        LOCATE_MOTION_MODE_PREVIEW   = 2
    } 	LOCATE_MOTION_MODE;

typedef
enum tagLOCATE_MOTION_STYLE
    {
        //LOCATE_MOTION_STYLE_OFF         = 0,
        LOCATE_MOTION_STYLE_BOX	        = 1,
        LOCATE_MOTION_STYLE_REDBOX      = 0xF000+1,
        LOCATE_MOTION_STYLE_CROSS       = 2,
        LOCATE_MOTION_STYLE_REDCROSS    = 0xF000+2
    } 	LOCATE_MOTION_STYLE;

/*
* More parameters may be added later.
*/
struct config {
    /* Overall system configuration parameters */
    /* daemon is directly cast into the cnt context rather than conf */
    int             setup_mode;
    char            *pid_file;
    char            *log_file;
    int             log_level;
    char            *log_type;
    int             quiet;
    int             native_language;
    int             watchdog_tmo;
    int             watchdog_kill;
    const char      *camera_name;
    int             camera_id;
    const char      *camera_dir;
    const char      *target_dir;

    /* Capture device configuration parameters */
    const char      *video_device;
    char            *video_params;
    int             auto_brightness;
    const char      *tuner_device;
    int             roundrobin_frames;
    int             roundrobin_skip;
    int             roundrobin_switchfilter;

    const char      *netcam_url;
    char            *netcam_params;
    const char      *netcam_high_url;
    char            *netcam_high_params;
    const char      *netcam_userpass;

    const char      *mmalcam_name;
    const char      *mmalcam_params;

    /* Image processing configuration parameters */
    int             width;
    int             height;
    int             framerate;
    int             minimum_frame_time;
    int             rotate;
    const char      *flip_axis;
    //const char      *locate_motion_mode;
    LOCATE_MOTION_MODE locate_motion_mode;
    //const char      *locate_motion_style;
    LOCATE_MOTION_STYLE locate_motion_style;
    const char      *text_left;
    const char      *text_right;
    int             text_changes;
    int             text_scale;
    const char      *text_event;

    /* Motion detection configuration parameters */
    int             pause;
    int             emulate_motion;
    int             threshold;
    int             threshold_maximum;
    int             threshold_tune;
    int             noise_level;
    int             noise_tune;
    const char      *despeckle_filter;
    const char      *area_detect;
    const char      *mask_file;
    const char      *mask_privacy;
    int             smart_mask_speed;
    int             lightswitch_percent;
    int             lightswitch_frames;
    int             microlightswitch;
    int             minimum_motion_frames;
    int             event_gap;
    int             pre_capture;
    int             post_capture;

    /* Script execution configuration parameters */
    char            *on_event_start;
    char            *on_event_end;
    char            *on_picture_save;
    char            *on_area_detected;
    char            *on_motion_detected;
    char            *on_movie_start;
    char            *on_movie_end;
    char            *on_camera_lost;
    char            *on_camera_found;

    /* Picture output configuration parameters */
    //const char      *picture_output;
    PICTURE_OUTPUT  picture_output;
    int             picture_output_motion;
    const char      *picture_type;
    int             picture_quality;
    const char      *picture_exif;
    const char      *picture_filename;

    /* Snapshot configuration parameters */
    int             snapshot_interval;
    const char      *snapshot_filename;

    /* Movie output configuration parameters */
    int             movie_output;
    int             movie_output_motion;
    int             movie_max_time;
    int             movie_bps;
    int             movie_quality;
    const char      *movie_codec;
    int             movie_duplicate_frames;
    int             movie_passthrough;
    const char      *movie_filename;
    const char      *movie_motion_filename_suffix;
    const char      *movie_extpipe_filename_suffix;
    int             movie_extpipe_use;
    const char      *movie_extpipe;

    /* Timelapse movie configuration parameters */
    int             timelapse_interval;
    //const char      *timelapse_mode;
    TIMELAPSE_MODE  timelapse_mode;
    int             timelapse_fps;
    int             timelapse_bps;
    int             timelapse_quality;
    const char      *timelapse_codec;
    const char      *timelapse_filename;

    /* Loopback device configuration parameters */
    const char      *video_pipe;
    const char      *video_pipe_motion;

    /* Webcontrol configuration parameters */
    int             webcontrol_port;
    int             webcontrol_ipv6;
    int             webcontrol_localhost;
    int             webcontrol_parms;
    int             webcontrol_interface;
    int             webcontrol_auth_method;
    const char      *webcontrol_authentication;
    int             webcontrol_tls;
    const char      *webcontrol_cert;
    const char      *webcontrol_key;
    char            *webcontrol_header_params;
    int             webcontrol_lock_minutes;
    int             webcontrol_lock_attempts;
    int             webcontrol_lock_max_ips;

    /* Live stream configuration parameters */
    int             stream_port;
    int             stream_localhost;
    int             stream_auth_method;
    const char      *stream_authentication;
    int             stream_tls;
    char            *stream_header_params;
    int             stream_preview_scale;
    int             stream_preview_newline;
    int             stream_preview_method;
    int             stream_quality;
    int             stream_grey;
    int             stream_motion;
    int             stream_maxrate;
    int             stream_limit;

    /* Database and SQL configuration parameters */
    const char      *database_type;
    const char      *database_dbname;
    const char      *database_host;
    int             database_port;
    const char      *database_user;
    const char      *database_password;
    int             database_busy_timeout;

    int             sql_log_picture;
    int             sql_log_snapshot;
    int             sql_log_movie;
    int             sql_log_timelapse;
    const char      *sql_query_start;
    const char      *sql_query_stop;
    const char      *sql_query;

    /* Command line parameters */
    int             argc;
    char            **argv;
};

struct context;
/**
 * typedef for a param copy function.
 */
typedef void (* conf_copy_func)(struct context *, char *, int);
typedef const char *(* conf_print_func)(struct context **, char **, int, unsigned int);

/**
 * description for parameters in the config file
 */
typedef struct {
    const char      *param_name;      /* name for this parameter                  */
    const char      *param_help;      /* short explanation for parameter          */
    unsigned int    main_thread;      /* belong only to main thread when value>0  */
    int             conf_value;       /* pointer to a field in struct context     */
    conf_copy_func  copy;             /* a function to set the value in 'config'  */
    conf_print_func print;            /* a function to output the value to a file */
    int             webui_level;      /* Enum to display in webui: 0,1,2,3,99(always to never)*/
} config_param;

extern config_param config_params[];

/**
 * description for deprecated parameters in the config file
 */
typedef struct {
    const char      *name;          /* Name of the deprecated option */
    const char      *last_version;  /* Last version this option was used in */
    const char      *info;          /* Short text on why it was deprecated (removed, replaced with, etc) */
    int             conf_value;     /* Pointer to the replacement field in struct context */
    const char      *newname;       /* Name of the new parameter */
    conf_copy_func  copy;           /* Function to set the replacement value */
} dep_config_param;

extern dep_config_param dep_config_params[];

struct context **conf_cmdparse(struct context **cnt, char *cmd, char *arg1);
void conf_print(struct context **cnt);
struct context **conf_load(struct context **cnt);
void conf_output_parms(struct context **cnt);
void copy_string(struct context *cnt, char *str, int val_ptr);

#endif /* _INCLUDE_CONF_H */
