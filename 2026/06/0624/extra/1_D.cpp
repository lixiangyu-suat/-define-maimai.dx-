#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, p, x, y, z;
    cin >> n >> p;
    vector<int> a(n+1), d(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) d[i] = a[i] - a[i-1];
    for (int i = 1; i <= p; i++){
        cin >> x >> y >> z;
        d[x]+=z;
        if (y+1 <= n) d[y+1]-=z;
    }
    int minp = INT_MAX;
    int c = 0;
    for (int i = 1; i <= n; i++){
        c += d[i];
        minp = min(minp, c);
    }
    cout << minp;
    return 0;
}