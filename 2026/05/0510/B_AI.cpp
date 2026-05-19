#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Node {
    int val;
    int type; // -1: 初始, 0: OR, 1: XOR, 2: AND
    int a_val, b_val;
};

struct Op {
    int t, a, b;
};

vector<Node> pool;
int basis[32];
long long combo[32]; // 记录 basis[i] 是由 pool 中哪些索引异或出来的
vector<Op> ans;
set<int> initial_s;

// 尝试将一个值插入线性基，mask 记录该值在 pool 中的来源组合
bool insert(int val, long long mask) {
    for (int i = 29; i >= 0; i--) {
        if (!(val >> i & 1)) continue;
        if (basis[i] == -1) {
            basis[i] = val;
            combo[i] = mask;
            return true;
        }
        val ^= basis[i];
        mask ^= combo[i];
    }
    return false;
}

// 检查 x 是否能被当前基底张成，返回 pool 索引的掩码
long long get_mask(int val) {
    long long mask = 0;
    for (int i = 29; i >= 0; i--) {
        if ((val >> i) & 1) {
            if (basis[i] == -1) return -1;
            val ^= basis[i];
            mask ^= combo[i];
        }
    }
    return (val == 0) ? mask : -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    for (int i = 0; i < 32; i++) basis[i] = -1;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        initial_s.insert(a);
        // 第一步：初步筛选，不计入操作次数
        if (insert(a, 1LL << pool.size())) {
            pool.push_back({a, -1, -1, -1});
        }
    }

    // 如果 x 已经在初始集合中
    if (initial_s.count(x)) {
        cout << 0 << endl;
        return 0;
    }

    // 第二步：通过 AND 扩张空间
    // 注意：pool 会在循环中动态增长，直到秩满或无法再增加
    for (int i = 0; i < (int)pool.size(); i++) {
        for (int j = 0; j <= i; j++) {
            int newVal = pool[i].val & pool[j].val;
            if (insert(newVal, 1LL << pool.size())) {
                ans.push_back({2, pool[i].val, pool[j].val});
                pool.push_back({newVal, 2, pool[i].val, pool[j].val});
                if (get_mask(x) != -1) goto synthesis;
            }
        }
    }

synthesis:
    long long final_mask = get_mask(x);
    if (final_mask == -1) {
        // 特殊处理 x = 0 的情况，如果 S 不为空且 x=0 不在 S 中
        if (x == 0 && !pool.empty()) {
            cout << 1 << endl;
            cout << "1 " << pool[0].val << " " << pool[0].val << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }

    // 第三步：利用最终掩码进行 XOR 合成
    vector<int> to_xor;
    for (int i = 0; i < (int)pool.size(); i++) {
        if ((final_mask >> i) & 1) to_xor.push_back(pool[i].val);
    }

    if (!to_xor.empty()) {
        int current = to_xor[0];
        vector<Op> xor_ops;
        for (int i = 1; i < (int)to_xor.size(); i++) {
            xor_ops.push_back({1, current, to_xor[i]});
            current ^= to_xor[i];
        }

        // 输出结果
        cout << ans.size() + xor_ops.size() << "\n";
        for (auto &o : ans) cout << o.t << " " << o.a << " " << o.b << "\n";
        for (auto &o : xor_ops) cout << o.t << " " << o.a << " " << o.b << "\n";
    }

    return 0;
}