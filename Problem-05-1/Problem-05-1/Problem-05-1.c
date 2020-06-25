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

	emp = WhoIsDuty(&list, "노무현", 2);
	printf("사번: %d\n", emp->empNum);
	printf("이름: %s\n", emp->name);
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