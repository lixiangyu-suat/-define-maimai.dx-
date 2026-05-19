#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool search(ll x, ll y){
    return y >= 3*x;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" ,stdin);
    #endif
    
    int n; cin >> n;
    while (n--){
        ll x, y;
        cin >> x >> y;
        bool ok = search(x, y);
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}