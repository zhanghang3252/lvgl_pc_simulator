#define _DEFAULT_SOURCE /* needed for usleep() */
#include <stdlib.h>
#include <unistd.h>
#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" issue*/
#include <SDL2/SDL.h>
#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"
#include "lv_drivers/sdl/sdl.h"
#include "gui_guider_ui/src/generated/gui_guider.h"
#include "gui_guider_ui/src/generated/events_init.h"
#include <time.h>
#include <stdio.h>
#include <pthread.h>
#include "user/link_list.h"

extern LinkList *lvgl_link_list;
void hal_init(void);
lv_ui guider_ui;
pthread_t lvgl_tick,lvgl_date_timer,lvgl_power;//线程
pthread_mutex_t lvgl_mutex;//线程互斥锁

/*充电动画函数*/
void *lvgl_power_f( void *arg ) {
    uint8_t power_value = 0;
    while (1) {
        if (power_value == 100) {
            power_value = 0;
        }
        pthread_mutex_lock(&lvgl_mutex);
        power_value++;
        lv_bar_set_value(guider_ui.timer_scr_bar_power,power_value,LV_ANIM_ON);
        lv_textprogress_set_value(guider_ui.timer_scr_textprogress_1,power_value);
        pthread_mutex_unlock(&lvgl_mutex);
        usleep(50*1000);//500ms
    }
}

/*更新日期时间线程函数*/
void *lvgl_date_timer_f(void *arg) {
    time_t current_time;
    struct tm *local_time;
    while (1) {
        current_time = time(NULL); // 获取当前时间
        local_time = localtime(&current_time);
        pthread_mutex_lock(&lvgl_mutex);
        lv_dclock_set_text_fmt(guider_ui.timer_scr_digital_clock_1,"%2d:%2d:%2d",local_time->tm_hour,local_time->tm_min,local_time->tm_sec);
        lv_label_set_text_fmt(guider_ui.timer_scr_datetext_1,"%d/%d/%d",2000+(local_time->tm_year-100),local_time->tm_mon+1,local_time->tm_mday);
        printf("time: %d:%d:%d\n",local_time->tm_hour,local_time->tm_min,local_time->tm_sec);
        lv_analogclock_set_time(guider_ui.watch_scr_analog_clock_1,local_time->tm_hour%12,local_time->tm_min,local_time->tm_sec);
        pthread_mutex_unlock(&lvgl_mutex);
        sleep(1);
    }
}
int main(void)
{
    lv_init();
    hal_init();

    pthread_mutex_init(&lvgl_mutex,NULL);//创建互斥锁

    pthread_mutex_lock(&lvgl_mutex);//获取锁
    setup_ui(&guider_ui);//界面初始化
    events_init(&guider_ui);//事件初始化
    pthread_mutex_unlock(&lvgl_mutex);//释放锁

    pthread_create(&lvgl_power,NULL,lvgl_power_f,NULL);//创建充电更新线程
    pthread_create(&lvgl_date_timer,NULL,lvgl_date_timer_f,NULL);//创建日期时间更新线程

    lvgl_link_list = link_list_creat(2);//创建4个循环链表
    link_list_change(lvgl_link_list,0,guider_ui.timer_scr,guider_ui.timer_scr_del,setup_scr_timer_scr);//插入链表内容
    link_list_change(lvgl_link_list,1,guider_ui.led_scr,guider_ui.led_scr_del,setup_scr_led_scr);//插入链表内容
    link_list_change(lvgl_link_list,2,guider_ui.tz_scr,guider_ui.tz_scr_del,setup_scr_tz_scr);//插入链表内容
    link_list_change(lvgl_link_list,3,guider_ui.watch_scr,guider_ui.watch_scr_del,setup_scr_watch_scr);//插入链表内容


    while (1) {
        pthread_mutex_lock(&lvgl_mutex);//获取锁
        lv_timer_handler();
        lv_task_handler();
        pthread_mutex_unlock(&lvgl_mutex);//释放锁
        usleep(1 * 1000);
    }
}
