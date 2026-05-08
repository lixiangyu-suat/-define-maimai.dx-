#include <bits/stdc++.h>
using namespace std;

//发现v1版本不利于扩展更多变量，于是让AI重构函数；

struct Node {
    long long val;  // 区间和 (原 d)
    long long mx;   // 区间最大值
    long long add;  // 加法懒标记 (原 la)
    long long cov;  // 覆盖标记 (原 v/ischangedvalue)
    bool hasCov;    // 是否有覆盖操作的标识

    Node() : val(0), mx(0), add(0), cov(0), hasCov(false) {}
};

class SegmentTree {
    vector<Node> tree;
    int n;

    // 抽离 PushUp：子节点贡献父节点
    void pushUp(int p) {
        tree[p].val = tree[p << 1].val + tree[p << 1 | 1].val;
        tree[p].mx = max(tree[p << 1].mx, tree[p << 1 | 1].mx);
    }

    // 抽离 PushDown：标记下传
    void pushDown(int p, int s, int t) {
        int mid = s + ((t - s) >> 1);
        
        // 优先级 1: 覆盖标记 (覆盖会覆盖掉之前的加法)
        if (tree[p].hasCov) {
            updateNodeCov(p << 1, s, mid, tree[p].cov);
            updateNodeCov(p << 1 | 1, mid + 1, t, tree[p].cov);
            tree[p].hasCov = false;
            tree[p].cov = 0;
        }
        
        // 优先级 2: 加法标记
        if (tree[p].add) {
            updateNodeAdd(p << 1, s, mid, tree[p].add);
            updateNodeAdd(p << 1 | 1, mid + 1, t, tree[p].add);
            tree[p].add = 0;
        }
    }

    // 辅助函数：更新单个节点的覆盖信息
    void updateNodeCov(int p, int s, int t, long long c) {
        tree[p].val = (t - s + 1) * c;
        tree[p].mx = c;
        tree[p].cov = c;
        tree[p].hasCov = true;
        tree[p].add = 0; // 覆盖后，之前的加法标记失效
    }

    // 辅助函数：更新单个节点的加法信息
    void updateNodeAdd(int p, int s, int t, long long c) {
        tree[p].val += (long long)(t - s + 1) * c;
        tree[p].mx += c;
        tree[p].add += c;
    }

public:
    SegmentTree(int n0) : n(n0) {
        tree.resize(n0 * 4);
    }

    void build(const vector<int>& a, int s, int t, int p) {
        if (s == t) {
            tree[p].val = a[s];
            tree[p].mx = a[s];
            return;
        }
        int mid = s + ((t - s) >> 1);
        build(a, s, mid, p << 1);
        build(a, mid + 1, t, p << 1 | 1);
        pushUp(p);
    }

    // 区间加法
    void updateAdd(int l, int r, int c, int s, int t, int p) {
        if (l <= s && t <= r) {
            updateNodeAdd(p, s, t, c);
            return;
        }
        pushDown(p, s, t);
        int mid = s + ((t - s) >> 1);
        if (l <= mid) updateAdd(l, r, c, s, mid, p << 1);
        if (r > mid) updateAdd(l, r, c, mid + 1, t, p << 1 | 1);
        pushUp(p);
    }

    // 区间查询：这里返回一个 Node 以同时获取和与最值
    pair<long long, long long> query(int l, int r, int s, int t, int p) {
        if (l <= s && t <= r) return {tree[p].val, tree[p].mx};
        pushDown(p, s, t);
        int mid = s + ((t - s) >> 1);
        long long sum = 0, maxVal = -2e18; // 极小值
        if (l <= mid) {
            auto res = query(l, r, s, mid, p << 1);
            sum += res.first;
            maxVal = max(maxVal, res.second);
        }
        if (r > mid) {
            auto res = query(l, r, mid + 1, t, p << 1 | 1);
            sum += res.first;
            maxVal = max(maxVal, res.second);
        }
        return {sum, maxVal};
    }
};