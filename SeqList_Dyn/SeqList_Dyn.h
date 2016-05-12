#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<memory.h>

typedef int DataType;

typedef struct SeqList{
	DataType* array;
	size_t size;
	size_t capacity;
}SeqList;
//输出
void Print(SeqList* pSeq)
{
	assert(pSeq);
	for (size_t i = 0; i < pSeq->size; i++)
	{
		printf("%d ", pSeq->array[i]);
	}
	printf("\n");
}
//检查容量,容量不足则增容
void Check(SeqList* pSeq)
{
	if (pSeq->size >= pSeq->capacity)
	{
		DataType* tmp;
		pSeq->capacity *= 2;
		tmp = (DataType*)malloc(sizeof(DataType)*pSeq->capacity);
		memcpy(tmp, pSeq->array, sizeof(DataType)*pSeq->size);
		free(pSeq->array);
		pSeq->array = tmp;		
	}
}
//初始化
void INIT(SeqList* pSeq)
{
	assert(pSeq);
	pSeq->capacity = 3;
	pSeq->array = (DataType*)malloc(sizeof(DataType)*pSeq->capacity);
	pSeq->size = 0;
}
//尾插
void PushBack(SeqList* pSeq, DataType x)
{
	assert(pSeq);
	Check(pSeq);
	pSeq->array[pSeq->size++] = x;
}
//删除所有的x
void RemoveAll(SeqList* pSeq, DataType x)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("SeqList is Empty\n");
	}
	size_t first = 0;
	size_t second = 0; 
	for (; second < pSeq->size; second++)
	{
		if (pSeq->array[second] != x)
		{
			pSeq->array[first] = pSeq->array[second];
			first++;
		}
	}
	pSeq->size = first;
}
//冒泡排序
void Sort(SeqList* pSeq)
{
	DataType tmp;
	DataType flag = 1;
	DataType time = pSeq->size - 1;
	assert(pSeq);
	while (flag)
	{
		flag = 0;
		for (int i = 0; i < time;i++)
		{
			if (pSeq->array[i]>pSeq->array[i + 1])
			{
				flag = 1;
				tmp = pSeq->array[i];
				pSeq->array[i] = pSeq->array[i + 1];
				pSeq->array[i + 1] = tmp;
			}
		}
		time--;
	}
}
//选择排序
void Select(SeqList* pSeq)
{
	assert(pSeq);
	size_t min;
	size_t max;
	size_t count;
	DataType tmp;
	for (size_t begin = 0, end = pSeq->size - 1; begin <= end; begin++, end--)
	{
		min = begin;
		max = end;
		for (count = begin; count <= max; count++)
		{
			if (pSeq->array[count] < pSeq->array[min])
			{
				min = count;
			}
			else if (pSeq->array[count] > pSeq->array[max])
			{
				max = count;
			}
		}
		if (min!=begin)
		{
			tmp = pSeq->array[begin];
			pSeq->array[begin] = pSeq->array[min];
			pSeq->array[min] = tmp;
		}
		if (max != end)
		{
			tmp = pSeq->array[end];
			pSeq->array[end] = pSeq->array[max];
			pSeq->array[max] = tmp;
		}
	}
}
//二分查找
size_t  Binary(SeqList* pSeq,DataType x)
{
	assert(pSeq);
	size_t left = 0;
	size_t right = pSeq->size - 1;
	size_t mid;
	while (left <= right)
	{
		mid =left + (right - left) / 2;
		if (pSeq->array[mid] < x)
		{
			left = mid + 1;
		}
		else if (pSeq->array[mid] > x)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
//用递归实现二分查找
size_t Binary_Recur(SeqList* pSeq, size_t left, size_t right, DataType x)
{
	assert(pSeq);
	if (left <= right)
	{
		size_t mid;
		mid = left + (right - left) / 2;
		if (pSeq->array[mid] < x)
		{
			return Binary_Recur(pSeq, mid + 1, right, x);
		}
		else if (pSeq->array[mid] > x)
		{
			return Binary_Recur(pSeq, left, mid - 1, x);
		}
		else
		{
			return mid;
		}
	}
	return -1;
}