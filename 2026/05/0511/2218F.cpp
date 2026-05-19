#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        int x, y, n; cin >> x >> y;
        n = x + y;

        if (x > y) cout << "NO" << endl;
        else if (x == 0){
            if (y%2 == 1) {
                cout << "YES" << endl;
                for (int i = 2; i <= y; i++) cout << 1 << " " << i << endl;
            }
            else cout << "NO" << endl;
        }
        /*
        if (n/2 < x) cout << "NO"
        */
        else{
            cout << "YES" << endl;
            int idx = 1;
            while (idx < x*2){
                cout << idx++ << ' '<< idx << endl;
            }
            idx++;
            while (idx <= n) cout << 2 << ' ' << idx++ << endl;
        }
    }
    return 0;
}