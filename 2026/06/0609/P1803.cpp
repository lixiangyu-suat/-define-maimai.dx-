#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+6;
vector<int> dp;
int main(){
    int n, maxn = 0; cin >> n;
    vector<int> a(N, -1); //下标为i的最大左区间
    
    for (int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        maxn = max(maxn, r);
        a[r] = max(l, a[r]);
    }
    
    dp.resize(maxn+1);
    for (int i = 1; i <= maxn; i++){
        if (a[i] != -1) dp[i] = max(dp[i-1], dp[a[i]] + 1);
        else dp[i] = dp[i-1]; //此时没有右区间数值=下标
    }
    cout << dp[maxn];
    return 0;
}