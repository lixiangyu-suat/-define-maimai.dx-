#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int dp[N][2], a[N];
int main(){
    int n;
    while (true){
        cin >> n;
        if (n == 0) return 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        memset(dp, 0x3f, sizeof(dp));

        dp[1][1] = dp[1][0] = 1;
        for (int i = 2; i <= n; i++){
            if (a[i] >= a[i-1]){
                dp[i][1] = min(dp[i-1][0]+1, dp[i-1][1]);
            }
            else{
                dp[i][1] = min(dp[i-1][0], dp[i-1][1]+1);
            }
        }
    }
    return 0;
}