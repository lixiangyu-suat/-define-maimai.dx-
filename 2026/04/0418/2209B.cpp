#include <bits/stdc++.h>
using namespace std;

int a[5005];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int k; cin >> k;
        for (int j = 0; j < k; j++){
            cin >> a[j];
        }

        int less_aj, bigger_aj;
        for (int j = 0; j < k; j++){
            less_aj = 0, bigger_aj = 0;
            for (int u = j+1; u < k; u++){
                if (a[j] < a[u]) bigger_aj++;
                else if (a[j] > a[u]) less_aj++;
            }
            cout << max(less_aj, bigger_aj) << ' ';
        }
        cout << endl;
    }
    return 0;
}