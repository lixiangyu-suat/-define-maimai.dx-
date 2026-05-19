#include <bits/stdc++.h>
using namespace std;
bool judge(){
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 1; i < s.length(); i++){
        if (s[i] == s[i-1]) cnt++;
        if (cnt == 3) return false;//找规律
    }
    return true;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" ,stdin);
    #endif
    
    int n; cin >> n;
    while (n--){
        if (judge()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}