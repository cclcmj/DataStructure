#ifndef SETTYPE_H_INCLUDED
#define SETTYPE_H_INCLUDED
#include <DataStructure.h>

#define MAXN 1000 //集合的最大元素

typedef int SetName;//默认用根节点下标作为集合名称
typedef struct SetType SetT;
struct SetType
{
    ElementType Data;
    int parent;
};

void Union(SetT S[],SetName Root1,SetName Root2);
int Find(SetT S[],ElementType X);



#endif // SETTYPE_H_INCLUDED
