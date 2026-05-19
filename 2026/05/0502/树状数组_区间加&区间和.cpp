//区间加 & 区间和
#include <bits/stdc++.h>
using namespace std;

class BIT{
    vector<int> t1; vector<long long> t2;
    int n;
    int lowbit(int x){
        return x & -x;
    }
public:
    void build(vector<int>& a){
        n = a.size()-1; //index:0--n
        t1.resize(n+1); t2.resize(n+1);
        for (int i = 0; i <= n; i++){
            t1[i] = t2[i] = 0;
        }
        for (int i = 1; i < a.size(); i++){
            int d = a[i] - a[i-1];
            int j = i + lowbit(i);
            t1[i] += d; t1[j] += d;
            t2[i] += d*i; t2[j] += d*i;
        }
    }

    void add(int i, int v){
        long long vi = v * i;
        while (i <= n){
            t1[i] += v; t2[i] += vi;
            i += lowbit(i);
        }
    }

    void add1(int l, int r, int v){//区间加
        add(l, v); add(r+1, -v);
    }

    long long presum(int i){//查询前缀和 (从差分到前缀）
        int pre_i = i;
        long long sum1 = 0, sum2 = 0;
        while (i > 0){ //不是>=0
            sum1 += t1[i]; sum2 += t2[i];
            i -= lowbit(i);
        }
        return (pre_i+1) * sum1 - sum2;
    }

    long long getsum(int l, int r){
        return presum(r) - presum(l-1);
    }
};

int main(){
    BIT bit;
    int n, m; cin >> n >> m;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    bit.build(a);
    for (int q = 1; q <= m; q++){
        int l, r, v; cin >> l >> r >> v;
        bit.add1(l, r, v);
    }
    cout << bit.getsum(1, n);
}
//区间乘法：