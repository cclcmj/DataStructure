#include <stdio.h>
#include <stdlib.h>
#include <DataStructure.h>
#include <SXStack.h>

SXStack CreateSXStack(int MAXSIZE)
{
    SXStack S=(SXStack)malloc(sizeof(struct SXSNode));
    S->Data=(ElementType*)malloc(MAXSIZE*sizeof(ElementType));
    S->top=-1;
    S->MAXSIZE=MAXSIZE;
}
int IsFull(SXStack S)
{
    if(S->top==S->MAXSIZE-1)return 1;
    else return 0;
}
int IsEmpty(SXStack S)
{
    if(S->top==-1)return 1;
    else return 0;
}
void Push(SXStack S,ElementType item)
{
    if(IsFull(S)){
        printf("栈满，无法插入元素\n");
        return;
    }
    S->Data[++(S->top)]=item;
    return;
}
ElementType Pop(SXStack S)
{
    if(IsEmpty(S)){
        printf("栈已空\n");
        return -1;
    }else{
        return (S->Data[(S->top)--]);
    }

}
void printSXStack(SXStack S)
{
    for(int i=0;i<=S->top;i++)
        printf("%d,",S->Data[i]);
    printf("\n");

}
