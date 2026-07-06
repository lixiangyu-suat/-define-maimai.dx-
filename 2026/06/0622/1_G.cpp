#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int main(){
    int n, x; cin >> n >> x;
    for (int i = 1; i <= n; i++){
        int t = i;
        while (t){
            int u = t % 10;
            if (x == u) cnt++;
            t /= 10;
        }
    }
    cout << cnt;
    return 0;
}