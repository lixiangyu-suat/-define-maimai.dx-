#include <bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    string s; cin >> s;
    int n = s.length();

    vector<int> dp(n+1);
    dp[1] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j < i; j++){
            if (s[j-1] > s[i-1]) continue;
            dp[i] = max(dp[i], dp[j]+1);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}