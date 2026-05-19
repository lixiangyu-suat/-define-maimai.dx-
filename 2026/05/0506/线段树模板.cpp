#include <bits/stdc++.h>
using namespace std;

//当只要求增加和查找区间时

class SegmentTree{
    vector<int> d, la, v;
    int n;
public:
    SegmentTree(int n0) : n(n0*4){
        d.resize(n0*4);
        la.resize(n0*4);
    }
    void build(vector<int>& a, int s, int t, int p){//对[s,t]区间建立线段树，当前（也就是根）节点的编号为p
        if (s==t){
            d[p] = a[s];
            return;
        }
        int m = (t-s)>>1 + s;
        build(a, s, m, p*2); build(a, m+1, t, p*2+1);
        d[p] = d[p*2] + d[p*2+1];
    }

    int getsum(int l, int r, int s, int t, int p){
        // [l, r] 为查询区间, [s, t] 为当前节点包含的区间, p 为当前节点的编号
        if (l <= s && t <= r) return d[p]; //当前区间为询问区间的子集; 原因：非子集，需要往下一层。
        int m = s + (t-s) >> 1, sum = 0;
        //插入下方懒惰标记的步骤，步骤在递归之前进行，使得递归getsum算上了懒惰标记的值
        if (la[p]){// 无需 l != r，如果s == t一定在上面就return了
            //d[p] += (t-s+1) * la[p]; la懒惰 是给孩子用的；本层的已经update过了
            d[p*2] += la[p] * (m-s+1); d[p*2+1] += la[p] * (t-m);
            la[p*2] += la[p]; la[p*2+1] += la[p];
            la[p] = 0;
        }

        if (l <= m) sum += getsum(l, r, s, m, p*2); // 如果左儿子代表的区间 [s, m] 与询问区间有交集, 则递归查询左儿子
        if (r > m) sum += getsum(l, r, m+1, t, p*2+1);
        return sum;
    }

    void update(int l, int r, int c, int s, int t, int p){
        if (l <= s && t <= r){
            d[p] += (t-s+1) * c; la[p] += c;
            return;
        }
        int m = (t-s) >> 1 + s;
        /*
        if (v[p]){//额外数组v储存是否修改了值
            d[p*2] += la[p] * (m-s+1); d[p*2+1] += la[p] * (t-m);
        }
            */
        if (la[p]){
            d[p*2] += la[p] * (m-s+1); d[p*2+1] += la[p] * (t-m);
            la[p*2] += la[p]; la[p*2+1] += la[p]; 
            la[p] = 0;
        }
        if (l <= m) update(l, r, c, s, m, p*2);
        if (r > m) update(l, r, c, m+1, t, p*2+1);
        d[p] = d[p*2] + d[p*2+1];
    }


};