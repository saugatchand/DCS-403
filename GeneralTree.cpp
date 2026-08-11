#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node
{
public:
    string data;
    vector<Node*> children;

    // Constructor
    Node(string value)
    {
        data = value;
    }
};

// Function to print the tree
void printTree(Node* root, string indent = "")
{
    if (root == nullptr)
        return;

    // Print current node
    cout << indent << root->data << endl;

    // Print all children
    for (Node* child : root->children)
    {
        printTree(child, indent + "    ");
    }
}

int main()
{
    // Create root node
    Node* root = new Node("CEO");

    // Create managers
    Node* hr = new Node("HR Manager");
    Node* it = new Node("IT Manager");
    Node* finance = new Node("Finance Manager");

    // Add managers to CEO
    root->children.push_back(hr);
    root->children.push_back(it);
    root->children.push_back(finance);

    // HR Manager's children
    hr->children.push_back(new Node("Recruiter"));
    hr->children.push_back(new Node("Payroll Officer"));

    // IT Manager's children
    it->children.push_back(new Node("DBA"));
    it->children.push_back(new Node("Software Engineer"));
    it->children.push_back(new Node("Network Engineer"));
    it->children.push_back(new Node("Security Engineer"));

    // Print the tree
    cout << "General Tree:" << endl;
    cout << "=============" << endl;

    printTree(root);

    return 0;
}