#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

Employee* WhoIsDuty(List* plist, char* name, int day);
void ShowEmployee(Employee* emp);

int main(void)
{
	List list;
	ListInit(&list);
	Employee* emp;

	emp = (Employee*)malloc(sizeof(Employee));
	emp->empNum = 1;
	strcpy(emp->name, "노무현");
	LInsert(&list, emp);

	emp = (Employee*)malloc(sizeof(Employee));
	emp->empNum = 2;
	strcpy(emp->name, "이명박");
	LInsert(&list, emp);

	emp = (Employee*)malloc(sizeof(Employee));
	emp->empNum = 3;
	strcpy(emp->name, "박근혜");
	LInsert(&list, emp);

	emp = (Employee*)malloc(sizeof(Employee));
	emp->empNum = 4;
	strcpy(emp->name, "문재인");
	LInsert(&list, emp);

	emp = WhoIsDuty(&list, "박근혜", 5);
	ShowEmployee(emp);
}

Employee* WhoIsDuty(List* plist, char* name, int day)
{
	Employee* data;
	int i;

	LFirst(plist, &data);
	if (strcmp(data->name, name) == 0)
	{
		for (i = 0; i < day; i++)
		{
			LNext(plist, &data);
		}
		return data;
	}
	for (i = 0; i < LCount(plist) - 1; i++)
	{
		LNext(plist, &data);
		if (strcmp(data->name, name) == 0)
		{
			for (i = 0; i < day; i++)
			{
				LNext(plist, &data);
			}
			return data;
		}
	}
	return NULL;
}

void ShowEmployee(Employee* emp)
{
	if (emp == NULL)
	{
		printf("해당 사원이 존재하지 않습니다.\n");
		return;
	}
	printf("사번: %d\n", emp->empNum);
	printf("이름: %s\n", emp->name);
}