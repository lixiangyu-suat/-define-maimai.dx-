#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;
long long a[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--){
        int n; cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int i = 2; i < n; i++){
            a[i+1] += a[i-1] - a[i];
            a[i] = a[i-1];
        }
        if (n%2 || a[n-1] <= a[n]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}