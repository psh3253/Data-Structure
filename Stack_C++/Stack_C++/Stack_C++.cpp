#include <iostream>
using namespace std;
template<typename T>

class Stack
{
private:
    int max_stack_size;
    int top = -1;
    T* element;
public:
    Stack<T>(int size)
    {
        element = new T[size];
        max_stack_size = size;
    }
    int isFull()
    {
        if (top >= max_stack_size - 1)
            return 1;
        else
            return 0;
    }

    int isEmpty()
    {
        if (top < 0)
            return 1;
        else
            return 0;
    }
    void stackFull()
    {
        int i;
        T* temp = new T[max_stack_size];
        for (i = 0; i < max_stack_size; i++)
        {
            temp[i] = element[i];
        }
        delete[] element;
        max_stack_size *= 2;
        element = new T[max_stack_size];
        for (i = 0; i < max_stack_size / 2; i++)
        {
            element[i] = temp[i];
        }
        delete[] temp;
    }

    void push(T item)
    {
        if (isFull())
            return;
        element[++top] = item;
    }

    T pop()
    {
        if (isEmpty())
            return -1;
        else
            return element[top--];
    }
};

int main(void)
{
    Stack<int>* s = new Stack<int>(10);
    s->push(10);
    s->push(20);
    s->push(30);
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    s->push(40);
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    delete[] s;
    return 0;
}