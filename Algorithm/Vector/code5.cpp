#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int value) {
        val = value;
        next = nullptr;
    }
};

void pList(Node* head) {
    Node* cur = head;

    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }

    cout << endl;
}

void reDup(Node* head) {
    Node* cur = head;
    
    while (cur) {
        Node* temp = cur;
        while (temp->next) {
            
            if (temp->next->val == cur->val) {
                Node* nDEL = temp->next;
                temp->next = temp->next->next;
                delete nDEL;
            } 
            
            else {
                temp = temp->next;
            }
        }
        
        cur = cur->next;
    }
}

int main() {
    int val;
    Node* head = nullptr;
    Node* tail = nullptr;

    while (cin >> val && val != -1) {
        Node* newNode = new Node(val);
        if (!head) head = newNode;
        else tail->next = newNode;
        tail = newNode;
    }

    reDup(head);
    pList(head);

    return 0;
}
