#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, n, m, id;
    cin >> a >> n >> m >> id;

    vector<int> af(21), xf(21);
    af[1] = 1; xf[1] = 0;
    af[2] = 0; af[3] = 1;
    xf[2] = 1; xf[3] = 1;
    for (int i = 4; i <= 20; i++){
        af[i] = af[i-1] + af[i-2];
        xf[i] = xf[i-1] + xf[i-2];
    }

    if (id <= 2) cout << a;
    else if (id == n){
        cout << 0;
    }
    else{
        int a1 = 1, x1 = 0;
        int a2 = 1, x2 = 0;
        
        for (int i = 3; i <= id; i++){
            a1 += af[i-2]; x1 += xf[i-2];
        }
        for (int i = 3; i <= n-1; i++){
            a2 += af[i-2]; x2 += xf[i-2];
        }

        int y = (m-a2*a)/x2;
        int ans = a1*a + x1*y;
        cout << ans;
    }
    return 0;
}