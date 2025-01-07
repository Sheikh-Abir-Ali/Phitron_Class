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
    Node *head1 = nullptr, *tail1 = nullptr;
    Node *head2 = nullptr, *tail2 = nullptr;
    int val;

    while (cin >> val && val != -1) {
        Node* newNode = new Node(val);
        if (!head1) head1 = newNode;
        else tail1->next = newNode;
        tail1 = newNode;
    }

    while (cin >> val && val != -1) {
        Node* newNode = new Node(val);
        if (!head2) head2 = newNode;
        else tail2->next = newNode;
        tail2 = newNode;
    }

    Node* temp1 = head1;
    Node* temp2 = head2;

    while (temp1 && temp2) {
        if (temp1->data != temp2->data) {
            cout << "NO" << endl;
            return 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if (temp1 || temp2) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    return 0;
}
