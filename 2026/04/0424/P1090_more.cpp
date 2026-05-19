#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> cnt(100005);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int n, t; cin >> n;
    ll sum = 0, val[2];

    queue<ll> q2;
    queue<int> q1;

    for (int i = 0; i < n; i++) {
        cin >> t;
        cnt[t]++;
    }
    for (int i = 0; i < 100005; i++){
        while (cnt[i]--) q1.push(i);
    }

    for (int i = 0; i < n-1; i++){
        for (int j = 0; j <= 1; j++){
            if (q2.empty() || (!q1.empty() && q1.front() < q2.front())){//q1更小，取q1的；
                val[j] = q1.front();
                q1.pop();
            }
            else{
                val[j] = q2.front();
                q2.pop();
            }
        }
        ll subsum = val[0] + val[1];
        sum += subsum;
        q2.push(subsum);
    }
    cout << sum;
    return 0;
}