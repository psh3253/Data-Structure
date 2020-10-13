#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// �⺻ ���� ������
int max_stack_size = 10;
int top = -1;

// ������ ��� á���� Ȯ��
int isFull()
{
    if (top >= max_stack_size - 1)
        return 1;
    else
        return 0;
}

// ���� ���� �ø���
int** stackFull(int** stack)
{
    max_stack_size *= 2;
    *stack = realloc(*stack, sizeof(int) * max_stack_size);
    return stack;
}

// ������ ������� Ȯ��
int isEmpty()
{
    if (top < 0)
        return 1;
    else
        return 0;
}

// ���ÿ� ������ �ֱ�
void push(int** stack, int item)
{
    if (isFull())
        stack = stackFull(stack);
    (*stack)[++top] = item;
}

// ���ÿ��� ������ ������
int pop(int** stack)
{
    if (isEmpty())
        return -1;
    else
        return (*stack)[top--];
}

// ���� ��ȸ
int peek(int** stack)
{
    if (isEmpty())
        return -1;
    else
        return (*stack)[top];
}

// ������ �켱���� ��ȯ
int getOpPrec(char op)
{
    switch (op)
    {
    case '*':
    case '/':
        return 3;
    case '+':
    case '-':
        return 2;
    case '(':
        return 1;
    }
    return -1;
}

// ������ �켱���� ���
int whoPrecOp(char op1, char op2)
{
    int op1Prec = getOpPrec(op1);
    int op2Prec = getOpPrec(op2);

    if (op1Prec > op2Prec)
        return 1;
    else if (op1Prec < op2Prec)
        return -1;
    else
        return 0;
}

// ����ǥ����� ����ǥ������� ��ȯ
void infixToPostfix(char exp[], char new_exp[])
{
    // ���� �����Ҵ�
    int* stack = (int*)malloc(sizeof(int) * max_stack_size);
    int expLen = strlen(exp);
    int i, idx = 0, top = -1;
    char tok, popOp;

    for (i = 0; i < expLen; i++)
    {
        tok = exp[i];
        // �ǿ������� ���
        if (isdigit(tok))
        {
            new_exp[idx++] = tok;
        }
        // �������� ���
        else
        {
            switch (tok)
            {
            case '(':
                push(&stack, tok);
                break;
            case ')': // '('�� ���ö� ���� ���ÿ��� ������ ������
                while (1)
                {
                    popOp = pop(&stack);
                    if (popOp == '(')
                        break;
                    new_exp[idx++] = popOp;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                // ���� �ֻ�� ���� ������ �켱������ tok���� ���ų� ���� ���
                while (!isEmpty(&stack) && whoPrecOp(peek(&stack), tok) >= 0)
                    new_exp[idx++] = pop(&stack);

                push(&stack, tok);
                break;
            }
        }
    }
    // ������ �� ������ ���ÿ��� ������ ������
    while (!isEmpty(&stack))
        new_exp[idx++] = pop(&stack);

    // new_exp ���ڿ��� �� ǥ��
    new_exp[idx] = '\0';
}

int calculate(char new_exp[])
{
    // ���� �����Ҵ�
    int* stack = (int*)malloc(sizeof(int) * max_stack_size);
    int expLen = strlen(new_exp);
    int i, top = -1;
    char tok, op1, op2;

    for (i = 0; i < expLen; i++)
    {
        tok = new_exp[i];

        // �ǿ������� ���
        if (isdigit(tok))
        {
            // char �ڷ��� ���ڸ� int�� ���ڷ� ��ȯ�� ���ÿ� �ֱ�
            push(&stack, tok - '0');
        }
        // �������� ���
        else
        {
            // �� ��° �ǿ����ڿ� ù ��° �ǿ����ڸ� ������� ������
            op2 = pop(&stack);
            op1 = pop(&stack);

            switch (tok)
            {
            case '+':
                push(&stack, op1 + op2);
                break;
            case '-':
                push(&stack, op1 - op2);
                break;
            case '*':
                push(&stack, op1 * op2);
                break;
            case '/':
                push(&stack, op1 / op2);
                break;
            }
        }
    }
    return pop(&stack);
}

int main(void)
{
    // ����ǥ���
    char exp[] = "((((6/2)-3+(4*2))-5*3))";
    // ����ǥ���
    char new_exp[100];
    // ���
    int result;

    infixToPostfix(exp, new_exp);
    result = calculate(new_exp);
    printf("��� : %d\n", result);
    return 0;
}