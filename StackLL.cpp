#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void push(Node*& top, int value)
{
    Node* newNode = createNode(value);
    if (newNode)
    {
        newNode->next = top;
        top = newNode;
    }
}

void pop(Node*& top)
{
    if (top == nullptr)
    {
        cout << "Underflow!" << endl;
    }
    else
    {
        Node* temp = top;
        top = top->next;
        free(temp);
    }
}

bool isEmpty(Node* top)
{
    return top == nullptr;
}

void display(Node* top)
{
    if (isEmpty(top))
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        cout << "Stack elements: ";
        Node* current = top;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

int main()
{
    Node* top = nullptr;
    int choice, value;

    do
    {
        cout << "\nPress:\n1 to Push\n2 to Pop\n3 to check if stack is empty\n4 to display elements\n5 to quit";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(top, value);
                break;
            case 2:
                pop(top);
                break;
            case 3:
                if (isEmpty(top))
                {
                    cout << "Stack is empty." << endl;
                } else
                {
                    cout << "Stack is not empty." << endl;
                }
                break;
            case 4:
                display(top);
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    while (top != nullptr)
    {
        Node* temp = top;
        top = top->next;
        free(temp);
    }

    return 0;
}

