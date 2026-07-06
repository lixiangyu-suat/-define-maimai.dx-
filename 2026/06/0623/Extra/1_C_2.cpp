#include <bits/stdc++.h>
using namespace std;

const int N = 121;
int s[N][N];

int main(){

    int n; cin >> n;
    int t, c;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> t;
            s[i][j] = t + s[i][j-1];
        }
    }

    int ans = INT_MIN;
    int maxc;
    for (int l = 1; l <= n; l++){
        for (int r = l; r <= n; r++){
            c = INT_MIN;
            maxc = INT_MIN;
            for (int i = 1; i <= n; i++){
                t = s[i][r]-s[i][l-1];
                c = (c > 0) ? (t+c) : t;
                maxc = max(c, maxc);
            }
            ans = max(ans, maxc);
        }
    }
    cout << ans;
    return 0;
}