// 也可以用dp解决带权重的

#include <bits/stdc++.h>
using namespace std;

struct time_val{
    int b, e;
    bool operator<(const time_val& o) const {
        return e < o.e;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int last_begin = -1;
    vector<time_val> v(n);
    for(auto& i : v) {
        cin >> i.b >> i.e;
        last_begin = max(last_begin, i.b);
    }
    sort(v.begin(), v.end());
    int ans = 1;
    int cur_end = v[0].e;
    for(int i = 0; i < n; ++i) {
        if (v[i].b >= cur_end) {
            ans++;
            cur_end = v[i].e;
        }
    }
    cout << ans << endl;
}

