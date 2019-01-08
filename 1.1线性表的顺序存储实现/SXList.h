#ifndef SXLIST_H_INCLUDED
#define SXLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <DataStructure.h>
#define MAXSIZE 10
/*
顺序线性表的具体实现
*/
typedef struct SXLNode *SXList;
struct SXLNode
{
    ElementType Data[MAXSIZE];
    int Last;
};

SXList MakeEmpty();
ElementType FindKth(int K,SXList L);
int Find(ElementType X,SXList L);//没找到返回-1
void Insert(ElementType X,int i,SXList L);//判断位置合法，表满
void Delete(int i,SXList L);//判断元素存在
int Length(SXList L);
//输出全部顺序表元素
void PrintSXList(SXList L);

#endif // SXLIST_H_INCLUDED
