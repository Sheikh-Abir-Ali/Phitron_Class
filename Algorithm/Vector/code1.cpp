#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

int main() {
    int x;
    Node* head = nullptr;
    Node* temp = nullptr;


    while (cin >> x && x != -1) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }


    if (head == nullptr) {
        cout << 0 << endl;
        return 0;
    }

    int mn = head->data, mx = head->data;
    temp = head;
    while (temp != nullptr) {
        if (temp->data < mn) mn = temp->data;
        if (temp->data > mx) mx = temp->data;
        temp = temp->next;
    }

    cout << mx - mn << endl;

    return 0;
}
