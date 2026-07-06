#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--){
        int n, k;
        cin >> n >> k;
        if (k == 1) {
            cout << "YES\n";
            continue;
        }
        int cnt = 2; // 本身和1必切换一次

        int i = 2;
        for (;i * i <= k; i++){
            if (k % i == 0) cnt += 1;
        }

        if (cnt%2) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}