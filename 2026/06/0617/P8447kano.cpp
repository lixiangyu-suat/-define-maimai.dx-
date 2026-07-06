#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
using namespace std;
#define int long long

 
void dfs(int rem, int &ans, int cnt, int M) {
    if (rem == 0) {
        ans = min(cnt, ans);
        return;
    }
    if (cnt >= ans) {
        return;
    }
    M = min((int)sqrt(rem), M);
    if (M == 0) return;
    if (M == 1) {
        ans = min(ans, cnt+rem);
        return;
    }
    int minus = M * M;
    int max_k = rem / minus;
    int next_m = M - 1;
    int next_minus = next_m * next_m;
    
    for (int k = max_k; k >= 0; --k) {
        int next_rem = rem - k * minus;
        int min_add = (next_rem + next_minus - 1) / next_minus;
        
        if (cnt + k + min_add >= ans) {
            break; 
        }
        dfs(next_rem, ans, cnt + k, next_m);
    }
}

void write(int x) {
    if (x > 9) write(x/10);
    putchar(x%10+'0');
}

inline int read(){
    int x = 0;
    char ch = getchar();
    while(ch <'0' || ch > '9') ch = getchar();
    while(ch>= '0'&& ch <= '9') {
        x = (x<<3) +(x<< 1)+(ch^48);
        ch = getchar();
    }
    return x;
}

signed main() {
    int t = read();
    while(t--) {
        int M = read(), q = read();
        while(q--) {
            int ans;
            int n = read();
            if (M * M >= n) ans = 4;
            else ans = n/(M*M) + 5;
            dfs(n, ans, 0, M);
            write(ans);
            printf("\n");
        }
    }
}