#include <SBinTree.h>
#include <stdio.h>
#include <stdlib.h>

SBinTree CreateSBinTree(int Maxsize)
{
    SBinTree BT=(SBinTree)malloc(struct STreeNode);
    BT->Data=(ElementType*)malloc(Maxsize*sizeof(ElementType));
    BT->MaxSize=Maxsize;
    BT->pos=0;
    return BT;
}
int Findleft(int i,SBinTree BT)
{
    if(i<1||i>=BT->MaxSize){
        print("i输入不合法");
        return -1;
    }else if(2i<=BT->pos){
        print("i元素没有左子节点\n");
        return 2i;
    }else{
        return 2i;
    }
}
int Findright(int i,SBinTree BT)
{
    if(i<1||i>=BT->MaxSize){
        print("i输入不合法");
        return -1;
    }else if((2i+1)<=BT->pos){
        print("i元素没有右子节点\n");
        return (2i+1);
    }else{
        return (2i+1);
    }
}
int Findfather(int i,SBinTree BT)
{
    if(i<1||i>=BT->MaxSize){
        print("i输入不合法");
        return -1;
    }else if(i==1){
        print("i元素为根元素\n");
        return -1;
    }else{
        return (i/2);
    }
}

bool IsEmpty(SBinTree BT)
{
    return (BT->Data[0]==0);
}
