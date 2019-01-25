#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED
#include <DataStructure.h>
#include <stdbool.h>

typedef struct BSTreeNode *BSTree;
typedef BSTree Position;
struct BSTreeNode
{
    ElementType Data;
    BSTree left;
    BSTree right;
};
//测试
Position Find(ElementType X,BSTree BST);
Position FindMin(BSTree BST);
Position FindMax(BSTree BST);
BSTree Insert(ElementType X,BSTree BST);
BSTree Delete(ElementType X,BSTree BST);

#endif // BINARYSEARCHTREE_H_INCLUDED
