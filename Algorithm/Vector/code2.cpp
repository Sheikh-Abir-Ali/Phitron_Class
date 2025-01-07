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
    int t;
    cin >> t;

    while (t--) {
        int x, val;
        Node *head = nullptr, *tail = nullptr;


        while (cin >> val && val != -1) {
            Node* newNode = new Node(val);
            if (!head) {
                head = newNode;
                tail = head;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        cin >> x;

        int index = 0;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == x) {
                cout << index << endl;
                break;
            }
            temp = temp->next;
            index++;
        }
        
        if (temp == nullptr) cout << -1 << endl;
    }

    return 0;
}
