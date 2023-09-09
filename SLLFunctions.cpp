#include <iostream>
#include <cstdlib>

struct Node
{
    int data;
    Node* next;
};

void insertNode(Node*& start, int value)
{
    Node* new_node = new Node();
    new_node->data = value;
    new_node->next = nullptr;

    if (start == nullptr)
    {
        start = new_node;
    }else
    {
        Node* ptr = start;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}

bool searchElement(Node* start, int value)
{
    Node* ptr = start;

    while (ptr != nullptr)
    {
        if (ptr->data == value)
        {
            return true;
        }
        ptr = ptr->next;
    }

    return false;
}

void sortList(Node*& start)
{
    if (start == nullptr || start->next == nullptr)
    {
        return;
    }

    bool swapped;
    do
    {
        swapped = false;
        Node* ptr = start;
        Node* prev = nullptr;

        while (ptr->next != nullptr)
        {
            if (ptr->data > ptr->next->data)
            {
                Node* temp = ptr->next;
                ptr->next = temp->next;
                temp->next = ptr;

                if (prev == nullptr)
                {
                    start = temp;
                }
                else
                {
                    prev->next = temp;
                }

                swapped = true;
            }
            prev = ptr;
            ptr = ptr->next;
        }
    } while (swapped);
}

void reverseList(Node*& start)
{
    Node* prev = nullptr;
    Node* ptr = start;
    Node* next = nullptr;

    while (ptr != nullptr)
    {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }

    start = prev;
}

void displayList(Node* start)
{
    Node* ptr = start;

    while (ptr != nullptr)
    {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }

    std::cout << std::endl;
}

int main()
{
    Node* start = nullptr;

    char ch;
    
    do
    {
        int value;
        std::cout << "Enter an integer to add to the linked list: ";
        std::cin >> value;
        insertNode(start, value);

        std::cout << "Do you want to add another integer? (y/n): ";
        std::cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    std::cout << "Original List: ";
    displayList(start);

    int sch_val;
    std::cout << "Enter an integer to search in the list: ";
    std::cin >> sch_val;
    
    if (searchElement(start, sch_val))
    {
        std::cout << "Element " << " found " << std::endl;
    } else
    {
        std::cout << "Element " << " not found" << std::endl;
    }

    sortList(start);
    std::cout << "Sorted List: ";
    displayList(start);

    reverseList(start);
    std::cout << "Reversed List: ";
    displayList(start);

    Node* ptr = start;
    while (ptr != nullptr)
    {
        Node* temp = ptr;
        ptr = ptr->next;
        delete temp;
    }

    return 0;
}

