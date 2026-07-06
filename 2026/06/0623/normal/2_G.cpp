#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int L, V, T;
        int s;
        cin >> L >> V >> T;
        s = V*T;
        int p1 = s, p2 = L-s;
        int p0 = (p1-p2)/2 + p2;
        int ans = max(abs(p1-p0), abs(p2-p0));
        cout << ans << "\n";
    }
    return 0;
}