#include <bits/stdc++.h>
using namespace std;

int lowbit(int x) {return x & -x;}

vector<int> c;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int n, m; cin >> n >> m;
    c.resize(n+1);

    int temp;
    for (int i = 1; i <= n; i++){
        cin >> temp;
        c[i] += temp;
        int j = i + lowbit(i);
        if (j <= n) c[j] += c[i];
    }

    int op, x, y, k;
    for (int q = 1; q <= m; q++){
        cin >> op;
        if (op == 1){
            cin >> x >> k;
            while (x <= n){
                c[x] += k;
                x += lowbit(x);
            }
        }else{
            cin >> x >> y;
            int sumx = 0, sumy = 0;
            for (int j = y; j > 0; j-=lowbit(j)) sumy += c[j]; //细节： > 0 不是>=0
            for (int j = x-1; j > 0; j-=lowbit(j)) sumx += c[j];
            cout << (sumy - sumx) << endl;
        }
    }
    return 0;
}