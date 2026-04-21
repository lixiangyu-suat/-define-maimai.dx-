// 相邻项比较
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; int k;
    cin >> s >> k;
    while(k--) {
        int i = 0;
        while(i < s.length() - 1) {
            if (s[i] > s[i+1]) break;
            else ++i;
        }
        s.erase(i, 1);
    }
    int i = 0;
    while(s[i] == '0') i++;
    cout << s.substr(i);
    if(i == s.length()) cout << 0;
}