#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

int main(void)
{
	List list;
	ListInit(&list);
	Employee* emp;
	
	emp = (Employee*)malloc(sizeof(Employee));
	emp->empNum = 1;
	strcpy(emp->name, "�빫��");
	LInsert(&list, emp);

	emp = (Employee*)malloc(sizeof(Employee));
	emp->empNum = 2;
	strcpy(emp->name, "�̸��");
	LInsert(&list, emp);

	emp = (Employee*)malloc(sizeof(Employee));
	emp->empNum = 3;
	strcpy(emp->name, "�ڱ���");
	LInsert(&list, emp);

	emp = (Employee*)malloc(sizeof(Employee));
	emp->empNum = 4;
	strcpy(emp->name, "������");
	LInsert(&list, emp);

	emp = WhoIsDuty(&list, "�빫��", 2);
	printf("���: %d\n", emp->empNum);
	printf("�̸�: %s\n", emp->name);
}

Employee* WhoIsDuty(List* list, char* name, int day)
{
	Employee *data;
	int i;

	if (LFirst(list, &data))
	{
		if (strcmp(data->name, name) == 0)
		{
			for (i = 0; i < day; i++)
			{
				LNext(list, &data);
			}
			return data;
		}
		while (LNext(list, &data))
		{
			if (strcmp(data->name, name) == 0)
			{
				for (i = 0; i < day; i++)
				{
					LNext(list, &data);
				}
				return data;
			}
		}
	}
}