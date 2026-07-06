#include <bits/stdc++.h>
using namespace std;

const int MOD = 11;
int main(){
    string s;
    cin >> s;
    vector<int> num(11);
    int idx = 1;
    for (auto c : s){
        if (c == '-') continue;
        else if (c == 'X') num[idx++] = 10;
        else num[idx++] = (c-'0');
    }
    idx = 10;
    int sum = 0;
    for (int i = 1; i <= 9; i++){
        sum += num[i]*i;
    }
    if (sum % MOD == num[idx]) cout << "Right";
    else {
        if (sum % MOD == 10) s[12] = 'X';
        else s[12] = (sum % MOD) + '0';
        cout << s;
    }
    return 0;
}