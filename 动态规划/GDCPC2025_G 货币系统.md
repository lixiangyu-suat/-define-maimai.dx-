https://gemini.google.com/share/8a93f1871cf0

通过的代码：
```c
#include <bits/stdc++.h>

using namespace std;

  

int main(){

    #ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    #endif

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    int n, q;

    cin >> n >> q;

    vector<int> a(n+1);

  

    for (int i = 1; i <= n; i++){

        cin >> a[i];

    }

    vector<int> dp(a[n]), cnt(a[n]), presum(a[n]);//0---maxAn

  

    int max_money_paper_id = 1;

    for (int i = 1; i < a[n]; i++){

        if (max_money_paper_id + 1 <= n && a[max_money_paper_id+1] <= i) max_money_paper_id++;

        dp[i] = dp[i-a[max_money_paper_id]] + 1;

    }

  

    for (int i = 0; i < a[n]; i++){

        cnt[dp[i]]++;

    }

  

    presum[0] = cnt[0] = 1;

    for (int i = 1; i < a[n]; i++){

        presum[i] = presum[i-1] + cnt[i];

    }

  

    while (q--){

        int m; cin >> m;

        if (m >= a[n]) cout << presum[a[n]-1] << ' ';

        else cout << presum[m] << ' ';

    }

    return 0;

}
```