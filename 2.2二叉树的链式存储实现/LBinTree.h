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

//last指向的节点只能是叶节点
enum LorR {right,left};
void AddNode(Position last,LorR lr,ElementType item);
void DeleteNode(Position last,LorR lr,ElementType item);

#endif // LBINTREE_H_INCLUDED
