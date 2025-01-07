#include <bits/stdc++.h>
using namespace std;

void fun(int *p){
    // *p = 100;
    int y = 200;
    p = &y;
    cout << "In Fun " << *p << endl; 
}

int main() {
    int n=21;
    int* p = &n;
    fun(p);
    cout << "In Main " << *p << endl;
    
    return 0;
}
