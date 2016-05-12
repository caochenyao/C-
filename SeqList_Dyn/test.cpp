#include<stdio.h>
#include<windows.h>
#include"SeqList_Dyn.h"

void Test()
{
	SeqList s;
	//初始化
	INIT(&s);             
	
	//尾插
	PushBack(&s, 4);      
	PushBack(&s, 1);
	PushBack(&s, 3);
	PushBack(&s, 2);
	PushBack(&s, 5);
	Print(&s);

	//冒泡排序
	Sort(&s);             
	Print(&s);

	//选择排序
	Select(&s);           
	Print(&s);

	//二分查找
	printf("ret:%d\n", Binary(&s, 4));                

	//用递归实现二分查找
	printf("ret:%d\n", Binary_Recur(&s, 0, 4, 2));    

	//删除所有的x
	RemoveAll(&s, 1);     
	Print(&s);
}

int main()
{
	Test();
	system("pause");
	return 0;
}