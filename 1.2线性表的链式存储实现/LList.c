#include <stdio.h>
#include <stdlib.h>
#include <DataStructure.h>
#include <LList.h>

LList MakeEmpty()
{
    LList L=(LList)malloc(sizeof(struct LLNod));
    L->Next=NULL;
    return L;
}
int Length(LList L)
{
    int i;LList p=L;
    for (i=-1;p!=NULL;i++)
        p=p->Next;
    return i;
}
LList FindKth(int K,LList L)
{
    if(K<1||K>Length(L)){
        printf("第%d个元素不存在",K);
        return NULL;
    }
    LList p=L;
    for (int i=0;i!=K;i++)
        p=p->Next;
    return p;
}
LList Find(ElementType X,LList L)
{
    if(L->Next==NULL){
        printf("表空");
        return NULL;
    }
    LList p=L;
    while(p!=NULL&&p->Data!=X)
        p=p->Next;
    if(p->Data!=X){
        printf("元素不存在");
        return NULL;
    }else{
        return p;
    }
}
LList Insert(ElementType X,int i,LList L)
{
    LList last;
    if(i<1||i>Length(L)+1){
        printf("第%d个元素不存在",i);
        return NULL;
    }else if(i==1){
        last = L;
    }else{
        last =FindKth(i-1,L);
    }
    LList n=(LList)malloc(sizeof(struct LLNod));

    if(n==L)printf("相等\n");

    n->Next=last->Next;
    last->Next=n;
    n->Data=X;
    return L;
}
LList Delete(int i,LList L)
{
    LList last,pos;
    if(i<1||i>Length(L)+1){
        printf("第%d个元素不存在/n",i);
        return NULL;
    }else if(i==1){
        last =L;
    }else{
        last =FindKth(i-1,L);
    }
    pos=last->Next;
    last->Next=pos->Next;
    free(pos);
    return L;
}

void printLList(LList L)
{
    LList pos=L->Next;int count=0;//有头节点
    while(pos!=NULL){
        count++;
        printf("第%d个元素为%d",count,pos->Data);
        pos=pos->Next;
    }
    printf("\n");
    return;
}
