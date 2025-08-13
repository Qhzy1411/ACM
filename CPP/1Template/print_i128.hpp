#include <bits/stdc++.h>
using namespace std;

// i128打印函数
void print_i128(__int128 x) {
    if (x == 0) {
        cout << "0";
        return;
    }
    stack<int> st;
    while (x > 0) {
        st.push(x % 10);
        x /= 10;
    }
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}