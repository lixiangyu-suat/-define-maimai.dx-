#include <bits/stdc++.h>
using namespace std;

const int N = 102;
int maxdp[N][N]; //从下标i开始，延申长度n的代价
int mindp[N][N];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int n; cin >> n;
    memset(maxdp, 0, sizeof(maxdp));
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            mindp[i][j] = 0x3f3f3f3f;
        }
    }

    for (int i = 1; i <= n; i++){
        cin >> maxdp[i][1];
        mindp[i][1] = maxdp[i][1];
    }

    for (int len = 2; len <= n; len++){
        for (int i = 1; i <= n; i++){
            for (int k = 1; k <= len-1; k++){
                int j = i+k; //(i+k-1) + 1
                int nj = (j <= n) ? j : (j%n);
                int l = (k == 1) ? 1 : 2;
                int r = (len-k == 1) ? 1 : 2;
                maxdp[i][len] = max(maxdp[i][len], l*maxdp[i][k] + r*maxdp[nj][len-k]);
                mindp[i][len] = min(mindp[i][len], l*mindp[i][k] + r*mindp[nj][len-k]);
            }
        }
    }
    int maxans = 0, minans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++){
        maxans = max(maxans, maxdp[i][n]);
        minans = min(minans, mindp[i][n]);
    }
    cout << minans << '\n' << maxans;
    return 0;
}