#include <bits/stdc++.h>
using namespace std;

class Solution{
    int dx[8] = {-11, -9, -7, -3, 3, 7, 9, 11};
    int target = 0b1111101111000110000100000;
    bool found = false;

    int totstep = 1;
    const int MAXLIMIT = 15;

public:
    Solution() {};
    int dfs(int curr, int sp, int step, int last){
        if (step > totstep){
            return step;
        }
        if (curr == target) {
            found = true;
            return step;
        }

        for (int i = 0; i < 8; i++){
            int nxtsp = sp + dx[i]; int nxt = curr;
            int totstep1;
            if (nxtsp >= 0 && nxtsp < 25 && nxtsp != last){
                if ((curr & (1<<nxtsp)) == 0){//要交换的那一位==0
                    //等价于无需操作
                }else{
                    nxt = ((-1) ^ (1<<nxtsp)) & curr;//要交换的那一位  置为0
                }
                totstep1 = dfs(nxt, nxtsp, step+1, curr);
            }
            if (found) return totstep1;
        }
        return -1;
    }

    void solve(){
        int start = 0, space;
        for (int i = 0; i < 5; i++){
            string s;
            cin >> s;
            for (int j = 0; j < 5; j++){
                char c = s[j];
                if (c == '1') start = start * 2 + 1;
                else start <<= 1;
                if (c == '*') space = i*5 + j;
            }
        }

        while (totstep <= MAXLIMIT && !found){
            totstep = dfs(start, space, 0, -1);
        }
        if (found) cout << totstep << endl;
        else cout << -1 << endl;
    }
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int t; cin >> t;
    while (t--){
        Solution solution;
        solution.solve();
    }
    return 0;
}