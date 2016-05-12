#include<stdio.h>
#include<windows.h>
#include"SList.h"

void Test()
{
	SList* List;
	//初始化
	INIT(List);

	//尾插
	PushBack(List, 1);
	PushBack(List, 2);
	PushBack(List, 3);
	PushBack(List, 4);
	PushBack(List, 5);
	Print(List);

	//尾删
	PopBack(List);
	Print(List);

	//头插
	PushFront(List, 0);
	Print(List);

	//头删
	PopFront(List);
	Print(List);

	//删除指定数据
	Remove(List, 2);
	Print(List);

	//查找指定数据
	SList* pos = Find(List, 4);
	//插入数据
	InSert(pos, 5);
	Print(List);

	SList* pos_s = Find(List, 5);
	//删除数据
	Erase(List, pos_s);
	Print(List);

	//链表逆置
	Reverse(List);
	Print(List);
}

int main()
{
	Test();
	system("pause");
	return 0;
}