#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while (T--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n), s(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            cin >> s[i];
        }
        for (int i = 0; i < n; i++){
            if (i != 0) cout << ' ';

            int x1, x2;
            int y;
            int k = 1;
            x1 = a[i] / 250 * (250-s[i]);
            x2 = -50 * (k-1);
            y = 0.3 * a[i];
            if (x1 + x2 < m && y < m){
                cout << "0";
            }
            else if (y >= m){
                cout << "inf";
            }
            else{
                while (x1 + x2 >= m) {
                    k++;
                    x2 = -50 * (k-1);
                }
                cout << k-1;
            }
        }
        cout << endl;
    }
}