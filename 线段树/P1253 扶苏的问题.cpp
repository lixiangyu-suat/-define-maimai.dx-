#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define int long long

vector<int> a;
vector<int> tree;
vector<int> lazy;
vector<int> lazy_change;
vector<bool> has_changed;

void init(int n) {
    a.resize(n);
    tree.resize(4 * n, 0);
    lazy.resize(4 * n, 0);
    lazy_change.resize(4 * n, 0);
    has_changed.resize(4*n, 0);
}

void push_up(int id) {
    tree[id] = max(tree[id<<1], tree[id<<1|1]);
}

void build(int id, int l, int r) {
    if (l == r) {
        tree[id] = a[l];
        return;
    }
    int mid = (l+r) >> 1;
    build(id<<1, l, mid);
    build(id<<1|1, mid+1, r);
    push_up(id);
    return;
}

void push_down(int id, int l, int r) {
    if (lazy[id] != 0 || has_changed[id]) {
        if (has_changed[id]) {
            tree[id<<1] = lazy_change[id];
            tree[id<<1|1] = lazy_change[id];
            lazy_change[id<<1] = lazy_change[id];
            lazy_change[id<<1|1] = lazy_change[id];
            has_changed[id<<1] = 1;
            has_changed[id<<1|1] = 1;
            lazy[id<<1] = 0;
            lazy[id<<1|1] = 0;
            lazy_change[id] = 0;
            has_changed[id] = 0;
        }
        if (lazy[id] != 0) {
            lazy[id<<1] += lazy[id];
            lazy[id<<1|1] += lazy[id];
            tree[id<<1] += lazy[id];
            tree[id<<1|1] += lazy[id];
            lazy[id] = 0;
        }
    }
}

void cng(int id, int l, int r, int val, int ql, int qr) {
    if (l >= ql && r <= qr) {
        tree[id] = val;
        lazy[id] = 0;
        lazy_change[id] = val;
        has_changed[id] = 1;
        return;
    }
    push_down(id, l, r);
    int mid = (l+r)>>1;
    if (mid >= ql) cng(id<<1, l, mid, val, ql, qr);
    if (mid < qr) cng(id<<1|1, mid+1, r ,val, ql, qr);
    push_up(id);
}

void update_range(int id, int l, int r, int val, int ql, int qr) {
    if (l >= ql && r <= qr) {
        tree[id] += val;
        lazy[id] += val;
        return;
    }
    push_down(id, l, r);
    int mid = (l+r)>>1;
    if (mid >= ql) update_range(id<<1, l, mid, val, ql, qr);
    if (mid < qr) update_range(id<<1|1, mid+1, r ,val, ql, qr);
    push_up(id);    
}

int query(int id, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return tree[id];
    push_down(id, l, r);
    int mid = (l+r) >> 1, res = -LLONG_MAX;
    if (mid >= ql) res = max(res, query(id<<1, l, mid, ql, qr));
    if (mid < qr) res = max(res, query(id<<1|1, mid+1, r, ql, qr));
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    init(n);
    for(auto& i : a) cin >> i;
    build(1, 0, n-1);
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int l, r, x; cin >> l >> r >>x;
            cng(1, 0, n-1, x, l-1, r-1);
        }
        else if (op == 2) {
            int l, r, x; cin >> l >> r >>x;
            update_range(1, 0, n-1, x, l-1, r-1);           
        }
        else if (op == 3) {
            int l, r; cin >> l >> r;
            cout << query(1, 0, n-1, l-1, r-1) << "\n";
        }
    }
}