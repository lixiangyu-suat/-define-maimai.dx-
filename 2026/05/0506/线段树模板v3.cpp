/*
不仅抽离出数据Info，还抽离出pushxx的行为，在不改动SegmentTree的情况下修改要维护的属性。
*/
#include <bits/stdc++.h>

struct Info {
    long long sum = 0;
    long long sqSum = 0; //维护平方和
    int len = 0; //维护区间长度r-l+1

    static Info merge(const Info& a, const Info& b) {
        return {a.sum + b.sum, a.sqSum + b.sqSum, a.len + b.len};
    }
};

struct Tag { //懒惰标记
    long long add = 0;
    long long mul = 1;

    void apply(const Tag& t) {
        mul = mul * t.mul;
        add = add * t.mul + t.add;
    }
};

void applyTag(Info& info, const Tag& tag) { //传递懒惰标记的具体行为
    if (info.len == 0) return;
    // (aX+b)^2 = a^2X^2 + 2abX + b^2 * len
    info.sqSum = info.sqSum * (tag.mul * tag.mul) 
                + 2 * tag.mul * tag.add * info.sum 
                + tag.add * tag.add * info.len;
    info.sum = info.sum * tag.mul + tag.add * info.len;
}

template <typename Info, typename Tag>
class SegmentTree {
    int n;
    std::vector<Info> info; //要维护的信息
    std::vector<Tag> tag;

    void pushup(int p) {
        info[p] = Info::merge(info[p << 1], info[p << 1 | 1]);
    }

    void apply(int p, const Tag& t) {
        applyTag(info[p], t);
        tag[p].apply(t);
    }

    void pushdown(int p) {
        // 只有非叶子节点才下传标记，且只有当标记不是初始状态时才下传
        // 简单处理：只要不是默认 Tag 就下传
        apply(p << 1, tag[p]);
        apply(p << 1 | 1, tag[p]);
        tag[p] = Tag(); 
    }

    void initLen(int l, int r, int p) {
        info[p].len = r - l + 1;
        if (l == r) return;
        // 修正优先级问题：先右移再加 l
        int mid = l + ((r - l) >> 1); 
        initLen(l, mid, p << 1);
        initLen(mid + 1, r, (p << 1) | 1);
    }
    
    void updateInfo(int p, int s, int t, int l, int r, const Tag& v) {
        if (l <= s && t <= r) {
            apply(p, v);
            return;
        }
        pushdown(p);
        int m = s + (t - s) / 2;
        if (l <= m) updateInfo(p << 1, s, m, l, r, v);
        if (r > m) updateInfo(p << 1 | 1, m + 1, t, l, r, v);
        pushup(p);
    }

    Info queryInfo(int p, int s, int t, int l, int r) {
        if (l <= s && t <= r) return info[p];
        pushdown(p);
        int m = s + (t - s) / 2;
        if (r <= m) return queryInfo(p << 1, s, m, l, r);
        if (l > m) return queryInfo(p << 1 | 1, m + 1, t, l, r);
        return Info::merge(queryInfo(p << 1, s, m, l, r), queryInfo(p << 1 | 1, m + 1, t, l, r));
    }

public:
    SegmentTree(int _n) : n(_n), info(4 * _n), tag(4 * _n) {
        if (_n > 0) initLen(1, _n, 1);
    }

    void update(int l, int r, const Tag& v) {
        if (l > r) return;
        updateInfo(1, 1, n, l, r, v);
    }

    Info query(int l, int r) {
        if (l > r) return Info();
        return queryInfo(1, 1, n, l, r);
    }
};

int main() {
    int n; 
    if (!(std::cin >> n)) return 0;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> a[i];

    SegmentTree<Info, Tag> tree(n);
    for (int i = 1; i <= n; i++) {
        // 初始化：区间加 a[i]，乘法保持 1
        tree.update(i, i, { (long long)a[i], 1 });
    }

    for (int i = 1; i <= n; i++) {
        Info res = tree.query(1, i);
        // 对应 Info 结构：sum, sqSum, len
        std::cout << "Range [1," << i << "]: Sum=" << res.sum 
                  << ", SqSum=" << res.sqSum 
                  << ", Len=" << res.len << std::endl;
    }
    return 0;
}