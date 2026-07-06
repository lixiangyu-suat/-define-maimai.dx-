#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int K = 16;
int n, m;

int vis[K+1];
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

void dfs(int k, int step){
    if (step == k){
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < k; i++){
            cnt[ball[i+1][vis[i]]]++;
        }
        ans = max(ans, judge_cnt());
        return;
    }
    vis[step] = 1;
    dfs(k, step+1);
    vis[step] = 0;
    dfs(k, step+1);
}

int main(){
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
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));

    dfs(k, 0);

    cout << ans;
    return 0;
}