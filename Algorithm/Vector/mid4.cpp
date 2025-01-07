#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert(Node* &head, Node* &tail, int index, int val) {
    Node* newnode = new Node(val);
    if (index == 0) {
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        return;
    }

    Node* tmp = head;
    int count = 0;

    while (tmp != NULL && count < index - 1) {
        tmp = tmp->next;
        count++;
    }

    if (tmp == NULL) {
        cout << "Invalid" << endl;
        delete newnode;
        return;
    }

    if (tmp->next == NULL) {
        tmp->next = newnode;
        newnode->prev = tmp;
        tail = newnode;
    } else {
        newnode->next = tmp->next;
        tmp->next->prev = newnode;
        tmp->next = newnode;
        newnode->prev = tmp;
    }
}

void print_list(Node* head, Node* tail) {
    Node* tmp = head;
    cout << "L -> ";
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;

    tmp = tail;
    cout << "R -> ";
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int index, value;
        cin >> index >> value;
        insert(head, tail, index, value);
        if (head != NULL) {
            print_list(head, tail);
        }
    }

    return 0;
}
