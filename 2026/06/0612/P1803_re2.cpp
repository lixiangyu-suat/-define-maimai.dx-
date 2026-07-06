#include <bits/stdc++.h>
using namespace std;

struct I{
    int l;
    int r;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<I> interval(n);
    for (int i = 0; i < n; i++){
        cin >> interval[i].l >> interval[i].r;
    }
    sort(interval.begin(), interval.end(), [&](I& a, I& b){
        if (a.r == b.r) return a.l > b.l;
        return a.r < b.r;
    });

    int cnt = 0;
    int curR = 0;
    for (auto [l, r] : interval){
        if (l >= curR){
            curR = r;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}