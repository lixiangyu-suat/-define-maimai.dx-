#include <bits/stdc++.h>
using namespace std;
#define pow2(n) (1<<(n))

const int N = 65536/2;
const int B = 15;
double dp[N][B+1]; //状态i，以j结尾的min d
double d[B+1][B+1];
double x[B+1], y[B+1];

int main(){
    fill(dp[0], dp[0] + N*(B+1), 1e9); 
    for (int i = 0; i <= B; i++) dp[0][i] = 0;

    int n; cin >> n; 

    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    for (int i = 0; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            d[j][i] = d[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
        }
    }

    for (int i = 1; i <= n; i++) dp[pow2(i-1)][i] = d[0][i];
    for (int cur = 1; cur < pow2(n); cur++){ 
        //枚举cur的bits
        int temp = cur;
        while (temp){
            int j = __builtin_ctz(temp)+1;
            int pre = (cur ^ pow2(j-1));
            int temppre = pre;
            while (temppre){
                int i = __builtin_ctz(temppre)+1;
                dp[cur][j] = min(dp[cur][j], dp[pre][i] + d[i][j]);
                temppre &= (temppre-1);
            }
            temp &= (temp-1);
        }
    }
    double ans = 1e9;
    int u = pow2(n)-1;
    for (int i = 1; i <= n; i++) ans = min(ans, dp[u][i]);
    printf("%.2f", ans);
    return 0;
}