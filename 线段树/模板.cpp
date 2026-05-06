#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct find_max_tree{
    vector<int> trees;
    vector<int> a;
    vector<int> lazy;
    void pushup(int p) {
        trees[p] = max(trees[p << 1], trees[p << 1|1]);
    }
    void build(int id, int l, int r) {
        if (l == r) {
            trees[id] = a[l];
            return;
        }
        if (l > r) return;
        int mid = (l+r)>>1;
        build(id<<1, l, mid);
        build(id<<1|1, mid+1, r);
        pushup(id);
    }

    find_max_tree(vector<int>& p) : a(p) {
        trees.resize(p.size()*4);
        lazy.resize(p.size()*4);
        build(1, 0, a.size()-1);
    }

    void update(int id, int idx, int val, int l, int r) {
        if (l == r) {
            trees[id] = val;
            return;
        }
        int mid = (l+r) >> 1;
        if (mid >= idx) update(id<<1, idx, val, l, mid);
        else update(id<<1|1, idx, val, mid+1, r);
        pushup(id);
    }

    void update(int idx, int val) {
        update(1, idx, val, 0, a.size()-1);
    }

    void pushdown(int id) {
        if (lazy[id] != 0) {
            trees[id<<1] += lazy[id];
            trees[id<<1|1] += lazy[id];
            lazy[id<<1] += lazy[id];
            lazy[id<<1|1] += lazy[id];
            lazy[id] = 0;
        }
    }


    const int INF = 0x3f3f3f3f;
    int search(int id, int l, int r, int L, int R)  {
        if (L <= l && R >= r) return trees[id];
        pushdown(id);
        int mid = (l+r) >> 1;
        int res = -INF;
        if (mid >= L) res = max(res, search(id<<1, l, mid, L, R));
        if (mid < R) res = max(res, search(id<<1|1, mid+1, r, L, R));
        return res;
    }

    int query(int L, int R) {
        return search(1, 0, a.size()-1, L, R);
    }


    void update_range(int val, int id, int l, int r, int L, int R) {
        if (l >= L && r <= R) {
            lazy[id] += val;
            trees[id] += val;
            return;
        }
        pushdown(id);
        int mid = (l+r)>>1;
        if (mid >= L) update_range(val, id<<1, l, mid, L, R);
        if (mid < R) update_range(val, id<<1|1, mid+1, r, L, R);
        pushup(id);
    }

    void update_range(int l, int r, int val) {
        update_range(val, 1, 0, a.size()-1, l, r);
    }
};


struct add_tree{
    vector<int> trees;
    vector<int> a;
    vector<int> lazy;  

    void pushup(int id) {
        trees[id] = trees[id<<1] + trees[id<<1|1];
    }

    void build(int id, int l, int r) {
        if (l == r) {
            trees[id] = a[l];
            return;
        }
        int mid = (l+r)>>1;
        build(id<<1, l, mid);
        build(id<<1|1, mid+1, r);
        pushup(id);
    }

    add_tree(vector<int>& p) : a(p) {
        trees.resize(p.size()*4);
        lazy.resize(p.size()*4);
        build(1, 0, a.size()-1);
    } 

    void update(int id, int idx, int val, int l, int r) {
        if (l == r) {
            trees[id] = val;
            return; 
        }
        int mid = (l+r)>>1;
        if (mid >= idx) update(id<<1, idx, val, l, mid);
        else update(id<<1|1, idx, val, mid+1, r);
        pushup(id);
    }

    void update(int idx, int val) {
        update(1, idx, val, 0, a.size()-1);
    }

    void pushdown(int id, int l, int r) {
        if (lazy[id] != 0) {
            int mid = (l+r)>>1;
            lazy[id<<1] += lazy[id];
            lazy[id<<1|1] += lazy[id];
            trees[id<<1] += lazy[id] * (mid-l+1);
            trees[id<<1|1] += lazy[id] * (r-mid); // 注意长度！
            lazy[id] = 0;
        }
    }

    int search(int id, int l, int r, int L, int R) {
        if (L <= l && r <= R) return trees[id];
        pushdown(id, l, r);
        int res = 0, mid = (l+r)>>1;
        if (mid >= L) res += search(id<<1, l, mid, L, R);
        if (mid < R) res += search(id<<1|1, mid+1, r, L, R);
        return res; 
    }

    void update_range(int id, int val, int l, int r, int L, int R) {
        if (l >= L && r <= R) {
            trees[id] += (r-l+1)*val;
            lazy[id] += val;
            return;
        }
        pushdown(id, l, r);
        int mid = (l + r) >> 1;
        if (mid >= L) update_range(id<<1, val, l, mid, L, R);
        if (mid < R) update_range(id<<1|1, val, mid+1, r, L, R);
        pushup(id);
    }

    void update_range(int l, int r, int val) {
        update_range(1, val, 0, a.size()-1, l, r);
    }
};