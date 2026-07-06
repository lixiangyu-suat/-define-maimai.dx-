#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    getline(cin, s);

    s[0] = 'h';
    s[s.length()-1] = '.';
    cout << "Okay, so I want to figure out " << s;
    return 0;

}