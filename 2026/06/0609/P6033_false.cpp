#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5+4;
vector<int> cnt(N);

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, t; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> t;
        cnt[t]++;
    }

    int times = n-1;
    int sum = 0;

    int idx = 1;
    int pre = -1;
    while (times){
        while (cnt[idx] == 0) idx++;

        if (pre != -1){
            int bonus = idx + pre;
            cnt[idx]--;
            cnt[bonus]++;
            sum += bonus;
            pre = -1;
            times--;
        }
        else if (cnt[idx] >= 2){ //不加else-> 因为pre而取完，导致在else部分cnt[idx]--至-1
            int t = cnt[idx] / 2;
            cnt[idx] = cnt[idx] & 1;
            sum += idx * t * 2;
            times -= t;
            cnt[idx*2] += t;
        }
        else{
            pre = idx;
            cnt[idx]--;
        }
    }

    cout << sum;
    return 0;
    
}