#include <bits/stdc++.h>
using namespace std;

double dp[8][8]; //0 -- i的最小费用

int main(){
    double S, C, L, P;
    double dist = C * L; // 装满油能跑的最大距离

    fill(dp, dp+64, 1.0e8);
    int N;
    cin >> S >> C >> L >> P >> N;
    vector<int> sum(N+2);
    sum[N+1] = S;

    vector<int> nxt(N+2); //下个最省油钱的站，起始=0站
    vector<double> p(N+1);
    p[0] = P;
    for (int i = 1; i <= N; i++){
        int D, pi;
        cin >> D >> pi;
        sum[i] = D;
        p[i] = pi;
    }
    //判断有没有方案
    bool exsit_solu = true;
    for (int i = 1; i <= N+1; i++){
        if (dist < sum[i] - sum[i-1]){
            exsit_solu = false;
            break;
        } 
    }
    if (exsit_solu == false){
        cout << "No Solution";
        return 0;
    }

    for (int i = 0; i <= N; i++){
        dp[i][i] = (sum[i] - sum[i-1]) * p[i];
    }

    for (int k = 1; k <= N+1; k++){
        for (int i = 0; i+k <= N+1; i++){
            for (int j = i + 1; j <= N && j - i < k; j++){
                if (dist >= sum[j] - sum[i]) {
                    double greedy = 1.0e8;

                    if (dist >= sum[i+k]-sum[i]){
                        greedy = (sum[i+k]-sum[i]) / L * p[j];
                    }
                    else{
                        greedy = (C*p[j] + (sum[i+k]-sum[i]-dist) 
                    }
                    dp[i][i+k] = min(dp[i][k], dp[i][j-1] + dp[j][i+k], greedy);
                }
            }
        }
    }


}