#include <bits/stdc++.h>
using namespace std;

int pos[105];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i = 0; i < n; i++){
            cin >> pos[i];
        }
        sort(pos, pos+n);
        int mid = pos[n/2];
        int l_cnt = 0, r_cnt = 0;
        int idx = 0;
        while (pos[idx] != mid){
            l_cnt++;
            idx++;
        }
        idx = n-1;
        while (pos[idx] != mid){
            r_cnt++;
            idx--;
        }
        cout << max(l_cnt, r_cnt) << "\n";
    }
    return 0;
}