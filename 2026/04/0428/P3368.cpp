#include <bits/stdc++.h>
using namespace std;

int lowbit(int x) {return x & -x;}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    int n, m; cin >> n >> m;
    vector<int> a(n+1), c(n+1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        int d = a[i]-a[i-1];
        c[i] += d;
        int j = i + lowbit(i);
        if (j <= n) c[j] += c[i];
    }

    int l, r, k;
    for (int q = 1; q <= m; q++){
        int op; cin >> op;
        if (op == 1){
            cin >> l >> r >> k;
            while (l <= n) {
                c[l] += k;
                l += lowbit(l);
            }
            int u = r+1;
            while (u <= n) {
                c[u] -= k;
                u += lowbit(u);
            }
        }else{
            cin >> k;
            int sum = 0;
            for (int j = k; j > 0; j-=lowbit(j)){
                sum += c[j];
            }
            cout << sum << endl;
        }
    }
    return 0;
}