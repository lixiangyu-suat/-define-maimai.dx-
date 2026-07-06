#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5+5;

vector<int> cnt(N);
ll val[2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    int t;

    queue<int> q1;
    queue<ll> q2;
    for (int i = 0; i < n; i++){
        cin >> t;
        cnt[t]++;
    }

    for (int i = 1; i < N; i++){
        while (cnt[i]--) q1.push(i);
    }

    ll sum = 0;
    for (int i = 1; i < n; i++){
        for (int j = 0; j <= 1; j++){
            //这种情况取q1（原队列） 的值
            if (q2.empty() || (!q1.empty() && q1.front() < q2.front())){
                val[j] = q1.front();
                q1.pop();
            }
            else {
                val[j] = q2.front();
                q2.pop();
            }
        }
        ll cost = val[0] + val[1];
        q2.push(cost); //大的加数相加一定更大，放在队尾
        sum += cost;
    }
    cout << sum;
    return 0;
}