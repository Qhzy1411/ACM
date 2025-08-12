#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(x) x.begin(), x.end()
#define size(x) int(x.size())
#define eb emplace_back
const int inf = 0x3f3f3f3f;

// 字符串前缀函数 时间：O(n)
vi str_prefix(string s) {
    int n = size(s);
    vi pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

// 字符串KMP 时间：O(n+m)
vi KMP(string text, string pattern) { // pattern为寻找目标
    string cur = pattern + '#' + text;
    int sz1 = size(text), sz2 = size(pattern);
    vi v;
    vi lps = str_prefix(cur);
    for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
        if (lps[i] == sz2)
            v.eb(i - 2 * sz2);
    }
    return v;
}

// 数组前缀函数 时间：O(n)
vi vi_prefix(vi v) {
    int n = size(v);
    vi pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && v[i] != v[j])
            j = pi[j - 1];
        if (v[i] == v[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

// 数组KMP 时间：O(n+m)
vi KMP(vi origin, vi pattern) { // pattern为寻找目标
    vi cur = pattern;
    cur.eb(-2 * inf); //-2inf为原数组中不可能出现值
    cur.insert(cur.end(), all(pattern));
    int sz1 = size(origin), sz2 = size(pattern);
    vi v;
    vi lps = vi_prefix(cur);
    for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
        if (lps[i] == sz2)
            v.eb(i - 2 * sz2);
    }
    return v;
}