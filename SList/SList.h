#include<stdio.h>
#include<malloc.h>

typedef int DataType;

typedef struct SList
{
	DataType _data;
	struct SList* _next;
}SList;
//初始化
void INIT(SList*& pHead)
{
	pHead = NULL;
}
//赋值
SList* BuyNode(DataType x)
{
	SList* List;
	List = (SList*)malloc(sizeof(SList));
	List->_data = x;
	List->_next = NULL;
	return List;
}
//输出
void Print(SList*& pHead)
{
	SList* tail = pHead;
	while (tail != NULL)
	{
		printf("%d->", tail->_data);
		tail = tail->_next;
	}
	printf("NULL\n");
}
//尾插
void PushBack(SList*& pHead,DataType x)
{
	if (pHead == NULL)
	{
		pHead = BuyNode(x);
	}
	else
	{
		SList *tail = pHead;
		while (tail->_next != NULL)
		{
			tail = tail->_next;
		}
		tail->_next = BuyNode(x);
	}
}
//尾删
void PopBack(SList*& pHead)
{
	if (pHead == NULL)
	{
		printf("SList is empty\n");
		return;
	}
	else if (pHead->_next == NULL)
	{
		free(pHead);
		pHead = NULL;
	}
	else
	{
		SList* tail = pHead,*pretail = NULL;
		while (tail->_next != NULL)
		{
			pretail = tail;
			tail = tail->_next;
		}
		pretail->_next = NULL;
		free(tail);
		tail = NULL;
	}
}
//头插
void PushFront(SList*& pHead, DataType x)
{
	if (pHead == NULL)
	{
		pHead = BuyNode(x);
	}
	else
	{
		SList* tail = pHead,*pretail = NULL;
		pretail = BuyNode(x);
		pretail->_next = tail;
		pHead = pretail;
	}
}
//头删
void PopFront(SList*& pHead)
{
	if (pHead == NULL)
	{
		printf("SList is empty\n");
		return;
	}
	else
	{
		SList* pretail = NULL, *tail = pHead;
		pretail = tail;
		tail = tail->_next;
		pHead = tail;
		free(pretail);
		pretail = NULL;
	}
}
//查找指定数据
SList* Find(SList* pHead, DataType x)
{
	SList* tail = pHead;
	while (tail->_data != x)
	{
		tail = tail->_next;
		if (tail == NULL)
		{
			return NULL;
		}
	}
	return tail;
}
//插入数据
void InSert(SList* pos, DataType x)
{
	SList* tail = pos, *d_tail = BuyNode(x);
	d_tail->_next = tail->_next;
	tail->_next = d_tail;
}
//删除数据
void Erase(SList*& pHead, SList* pos)
{
	SList* tail = pHead,*pretail = NULL;
	while (tail != pos)
	{
		pretail = tail;
		tail = tail->_next;
	}
	pretail->_next = tail->_next;
	free(tail);
	tail = NULL;
}
//删除指定的数据
void Remove(SList*& pHead, DataType x)
{
	if (pHead == NULL)
	{
		printf("SList is empty\n");
		return;
	}
	else
	{
		SList* tail = pHead, *pretail = NULL;
		pretail = tail;
		while (tail->_data != x)
		{
			pretail = tail;
			tail = tail->_next;
			//如果指定的数据不存在
			if (tail == NULL)                 
			{
				printf("There is no data\n");
				return;
			}
		}
		pretail->_next = tail->_next;
		free(tail);
		tail = NULL;
	}
}
//链表逆序
void Reverse(SList*& pHead)
{
	if (pHead == NULL)
	{
		printf("SList is empty\n");
		return;
	}
	else if (pHead->_next == NULL)
	{
		return;
	}
	else
	{
		SList* nHead = pHead, *npHead = NULL, *tmp= NULL;
		while (nHead != NULL)
		{	
			tmp = nHead->_next;
			nHead->_next = NULL;
			nHead->_next = npHead;
			npHead = nHead;
			nHead = tmp;
		}
		pHead = npHead;
	}
}