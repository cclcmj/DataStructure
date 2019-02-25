#include <SetType.h>
#include <stdio.h>
#include <stdlib.h>

int Find(SetT S[],ElementType X)
{
    int i;
    for(i=0;i<=MAXN&&S[i].Data!=X;i++);
    if(i>=MAXN){
        printf("S中没有值为%d的元素",X);
        return -1;
    }
    for(;S[i].parent>=0;i=(S[i].parent));
    return i;

}

void Union(SetT S[],SetName Root1,SetName Root2)
{
    int a,b;
    a=Find(S,Root1);
    b=Find(S,Root2);
    if(Root1>Root2)
        S[b].parent=a;
    else if(Root1<Root2)
        S[a].parent=b;
    return ;
}
