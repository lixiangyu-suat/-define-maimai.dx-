// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1000005;
// int dp[N];
// bool search(int x, int m){
//     if (dp[x] != -1){
//         return (dp[x] == 1);
//     }
//     if (x == 0) {
//         return false;//没得拿了，输掉
//     }
//     for (int i = 1; i <= min(x, m); i++){
//         if (!search(x-i, m)){//这种情况下这个人可以赢
//             dp[x] = 1;
//             return true;
//         }
//     }
//     //遍历了所有情况都失败
//     dp[x] = 0;
//     return false;
// }
// int test(){
//     int n, m;
//     cin >> n >> m;

//     memset(dp, -1, sizeof(dp));

//     bool ans = search(n, m);
//     char man = ans ? 'A' : 'B';
//     cout << man << endl;
//     return 0;
// }

// int main(){
//     while (1) test();
    
// }


//动态规划ver.
/*
【游戏背景】有一堆数量为 $n$ 的石子。
【游戏规则】由两名玩家（通常为 A 和 B）轮流进行。
每人每次可以从这堆石子中取走 $[1, m]$ 个石子（即最少取 $1$ 个，最多取 $m$ 个）。
取走最后一个石子的人获胜（即无法移动的人输）。
【你的任务】给定石子总数 $n$ 和每次取子的上限 $m$，
假设两名玩家都足够聪明（均采取最优策略），判断先手（A）是否能获胜。
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<bool> dp;

int test(){
    int n, m;
    cin >> n >> m;
    dp.resize(n+1);

    for (int i = 1; i <= n; i++){
        if (i <= m) dp[i] = true;//dp[i] = true意味着在石子数量为i的时候，可以有方案使得让当前人获胜，反之让对方获胜。
        else {
            bool findans = false;
            for (int j = 1; j <= m; j++){
                if (!dp[i-j]) { //注意不是dp[i-j] == true,是false，因为i-j是当前人已经拿了之后，下一个状态。
                    findans = true;
                    break;
                }
            }
            dp[i] = findans;
        }
    }//这里的所有答案都从小的递推而来，而且转移涵盖了所有情况而且转移正确
    char man = dp[n] ? 'A' : 'B';
    cout << man << endl;
    return 0;
}

int main(){
    while (1) test();
    
}
