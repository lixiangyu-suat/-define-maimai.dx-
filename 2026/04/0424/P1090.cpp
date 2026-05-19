#include <bits/stdc++.h>
using namespace std;

map<int, int> cnt;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int n; cin >> n;
    int t;
    for (int i = 0; i < n; i++){
        cin >> t;
        cnt[t]++;
    }

    int sum = 0;
    int mergetimes = 0;
    for (auto it = cnt.begin(); ;){
        if (mergetimes + 1 == n) break;
        auto [x, c] = *it;
        //cout << x << ' ' << c << endl;

        if (c >= 2){
            sum += (x*(c/2*2));

            cnt[x*2]+=c/2; //merge
            mergetimes += c/2;
        }
        if (c%2 == 1){
            mergetimes++;
            it = cnt.erase(it);
            //++it;

            auto& [nx, nc] = *it;
            //cout << "nxt: " << nx << ' ' << nc << endl;

            sum += (x + nx);
            cnt[x+nx]++;

            nc--;
        }else{

            it = cnt.erase(it);
        }
        //cout << "sum = " << sum << endl << endl;
    }
    cout << sum;
    return 0;
}