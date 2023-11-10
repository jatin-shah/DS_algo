#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node {
    public:
    int data;
    node *left;
    node *right;

    node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }

    void insert_level_order(int val) {
        node *nn = new node(val);
        queue<node *> Q;
        Q.push(this);

        while(!Q.empty()) {
            node *n = Q.front();
            Q.pop();

            if (!n->left) {
                n->left = nn;
                return;
            } else if(!n->right) {
                n->right = nn;
                return;
            } else {
                Q.push(n->left);
                Q.push(n->right);
            }
        }
    }

    bool remove_node(node *n, node *cur = nullptr) {
        node *root = nullptr;
        if (cur)
            root = cur;
        else    
            root = this;
        if (root == n){
            delete n;
            root = nullptr;
            return true;
        }
        if (root->left == n) {
            delete n;
            root->left = nullptr;
            return true;
        }
        if (root->right == n) {
            delete n;
            root->right = nullptr;
            return true;
        }
        if (!remove_node(n, root->left))
            return remove_node(n, root->right);
        else
            return true;
    }

    void delete_node(int val, node *n = nullptr) {
        node *cur = nullptr;
        if (n)
            cur = n;
        else
            cur = this;
        if (!cur->left && !cur->right) {
            if (cur->data == val) {
                delete cur;
                cur = nullptr;
                //return cur;
            }
        }

        queue<node *> Q;
        Q.push(cur);

        node *key_node = nullptr;
        node *cur_node = nullptr;

        while (!Q.empty()) {
            cur_node = Q.front();
            Q.pop();

            if (cur_node->data == val)
                key_node = cur_node;

            if (cur_node->left)
                Q.push(cur_node->left);
            if (cur_node->right)
                Q.push(cur_node->right);
        }

        if (key_node) {
            key_node->data = cur_node->data;
            // remove cur_node
            remove_node(cur_node);
        }

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
            cout << cur->data << " ";
            if (cur->right)
                print_inorder(cur->right);
        }
    }

    void print_inorder_stack(node *n = nullptr) {
        stack<node *> Stk;
        node *cur = nullptr;
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
            cout << cur->data << " ";
            cur = cur->right;
        }
    }

    void print_preorder(node *n = nullptr) {
        node *cur = nullptr;
        if (n)
            cur = n;
        else
            cur = this;
        if (cur) {
            cout << cur->data << " ";
            if (cur->left)
                print_preorder(cur->left);
            if (cur->right)
                print_preorder(cur->right);
        }
    }

    void print_postorder(node *n = nullptr) {
        node *cur = nullptr;
        if (n)
            cur = n;
        else
            cur = this;
        if (cur) {
            if (cur->left)
                print_postorder(cur->left);
            if (cur->right)
                print_postorder(cur->right);
            cout << cur->data << " ";
        }
    }

    int find_sum(int low, int high, node *n = nullptr) {
        int result = 0;
        node *cur = nullptr;
        if (n)
            cur = n;
        else    
            cur = this;
        if (cur) {
            if (cur->data >= low && cur->data <= high)
                result += cur->data;
            if (cur->left && cur->data > low)
                result += find_sum(low, high, cur->left);
            if (cur->right && cur->data < high)
                result += find_sum(low, high, cur->right);
        }
        return result;
    }
};

int main() {
/*
            1
           / \
          2   3
             /
            4
        
        2 1 4 3
*//*
    node root(1);
    node n2(2);
    node n3(3);
    node n4(4);

    root.left = &n2;
    root.right = &n3;
    n3.left = &n4;

    root.print_inorder();
*/
/*
            10 (root)
           /  \
         20    30
        / \      \
       40 50     70

       40 20 50 10 30 70 
*//*
    node *root = new node(10);
    node *n20 = new node(20);
    node *n30 = new node(30);
    node *n40 = new node(40);
    node *n50 = new node(50);
    node *n70 = new node(70);

    root->left = n20;
    root->right = n30;
    n20->left = n40;
    n20->right = n50;
    n30->right = n70;

    root->print_inorder();
    cout << endl;

    root->insert_level_order(60);
    root->print_inorder();
    cout << endl;
*/  
/*
            1 (root)
           /  \
          2    3
         /    /
        4    5
         \
          6

Inorder:    4 6 2 1 5 3 
Preorder:   1 2 4 6 3 5
Postorder:  6 4 2 5 3 1
*//*
    node *root = new node(1);
    node *n2 = new node(2);
    node *n3 = new node(3);
    node *n4 = new node(4);
    node *n5 = new node(5);
    node *n6 = new node(6);

    root->left = n2;
    root->right = n3;
    n2->left = n4;
    n3->left = n5;
    n4->right = n6;

    cout << "Inorder:\t";
    root->print_inorder();
    cout << endl;

    cout << "Inorder stack:\t";
    root->print_inorder_stack();
    cout << endl;

    cout << "Preorder:\t";
    root->print_preorder();
    cout << endl;

    cout << "Postorder:\t";
    root->print_postorder();
    cout << endl;

    // root->delete_node(3);
    // root->print_inorder();
    // cout << endl;
*/
/*
            10 (root)
           /  \
          5    15
         / \     \
        3   7     18

Inorder:    3 5 7 10 15 18 
Preorder:   10 5 3 7 15 18
Postorder:  3 7 5 18 15 10
*/
    node *root = new node(10);
    node *n5 = new node(5);
    node *n3 = new node(3);
    node *n7 = new node(7);
    node *n15 = new node(15);
    node *n18 = new node(18);

    root->left = n5;
    root->right = n15;
    n5->left = n3;
    n5->right = n7;
    n15->right = n18;

    cout << "Inorder:\t";
    root->print_inorder();
    cout << endl;

    cout << "Inorder stack:\t";
    root->print_inorder_stack();
    cout << endl;

    cout << "Preorder:\t";
    root->print_preorder();
    cout << endl;

    cout << "Postorder:\t";
    root->print_postorder();
    cout << endl;

    cout << "insert_level_order(13):\t";
    root->insert_level_order(13);
    root->print_inorder();
    cout << endl;

    cout << "Find sum [4, 19]:\t";
    cout << root->find_sum(4, 19);
    cout << endl;


    return 0;
}
