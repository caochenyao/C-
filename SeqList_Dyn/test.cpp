#include<stdio.h>
#include<windows.h>
#include"SeqList_Dyn.h"

void Test()
{
	SeqList s;
	INIT(&s);             //初始化
	
	PushBack(&s, 4);      //尾插
	PushBack(&s, 1);
	PushBack(&s, 3);
	PushBack(&s, 2);
	PushBack(&s, 5);
	Print(&s);

	Sort(&s);             //冒泡排序
	Print(&s);

	Select(&s);           //选择排序
	Print(&s);

	printf("ret:%d\n", Binary(&s, 4));                //二分查找

	printf("ret:%d\n", Binary_Recur(&s, 0, 4, 2));    //用递归实现二分查找

	RemoveAll(&s, 1);     //删除所有的x
	Print(&s);
}

int main()
{
	Test();
	system("pause");
	return 0;
}