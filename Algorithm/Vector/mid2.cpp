#include<bits/stdc++.h>

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

void print_forward(Node* head){
    Node* tmp = head;
    while (tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }

    cout << endl;
}

void insert_at_tail(Node* &head, Node* &tail, int val){
    
    Node* newnode = new Node(val);
    if (head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }

    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;

}

bool palindrome(Node* head, Node* tail){
    while (head != NULL && tail != NULL){
        if (head->val != tail->val){
            return false;
        }

        if (head == tail || head->next == tail){
            break;
        }
        head = head->next;
        tail = tail->prev;
    }
    return true;
} 


int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int value;

    while (true) {
        cin >> value;
        if (value == -1) break;
        insert_at_tail(head, tail, value);
    }

    palindrome(head, tail) ? cout << "YES" : cout << "NO";

    return 0;
}
