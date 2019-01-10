#ifndef SXQUEUE_H_INCLUDED
#define SXQUEUE_H_INCLUDED
#include <DataStructure.h>
/*
循环队列的顺序存储实现
*/
typedef struct SXQNode *SXQueue;
struct SXQNode
{
    ElementType *Data;
    int rear;//表尾
    int fron;//表头
    int Maxsize;
};

SXQueue CreateSXQueue(int Maxsize);
int IsFullQ(SXQueue Q);
int IsEmptyQ(SXQueue);
void AddSXQ(SXQueue Q,ElementType item);
ElementType DeleteSXQ(SXQueue);

void printSXQ(SXQueue Q);//输出所有元素

#endif // SXQUEUE_H_INCLUDED
