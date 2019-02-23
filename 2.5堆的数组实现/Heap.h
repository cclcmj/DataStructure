#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include <DataStructure.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct HNode *Heap;
typedef Heap MinHeap;
typedef Heap MaxHeap;

struct HNode
{
    ElementType *Data; //存储数据元素的数组
    int Size;          //堆的当前容量
    int Capacity;      //堆的最大容量
};

MaxHeap CreateHeap(int MaxSize);
bool IsFull(MaxHeap H);
bool IsEmpty(MaxHeap H);
void PercDown(MaxHeap H,int P);
//将H中以H->Data[P]为根的子堆调整为最大堆
void BuildHeap(MaxHeap H);
//调整H->Data[]中的元素，使满足最大堆的有序性
bool Insert(MaxHeap H,ElementType X);  //其中H->Data[0]已经定义为哨兵
ElementType DeleteMax(MaxHeap H);


#endif // HEAP_H_INCLUDED
