#include <iostream>

const int max_size = 100;
int stack[max_size];
int top = -1;

void pushElement(int item, int size)
{
	if (top == size-1)
	{
		std::cout << "Stack Overflow!" << std::endl;
	}
	else
	{
		top++;
		stack[top] = item;
	}
}

void popElement()
{
	if (top == -1)
	{
		std::cout << "Stack Underflow!" << std::endl;
	}
	else
	{
		int item = stack[top];
		top--;
	}
}

bool isEmpty()
{
	return top == -1;
}

bool isFull(int size)
{
	return top == size-1;
}

void displayElements(int size)
{
	if (top == -1)
	{
		std::cout << "Empty Stack!" << std::endl;
	}
	else
	{
		for (int i=0; i<size; i++)
		{
			std::cout << stack[i] << " ";
		}
	}
}

int main()
{
	int n, ch;
	
	std::cout << "Enter the size of the stack: ";
	std::cin >> n;
	
	while (true)
	{
		std::cout << "Enter 1 to Push\nEnter 2 to Pop\nEnter 3 to check if the stack is empty\nEnter 4 to check if the stack is full\nEnter 5 to display the elements\nEnter 6 to exit: ";
		std::cin >> ch;
		
		switch (ch)
		{
			case 1:
				int num;
				std::cout << "Enter the number you want to push: ";
				std::cin >> num;
				pushElement(num, n);
				break;
			case 2:
				popElement();
				break;
			case 3:
				if (isEmpty())
				{
					std::cout << "Stack is Empty!";
				}
				else
				{
					std::cout << "Stack is not Empty!";
				}
				break;
			case 4:
				if (isFull(n))
				{
					std::cout << "Stack is Full!";
				}
				else
				{
					std::cout << "Stack is not full!";
				}
				break;
			case 5:
				displayElements(n);
				break;
			case 6:
				return 0;
				break;
			default:
				std::cout << "INVALID INPUT!";
		}
	}

	return 0;
}	
