#include<bits/stdc++.h>

using namespace std;

int main() {
   
    // list <int> li; // created a list
    list<int> li(10,21);
    // cout << *li.begin() << endl; // .begin() is an iterator

    // for (auto it = li.begin(); it != li.end(); it++){
    //     cout << *it << " ";
    // }
    // list<int> li2(5,1);
    list<int> l2 = {1,2,3,4,5};
    l2.insert(next(l2.begin(), 2), 10);
    // vector<int> l2(li2.begin(), li2.end());

    for (int val : l2){
        cout << val << " ";
    }

    return 0;
}
