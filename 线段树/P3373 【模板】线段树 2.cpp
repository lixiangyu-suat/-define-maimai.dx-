#include <bits/stdc++.h>
#include <ios>
#include <vector>
#define int long long
int mod;
using namespace std;

int n, m;
vector<int> tree;
vector<int> lazy;
vector<int> lazy_mul;
vector<int> p;

void init(int n) {
    tree.resize(4*n);
    lazy.resize(4*n);
    p.resize(n);
    lazy_mul.resize(4*n, 1);
}

void pushup(int id) {
    tree[id] = (tree[id << 1] + tree[id<<1|1])%mod;
}

void build(int id, int l, int r) {
    if (l == r) {
        tree[id] = p[l];
        return;
    }

    int mid = (l+r)>>1;
    build(id<<1, l, mid);
    build(id<<1|1, mid+1, r);

    pushup(id);
}



void pushdown(int id, int l, int r) {
    if (lazy[id] != 0 || lazy_mul[id] != 1) {
        int mid = (l+r) >> 1;
        tree[id<<1] = (tree[id<<1] * lazy_mul[id] % mod + lazy[id] * (mid-l+1)) % mod; 
        tree[id<<1|1] = (tree[id<<1|1] * lazy_mul[id] % mod + lazy[id]*(r-mid)) % mod; 
        lazy_mul[id<<1] =(lazy_mul[id<<1]* lazy_mul[id])%mod;
        lazy_mul[id<<1|1] = (lazy_mul[id<<1|1]* lazy_mul[id])%mod;
        lazy[id<<1] = (lazy[id<<1] * lazy_mul[id]) % mod + lazy[id];
        lazy[id<<1|1] = (lazy[id<<1|1] * lazy_mul[id]) % mod + lazy[id];
        lazy_mul[id] = 1; lazy[id] = 0;
    }
}

int sum(int id, int l, int r, int L, int R) {
    if (L <= l && R >= r) return tree[id];
    pushdown(id, l, r);
    int mid = (r+l)>>1, res = 0;
    if(mid >= L) res += sum(id<<1, l, mid, L, R)%mod;
    if(mid < R) res += sum(id<<1|1, mid+1, r, L , R)%mod;
    return res%mod;
}

void update_range(int id, int val, int l, int r, int L, int R) {
    if (L <= l && R >= r) {
        tree[id] += (r-l+1)*val;
        lazy[id]+=val;
        tree[id] %= mod;
        lazy[id] %= mod;
        return;
    }
    pushdown(id, l, r);
    int mid = (l+r) >> 1;
    if (mid >= L) update_range(id<<1, val, l, mid, L, R);
    if (mid < R) update_range(id<<1|1, val, mid+1, r, L, R);
    pushup(id);
}
void update_range_mul(int id, int val, int l, int r, int L, int R) {
    if (L <= l && R >= r) {
        lazy_mul[id] = (lazy_mul[id] * val)%mod;
        lazy[id] = (lazy[id] * val)%mod;
        tree[id] = (tree[id] * val) %mod;
        return;
    }
    pushdown(id, l, r);
    int mid = (l+r)>>1;
    if (mid >= L) update_range_mul(id<<1, val, l, mid, L, R);
    if (mid < R) update_range_mul(id<<1|1, val, mid+1, r, L, R);
    pushup(id);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m; cin >> n >> m >> mod;
    init(n);
    for(auto& i : p) cin >> i;
    build(1, 0, n-1);
    while(m--) {
        int q; cin >> q;
        if (q==1) {
            int x, y, k; cin >> x >> y >> k;
            update_range_mul(1, k, 0, n-1, x-1, y-1);
        }
        if(q == 2) {
            int l, r, val; cin >> l >> r >> val;
            update_range(1, val, 0, n-1, l-1, r-1);
        }
        else if (q == 3) {
            int l, r; cin >> l >> r;
            cout << sum(1,0,n-1,l-1,r-1) %mod<< "\n";
        }
    }
}