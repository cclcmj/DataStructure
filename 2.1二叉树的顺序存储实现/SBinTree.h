#ifndef SBINTREE_H_INCLUDED
#define SBINTREE_H_INCLUDED
#include <DataStructure.h>
#include <stdbool.h>//可用bool中true false
typedef struct STreeNode *SBinTree;
struct STreeNode
{
    ElementType *Data;
    int MaxSize;
    int pos;
};

SBinTree CreateSBinTree(int Maxsize);
bool IsEmpty(SBinTree BT);
void TraversalST(SBinTree BT);

int Findleft(int i,SBinTree BT);//寻找左子节点
int Findright(int i,SBinTree BT);//寻找右子节点
int Findfather(int i,SBinTree BT);//寻找父节点

#endif // SBINTREE_H_INCLUDED
