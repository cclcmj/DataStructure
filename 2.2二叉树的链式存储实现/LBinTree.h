#ifndef LBINTREE_H_INCLUDED
#define LBINTREE_H_INCLUDED
#include <DataStructure.h>
#include <stdbool.h>

typedef struct LTreeNode *LBinTree;
typedef LBinTree Position;
struct LTreeNode
{
    ElementType Data;
    LBinTree left;
    LBinTree right;
};

LBinTree CreateLBinTree();
bool IsEmpty(LBinTree Bt);
void TraversalST(LBinTree BT);

#endif // LBINTREE_H_INCLUDED
