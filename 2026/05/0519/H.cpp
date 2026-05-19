#include <bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        int gold = 0, sil = 0;
        int used_sil = 0;
        bool dead = false;
        for (int i = 0; i < n; i++){
            int o, x; cin >> o >> x;
            if (o == 3){
                if ((x / k <= gold && x % k <= sil)){
                    gold -= (x / k);
                    sil -= (x % k);
                    used_sil += (x % k);
                }
                else if (x <= sil){
                    sil -= x;
                    used_sil += x;
                }
                else if (gold * k >= x){
                    gold -= (x / k + 1);
                }
                else {
                    cout << -1 << '\n';
                    dead = true;
                    break;
                }
            }
            else if (o == 1) gold += x;
            else sil += x;
        }
        if (!dead) cout << (sil + gold*k) << '\n';
        cout.flush();
    }
    return 0;
}