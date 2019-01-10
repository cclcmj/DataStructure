#include <stdio.h>
#include <stdlib.h>
#include <DataStructure.h>
#include <SXQueue.h>

SXQueue CreateSXQueue(int Maxsize)
{
    SXQueue n=(SXQueue)malloc(sizeof(struct SXQNode));
    n->Data=(ElementType*)malloc((Maxsize+1)*sizeof(ElementType));
    n->rear=0;
    n->fron=0;
    n->Maxsize=Maxsize;
}
int IsFullQ(SXQueue Q)
{
    return ((Q->rear+1)%(Q->Maxsize+1)==Q->fron);
}
int IsEmptyQ(SXQueue Q)
{
    return (Q->rear==Q->fron);
}
void AddSXQ(SXQueue Q,ElementType item)
{
    if(IsFullQ(Q)){
        printf("队列满\n");
        return;
    }else{
        Q->rear=(Q->rear+1)%(Q->Maxsize+1);
        Q->Data[Q->rear]=item;
        return;
    }
}
ElementType DeleteSXQ(SXQueue Q)
{
    if(IsEmptyQ(Q)){
        printf("队列空\n");
        return -1;
    }else{
        Q->fron=(Q->fron+1)%(Q->Maxsize+1);
        return Q->Data[Q->fron];
    }
}

void printSXQ(SXQueue Q)
{
    int pos=(Q->fron+1)%(Q->Maxsize+1);
    while(pos!=(Q->rear+1)%(Q->Maxsize+1))
    {
        printf("%d,",Q->Data[pos]);
        pos=(pos+1)%(Q->Maxsize+1);
    }
    printf("\n");
}
