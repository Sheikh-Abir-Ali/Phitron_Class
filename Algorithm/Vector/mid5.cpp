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

void insert_at_head(Node* &head, Node* &tail, int val) {
    Node* newnode = new Node(val);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insert_at_tail(Node* &head, Node* &tail, int val) {
    Node* newnode = new Node(val);
    if (tail == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void delete_at_index(Node* &head, Node* &tail, int index) {
    if (index < 0) {
        return;
    }

    Node* tmp = head;
    for (int i = 0; i < index && tmp != NULL; ++i) {
        tmp = tmp->next;
    }

    if (tmp == NULL) {
        return;
    }

    if (tmp->prev != NULL) {
        tmp->prev->next = tmp->next;
    } else {
        head = tmp->next;
    }

    if (tmp->next != NULL) {
        tmp->next->prev = tmp->prev;
    } else {
        tail = tmp->prev;
    }

    delete tmp;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int X, V;
        cin >> X >> V;
        if (X == 0) {
            insert_at_head(head, tail, V);
        } else if (X == 1) {
            insert_at_tail(head, tail, V);
        } else if (X == 2) {
            delete_at_index(head, tail, V);
        }
        print_list(head, tail);
    }

    return 0;
}
