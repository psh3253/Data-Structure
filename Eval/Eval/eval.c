#include <stdio.h>
#include <stdlib.h>
int max_stack_size = 10;
int top = -1;
char* expr;
typedef enum
{
	lparen, rparen, plus, minus, times, divide, mod, eos, operand
} precedence;

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

int eval(char* expr)
{
	int* stack = (int*)malloc(sizeof(int) * max_stack_size);
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0;
	token = getToken(&symbol, &n);
	while (token != eos)
	{
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
		token = getToken(&symbol, &n);
	}
	return pop(&stack);
}

precedence getToken(char* symbol, int* n)
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

int main(void)
{
	expr = "62/3-42*+ ";
	printf("%d\n", eval(expr));
	return 0;
}