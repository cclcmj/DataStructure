#ifndef SBINTREE_H_INCLUDED
#define SBINTREE_H_INCLUDED
#include <DataStructure.h>
#include <stdbool.h>//可用bool中true false
typedef struct STreeNode *SBinTree;
struct STreeNode
{
    ElementType *Data;
    int MaxSize;
};

SBinTree CreateSBinTree();
bool IsEmpty(SBinTree BT);
void TraversalST(SBinTree BT);

#endif // SBINTREE_H_INCLUDED
