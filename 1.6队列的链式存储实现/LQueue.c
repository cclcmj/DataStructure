#include <stdio.h>
#include <stdlib.h>
#include <DataStructure.h>
#include <LQueue.h>

LQueue CreateLQ()
{
    LQueue Q=(LQueue)malloc(2*sizeof(struct Node));
    Q->fron=(struct Node*)malloc(sizeof(struct Node));
    Q->rear=(struct Node*)malloc(sizeof(struct Node));
    Q->fron=Q->rear=NULL;
}
int IsEmptyLQ(LQueue Q)
{
    return (Q->fron==NULL);
}
void AddLQ(LQueue Q,ElementType item)
{
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    n->Data=item;
    if(IsEmptyLQ(Q)){
        Q->fron=Q->rear=n;
        n->Next=NULL;
        return;
    }else{
        n->Next=Q->rear->Next;
        Q->rear->Next=n;
        Q->rear=n;
        return;
    }
}
ElementType DeleteLQ(LQueue Q)
{
    int i;
    struct Node *n;
    if(IsEmptyLQ(Q)){
        printf("队列空\n");
        return -1;
    }else if(Q->fron==Q->rear){
        n=Q->fron;
        i=n->Data;
        free(n);
        Q->fron=Q->rear=NULL;
        return i;
    }else{
        i=Q->fron->Data;
        n=Q->fron;
        Q->fron=n->Next;
        i=n->Data;
        free(n);
        return i;
    }
}

void printLQ(LQueue Q)
{
    struct Node *n=Q->fron;
    while(n!=NULL)
    {
        printf("%d,",n->Data);
        n=n->Next;
    }
    printf("\n");
    return;
}
