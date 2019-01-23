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
void PreOrderTraversalST(LBinTree BT);//先序非递归遍历
void InOrderTraversalST(LBinTree BT);//中序非递归遍历
void PosOrderTraversalST(LBinTree BT);//后序非递归遍历


//last指向的节点只能是叶节点
enum LorR {right,left};
void AddNode(Position last,enum LorR lr,ElementType item);
ElementType DeleteNode(Position last,enum LorR lr);


//遍历用到的堆栈
typedef struct SNode *Stack;
struct SNode
{
    Position Data;
    Stack Next;
};
Stack CreateStack();
bool IsEmptyS(Stack S);
void Push(Position pos,Stack S);
Position Pop(Stack S);

#endif // LBINTREE_H_INCLUDED
