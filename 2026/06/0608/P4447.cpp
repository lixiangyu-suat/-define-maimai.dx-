#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int t;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> t;
        cnt[t]++;
    }
    int maxcnt = INT_MAX, cur = 0;

    while (true){
        bool clear = true;
        for (auto it = cnt.begin(); it != cnt.end(); it++){
            auto& [id, c] = *it;
            if (c == 0) continue;
            else if ( it!=cnt.begin() && ((*it).second > (*(--it)).second) + 1){
                cur++;
                c--;
                maxcnt = min(maxcnt, cur);
                cur = 0;
            }
            
            if (c > 1){
                c--;
                cur++;
                if ((++it) == cnt.end() || (*(++it)).second == 1) {
                    if (clear) clear = !clear;
                    if (cur > 0) maxcnt = min(maxcnt, cur);
                    cur = 0;
                    break;
                }
            }
            else{
                c--;
                cur++;
            }
            if (clear) clear = !clear;
        }
        if (cur > 0) maxcnt = min(maxcnt, cur);
        cur = 0;
        if (clear) break;
    }
    
    cout << maxcnt;
    return 0;
}