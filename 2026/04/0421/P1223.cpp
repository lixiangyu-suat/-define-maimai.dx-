#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[1005];
int main(){
    # ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    # endif
    long long n, tot = 0; cin >> n;
    for (int id = 1; id <= n; id++) {
        cin >> a[id].first;
        a[id].second = id;
    }
    sort(a+1, a+n+1, [&](pair<int, int> l, pair<int, int> r){
        if (l.first == r.first) return l.second < r.second;
        return l.first < r.first;
    });
    for (int id = 1; id <= n; id++) {
        cout << a[id].second << ' ';
        tot += a[id].first*(n-id);
    }
    printf("\n%.2f", ((double)tot/n));
    return 0;
}