#include <iostream>
#include <format>
using namespace std;

class node {
    public:
        int value;
        node *next;

    node(int data = 0) {
        value = data;
        next = nullptr;
    }

    node *insert_at_head(int data = 0) {
        node *n = new node(data);
        n->next = this;
        return n;
    }

    node *insert_at_tail(int data = 0) {
        node *new_n = new node(data);

        node *n = this;
        while(n->next) {
            n = n->next;
        }
        n->next = new_n;
        return this;
    }

    node *insert_after_val(int val, int data = 0) {
        node *new_n = new node(data);

        node *n = this;
        while(n->next && (n->value != val)) {
            n = n->next;
        }
        if (n->value == val) {
            node *save_next = n->next;
            n->next = new_n;
            new_n->next = save_next;
        }
        return this;
    }

    node *delete_head() {
        return this->next;
    }

    node *delete_tail() {
        node *prev = this;
        node *n = prev->next;
        while(n && n->next) {
            prev = n;
            n = n->next;
        }
        prev->next = nullptr;
        return (n) ? this : nullptr;
    }

    node *delete_val(int val) {
        node *prev = this;
        if (prev->value == val)
            return prev->next;
        node *n = prev->next;
        while(n && n->value != val && n->next) {
            prev = n;
            n = n->next;
        }
        if (n && n->value == val)
            prev->next = n->next;
        return this;
    }

    // Returns index of node (0=head), where value is found
    int find_val(int val) {
        node *n = this;
        int index = 0;
        while(n && n->value != val && n->next) {
            n = n->next;
            index++;
        }
        if (n && n->value == val)
            return index;
        else
            return -1;
    }

    int find_middle() {
        node *slow = this;
        node *fast = this;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->value;
    }

    bool loop_in_ll() {
        node *slow = this;
        node *fast = this;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) return true;
        }
        return false;
    }

    void print_LL() {
        node *n = this;
        while(n) {
            cout << n->value << "->";
            n = n->next;
        }
        cout << "NULL\n";
    };
};

main() {
    node n1(1), n2(2), n3(3), n4(66), n5(109);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = nullptr; // &n3; //

    node *n = &n1;
    n->print_LL();

    // Insert in beginning
    n = n->insert_at_head(99);
    n->print_LL();

    // Insert at the end
    n = n->insert_at_tail(109);
    n->print_LL();

    // Insert after a specific value
    n = n->insert_after_val(1, 66);
    n->print_LL();

    // Delete the head
    n = n->delete_head();
    n->print_LL();

    // Delete the tail
    n = n->delete_tail();
    n->print_LL();

    // Delete a specific value
    n = n->delete_val(66);
    n->print_LL();

    // Find a value in ll
    int findval = 3;
    int findindex = n->find_val(findval);
    if (findindex > -1)
        cout << "Value " << findval << " found at index " << findindex << endl;
    else
        cout << "Value " << findval << " not found in linked list\n";

    // Insert at the end
    n = n->insert_at_tail(18);
    n->print_LL();

    // Insert at the end
    n = n->insert_at_tail(37);
    n->print_LL();

    // Find middle of ll
    cout << "Middle of linked list has value " << n->find_middle() << endl;

    // Check for loop
    cout << "Loop in linked list: " << n->loop_in_ll();
}