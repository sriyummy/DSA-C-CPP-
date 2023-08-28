#include <iostream>
#include <cstdlib>

void insElement(int array[], int size, int position, int number)
{
    for (int i = size; i > position-1; i--)
    {
        array[i] = array[i - 1];
    }
    array[position - 1] = number;

    std::cout << "New array: " << std::endl;
    for (int i = 0; i < size+1; i++)
    {
        std::cout << array[i] << " ";
    }
}

void delElement(int array[], int size, int position)
{
    for (int i = position - 1; i < size - 1; i++)
    {
        array[i] = array[i + 1];
    }

    std::cout << "New array: " << std::endl;
    for (int i = 0; i < size-1; i++)
    {
        std::cout << array[i] << " ";
    }
}

void findElement(int array[], int size, int number)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == number)
        {
            std::cout << "The element is found at index number: " << i << std::endl;
            return;
        }
    }
    std::cout << "Element not found." << std::endl;
}

void travArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int n, ch;

    std::cout << "Enter the number of elements you want to put in the array: " << std::endl;
    std::cin >> n;

    int *arr = new int[n];

    std::cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::cout << "Enter 1 to insert an element, 2 to delete an element, " << "3 to search an element, 4 to traverse the array: " << std::endl;
    std::cin >> ch;

    switch (ch)
    {
        case 1:
        {
            int num, pos;
            std::cout << "Enter the element you want to insert in the array: " << std::endl;
            std::cin >> num;
            std::cout << "Enter the position you want to insert the element in: " << std::endl;
            std::cin >> pos;

            insElement(arr, n, pos, num);

            break;
        }

        case 2:
        {
            int pos;
            std::cout << "Enter the position of the element you want to delete: " << std::endl;
            std::cin >> pos;

            delElement(arr, n, pos);

            break;
        }

        case 3:
        {
            int num;
            std::cout << "Enter the element you want to search for: " << std::endl;
            std::cin >> num;

            findElement(arr, n, num);

            break;
        }

        case 4:
        {
            travArray(arr, n);

            break;
        }

        default:
        {
            std::cout << "Please enter a valid choice!" << std::endl;
        }
    }

    delete[] arr;
   
    return 0;
}
