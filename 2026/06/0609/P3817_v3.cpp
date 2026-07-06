#include <bits/stdc++.h>
using namespace std;

struct I{
    int l;
    int r;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    int l, r;
    vector<I> a(n); // r-> maxl
    for (int i = 0; i < n; i++){
        cin >> l >> r;
        a[i] = {l, r};
    }
    sort(a.begin(), a.end(), [&](I& a, I& b){
        if (a.r == b.r) return a.l > b.l;
        return a.r < b.r;
    });

    int latest = 0;
    int sum = 0;
    for (auto [l, r] : a){
        if (latest <= l){
            sum++;
            latest = r;
        }
    }
    cout << sum;
    return 0;
}