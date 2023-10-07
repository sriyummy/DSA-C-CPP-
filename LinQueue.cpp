#include <iostream>
using namespace std;

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int value)
{
    if (rear == MAX_SIZE - 1)
    {
        cout << "Overflow" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
}

void dequeue()
{
    if (front == -1)
    {
        cout << "Ubderflow" << endl;
    }
    else
    {
        int dequeuedValue = queue[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
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
        cout << "The Queue s: ";
        for (int i = front; i <= rear; ++i)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

bool isEmpty()
{
    return front == -1;
}

bool isFull()
{
    return rear == MAX_SIZE - 1;
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
                cout << "Please enter a valid choice!" << endl;
        }

    } while (choice != 6);
    
    return 0;
}
