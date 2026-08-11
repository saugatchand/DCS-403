#include <iostream>
using namespace std;

class Stack
{
private:
    int arr[5];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int value)
    {
        if (top == 4)
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    void peek()
    {
        if (top == -1)
            cout << "Stack is empty\n";
        else
            cout << "Top element: " << arr[top] << endl;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.pop();

    s.display();

    s.peek();

    return 0;
}