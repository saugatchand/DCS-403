#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Root: " << root->data << endl;
    cout << "Left Child: " << root->left->data << endl;
    cout << "Right Child: " << root->right->data << endl;

    return 0;
}
