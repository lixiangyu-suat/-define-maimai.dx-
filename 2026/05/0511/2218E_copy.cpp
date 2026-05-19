#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 线性基模板
 * 用于处理异或相关的最大值、存在性等问题
 */
struct LinearBasis {
    long long basis[31]; // 题目 a_i <= 10^9，30位足够，31保险

    LinearBasis() {
        for (int i = 0; i < 31; ++i) basis[i] = 0;
    }

    void insert(long long x) {
        for (int i = 30; i >= 0; --i) {
            if (!(x >> i)) continue;
            if (!basis[i]) {
                basis[i] = x;
                return;
            }
            x ^= basis[i];
        }
    }

    long long queryMax() {
        long long res = 0;
        for (int i = 30; i >= 0; --i) {
            if ((res ^ basis[i]) > res) {
                res ^= basis[i];
            }
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    LinearBasis lb;
    long long total_xor = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_xor ^= a[i];
        lb.insert(a[i]);
    }

    // 根据题目操作逻辑，最终结果最大值即为线性基能张成的空间中的最大值
    // 特殊情况：如果所有数异或和为0且n为2，结果只能是0
    cout << lb.queryMax() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}