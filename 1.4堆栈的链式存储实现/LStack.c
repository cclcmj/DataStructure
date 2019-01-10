#include <stdio.h>
#include <stdlib.h>
#include <DataStructure.h>
#include <LStack.h>

LStack CreateLStack()
{
    LStack S=(LStack)malloc(sizeof(struct LSNode));
    S->Next=NULL;
    return S;
}
int IsEmpty(LStack S)
{
    if(S->Next)
        return 0;
    else
        return 1;
}
void Push(ElementType item,LStack S)
{
    LStack n=(LStack)malloc(sizeof(struct LSNode));
    n->Data=item;
    n->Next=S->Next;
    S->Next=n;
}
ElementType Pop(LStack S)
{
    if(IsEmpty(S))
    {
        printf("栈满");
        return NULL;
    }
    else
    {
        int i;
        LStack n=(LStack)malloc(sizeof(struct LSNode));
        n=S->Next;
        i=n->Data;
        S->Next=n->Next;
        free(n);
        return i;
    }
}

void printLStack(LStack S)
{
    LStack pos=S->Next;
    while(pos)
    {
        printf("%d,",pos->Data);
        pos=pos->Next;
    }
    printf("\n");
    return;
}
