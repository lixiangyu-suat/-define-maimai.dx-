#include <bits/stdc++.h>
using namespace std;

vector<bool> dp;
vector<int> coins;
int cnt = 0;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int n, k; cin >> n >> k;

    dp.resize(k+1, false);
    coins.resize(n);
    dp[0] = true;

    for (int i = 0; i < n; i++){
        cin >> coins[i];
        
        dp[coins[i]] = true;
        cnt++;
    }
    for (int i = 0; i <= k; i++){
        if (dp[i]) continue;
        for (int j = 0; j < n; j++){
            int olddp = i - coins[j];
            if (olddp >= 0 && dp[olddp]) {
                cnt++;
                dp[i] = true;
                break;
            }
        }
    }

    cout << cnt << endl;
    for (int i = 0; i <= k; i++){
        if (dp[i]) cout << i << ' ';
    }
    return 0;
}