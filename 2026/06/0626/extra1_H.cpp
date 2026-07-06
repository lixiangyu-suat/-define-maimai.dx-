#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int vis[N][N];
int x[N], y[N], t[N*2];
int n, m;

int link(int x){
    return lower_bound(t, t+m, x) - t;
}

void f(int x1, int y1, int x2, int y2){
    if (x1 == x2 || y1 == y2) return;
    for (int i = x1; i <= x2; i++){
        for (int j = y1; j <= y2; j++){
            if (!vis[i][j]) vis[i][j] = 1;
        }
    }
}

long long cnt(){
    long long sum = 0;
    long long s;
    for (int i = 0; i < m-1; i++){
        for (int j = 0; j < m-1; j++){
            if (vis[i][j] && vis[i+1][j] && vis[i][j+1] && vis[i+1][j+1]){
                s = (t[j+1] - t[j]) * (t[i+1] - t[i]);
                sum += s;
            }
        }
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(vis, 0, sizeof(vis));
    cin >> n;

    int x1, x2, y1, y2;
    for (int i = 0; i < n; i++){
        cin >> x[i*2] >> y[i*2] >> x[i*2+1] >> y[i*2+1];
    }

    for (int i = 0; i < n*2; i++){
        t[i] = x[i];
    }
    for (int i = 0; i < n*2; i++){
        t[i+n*2] = y[i];
    }
    sort(t, t+n*4);
    m = unique(t, t+n*4) - t;

    for (int i = 0; i < n; i++){
        x1 = x[i*2]; y1 = y[i*2];
        x2 = x[i*2+1]; y2 = y[i*2+1];
        f(link(x1), link(y1), link(x2), link(y2)); //fill
    }

    long long s = cnt();
    cout << s;

    return 0;
}