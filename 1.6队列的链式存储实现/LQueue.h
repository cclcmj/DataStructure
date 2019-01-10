#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#include <DataStructure.h>

/*
队列的链式存储实现
*/
typedef struct LQNode *LQueue;
struct Node
{
    ElementType Data;
    struct Node *Next;
};
struct LQNode
{
    struct Node *fron;
    struct Node *rear;
};

LQueue CreateLQ();
int IsEmptyLQ(LQueue Q);
void AddLQ(LQueue Q,ElementType item);
ElementType DeleteLQ(LQueue Q);

void printLQ(LQueue Q);//输出全部元素

#endif // LQUEUE_H_INCLUDED
