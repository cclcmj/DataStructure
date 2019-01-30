#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED
#include <DataStructure.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct AVLTNode *AVLTree;
typedef AVLTree Position;
struct AVLTNode
{
    ElementType Data;
    AVLTree right;
    AVLTree left;
    int Height;
};

int Max(int a,int b);
int GetBalance(Position A);

AVLTree singleftRotation(Position A);
AVLTree singrightRotation(Position A);
AVLTree doubleLeftRightRotation(Position A);
AVLTree doubleRightLeftRotation(Position A);

AVLTree Insert(AVLTree T,ElementType X);
AVLTree Delete(AVLTree T,ElementType X);
AVLTree FindMin(AVLTree T);


#endif // AVLTREE_H_INCLUDED
