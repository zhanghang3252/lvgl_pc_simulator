//
// Created by 20757 on 25-1-25.
//

#ifndef LINK_LIST_H
#define LINK_LIST_H
#include "stdlib.h"
#include "lvgl/lvgl.h"
#include "gui_guider_ui/src/generated/gui_guider.h"
typedef struct student{
    /*-链表必须设置项-*/
    uint8_t id;//屏幕ID
    struct student *next;
    struct student *on;
    /*-------------*/

    lv_obj_t *lvgl_scr;//屏幕结构体
    bool lvgl_scr_del;//是否更新
    ui_setup_scr_t setup_scr;//更新函数
} LinkList;



LinkList *link_list_creat(int n);
void link_list_change(LinkList *list,int id,lv_obj_t *lvgl_scr,bool lvgl_scr_del,ui_setup_scr_t setup_scr);
#endif //LINK_LIST_H
