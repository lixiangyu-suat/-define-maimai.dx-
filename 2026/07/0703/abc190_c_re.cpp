#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int K = 16;
int n, m;

int con[N][2];
int ball[K+1][2];
int cnt[N];
int ans = 0;

int judge_cnt(){
    int res = 0;
    for (int i = 1; i <= m; i++){
        if (cnt[con[i][0]] && cnt[con[i][1]]) res++;
    }
    return res;
}


int main(){
    memset(cnt, 0, sizeof(cnt));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> n >> m;

    for (int i = 1; i <= m; i++){
        cin >> con[i][0] >> con[i][1];
    }

    cin >> k;
    int maxbit = 2 << k;
    for (int i = 1; i <= k; i++){
        cin >> ball[i][0] >> ball[i][1];
    }

    for (int b = 0; b < maxbit; b++){
        int bit = b;
        for (int i = 1; i <= k; i++){
            cnt[ball[i][bit&1]]++;
            if (bit > 0) bit >>= 1;
        }
        ans = max(ans, judge_cnt());

        bit = b;
        for (int i = 1; i <= k; i++){
            cnt[ball[i][bit&1]]--;
            if (bit > 0) bit >>= 1;
        }
    }

    cout << ans;
    return 0;
}