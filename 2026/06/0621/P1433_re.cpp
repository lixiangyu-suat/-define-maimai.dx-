#include <bits/stdc++.h>
using namespace std;

const int N = 65536/2;
const int B = 15;
double dp[N][B+1]; //状态i，以j结尾的min d
double d[B+1][B+1];

int cntbit(int x){
    int res = 0;
    while (x){
        if (x&1) res++;
        x >>= 1;
    }
    return res;
}
int pow2(int n) {return 1 << n;}

int main(){
    fill(dp[0], dp[0] + N*(B+1), 1e9); //不是fill(dp, dp +...)
    for (int i = 0; i <= B; i++) dp[0][i] = 0;

    int n; cin >> n;
    vector<double> x(n+1), y(n+1);
    vector<vector<int>> bit(n+1);

    for (int i = 0; i < pow(2, n); i++) bit[cntbit(i)].push_back(i);

    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    for (int i = 0; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            d[j][i] = d[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
        }
    }

    for (int p = 1; p <= n; p++) dp[pow2(p-1)][p] = d[0][p]; //init

    for (int k = 2; k <= n; k++){ //1---n
        for (auto cur : bit[k]){
            //枚举cur的bits
            for (int j = 1; j <= n; j++){
                if (cur & pow2(j-1)){ //不是cur & (1<<j)) == 1
                    //枚举pre
                    int pre = (cur ^ pow2(j-1));
                    for (int i = 1; i <= n; i++) if ((pre & pow2(i-1))) dp[cur][j] = min(dp[cur][j], dp[pre][i] + d[i][j]);
                }
            }
            
        }
    }
    double ans = 1e9;
    int u = pow(2, n) - 1;
    for (int i = 1; i <= n; i++) ans = min(ans, dp[u][i]);
    printf("%.2f", ans);
    return 0;
}