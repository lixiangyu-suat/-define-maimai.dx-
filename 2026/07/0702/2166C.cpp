#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n;
int a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--){
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        long long s = 0;
        for (int i = 0; i < n-1; i++) s += max(a[i], a[i+1]);
        s += max(a[n-1], a[0]);
        
        s -= *max_element(a, a+n);
        cout << s << "\n";
    }
    return 0;
}