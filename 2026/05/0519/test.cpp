//线性dp例题3：顺序对齐
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    int premax = 0, olddp, leftup; //leftup:左上角的一个格子
    vector<int> colmax(m+1);
    vector<int> dp(m+1);//s1前i个字符与s2前j个字符产生一定匹配的时候，得出的最大值。
    //注意！！这时候可以视为把后面的n-i与m-j个字符全部遮盖掉，只考虑这个子问题。
    //求解这个子问题，需要【往后看】一步，用到以前的dp。

    for (int i = 1; i <= n; i++){
        leftup = dp[0];
        premax = 0;
        for (int j = 1; j <= m; j++){
            olddp = dp[j];
            dp[j] = max(leftup + ((s1[i-1] == s2[j-1]) ? 2 : 0), max(premax-1, colmax[j]-1));
            colmax[j] = max(colmax[j], dp[j]);
            premax = max(premax, dp[j]);
            leftup = olddp;
        }
    }
    
    //还是要输出所有dp里面最大的那一个max(max(alldp))
    return 0;
}