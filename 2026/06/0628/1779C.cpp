#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int a[N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--){
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        // m....2
        priority_queue<int> pq; //前序列暂时未被使用的num
        long long s = 0;
        int cnt = 0;

        for (int i = m; i >= 2; i--){
            s += a[i]; //s至少add每一个num
            if (a[i] > 0){
                pq.push(a[i]);
            }
            if (s > 0){
                long long t = pq.top();
                pq.pop();
                s -= 2*t;
                cnt++;
            }
        }

        // m....n
        while (!pq.empty()) pq.pop();
        s = 0;
        for (int i = m+1; i <= n; i++) a[i] = -a[i]; //取反方便pq使用
        for (int i = m+1; i <= n; i++){
            s += a[i];
            if (a[i] > 0){
                pq.push(a[i]);
            }
            if (s > 0){
                long long t = pq.top();
                pq.pop();
                s -= 2*t;
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}