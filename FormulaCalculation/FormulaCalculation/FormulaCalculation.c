#include <stdio.h>
#include <stdlib.h>
int max_stack_size = 10;
int top = -1;
int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };
typedef enum
{
	lparen, rparen, plus, minus, times, divide, mod, eos, operand
} precedence;
int isFull();
int** stackFull(int**);
int isEmpty();
void push(int**, int);
int pop(int**);
int seek(int**);
void printToken(char*, precedence, int*);
int eval(char*);
void postfix(char*, char*);
precedence getToken(char*, char*, int*);
void postfixStackPrint(int**);
void evalStackPrint(int**);


int isFull()
{
	if (top >= max_stack_size - 1)
		return 1;
	else
		return 0;
}

int** stackFull(int** stack)
{
	max_stack_size *= 2;
	*stack = realloc(*stack, sizeof(int) * max_stack_size);
	return stack;
}

int isEmpty()
{
	if (top < 0)
		return 1;
	else
		return 0;
}

void push(int** stack, int item)
{
	if (isFull())
		stack = stackFull(stack);
	(*stack)[++top] = item;
}

int pop(int** stack)
{
	if (isEmpty())
		return -1;
	else
		return (*stack)[top--];
}

int seek(int** stack)
{
	if (isEmpty())
		return -1;
	else
		return (*stack)[top];
}

void printToken(char* new_expr, precedence symbol, int* k)
{
	switch (symbol)
	{
	case lparen:
		new_expr[(*k)++] = '(';
		break;
	case rparen:
		new_expr[(*k)++] = ')';
		break;
	case plus:
		new_expr[(*k)++] = '+';
		break;
	case minus:
		new_expr[(*k)++] = '-';
		break;
	case divide:
		new_expr[(*k)++] = '/';
		break;
	case times:
		new_expr[(*k)++] = '*';
		break;
	case mod:
		new_expr[(*k)++] = '%';
	}
}

int eval(char* expr)
{
	int* stack = (int*)malloc(sizeof(int) * max_stack_size);
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0, result;
	top = -1;
	token = getToken(expr, &symbol, &n);
	while (token != eos)
	{
		printf("Token : %c\n", symbol);
		evalStackPrint(&stack);
		printf("Top : %d\n\n", top);

		if (token == operand)
			push(&stack, symbol - '0');
		else
		{
			op2 = pop(&stack);
			op1 = pop(&stack);
			switch (token)
			{
			case plus:
				push(&stack, op1 + op2);
				break;
			case minus:
				push(&stack, op1 - op2);
				break;
			case times:
				push(&stack, op1 * op2);
				break;
			case divide:
				push(&stack, op1 / op2);
				break;
			case mod:
				push(&stack, op1 % op2);
			}
		}
		token = getToken(expr, &symbol, &n);
	}
	result = pop(&stack);
	free(stack);
	return result;
}

void postfix(char* expr, char* new_expr)
{
	int* stack = (int*)malloc(sizeof(int) * max_stack_size);
	char symbol;
	precedence token;
	int n = 0;
	int k = 0;
	push(&stack, eos);
	for (token = getToken(expr, &symbol, &n); token != eos; token = getToken(expr, &symbol, &n))
	{
		printf("Token : %c\n", symbol);
		postfixStackPrint(&stack);
		printf("Top : %d\n\n", top - 1);
		if (token == operand)
			new_expr[k++] = symbol;
		else if (token == rparen)
		{
			while (seek(&stack) != lparen)
				printToken(new_expr, pop(&stack), &k);
			pop(&stack);
		}
		else
		{
			while (isp[seek(&stack)] >= icp[token])
				printToken(new_expr, pop(&stack), &k);
			push(&stack, token);
		}
	}
	while ((token = pop(&stack)) != eos)
		printToken(new_expr, token, &k);
	new_expr[k++] = ' ';
	new_expr[k++] = '\0';
	free(stack);
}

precedence getToken(char* expr, char* symbol, int* n)
{
	*symbol = expr[(*n)++];
	switch (*symbol)
	{
	case '(':
		return lparen;
	case ')':
		return rparen;
	case '+':
		return plus;
	case '-':
		return minus;
	case '/':
		return divide;
	case '*':
		return times;
	case '%':
		return mod;
	case ' ':
		return eos;
	default:
		return operand;
	}
}

void postfixStackPrint(int** stack)
{
	printf("Stack : ");
	int i, token;
	for (i = 0; i < top + 1; i++)
	{
		token = (*stack)[i];
		switch (token)
		{
		case lparen:
			printf("( ");
			break;
		case rparen:
			printf(") ");
			break;
		case plus:
			printf("+ ");
			break;
		case minus:
			printf("- ");
			break;
		case divide:
			printf("/ ");
			break;
		case times:
			printf("* ");
			break;
		case mod:
			printf("% ");;
		}
	}
	printf("\n");
}

void evalStackPrint(int** stack)
{
	int i;
	printf("Stack : ");
	for (i = 0; i < top + 1; i++)
	{
		printf("%d ", (*stack)[i]);
	}
	printf("\n");
}

int main(void)
{
	char expr[] = "((((6/2)-3+(4*2))-5*3)) ";
	char* new_expr = (char*)malloc(sizeof(char) * 100);
	int result;
	postfix(expr, new_expr);
	printf("후위표기법 : %s\n\n", new_expr);
	result = eval(new_expr);
	printf("계산 값 : %d\n", result);
	return 0;
}