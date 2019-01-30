#include <DataStructure.h>
#include <AVLTree.h>
#include <stdio.h>
#include <stdlib.h>

int Max(int a,int b)
{
    return a>b?a:b;
}
int GetBalance(Position A)
{
    return (A->left->Height-A->right->Height);
}
AVLTree FindMin(AVLTree T)
{
    if(!T){
        printf("树空\n");
        return NULL;
    }else if(!T->left)
        return T;
    else
        return FindMin(T->left);
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
        if(GetBalance(T)==2)
            if(X<T->left->Data)
                T=singleftRotation(T);
            else
                T=doubleLeftRightRotation(T);
    }
    else if(X>T->Data){
        T->right=Insert(T->right,X);
        if(GetBalance(T)==-2)
            if(X>T->right->Data)
                T=singrightRotation(T);
            else
                T=doubleRightLeftRotation(T):
    }
    T->Height=Max(GetHeight(T->left),GetHeight(T->right))+1;
    return T;
}

AVLTree Delete(AVLTree T,ElementType X)
{
    if(!T){
        printf("树为空\n");
        return NULL;
    }
    else if(X<T->Data){
        T-left=Delete(T->left,X);
        if(GetBalance(T)==-2)
            if(GetBalance(T->right)==-1)
                T=singrightRotation(T);
            else if(GetBalance(T->right)==1)
                T=doubleRightLeftRotation(T);
    }
    else if(X>T-<Data){
        T->right=Delete(T->right,X);
        if(GetBalance(T)==2)
            if(GetBalance(T->left)==1)
                T=singleftRotation(T);
            else if(GetBalance(T->left)==-1)
                T=doubleLeftRightRotation(T);
    }
    else{
        if(T->left&&T->right){
            T->Data=FindMin(T->right);
            T->right=Delete(T->right,T->Data);
        }else{
            Position pos=T;
            if(!T->left)
                T=T->right;
            else if(!T->right)
                T=T->left;
            free(pos);
        }
        T->Height=Max(GetHeight(T->left),GetHeight(T->right))+1;
        return T;
    }
}

