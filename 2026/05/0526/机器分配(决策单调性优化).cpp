#include <bits/stdc++.h>
using namespace std;

const int N = 505, M = 505;

int a[N][M];
vector<int> olddp(M), newdp(M);

void solve(int t, int l, int r, int optL, int optR){
    if (l > r) return;
    int mid = (r-l)/2 + l;

    int maxVal = olddp[mid], best_opt = optL;
    for (int i = optL; i <= min(optR, mid); i++){
        if (maxVal < a[t][i] + olddp[mid-i]){
            maxVal = a[t][i] + olddp[mid-i];
            best_opt = i;
        }
    }

    newdp[mid] = maxVal; //记录中间容量的最优解
    solve(t, l, mid-1, optL, best_opt);
    solve(t, mid+1, r, best_opt, optR);//一定能保证mid=l....r都能访问过一次；
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    memset(a, 0, sizeof(a));
    
    int n, m; //公司数量为n
    cin >> m >> n;
    for (int k = 0; k < n; k++){
        for (int j = 1; j <= m; j++){
            cin >> a[k][j];
        }
    }

    for (int i = 0; i < n; i++){
        solve(i, 0, m, 0, m);
        swap(newdp, olddp);
    }
    cout << olddp[m];
    return 0;
}