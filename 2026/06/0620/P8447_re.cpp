#include <bits/stdc++.h>
using namespace std;
#define int long long

int cnt;
const int MAXM2 = 2.5e5;

void dfs(int cur, int m, int step){
    if (cur <= 0){
        if (step < cnt) cnt = step;
        return;
    }

    m = min((long long)m, (long long)sqrtl(cur));

    int m2 = m*m;
    int div = cur / (m2); //m2:当前贪心的最大数^2
    if (m2 == 1){
        dfs(0, 0, step+div); //用完这么多个
    }
    else{
        for (int j = div; j >= 0; j--){ //搜索，贪心j个
            int nxt = cur-j*m2;

            if (nxt != 0){
                int nxtstep = (nxt-1) / ((m-1)*(m-1)) + 1;
                if (step + j + nxtstep >= cnt) break;

                int nxt_m = min(m-1, (int)sqrt(nxt));
                int nxt_m2 = nxt_m*nxt_m;
                nxtstep = (nxt-1) / nxt_m2 + 1;
                if (step + j + nxtstep >= cnt) continue;
            }
            
            dfs(nxt, m-1, step+j);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while (T--){
        int m, Q;
        cin >> m >> Q;
        int m2 = m*m;

        while (Q--){
            int n;
            cin >> n;

            cnt = n / (m2) + 4;
            dfs(n, m, 0);
            cout << cnt << "\n";
        }
    }
}