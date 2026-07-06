#include <bits/stdc++.h>
using namespace std;
#define int long long

int MOD = 998244353;

struct OP{
    bool x1 = false;
    bool x2 = false;
    bool x3 = false;
};
set<int> op1 = {1,3,5,7}, op2 = {2,3,6,7}, op3 = {4,5,6,7};

int n, m;
int tot = 0;
void dfs(vector<int>& A, vector<int>& B, int sum, int aidx, int bidx, int step, vector<OP>& o){
    if (step == m) {
        tot = (tot + sum) % MOD;
        return;
    }
    if (o[step].x1) {
        if (aidx < A.size()) dfs(A, B, (sum + A[aidx]) % MOD, aidx+1, bidx, step+1, o);
        else dfs(A, B, sum, aidx, bidx, step+1, o);
    }
    if (o[step].x2){
        if (aidx < A.size()) {
            int u = A[aidx];
            temp.push(u);
            dfs(A, B, sum, aidx+1, step+1, o);
        }
        else{
            dfs(A, B, sum, aidx, step+1, o);
        }
    }
    if (o[step].x3) {
        stack<int> temp = B;
        if (temp.empty()) dfs(A, B, sum, aidx, step+1, o);
        else {
            int u = temp.top();
            temp.pop();
            dfs(A, temp, (sum + u) % MOD, aidx, step+1, o);
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T, c;
    cin >> T >> c;
    while (T--){
        
        cin >> n >> m;
        vector<int> A(n);
        vector<OP> o(m);
        for (int i = 0; i < n; i++){
            cin >> A[i];
        }
        for (int i = 0; i < m; i++){
            int temp; cin >> temp;
            if (op1.find(temp) != op1.end()) o[i].x1 = true;
            if (op2.find(temp) != op2.end()) o[i].x2 = true;
            if (op3.find(temp) != op3.end()) o[i].x3 = true;
        }

        vector<int> B(n);
        dfs(A, B, 0, 0, 0, 0, o);
        cout << tot << endl;
    }
    return 0;
}