#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
#include <numeric>
#include <cmath>
using namespace std;
#define int long long
int n, k;

bool check(int t);
struct Z
{
    int a, b;
};
vector<Z> zombies;

struct range
{
    int l, r;
};

bool cmp(range &r1, range &r2)
{
    return r1.r > r2.r;
}

bool check(int t)
{
    vector<range> rngs;
    rngs.reserve(n + 5);
    for (auto &[a, b] : zombies)
    {
        int dt = t - a;
        //cout << "a-b-dt : " << a << ' ' << b << ' ' << dt << endl;
        if (dt < 0)
            continue;
        rngs.push_back({max(0ll, b - dt), min(k, b + dt)});
    }
    sort(rngs.begin(), rngs.end(), cmp);
    if (rngs.empty())
        return 0;
    int L = rngs[0].l, R = rngs[0].r;
    bool f = 1;
    for (int i = 1; i < rngs.size() && f; ++i)
    {
        range cur = rngs[i];
        if (cur.r >= L - 1)
        {
            L = min(cur.l, L);
        }
        else
            f = 0;
    }
    if (L != 0 || R != k)
        f = 0;
    return f;
}
int search(int l, int r)
{
    int mid;
    while (l < r)
    {
        mid = (r - l) / 2 + l;
        if (check(mid))
        {

            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    zombies.resize(n);
    for(auto& [a, b] : zombies)
        cin >> a >> b;
    int ans = search(0, 2 * k + 5);
    cout << ans;
    return 0;
}
