#include<bits/stdc++.h>

using namespace std;

class myStack
{
    public:
        vector<int> v;
        void push(int val)
        {
            v.push_back(val);
        }

        void pop()
        {
            if (!v.empty())
                v.pop_back();
        }

        int top()
        {
            return v.back();
        }

        int size(){
            return v.size();
        }

        bool empty(){
            return v.empty();
        }
};

int main() {
   
    myStack st;
    
    int x;
    while(cin >> x && x != -1){
        st.push(x);
    }

    if (!st.empty()) {
        cout << "Top element: " << st.top() << endl;
    } else {
        cout << "Stack is empty" << endl;
    }

    return 0;
}
