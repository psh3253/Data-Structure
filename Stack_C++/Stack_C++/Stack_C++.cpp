#include <iostream>
#include <queue>
#define MAX_STACK_SIZE    100
using namespace std;

class Stack
{
private:
    int element[MAX_STACK_SIZE];
    int top = -1;
public:
    int isEmpty()
    {
        if (top < 0)
            return 1;
        return 0;
    }

    int isFull()
    {
        if (top >= MAX_STACK_SIZE - 1)
            return 1;
        return 0;
    }

    void push(int item)
    {
        if (isFull())
            return;
        element[++top] = item;
    }

    int pop()
    {
        if (isEmpty())
            return -1;
        return element[top--];
    }
    int peek()
    {
        if (isEmpty())
            return -1;
        return element[top];
    }
};

int main()
{
    Stack* s = new Stack();
    s->push(10);
    s->push(20);
    s->push(30);
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    s->push(40);
    cout << s->pop() << endl;
    cout << s->pop() << endl;
}