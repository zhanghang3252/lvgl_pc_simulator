#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del)
{
    lv_obj_t * act_scr = lv_scr_act();
    if (auto_del && is_clean) {
        lv_obj_clean(act_scr);
    }
    if (new_scr_del) {
        //setup_scr(ui);//会重新绘制页面有bug
    }
    lv_scr_load_anim(*new_scr, anim_type, time, delay, auto_del);
    //*old_scr_del = auto_del;
}

void init_scr_del_flag(lv_ui *ui)
{
    ui->timer_scr_del = true;
    ui->led_scr_del = true;
    ui->tz_scr_del = true;
    ui->watch_scr_del = true;
}

void setup_ui(lv_ui *ui)
{
    init_scr_del_flag(ui);

    setup_scr_timer_scr(ui);
    setup_scr_led_scr(ui);
    setup_scr_tz_scr(ui);
    setup_scr_watch_scr(ui);

    lv_scr_load(ui->timer_scr);
}
