#include <bits/stdc++.h>
using namespace std;
#define int long long

// 快速计算 10 的幂
int pow10_val(int p) {
    int res = 1;
    for (int i = 0; i < p; i++) res *= 10;
    return res;
}

// 获取数字的位数
int get_len(int x) {
    if (x == 0) return 1;
    int len = 0;
    while (x) {
        len++;
        x /= 10;
    }
    return len;
}

// 检查并获取情况一中生成的 d
// L 为总长度，len_m 为 m 的长，m 为月份
int get_case1_day(int m, int len_m, int L) {
    string sm = to_string(m);
    // 构造长度为 L 的回文数
    // 前缀是 sm，我们需要把它补全到长度 L
    string palind = sm;
    int half = (L + 1) / 2;
    
    // 如果 m 的长度不够前半部分，说明在情况一的边界之外（其实情况一限制了 L <= 2*len_m，所以 sm 长度一定够前半部分）
    if (sm.length() < half) return -1; 
    
    // 补全后半部分：后半部分等于前半部分的翻转
    string front_part = sm.substr(0, half);
    string back_part = front_part;
    reverse(back_part.begin(), back_part.end());
    
    // 根据奇偶性拼接
    if (L % 2 == 1) {
        palind = front_part + back_part.substr(1);
    } else {
        palind = front_part + back_part;
    }
    
    // 检查构造出来的回文数是否依然以 m 开头（防止高位不匹配）
    if (palind.substr(0, len_m) != sm) return -1;
    
    // 提取 d：后 L - len_m 位
    int len_d = L - len_m;
    string sd = palind.substr(len_m);
    
    // 检查是否有前导 0 导致位数改变
    if (sd[0] == '0') return -1; 
    
    return stoll(sd);
}

void solve() {
    int n; 
    if (!(cin >> n)) return;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    int total_ans = 0;
    
    for (int i = 1; i <= n; i++) {
        int m = i;
        int len_m = get_len(m);
        int max_a = a[i];
        
        // ---- 情况一：len_d <= len_m ----
        for (int len_d = 1; len_d <= min(len_m, max_a); len_d++) {
            int L = len_m + len_d;
            int d = get_case1_day(m, len_m, L);
            if (d >= 1 && d <= pow10_val(max_a) - 1) {
                total_ans++;
            }
        }
        
        // ---- 情况二：len_d > len_m ----
        // 此时 len_d 的范围是 [len_m + 1, max_a]
        for (int len_d = len_m + 1; len_d <= max_a; len_d++) {
            int L = len_m + len_d;
            int half = (L + 1) / 2;
            int k = half - len_m;
            if (k >= 0) {
                total_ans += pow10_val(k);
            }
        }
    }
    
    cout << total_ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T, c;
    if (cin >> T >> c) {
        while (T--) {
            solve();
        }
    }
    return 0;
}