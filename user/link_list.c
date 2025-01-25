#include "link_list.h"
/*
 *创建循环链表
 * 输入:
 * n：普通链表的个数，为0则只有头链表和尾链表
 * 输出:
 * 返回头链表
 */
LinkList *link_list_creat(int n){
    LinkList *head, *node, *end,*head_temp;//定义头节点，普通节点，尾部节点
    head = (LinkList*)malloc(sizeof(LinkList));//分配地址
    end = (LinkList*)malloc(sizeof(LinkList));//分配地址
    head_temp=head;

    head->id=0;//头链表id为0
    head->on=end;

    end->id=n+1;//尾链表id为最后一个
    end->next=head;//尾链表的下个链表尾头链表

    if (n == 0) {
        end->on=head;
        head->next=end;
        return head;
    }

    for(int i = 1; i < n+1; i++) {
        node = (LinkList*)malloc(sizeof(LinkList));//分配内存

        node->id=i;//分配ID
        node->on=head_temp;//设置第一个普通链表的上一个为头链表，第二个普通链表的头为上一个普通链表
        head_temp->next = node;//第一次为头链表为第一个普通链表，第二次则是上一个普通连表的下个链表为本次链表
        head_temp = node;//上个链表赋值尾本次链表
    }
    head_temp->next = end;//普通链表的下一个为尾链表
    end->on=head_temp;//尾链表的上一个是最后一个普通链表

    return head;//返回头链表
}


void link_list_change(LinkList *list,int id,lv_obj_t *lvgl_scr,bool lvgl_scr_del,ui_setup_scr_t setup_scr) {
    LinkList *t = list;
    while(t->next!=NULL && t->id!=id) {
        t=t->next;
    }
    t->lvgl_scr=lvgl_scr;
    t->lvgl_scr_del=lvgl_scr_del;
    t->setup_scr=setup_scr;
}