#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string s; cin >> s;
        int maxn = 0, minn = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '1' && i+2 < n && s[i+2] == '1'){
                s[i+1] = '1';
            }
        }
        for (int i = 0; i < n; i++){
            if (s[i] == '1'){
                maxn++;
            }
        }
        for (int i = 0; i < n; i++){
            if (s[i] == '1' && i+2 < n && s[i+2] == '1'){
                s[i+1] = '0';
            }
        }
        for (int i = 0; i < n; i++){
            if (s[i] == '1'){
                minn++;
            }
        }
        cout << minn << ' ' << maxn << '\n';
    }
    return 0;
}