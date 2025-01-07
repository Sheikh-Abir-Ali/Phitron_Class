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

    st.push(10);
    st.push(21);
    st.push(311);

    cout << st.top() << endl;

    st.pop();
    // st.pop();
    // st.pop();
    if (st.empty() == false) cout << st.top() << endl;
    

    return 0;
}
