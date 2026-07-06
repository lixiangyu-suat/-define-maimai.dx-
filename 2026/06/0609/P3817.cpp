#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    long long cnt = 0;
    for (int i = 1; i < n; i++){
        int c1 = a[i] + a[i-1] - x;
        if (c1 > 0) {
            if (a[i] >= c1){
                a[i] -= c1;
            }
            else {
                a[i-1] -= (c1-a[i]);
                a[i] = 0;
            }
            cnt += (long long)c1;
        }
    }
    cout << cnt;
    return 0;
}