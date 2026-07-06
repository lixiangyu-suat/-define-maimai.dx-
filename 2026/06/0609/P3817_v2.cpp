#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int l, r;
    map<int, int> a; // r-> maxl
    for (int i = 0; i < n; i++){
        cin >> l >> r;
        a[r] = max(a[r], l);
    }
    int latest = 0;
    int sum = 0;
    for (auto [r, l] : a){
        if (latest <= l){
            sum++;
            latest = r;
        }
    }
    cout << sum;
    return 0;
}