#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define InitSize 30

typedef int ElemType;
typedef struct
{
    ElemType *data;
    int last;
} SeqList;

// 初始化顺序表
void InitList(SeqList *L)
{
    L = (SeqList *)malloc(sizeof(SeqList)); //为顺序表分配空间
    L->last = -1;                           //空表长度为0
}

//插入元素
int InsList(SeqList *L, int i, ElemType e)
{
    int k = 0;
    if ((i < 1) || (i > L->last + 2))
    {
        printf("插入位置i不合法");
        return (ERROR);
    }
    if (L->last >= MAXSIZE - 1)
    {
        printf("表已满,无法插入");
        return (ERROR);
    }

    for (k = L->last; k >= i - 1; k--)
    {
        L->data[k + 1] = L->data[k]; //为插入移动元素
    }
    L->data[i - 1] = e; //将数组第i个元素的下标为i-1的元素赋值e
    L->last++;          //表长加1
    return (OK);
}

// 判断是否为空和显示结果
int ListEmpty(SeqList *L)
{
    if (L->last == -1)
    {
        return (OK);
    }
    else
    {
        return (ERROR);
    }
}

//打印表
int DispList(SeqList *L)
{
    if (ListEmpty(L))
    {
        return 0;
    }

    for (int i = 0; i < L->last; i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

//求线性表的长度
int ListLength(SeqList *L)
{
    return L->last;
}

//存取值
int GetElem(SeqList *L, int i, ElemType *e)
{
    //判断i值是否合理，若不合理返回0
    if (i < 1 || i > L->last + 1)
    {
        return 0;
    }
    *e = L->data[i - 1];
    return OK;
}

//查找元素位置
int Locate(SeqList *L, ElemType e)
{
    int i;
    for (i = 0; i <= L->last; i++)
    {
        if (L->data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}

//删除元素
int DelList(SeqList *L, int i, ElemType e)
{
    int j;
    if (i < 1 || i > L->last)
    {
        printf("删除位置不合法");
        return ERROR;
    }

    e = L->data[i - 1];
    for (j = i; j <= L->last; j++)
    {
        L->data[j - 1] = L->data[j];
    }
    L->last--;
    printf("删除的元素为:%d\n", e);
    return OK;
}

//释放空间
void DestroyList(SeqList *L)
{
    free(L);
}

int main()
{

    SeqList L;
    ElemType e;
    InitList(&L);
    printf("(1) i超过范围\n");
    InsList(&L, 2, 10);
    InsList(&L, 1, 20);
    //打印表
    DispList(&L);
    DelList(&L, 2, e);
}
