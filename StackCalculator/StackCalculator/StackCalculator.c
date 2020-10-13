#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 기본 스택 사이즈
int max_stack_size = 10;
int top = -1;

// 스택이 모두 찼는지 확인
int isFull()
{
    if (top >= max_stack_size - 1)
        return 1;
    else
        return 0;
}

// 스택 공간 늘리기
int** stackFull(int** stack)
{
    max_stack_size *= 2;
    *stack = realloc(*stack, sizeof(int) * max_stack_size);
    return stack;
}

// 스택이 비었는지 확인
int isEmpty()
{
    if (top < 0)
        return 1;
    else
        return 0;
}

// 스택에 데이터 넣기
void push(int** stack, int item)
{
    if (isFull())
        stack = stackFull(stack);
    (*stack)[++top] = item;
}

// 스택에서 데이터 꺼내기
int pop(int** stack)
{
    if (isEmpty())
        return -1;
    else
        return (*stack)[top--];
}

// 스택 조회
int peek(int** stack)
{
    if (isEmpty())
        return -1;
    else
        return (*stack)[top];
}

// 연산자 우선순위 반환
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

// 연산자 우선순위 계산
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

// 중위표기식을 후위표기식으로 변환
void infixToPostfix(char exp[], char new_exp[])
{
    // 스택 동적할당
    int* stack = (int*)malloc(sizeof(int) * max_stack_size);
    int expLen = strlen(exp);
    int i, idx = 0, top = -1;
    char tok, popOp;

    for (i = 0; i < expLen; i++)
    {
        tok = exp[i];
        // 피연산자인 경우
        if (isdigit(tok))
        {
            new_exp[idx++] = tok;
        }
        // 연산자인 경우
        else
        {
            switch (tok)
            {
            case '(':
                push(&stack, tok);
                break;
            case ')': // '('가 나올때 까지 스택에서 데이터 꺼내기
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
                // 스택 최상단 값의 연산자 우선순위가 tok보다 높거나 같은 경우
                while (!isEmpty(&stack) && whoPrecOp(peek(&stack), tok) >= 0)
                    new_exp[idx++] = pop(&stack);

                push(&stack, tok);
                break;
            }
        }
    }
    // 스택이 빌 때까지 스택에서 데이터 꺼내기
    while (!isEmpty(&stack))
        new_exp[idx++] = pop(&stack);

    // new_exp 문자열의 끝 표시
    new_exp[idx] = '\0';
}

int calculate(char new_exp[])
{
    // 스택 동적할당
    int* stack = (int*)malloc(sizeof(int) * max_stack_size);
    int expLen = strlen(new_exp);
    int i, top = -1;
    char tok, op1, op2;

    for (i = 0; i < expLen; i++)
    {
        tok = new_exp[i];

        // 피연산자인 경우
        if (isdigit(tok))
        {
            // char 자료형 숫자를 int형 숫자로 변환후 스택에 넣기
            push(&stack, tok - '0');
        }
        // 연산자인 경우
        else
        {
            // 두 번째 피연산자와 첫 번째 피연산자를 순서대로 꺼내기
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
    // 중위표기식
    char exp[] = "((((6/2)-3+(4*2))-5*3))";
    // 후위표기식
    char new_exp[100];
    // 결과
    int result;

    infixToPostfix(exp, new_exp);
    result = calculate(new_exp);
    printf("결과 : %d\n", result);
    return 0;
}