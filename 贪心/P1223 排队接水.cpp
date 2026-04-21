// 用数学思维求前缀和更快

#include <bits/stdc++.h>
using namespace std;
#define int long long

struct p{
    int id;
    int t;
};


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<p> a;
    vector<int> pre(n, 0);
    a.reserve(n);
    int sum = 0;
    for(int i = 1; i <= n; ++i){
        int k; cin >> k;
        a.push_back({i, k});
    }
    sort(a.begin(), a.end(), [&](p p1, p p2)
        {
            if (p1.t != p2.t) return p1.t < p2.t;
            else return p1.id < p2.id;
        }
    );
    for(int i = 1; i < n; ++i) {
        pre[i] = pre[i-1] + a[i-1].t;
    }
    for(auto& i: pre) sum += i;
    for(auto& i: a) cout << i.id << " ";
    cout << endl << fixed << setprecision(2) << (double)sum/n << endl;
}
