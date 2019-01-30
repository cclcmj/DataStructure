#include <DataStructure.h>
#include <AVLTree.h>
#include <stdio.h>
#include <stdlib.h>

int Max(int a,int b)
{
    return a>b?a:b;
}
int GetHeight(Position A)
{
    return A->Height;
}
AVLTree singleftRotation(Position A)
{
    Position B=A->left;
    A->left=B->right;
    B->right=A;
    A->Height=MAX(GetHeight(A->right),GetHeight(A->left))+1;
    B->Height=MAX(GetHeight(B->left),GetHeight(A))+1;
    return B;
}
AVLTree singrightRotation(Position A)
{
    Position B=A->right;
    A->right=B->left;
    B->left=A;
    A->Height=MAX(GetHeight(A->right),GetHeight(A->left))+1;
    B->Height=Max(GetHeight(B->right),GetHeight((B->left))+1;
    return B;
}
AVLTree doubleLeftRightRotation(Position A)
{
    A->left=singrightRotation(A->left);
    return singleftRotation(A);
}
AVLTree doubleRightLeftRotation(Position A)
{
    A->right=singleftRotation(Position A->right);
    return singrightRotation(A);
}
AVLTree Insert(AVLTree T,ElementType X)
{
    if(!T){
        T=(AVLTree)malloc(sizeof(struct AVLTNode));
        T->Data=X;
        T->right=T->left=NULL;
        T->Height=0;
    }
    else if(X<T->Data){
        T->left=Insert(T->left,X);
        if(GetHeight(T->left)-GetHeight(T->right)==2)
            if(X<T->left->Data)
                T=singleftRotation(T);
            else
                T=doubleLeftRightRotation(T);
    }
    else if(X>T->Data){
        T->right=Insert(T->right,X);
        if(GetHeight(T->right)-GetHeight(T->left)==2)
            if(X>T->right->Data)
                T=singrightRotation(T);
            else
                T=doubleRightLeftRotation(T):
    }
    T->Height=Max(GetHeight(T->left),GetHeight(T->right))+1;
    return T;
}
/*
AVLTree Delete(AVLTree T,ElementType X)
{
    if(!T)
        printf("要删除的元素不存在\n");
    else if(X<T->Data){
        T->left=Delete(T->left,X);
        if(X<T->left->Data)
            T=singleftRotation(T);
        else

    }
}
*/
