#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> s(n+1);

    int t;
    for (int i = 1; i <= n; i++){
        cin >> t;
        s[i] = s[i-1] + t;
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        cout << (s[r]-s[l-1]) << "\n";
    }
    return 0;
}