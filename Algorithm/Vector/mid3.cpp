#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    string val;
    Node* next;
    Node* prev;

    Node(string val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail, string val) {
    Node* newnode = new Node(val);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

Node* find(Node* head, string address) {
    Node* tmp = head;
    while (tmp != NULL) {
        if (tmp->val == address) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    string value;

    while (cin >> value && value != "end") {
        insert_at_tail(head, tail, value);
    }

    int Q;
    cin >> Q;
    Node* current = head;
    string cmd;

    for (int i = 0; i < Q; ++i) {
        cin >> cmd;
        if (cmd == "visit") {
            string address;
            cin >> address;
            Node* result = find(head, address);
            if (result != NULL) {
                current = result;
                cout << current->val << endl;
            } else {
                cout << "Not Available" << endl;
            }
        } else if (cmd == "next") {
            if (current->next != NULL) {
                current = current->next;
                cout << current->val << endl;
            } else {
                cout << "Not Available" << endl;
            }
        } else if (cmd == "prev") {
            if (current->prev != NULL) {
                current = current->prev;
                cout << current->val << endl;
            } else {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}
