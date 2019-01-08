#include <stdio.h>
#include <stdlib.h>
#include <DataStructure.h>
#include <SXList.h>

SXList MakeEmpty()
{
    SXList L = (SXList)malloc(sizeof(struct SXLNode));
    L->Last=-1;
    return L;
}
ElementType FindKth(int K,SXList L)
{
    return L->Data[K-1];
}
int Find(ElementType X,SXList L)
{
    int i=0;
    while(i<=L->Last-1&&L->Data[i]!=X)
        i++;
    if(i>L->Last)i=-1;
    return i+1;
}
void Insert(ElementType X,int i,SXList L)
{
    if(L->Last==MAXSIZE-1){
        printf("表满");
        return;
    }
    if(i<1||i>L->Last+2){
        printf("元素不合法");
        return;
    }
    int j;
    for(j=L->Last;j>=i-1;j--)
        L->Data[j+1]=L->Data[j];
    L->Data[i-1]=X;
    L->Last++;
    return;
}
void Delete(int i,SXList L)
{
    if(i<1||i>L->Last+1)
    {
        printf("位置不合法");
        return;
    }
    int j;
    for(j=i-1;j<L->Last;j++)
        L->Data[j]=L->Data[j+1];
    L->Last--;
}
int Length(SXList L)
{
    return L->Last+1;
}
//输出顺序表全部元素
void PrintSXList(SXList L)
{
    for(int i=0;i<=L->Last;i++)
        printf("第%d个元素为%d,",i+1,L->Data[i]);
    printf("\n");
    return;
}
