#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;
int n;
long long a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--){
        cin >> n; //n >= 2
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 1; i < n-1; i++){
            a[i+1] += a[i-1] - a[i];
            a[i] = a[i-1];
        }
        if (a[n-1] >= a[n-2] || n%2) cout << "YES\n";
        else cout << "No\n";
    }

    return 0;
}