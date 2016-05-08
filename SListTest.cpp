#include<stdio.h>
#include<windows.h>
#include"SList.h"

void Test()
{
	SList* List;
	INIT(List);
	PushBack(List, 1);
	PushBack(List, 2);
	PushBack(List, 3);
	PushBack(List, 4);
	PushBack(List, 5);
	Print(List);

	PopBack(List);
	Print(List);

	PushFront(List, 0);
	Print(List);

	PopFront(List);
	Print(List);

	Remove(List, 2);
	Print(List);

	SList* pos = Find(List, 4);
	InSert(pos, 5);
	Print(List);

	SList* pos_s = Find(List, 5);
	Erase(List, pos_s);
	Print(List);

	Reverse(List);
	Print(List);
}

int main()
{
	Test();
	system("pause");
	return 0;
}