#include <bits/stdc++.h>
using namespace std;

const int N = 505, M = 505;

int a[N][M];
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
            for (int k = j; k >= 0; k--){
                newdp[j] = max(newdp[j], olddp[k] + a[i][j-k]);
            }
        }
        swap(olddp, newdp);
    }
    cout << olddp[m];
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