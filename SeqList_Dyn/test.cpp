#include<stdio.h>
#include<windows.h>
#include"SeqList_Dyn.h"

void Test()
{
	SeqList s;
	INIT(&s);             //��ʼ��
	
	PushBack(&s, 4);      //β��
	PushBack(&s, 1);
	PushBack(&s, 3);
	PushBack(&s, 2);
	PushBack(&s, 5);
	Print(&s);

	Sort(&s);             //ð������
	Print(&s);

	Select(&s);           //ѡ������
	Print(&s);

	printf("ret:%d\n", Binary(&s, 4));                //���ֲ���

	printf("ret:%d\n", Binary_Recur(&s, 0, 4, 2));    //�õݹ�ʵ�ֶ��ֲ���

	RemoveAll(&s, 1);     //ɾ�����е�x
	Print(&s);
}

int main()
{
	Test();
	system("pause");
	return 0;
}