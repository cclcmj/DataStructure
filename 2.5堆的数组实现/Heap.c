#include <Heap.h>

MaxHeap CreateHeap(int MaxSize)
{
    MaxHeap H=(Heap)malloc(sizeof(struct HNode));
    H->Data=(ElementType *)malloc((MaxSize+1)*sizeof(ElementType));
    H->Size=0;
    H->Capacity=MaxSize;
    H->Data[0]=1000;//哨兵，元素值最大不超过此值
    return H;
}
bool IsFull(MaxHeap H)
{
    return (H->Size == H->Capacity);
}
bool IsEmpty(MaxHeap H)
{
    return (H->Size==0);
}
void PercDown(MaxHeap H,int P)
{
    int parent,child;
    ElementType X;

    X=H->Data[P];
    for(parent=P;parent*2<=H->Size;parent=child){
        child=parent*2;
        if((child!=H->Size)&&(H->Data[child]<H->Data[child+1]))
            child++;
        if(X>=H->Data[child])break;
        else
            H->Data[parent]=H->Data[child];//下滤，从上往下
    }
    H->Data[parent]=X;
    return;
}
void BuildHeap(MaxHeap H)
{
    for(int i=H->Size/2;i>0;i--){
        PercDown(H,i);
    }
    return;
}
bool Insert(MaxHeap H,ElementType X)
{
    int i;
    if(IsFull(H)){
        printf("最大堆已满\n");
        return false;
    }else{
        i=++H->Size;//X插入数组中最后一个位置；
        for( ;X>H->Data[i/2];i/=2)
            H->Data[i]=H->Data[i/2];//上滤，自下往上
        H->Data[i]=X;
    }
    return true;
}
ElementType DeleteMax(MaxHeap H)
{
    int parent,child;
    ElementType MaxItem,X;

    if(IsEmpty(H)){
        printf("最大堆已空\n");
        return -1;
    }

    MaxItem=H->Data[1];
    X=H->Data[H->Size--];
    for(parent=1;parent*2<=H->Size;parent=child){
        child=parent*2;
        if((child!=H->Size)&&(H->Data[child]<H->Data[child+1]))
            child++;
        if(X>=H->Data[child])
            break;
        else{
            H->Data[parent]=H->Data[child];
        }
    }
    H->Data[parent]=X;

    return MaxItem;
}
