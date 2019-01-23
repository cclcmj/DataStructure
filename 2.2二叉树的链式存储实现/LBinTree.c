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
void PreOrderTraversalST(LBinTree T)
{
    Stack S=CreateStack();
    LBinTree pos=T->left;
    while(pos||!IsEmptyS(S)){
        while(pos){
            printf("%d,",pos->Data);
            Push(pos,S);
            pos=pos->left;
        }
        if(!IsEmptyS(S)){
            pos=Pop(S);
            pos=pos->right;
        }
    }
    free(S);
    printf("\n");
    return;
}
void InOrderTraversalST(LBinTree BT)
{
    Stack S=CreateStack();
    LBinTree pos=BT->left;
    while(pos||!IsEmptyS(S)){
        while(pos){
            Push(pos,S);
            pos=pos->left;
        }
        if(!IsEmptyS(S)){
            pos=Pop(S);
            printf("%d,",pos->Data);
            pos=pos->right;
        }
    }
    free(S);
    printf("\n");
    return;
}
void PosOrderTraversalST(LBinTree BT)
{
    Stack S =CreateStack();
    LBinTree pos=BT->left;LBinTree LastPos;
    if(IsEmpty(BT)){
        printf("树空");
        return;
    }
    Push(pos,S);
    while(!IsEmptyS(S)){
        pos=NULL;
        pos=Pop(S);
        Push(pos,S);
        if((pos->left==NULL&&pos->right==NULL)||(LastPos!=NULL&&(LastPos==pos->right))||(LastPos!=NULL&&(pos->right==NULL&&LastPos==pos->left)))
        {
            printf("%d,",pos->Data);
            LastPos=pos;
            pos=Pop(S);
        }else if(pos->left!=NULL&&LastPos!=pos->left){
            Push(pos->left,S);
        }else if(pos->right!=NULL){
            Push(pos->right,S);
        }
    }
    free(S);
    printf("\n");
    return;
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

Stack CreateStack()
{
    Stack n=(Stack)malloc(sizeof(struct SNode));
    n->Data=NULL;
    n->Next=NULL;
    return n;
}
bool IsEmptyS(Stack S){
    if(S->Next==NULL)
        return true;
    else return false;
}
void Push(Position Tpos,Stack S)
{
    Stack n=(Stack)malloc(sizeof(struct SNode));
    n->Next=S->Next;
    S->Next=n;
    n->Data=Tpos;
}
Position Pop(Stack S)
{
    if(IsEmptyS(S)){
        printf("栈空");
        return NULL;
    }
    Stack Spos=S->Next;
    Position Tpos=Spos->Data;
    S->Next=Spos->Next;
    free(Spos);
    return Tpos;
}
