#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<int> coins;
vector<int> ans;
int cnt = 0;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int n, k; cin >> n >> k;

    dp.resize(k+1, 0);
    coins.resize(n+1);
    dp[0] = true;

    int sum = 0;
    for (int i = 1; i <= n; i++){
        cin >> coins[i];
    }

    for (int t = 0; t <= k; t++){
        fill(dp.begin(), dp.end(), -1e9);
        dp[0] = 0;
        for (int i = 1; i <= n; i++){
            for (int j = t; j >= coins[i]; j--){
                if (dp[j-coins[i]] == -1e9) continue;
                dp[j] = max(dp[j], dp[j-coins[i]]+1);
            }
        }
        if (dp[t] != -1e9) {
            cnt++;
            ans.push_back(t);
        }
    }
    
    cout << cnt << endl;
    for (auto u : ans) cout << u << ' ';
    return 0;
}