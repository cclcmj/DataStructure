#ifndef LSTACK_H_INCLUDED
#define LSTACK_H_INCLUDED
#include <DataStructure.h>

/*
堆栈的链式存储实现
*/
typedef struct LSNode *LStack;
struct LSNode
{
    ElementType Data;
    LStack Next;
};

LStack CreateLStack();
int IsEmpty(LStack S);
void Push(ElementType item,LStack S);
ElementType Pop(LStack S);//判断栈空

void printLStack(LStack S);//输出栈的全部元素
#endif // LSTACK_H_INCLUDED
