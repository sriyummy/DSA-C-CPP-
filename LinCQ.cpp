#include <iostream>
using namespace std;

#define MAX_SIZE 5

int circularQueue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int value)
{
    if ((rear + 1) % MAX_SIZE == front)
    {
        cout << "Overflow" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        circularQueue[rear] = value;
    }
}

void dequeue()
{
    if (front == -1)
    {
        cout << "Underflow" << endl;
    }
    else
    {
        int dequeuedValue = circularQueue[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
    }
}

void traverse()
{
    if (front == -1)
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        int i = front;
        cout << "Your Queue is: ";
        do
        {
            cout << circularQueue[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        cout << endl;
    }
}

bool isEmpty()
{
    return front == -1;
}

bool isFull()
{
    return (rear + 1) % MAX_SIZE == front;
}

int main()
{
    int choice;
    do
    {
        cout << "Enter your choice:\n1. Enqueue\n2. Dequeue\n3. Traverse\n4. IsEmpty\n5. IsFull\n6. Exit";
        cin >> choice;

        switch (choice)
        {
            case 1:
                int value;
                cout << "Enter the element to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;
            case 4:
                cout << (isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;
            case 5:
                cout << (isFull() ? "Queue is full." : "Queue is not full.") << endl;
                break;
            case 6:
                cout << "Adios!" << endl;
                break;
            default:
                cout << "Please Enter a Valid choice" << endl;
        }

    } while (choice != 6);

    return 0;
}
