#include <iostream>

using namespace std;

struct Stack
{
    char data[100];
    int top;

    Stack()
    {
        top = -1;
    }

    void push(char value)
    {
        data[++top] = value;
    }

    char pop()
    {
        if (isEmpty())
        {
            cerr << "Error: Stack is empty" << endl;
            return '\0';
        }
        return data[top--];
    }

    char peek()
    {
        if (isEmpty())
        {
            cerr << "Error: Stack is empty" << endl;
            return '\0';
        }
        return data[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

void infixToPostfix(const char* infix)
{
    Stack operatorStack;
    char postfix[100];
    int postfixIndex = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];
        if (isalnum(c))
        {
            postfix[postfixIndex++] = c;
        }
        else if (c == '(')
        {
            operatorStack.push(c);
        }
        else if (c == ')')
        {
            while (!operatorStack.isEmpty() && operatorStack.peek() != '(')
            {
                postfix[postfixIndex++] = operatorStack.pop();
            }
            operatorStack.pop();
        }
        else if (isOperator(c))
        {
            while (!operatorStack.isEmpty() && precedence(c) <= precedence(operatorStack.peek()))
            {
                postfix[postfixIndex++] = operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.isEmpty())
    {
        postfix[postfixIndex++] = operatorStack.pop();
    }

    postfix[postfixIndex] = '\0';

    cout << "Postfix Expression: " << postfix << endl;
}

int main()
{
    const char* infixExpression = "A+B*C-(D/E+F)";
    infixToPostfix(infixExpression);

    return 0;
}

