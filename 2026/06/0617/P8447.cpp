#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 250000;
const int M = 500;
int cnt[N+1];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("out.txt", "w", stdout);
    #endif

    memset(cnt, 0x3f, sizeof(cnt));

    int T; cin >> T;

    while (T--){
        int m, q, x;
        cin >> m >> q;
        int m2 = m*m;

        cnt[1] = 1;
        cnt[0] = 0;
        for (int i = 2; i <= m2; i++){
            for (int j = 1; j * j <= i; j++){
                cnt[i] = min(cnt[i], cnt[i-j*j] + 1);
            }
        }

        for (int i = 0; i < q; i++){
            cin >> x;
            int op1 = x / m2;
            x = x - op1 * m2;
            int op2 = cnt[x];
            cout << (op1 + op2) << "\n";
            //cout.flush();
        }
    }
    return 0;
}