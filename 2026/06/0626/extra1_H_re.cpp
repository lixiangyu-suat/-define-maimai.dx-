#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
bool vis[N][N];
int x[N], y[N], tx[N], ty[N];
int n, xc, yc;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(vis, false, sizeof(vis));
    cin >> n;
    xc = yc = n*2;

    for (int i = 0; i < n; i++){
        cin >> x[i*2] >> y[i*2] >> x[i*2+1] >> y[i*2+1];
        tx[i*2] = x[i*2]; tx[i*2+1] = x[i*2+1];
        ty[i*2] = y[i*2]; ty[i*2+1] = y[i*2+1];
    }
    sort(tx, tx+xc);
    xc = unique(tx, tx+xc) - tx;
    sort(ty, ty+yc);
    yc = unique(ty, ty+yc) - ty;

    int x1, y1, x2, y2;
    for (int i = 0; i < n; i++){
        x1 = lower_bound(tx, tx+xc, x[i*2]) - tx;
        y1 = lower_bound(ty, ty+yc, y[i*2]) - ty;
        x2 = lower_bound(tx, tx+xc, x[i*2+1]) - tx;
        y2 = lower_bound(ty, ty+yc, y[i*2+1]) - ty;
        for (int x = x1; x < x2; x++){
            for (int y = y2; y < y1; y++){
                vis[x][y] = true;
            }
        }
    }

    long long sum = 0;
    for (int x = 0; x < xc-1; x++){ //tx[0.....xc-1]
        for (int y = 0; y < yc-1; y++){
            if (vis[x][y]){
                sum += 1LL * (tx[x+1] - tx[x]) * (ty[y+1] - ty[y]);
            }
        }
    }
    cout << sum;

    return 0;
}