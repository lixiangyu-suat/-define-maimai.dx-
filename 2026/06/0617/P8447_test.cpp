#include <bits/stdc++.h>
using namespace std;
#define int long long

int get_rand(int l, int r){
    // 如果想每次运行生成不同的数据，可以改成 chrono::steady_clock::now().time_since_epoch().count()
    static mt19937 f(1); 
    return uniform_int_distribution<int> (l, r) (f);
}

const int Q = 5e4;
const int X = 1e18;

signed main(){
    // 建议加上 cpp 的快读快写，生成大数据时会快很多
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("in.txt", "w", stdout);
    
    vector<int> M;
    int totm = 500;
    int max_T = 20; // 显式限制最大组数
    
    while (totm > 0){
        // 如果到了最后一组限制，把剩下的全部分配掉
        if (M.size() == max_T - 1) {
            M.push_back(totm);
            break;
        }
        int curm = get_rand(1, totm);
        totm -= curm;
        M.push_back(curm);
    }
    
    int T = M.size();
    cout << T << "\n"; // 用 "\n" 代替 endl 提升打表效率
    
    // 正序输出，符合正常的生成逻辑
    for (int i = 0; i < T; i++) {
        int m = M[i];
        int q = get_rand(1, Q);
        
        cout << m << ' ' << q << "\n"; // 修复了这里漏掉的换行
        for (int j = 0; j < q; j++){
            int x = get_rand(1, X);
            cout << x << '\n';
        }
    }
    return 0;
}