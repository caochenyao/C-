#include<stdio.h>
#include<windows.h>
#include"SeqList_Dyn.h"

void Test()
{
	SeqList s;
	//��ʼ��
	INIT(&s);             
	
	//β��
	PushBack(&s, 4);      
	PushBack(&s, 1);
	PushBack(&s, 3);
	PushBack(&s, 2);
	PushBack(&s, 5);
	Print(&s);

	//ð������
	Sort(&s);             
	Print(&s);

	//ѡ������
	Select(&s);           
	Print(&s);

	//���ֲ���
	printf("ret:%d\n", Binary(&s, 4));                

	//�õݹ�ʵ�ֶ��ֲ���
	printf("ret:%d\n", Binary_Recur(&s, 0, 4, 2));    

	//ɾ�����е�x
	RemoveAll(&s, 1);     
	Print(&s);
}

int main()
{
	Test();
	system("pause");
	return 0;
}