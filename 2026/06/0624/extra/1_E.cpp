#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5005;
int a[N];
int col[N][N];

signed main(){
    memset(a, 0, sizeof(a));
    memset(col, 0, sizeof(col));
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x1, x2, y1, y2;
    cin >> n >> m;

    int x, y;
    for (int i = 0; i < m; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        col[y1][x1]++; col[y1][x2+1]--;
        col[y2+1][x1]--; col[y2+1][x2+1]++;
    }

    int sum = 0;
    for (int j = 1; j <= n; j++){
        int d = 0;
        for (int i = 1; i <= n; i++){
            d += col[j][i];
            a[i] = a[i] + d;
            sum += (i+j)^a[i];
        }
    }

    cout << sum;
    return 0;
}