#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int T; cin >> T;

    while (T--){
        unordered_map<string, int> cnt;
        unordered_map<string, int> pd;
        unordered_map<string, bool> passed;
        int n, a, b; cin >> n >> a >> b;
        int s; cin >> s;
        int penalty = 0;
        int passcnt = 0;
        while (s--){
            int t; string question; string state;
            cin >> t >> question >> state;
            if (state == "ac" && !passed[question]) {
                penalty += 20 * cnt[question] + t;
                passcnt++;
                passed[question] = 1;
            }
            else if (state == "rj" && !passed[question]) {
                cnt[question]++;
            }
            else if (state == "pd" && !passed[question] && !pd.count(question)) {
                pd[question] = t;
            }
        }
        if (pd.size() + passcnt < a) cout << -1 << endl;
        
        else if (pd.size() + passcnt == a) {

            for(auto&[i, j] : pd) penalty += cnt[i] *20 + j;
            if (penalty >= b) cout << -1 << endl;
            else cout << pd.size() << endl;
        }
        else {
            vector<int>p;
            for(auto&[i, j] : pd) {
                p.push_back(20*cnt[i] + j);
            }
            sort(p.begin(), p.end());
            int diff = a - passcnt;
            for(int i = 0; i < p.size(); i++){
                if (i < diff) penalty += p[i];
                else{
                    if (penalty >= b) diff++;
                    break;
                }
            }
            if (diff < 0) diff = 0;
            cout << diff << endl;
        }

    }
}