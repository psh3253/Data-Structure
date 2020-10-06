#include <iostream>
#include <random>
using namespace std;
template<typename T>

class Queue
{
private:
    int max_queue_size;
    int front = -1;
    int rear = -1;
    T* element;
public:
    Queue<T>(int size)
    {
        element = new T[size];
        max_queue_size = size;
    }
    int isFull()
    {
        if (rear == max_queue_size - 1)
            return 1;
        else
            return 0;
    }

    int isEmpty()
    {
        if (front == rear)
            return 1;
        else
            return 0;
    }
    void queueFull()
    {
        int i;
        T* temp = new T[max_queue_size];
        for (i = 0; i < max_queue_size; i++)
        {
            temp[i] = element[i];
        }
        delete[] element;
        max_queue_size *= 2;
        element = new T[max_queue_size];
        for (i = 0; i < max_queue_size / 2; i++)
        {
            element[i] = temp[i];
        }
        delete[] temp;
    }

    void addQ(T item)
    {
        if (isFull())
            queueFull();
        element[++rear] = item;
    }

    T deleteQ()
    {
        if (isEmpty())
            return -1;
        else
            return element[++front];
    }
};

int main(void)
{
    int i;
    random_device rd;
    mt19937_64 gen(rd());
    std::uniform_int_distribution<int> select(0, 1);
    std::uniform_int_distribution<int> number(1, 1000);
    Queue<int>* q = new Queue<int>(10);
    for (i = 0; i < 1000; i++)
    {
        if (select(gen) == 0)
        {
            q->addQ(number(gen));
        }
        else
        {
            cout << q->deleteQ() << endl;
        }
    }
    delete[] q;
    return 0;
}