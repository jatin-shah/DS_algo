#include <iostream>
#include <stack>
using namespace std;

class node {
public:
    int val;
    node *left = nullptr;
    node *right = nullptr;

    node(int data) {
        val = data;
    } 

    void print_inorder(node *n = nullptr) {
        node *cur = nullptr;
        if (n)
            cur = n;
        else    
            cur = this;

        if (cur) {
            if (cur->left)
                print_inorder(cur->left);
            cout << cur->val << "\t";
            if (cur->right)
                print_inorder(cur->right);
        }
    }

    void print_inorder_stack(node *n = nullptr) {
        node *cur = nullptr;
        stack<node *> Stk;
        if (n)
            cur = n;
        else    
            cur = this;

        while (cur || !Stk.empty()) {
            while (cur) {
                Stk.push(cur);
                cur = cur->left;
            }
            cur = Stk.top();
            Stk.pop();
            cout << cur->val << "\t";
            cur = cur->right;
        }
    }
};

int main() {
/*
    stack<int> Stk;

    for (int i = 0; i < 5; i++)
        Stk.push(i);
    
    cout << "Size = " << Stk.size() << endl;
    cout << "Top = " << Stk.top() << endl;

    Stk.pop();
    Stk.pop();

    cout << "Size = " << Stk.size() << endl;
    cout << "Top = " << Stk.top() << endl;

    if (Stk.empty())
        cout << "Stack is empty!\n";
    else 
        cout << "Stack is not empty.\n";
*/
/*
            1 (root)
           / \
          2   3
         /   / \
        4   5   6
         \
          7

    Inorder: 4 7 2 1 5 3 6 
*/    
    node *root = new node(1);
    node *n2 = new node(2);
    node *n3 = new node(3);
    node *n4 = new node(4);
    node *n5 = new node(5);
    node *n6 = new node(6);
    node *n7 = new node(7);

    root->left = n2;
    root->right = n3;
    n2->left = n4;
    n4->right = n7;
    n3->left = n5;
    n3->right = n6;

    cout << "root->print_inorder()\n";
    root->print_inorder();
    cout << "\nroot->print_inorder_stack()\n";
    root->print_inorder_stack();
    cout << endl;

    return 0;
} 