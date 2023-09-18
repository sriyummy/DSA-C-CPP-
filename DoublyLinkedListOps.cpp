#include <iostream>
#include <cstdlib>

struct Node
{
    struct Node* prev;
    struct Node* next;
    int data;
};

struct Node* head = nullptr;

void insertion_beginning()
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    int item;

    if (ptr == NULL)
    {
        std::cout << "\nOVERFLOW" << std::endl;
    }
    else
    {
        std::cout << "\nEnter Item value: ";
        std::cin >> item;

        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            ptr->data = item;
            head = ptr;
        }
        else
        {
            ptr->data = item;
            ptr->prev = NULL;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        std::cout << "\nNode inserted" << std::endl;
    }
}

void insertion_last()
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    int item;

    if (ptr == NULL)
    {
        std::cout << "\nOVERFLOW" << std::endl;
    }
    else
    {
        std::cout << "\nEnter value: ";
        std::cin >> item;
        ptr->data = item;

        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        }
        else
        {
            struct Node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
        std::cout << "\nNode inserted" << std::endl;
    }
}

void insertion_specified()
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    int item, loc, i;

    if (ptr == NULL)
    {
        std::cout << "\nOVERFLOW" << std::endl;
    } else
    {
        struct Node* temp = head;
        std::cout << "Enter the location: ";
        std::cin >> loc;

        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                std::cout << "\nThere are less than " << loc << " elements" << std::endl;
                return;
            }
        }
        std::cout << "Enter value: ";
        std::cin >> item;
        ptr->data = item;
        ptr->next = temp->next;
        ptr->prev = temp;
        temp->next = ptr;
        temp->next->prev = ptr;
        std::cout << "\nNode inserted" << std::endl;
    }
}

void deletion_beginning()
{
    struct Node* ptr;

    if (head == NULL)
    {
        std::cout << "\nUNDERFLOW" << std::endl;
    } else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        std::cout << "\nNode deleted" << std::endl;
    }
    else
    {
        ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        std::cout << "\nNode deleted" << std::endl;
    }
}

void deletion_last()
{
    struct Node* ptr;

    if (head == NULL)
    {
        std::cout << "\nUNDERFLOW" << std::endl;
    } else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        std::cout << "\nNode deleted" << std::endl;
    } else {
        ptr = head;
        if (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
        std::cout << "\nNode deleted" << std::endl;
    }
}

void deletion_specified() {
    struct Node* ptr, *temp;
    int val;

    std::cout << "\nEnter the data after which the node is to be deleted: ";
    std::cin >> val;
    ptr = head;

    while (ptr->data != val)
        ptr = ptr->next;

    if (ptr->next == NULL) {
        std::cout << "\nCan't delete" << std::endl;
    } else if (ptr->next->next == NULL) {
        ptr->next = NULL;
    } else {
        temp = ptr->next;
        ptr->next = temp->next;
        temp->next->prev = ptr;
        free(temp);
        std::cout << "\nNode deleted" << std::endl;
    }
}

void display() {
    struct Node* ptr;
    std::cout << "\nPrinting values..." << std::endl;
    ptr = head;

    while (ptr != NULL) {
        std::cout << ptr->data << std::endl;
        ptr = ptr->next;
    }
}

void search() {
    struct Node* ptr;
    int item, i = 0, flag;
    ptr = head;

    if (ptr == NULL) {
        std::cout << "\nEmpty List" << std::endl;
    } else {
        std::cout << "\nEnter item which you want to search?" << std::endl;
        std::cin >> item;

        while (ptr != NULL) {
            if (ptr->data == item) {
                std::cout << "\nItem found at location " << i + 1 << std::endl;
                flag = 0;
                break;
            } else {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }

        if (flag == 1) {
            std::cout << "\nItem not found" << std::endl;
        }
    }
}

int main()
{
    int choice = 0;

    while (choice != 9)
    {
        std::cout << "\nChoose one option from the following list: " << std::endl;
        std::cout << "\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location" << std::endl;
        std::cout << "4.Delete from Beginning\n5.Delete from last\n6.Delete the node after the given data" << std::endl;
        std::cout << "7.Search\n8.Show\n9.Exit" << std::endl;
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                insertion_beginning();
                break;
            case 2:
                insertion_last();
                break;
            case 3:
                insertion_specified();
                break;
            case 4:
                deletion_beginning();
                break;
            case 5:
                deletion_last();
                break;
            case 6:
                deletion_specified();
                break;
            case 7:
                search();
                break;
            case 8:
                display();
                break;
            case 9:
            return 0;
            
            default:
                std::cout << "Please enter a valid choice." << std::endl;
        }
    }
    return 0;
}


