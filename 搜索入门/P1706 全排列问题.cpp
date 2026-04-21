#include <bits/stdc++.h>
using namespace std;

vector<bool> vis(10, 0);
vector<int> ans;
int n;

void dfs() {
    if (ans.size() == n) {
        for (int x : ans) {
            cout << setw(5) << x;
        }
        cout << "\n";
        return;
    }
    
    for(int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            vis[i] = 1;
            ans.push_back(i);
            dfs(); // 继续向下搜索
            vis[i] = 0; // 回溯
            ans.pop_back(); // 回溯
        }
    }
}

int main() {
    cin >> n;
    dfs(); 
    return 0;
}


// 可以使用stl
void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1); 

    do {
        for (int x : ans) {
            cout << setw(5) << x;
        }
        cout << "\n";
    } while (next_permutation(ans.begin(), ans.end()));
}