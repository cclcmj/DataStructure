#include <stdio.h>
#include <stdlib.h>
#include <DataStructure.h>
#include <LBinTree.h>

LBinTree CreateLBinTree()
{
    LBinTree BT=(LBinTree)malloc(sizeof(struct LTreeNode));
    BT->left=BT->right=NULL;
    return BT;
}
bool IsEmpty(LBinTree BT)
{
    return (BT->left==NULL);
}


void AddNode(Position last,enum LorR lr,ElementType item)
{
    LBinTree n=(LBinTree)malloc(sizeof(struct LTreeNode));
    n->Data=item;
    n->left=NULL;
    n->right=NULL;
    if(last!=NULL&&lr==right&&last->right==NULL)last->right=n;
    else if(last!=NULL&&lr==left&&last->left==NULL)last->left=n;
    else printf("出错\n");
    return;
}
ElementType DeleteNode(Position last,enum LorR lr)
{
    LBinTree n;int i;
    if(last==NULL){
        printf("删除的元素的父节点不存在\n");
        return -1;
    }else if(lr==right&&last->right!=NULL){
        n=last->right;
        last->right=NULL;
        i=n->Data;
        free(n);
        return i;
    }else if(lr==left&&last->left!=NULL){
        n=last->left;
        last->left=NULL;
        i=n->Data;
        free(n);
        return i;
    }else {
        printf("删除的节点不存在\n");
        return -1;
    }
}
