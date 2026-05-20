#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
#include <numeric>
#include <cmath>
using namespace std;
using ll = long long;
#define int long long
ll n, k;

bool check(ll t);
struct Z
{
    ll a, b;
    bool operator<(const Z &o) const
    {
        return o.b < b;
    }
};
vector<Z> zombies(1e5 + 1); // ai, bi;

ll max(ll a, ll b)
{
    if (a >= b)
        return a;
    return b;
}
struct range{
    int l, r;
};

bool cmp(range& r1, range& r2){
    return r1.r > r2.r;
}
bool check(ll t)
{
    vector<range> ranges;
    for (int i = 0; i < n; ++i) {
        int dt = t - zombies[i].a;
        if (dt < 0) continue;
        int xl = zombies[i].b - dt, xr = zombies[i].b + dt;
        ranges.push_back({max(0,xl), min(xr,k)});
    }
    sort(ranges.begin(), ranges.end(), cmp);
    int l = INT_MAX;
    int r = -INT_MAX;
    bool found = 1;
    while(found){
        //found = 0;
        for (auto &[i, j] : ranges)
        {
            // if (l == INT_MAX)
            // {
            //     l = i;
            //     r = j;
            //     found = 1;
            // }
            // else if (i <= r)
            // {
            //     if (r >= i && l <= j) continue;
            //     r = max(r, j);
            //     l = min(l, i);
            //     found = 1;
            // }
            cout << "i: " << i << "  j:" << j << endl;
        }
    }
    if (r == k && l == 0)
        return 1;
    return 0;
}

// ll min(ll a, ll b)
// {
//     if (a < b)
//         return a;
//     return b;
// }

ll search(ll l, ll r)
{
    ll mid;
    while (l < r)
    {
        mid = (r - l) / 2 + l;
        if (check(mid))
        {
            cout << "true" << "\n";
            r = mid;
        }
        else
        {
            cout << "f" << "\n";
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
    for (int i = 0; i < n; i++)
    {
        int a, b;
        Z zz;
        cin >> zz.a >> zz.b;
        zombies[i] = zz;
    }
    sort(zombies.begin(), zombies.end());

    ll ans = search(0, k);
    cout << ans;
    return 0;
}
