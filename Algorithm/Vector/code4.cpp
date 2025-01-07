#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val) {
        value = val;
        next = nullptr;
    }
};

void pList(Node* head) {
    Node* cNode = head;
    while (cNode) {
        cout << cNode->value << " ";
        cNode = cNode->next;
    }
    cout << endl;
}

int main() {
    int nQuery;
    cin >> nQuery;

    Node* head = nullptr;

    while (nQuery--) {
        int action, val;
        cin >> action >> val;

        if (action == 0) { 
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;

        } else if (action == 1) {  
            Node* newNode = new Node(val);

            if (!head) {
                head = newNode;
            } 
            
            else {
                Node* cNode = head;
                while (cNode->next) {
                    cNode = cNode->next;
                }
                cNode->next = newNode;
            }
        } 
        
        else if (action == 2) {  
            if (val < 0) continue;
            if (val == 0 && head) {  
                Node* temp = head;
                head = head->next;
                delete temp;

            } 
            
            else {
                Node* cNode = head;
                int index = 0;
                while (cNode && index < val - 1) {
                    cNode = cNode->next;
                    index++;
                }

                if (cNode && cNode->next) {
                    Node* nDEL = cNode->next;
                    cNode->next = cNode->next->next;
                    delete nDEL;
                }
            }
        }

        pList(head);
    }

    return 0;
}
