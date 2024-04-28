// 带头指针的循环链表：方便从任意位置遍历链表

// 带尾指针的循环链表：方便从任意位置遍历链表，同时方便链表的合并
/*
    p = rearA->next;
    rearA->next = rearB->next->next;
    rearB = p;
    free(p);
*/

// 双向循环链表：可以从链表中任意的位置，任意方向遍历链表
// 用空间换时间
// 时间复杂度下降；空间复杂度上升
// 双向链表的定义
/*
    typedef struct DulNode {   
        ElemType data;
        DulNode *prior;
        DulNode *next;
    } DulNode, *DuLinkList;
*/

// 双向链表的插入操作
// 在p的后面插入s
// 注意：指针修改的顺序不可随意改动
// 若先将p->next修改了，就不行
/*
    s->prior = p;
    s->next = p->next;
    p->next->prior = s;
    p->next = s;        
*/

// 双向链表的删除操作
// 删除位置p的结点
/*
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
*/