#include <bits/stdc++.h>
using namespace std;

const int N = 121;
int s[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int sum, u;
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++){
        sum = 0;
        for (int j = 1; j <= n; j++){
            cin >> u;
            sum += u;
            s[i][j] = s[i-1][j] + sum;
        }
    }

    for (int x1 = 1; x1 <= n; x1++){
        for (int y1 = 1; y1 <= n; y1++){
            for (int x2 = x1; x2 <= n; x2++){
                for (int y2 = y1; y2 <= n; y2++){
                    sum = s[x2][y2] + s[x1-1][y1-1] - s[x2][y1-1] - s[x1-1][y2];
                    ans = max(sum, ans);
                }
            }
        }
    }

    cout << ans;
    return 0;
}