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
    return (BT==NULL);
}


void AddNode(Position last,LorR lr,ElementType item)
{
    LBinTree n=(LBinTree)malloc(sizeof(struct LTreeNode));
    n->Data=item;
    if(last!=NULL&&lr==right&&last->right==NULL)last->right=n;
    else if(last!=NULL&&lr==left&&last->left==NULL)last->left=n;
    else printf("出错\n");
    return;
}
void DeleteNode(Position last,LorR lr,ElementType item)
{
    LBinTree n;
    if(last==NULL){
        printf("删除的元素的父节点不存在\n");
        return;
    }else if(lr==right&&last->right!=NULL){
        n=last->right;
        last->right=NULL;
        free(n);
        return;
    }else if(lr==left&&last->left!NULL){
        n=last->left;
        last->left=NULL;
        free(n);
        return;
    }else {
        printf("删除的节点不存在\n");
        return;
    }
}
