#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

const int N = 505, M = 505;

int a[N][M];
int g[N][M]; //容量为 j 的时候，第i个公司得到的机器数量
int olddp[M];//（前i个公司）在机器数量为j的时候的最优生产力
int newdp[M];

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    memset(a, 0, sizeof(a));
    memset(olddp, 0, sizeof(olddp));
    
    int n, m; //公司数量为n
    cin >> m >> n;
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        memset(newdp, 0, sizeof(newdp));
        for (int j = 1; j <= m; j++){ //j：容量m0
            g[i][j] = 0;
            for (int k = j; k >= 0; k--){
                if (newdp[j] < olddp[j-k] + a[i][k]){
                    newdp[j] = olddp[j-k] + a[i][k];
                    g[i][j] = k;
                }
            }
        }
        swap(olddp, newdp);
    }
    cout << olddp[m] << endl;
    
    int idx = n-1;
    int v = m;

    vector<int> ans(m);
    while (idx >= 0){
        ans[idx] = g[idx][v];
        v -= g[idx][v];
        idx--;
    }
    for (auto t : ans){
        printf("id : %d  num : %d\n", t+1, ans[t]);
    }
    return 0;

}


/*

for (int i = 0; i < n; i++){
    for (int j = m; j >= 1; j--){ //j：容量m0；倒序遍历可以类似01背包问题，避免swap(old, newdp)
        for (int k = j; k >= 0; k--){
            dp[j] = max(dp[j], dp[j-k] + a[i][k]);
        }
    }
    swap(olddp, newdp);
}
    */