#include "link_list.h"
/*
 *创建循环链表
 * 输入:
 * n：链表的个数，为0则只有头链表和尾链表，
 * 输出:
 * 返回头链表
 */
LinkList *link_list_creat(int n)
{
    n=n-2;//去掉头尾节点
    if (n<0) return NULL;
    //定义头节点，尾部节点
    LinkList *head = (LinkList *) malloc(sizeof(LinkList));//分配地址
    LinkList *end = (LinkList *) malloc(sizeof(LinkList));//分配地址
    LinkList *head_temp = head;

    head->id=0;//头链表id为0
    head->on=end;

    end->id=n+1;//尾链表id为最后一个
    end->next=head;//尾链表的下个链表尾头链表

    if (n == 0) {//如果n为0则把头尾链表相交
        end->on=head;
        head->next=end;
        return head;
    }

    for(int i = 1; i < n+1; i++) {
        //定义普通节点
        LinkList *node = (LinkList *) malloc(sizeof(LinkList));//分配内存
        node->id=i;//分配ID
        node->on=head_temp;//设置第一个普通链表的上一个为头链表，第二个普通链表的头为上一个普通链表
        head_temp->next = node;//第一次为头链表为第一个普通链表，第二次则是上一个普通连表的下个链表为本次链表
        head_temp = node;//上个链表赋值尾本次链表
    }
    head_temp->next = end;//普通链表的下一个为尾链表
    end->on=head_temp;//尾链表的上一个是最后一个普通链表

    return head;//返回头链表
}

/*
 *插入链表内容
 * 输入:
 * list：链表头文件
 * id：链表ID
 * lvgl_scr：lvgl屏幕结构体
 * lvgl_scr_del：lvgl屏幕状态
 * setup_scr：lvgl屏幕函数
 * 输出:
 * 无
 */
void link_list_change(LinkList *list,int id,lv_obj_t *lvgl_scr,bool lvgl_scr_del,ui_setup_scr_t setup_scr) {
    while(list->next!=NULL && list->id!=id) {
        list=list->next;
    }
    list->lvgl_scr=lvgl_scr;
    list->lvgl_scr_del=lvgl_scr_del;
    list->setup_scr=setup_scr;
}