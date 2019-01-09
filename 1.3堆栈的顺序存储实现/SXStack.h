#ifndef SXSTACK_H_INCLUDED
#define SXSTACK_H_INCLUDED
#include <DataStructure.h>


/*
堆栈的顺序存储实现
*/

typedef struct SXSNode *SXStack;
struct SXSNode
{
    ElementType *Data;//存储元素的数组
    int top;
    int MAXSIZE;
};

SXStack CreateSXStack(int MAXSIZE);
int IsFull(SXStack S);
void Push(SXStack S,ElementType item);//入栈，判断栈满
int IsEmpty(SXStack S);
ElementType Pop(SXStack S);//出栈，判断栈空

//输出全部元素
void printSXStack(SXStack S);

#endif // SXSTACK_H_INCLUDED
