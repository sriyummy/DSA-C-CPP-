#include <iostream>
#include <cstdlib>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* start;

    LinkedList() {
        start = nullptr;
    }

    void insertAtPosition(int data, int position) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = nullptr;

        if (position == 1) {
            newNode->next = start;
            start = newNode;
            return;
        }

        Node* prev = start;
        for (int i = 1; i < position - 1 && prev != nullptr; i++) {
            prev = prev->next;
        }

        if (prev == nullptr) {
            std::cout << "Position does not exist" << std::endl;
            free(newNode);
            return;
        }

        newNode->next = prev->next;
        prev->next = newNode;
    }

    void insertAfterData(int dataToFind, int newData) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = newData;
        newNode->next = nullptr;

        Node* current = start;

        while (current != nullptr && current->data != dataToFind) {
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Data not found" << std::endl;
            free(newNode);
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void deleteAtPosition(int position) {
        if (start == nullptr) {
            std::cout << "List is empty!" << std::endl;
        }

        if (position == 1) {
            Node* temp = start;
            start = start->next;
            free(temp);
            return;
        }

        Node* prev = start;
        Node* current = nullptr;

        for (int i = 1; i < position - 1 && prev != nullptr; i++) {
            prev = prev->next;
        }

        if (prev == nullptr || prev->next == nullptr) {
            std::cout << "Invalid position!" << std::endl;
            return;
        }

        current = prev->next;
        prev->next = current->next;
        free(current);
    }

    void deleteData(int dataToDelete) {
        if (start == nullptr) {
            std::cout << "List is empty!" << std::endl;
            return;
        }

        if (start->data == dataToDelete) {
            Node* temp = start;
            start = start->next;
            free(temp);
            return;
        }

        Node* prev = start;
        Node* current = nullptr;

        while (prev->next != nullptr && prev->next->data != dataToDelete) {
            prev = prev->next;
        }

        if (prev->next == nullptr) {
            std::cout << "Data not found!" << std::endl;
            return;
        }

        current = prev->next;
        prev->next = current->next;
        free(current);
    }

    int countNodes() {
        int count = 0;
        Node* current = start;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void traverse() {
        Node* current = start;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
} LinkedList;

int main() {
    LinkedList list;

    int ch;
    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Insert at specific position" << std::endl;
        std::cout << "2. Insert after given data" << std::endl;
        std::cout << "3. Delete from specific position" << std::endl;
        std::cout << "4. Delete a given data" << std::endl;
        std::cout << "5. Count nodes" << std::endl;
        std::cout << "6. Traverse" << std::endl;
        std::cout << "7. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> ch;

        switch (ch) {
            case 1: {
                int data, pos;
                std::cout << "Enter data and position: ";
                std::cin >> data >> pos;
                list.insertAtPosition(data, pos);
                break;
            }
            case 2: {
                int data, newData;
                std::cout << "Enter data to find and the new data: ";
                std::cin >> data >> newData;
                list.insertAfterData(data, newData);
                break;
            }
            case 3: {
                int pos;
                std::cout << "Enter position to delete: ";
                std::cin >> pos;
                list.deleteAtPosition(pos);
                break;
            }
            case 4: {
                int dataToDelete;
                std::cout << "Enter data to delete: ";
                std::cin >> dataToDelete;
                list.deleteData(dataToDelete);
                break;
            }
            case 5: {
                int count = list.countNodes();
                std::cout << "Number of nodes: " << count << std::endl;
                break;
            }
            case 6: {
                std::cout << "Linked List: ";
                list.traverse();
                break;
            }
            case 7: {
                exit(0);
            }
            default: {
                std::cout << "Invalid Input" << std::endl;
                break;
            }
        }
    }

    return 0;
}

