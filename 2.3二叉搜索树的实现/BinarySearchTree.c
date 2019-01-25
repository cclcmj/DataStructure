#include <DataStructure.h>
#include <BinarySearchTree.h>
#include <stdio.h>

BSTree Insert(ElementType X,BSTree BST)
{
    if(!BST){
        BST=(BSTree)malloc(sizeof(struct BSTreeNode));
        BST->Data=X;
        BST->left=BST->right=NULL;
    }else{
        if(X>BST->Data)
            Insert(X,BST->right);
        else if(X<BST->Data);
            Insert(X,BST->left);
    }
    return BST;
}
BSTree Delete(ElementType X,BSTree BST)
{
    if(!BST){
        printf("要找的元素不存在\n");
        return BST;
    }else if(X>BST->Data)
        Delete(X,BST->right);
    else if(X<BST->Data)
        Delete(X,BST->left);
    else{
        if(BST->left&&BST->right){
            BST->Data=FindMin(BST->right)->Data;
            BST->right=Delete(BST->Data,BST->right);
        }else{
            BSTree tmp=BST;
            if(!BST->left)
                BST=BST->right;
            if(!BST->right)
                BST=BST->left;
            free(tmp);
        }
    return BST;
    }
}
Position Find(ElementType X,BSTree BST)
{
    if(!BST){
        printf("查找元素不存在\n");
        return NULL;
    }else if(X>BST->Data)
        return Find(X,BST->right);
    else if(X<BST->Data)
        return Find(X,BST->left);
    else
        return BST;
}
Position FindMin(BSTree BST)
{
    if(!BST){
        printf(" 空二叉树\n");
        return NULL;
    }else if(!BST->left)
        return BST;
    else
        return FindMin(BST->left);
}
Position FindMax(BSTree BST)
{
    if(!BST){
        printf("空二叉树\n");
        return NULL;
    }else if(!BST->right)
        return BST;
    else
        return FindMax(BST->right);
}
