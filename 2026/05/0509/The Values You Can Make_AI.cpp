#include <bits/stdc++.h>
using namespace std;

bitset<505> dp[505];
int main(){
    int n, k; cin >> n >> k;
    dp[0].set(0);
    
    for (int i = 0; i < n; i++){
        int coin; cin >> coin;
        for (int j = k; j >= coin; j--){
            dp[j] = dp[j] | dp[j-coin] | (dp[j-coin] << coin);
        }
    }

    bitset<505>& ans = dp[k];
    cout << ans.count() << endl;
    for (int i = 0; i <= k; i++){
        if (ans.test(i)) cout << i << ' ';
    }
    return 0;
}