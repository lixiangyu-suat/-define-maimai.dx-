#include <bits/stdc++.h>
using namespace std;

const int N = 505, M = 505;

int a[N][M];
int g[N][M]; //容量为 j 的时候，第i个公司得到的机器数量
int dp[M];//（前i个公司）在机器数量为j的时候的最优生产力
int sum[N][M];

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    memset(a, 0, sizeof(a));
    memset(sum, 0, sizeof(sum));
    
    int n, m; //公司数量为n
    cin >> m >> n;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    sum[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = m; j >= 1; j--){ //j：容量m0
            g[i][j] = 0;
            for (int k = j; k >= 0; k--){
                int olddp = dp[j];
                if (dp[j] < dp[j-k] + a[i][k]){
                    dp[j] = dp[j-k] + a[i][k];
                    g[i][j] = k;
                }
                if (olddp == dp[j-k] + a[i][k]){
                    sum[i][j] += sum[i-1][j-k];
                }else if(dp[j] == dp[j-k] + a[i][k]){
                    sum[i][j] = sum[i-1][j-k];
                }
            }
        }
    }
    cout << dp[m] << endl;
    cout << "sum:" << endl;

    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++){
            cout << sum[i][j] << ' ';
        }
        cout << endl;
    }
    int idx = n;
    int v = m;

    vector<int> ans(n+1);
    while (idx > 0){
        ans[idx] = g[idx][v];
        v -= g[idx][v];
        idx--;
    }
    for (int i = 1; i <= n; i++){
        printf("id : %d  num : %d\n", i, ans[i]);
    }
    return 0;

}
