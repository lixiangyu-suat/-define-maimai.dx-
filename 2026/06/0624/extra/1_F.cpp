#include <bits/stdc++.h>
using namespace std;
struct I{
    long long l, r;
};

bool cmp(I& a, I&b){
    return a.r > b.r;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<I> a(n);
    int t;
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
    }
    sort(a.begin(), a.end(), cmp);

    int len = 0;
    long long ml = LONG_LONG_MAX, mr = LONG_LONG_MAX;
    for (int i = 0; i < n; i++){
        if (a[i].r <= ml){
            len += mr-ml;
            mr = a[i].r;
            ml = a[i].l;
        }
        else{
            ml = min(a[i].l, ml);
        }
    }
    len += mr-ml;
    cout << len;
    return 0;
}