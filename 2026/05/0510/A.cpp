#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+5, M = 11;

int matrix[N][M];
int row_sum[N], col_sum[M];
int n, m, a, b;
int _return_max_row(int r){
    int res = m* a * r;
    res += (b * (m+1) *m) /2;
    return res;
}

int _return_max_col(int c) {
    int res = n* b * c;
    res += (a*(n+1) * n) /2;
    return res;
}

signed main(){

    cin >> n >> m >> a >> b;
    for (int i = 1; i <= n; i++){
        string s; cin >> s;
        for (int j = 1; j <= m; j++){
            matrix[i][j] = s[j-1] - '0';
            row_sum[i] += matrix[i][j] * (a*i + b*j);
            col_sum[j] += matrix[i][j] * (a*i + b*j);
        }
    }
    // cout << row_sum[1] << " " << col_sum[2] << " " << _return_max_col(1);
    for(int r = 1; r <= n; ++r) {
        for(int c = 1; c <= m; ++c){
            int cur = matrix[r][c]*(a * r + b * c);
            int cur_flip = (!matrix[r][c]) * (a * r + b * c);
            int max1 = row_sum[r] + col_sum[c] - cur;
            int max2 = _return_max_row(r) - row_sum[r] + col_sum[c] - cur;
            int max3 = _return_max_col(c) - col_sum[c] + row_sum[r] - cur;
            int max4 = _return_max_col(c) - col_sum[c] + _return_max_row(r) - row_sum[r] - cur_flip;
            int mx = max(max(max1,max4), max(max2,max3));
            if (mx == max1) continue;
            else if (mx == max2) {
                row_sum[r] = _return_max_row(r) - row_sum[r];
                col_sum[c] = col_sum[c] - cur + cur_flip;
            }
            else if (mx == max3) {
                col_sum[c] = _return_max_row(c) - col_sum[c];
                row_sum[r] = row_sum[r] - cur + cur_flip;
            }
            else if (mx == max4) {
                row_sum[r] = _return_max_row(r) - row_sum[r] - cur_flip + cur;
                col_sum[c] = _return_max_col(c) - col_sum[c] - cur_flip + cur;
            }
        }
    }
    int ans = 0;
    for(int c = 1; c <= m; ++c) {
        ans += col_sum[c];
    }
    cout << ans << "\n";
}