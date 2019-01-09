#ifndef LLIST_H_INCLUDED
#define LLIST_H_INCLUDED

/*
线性表的链式存储实现
*/

typedef struct LLNod *LList;
struct LLNod
{
    ElementType Data;
    LList Next;
};

LList MakeEmpty();
int Length(LList L);
LList FindKth(int K,LList L);
LList Find(ElementType X,LList L);
LList Insert(ElementType X,int i,LList L);//不存在，表头，正常
LList Delete(int i,LList L);//不存在，表头，正常

//输出链表的全部元素
void printLList(LList L);


#endif // LLIST_H_INCLUDED
