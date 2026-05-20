#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
#include <numeric>
#include <cmath>
using namespace std;

int solve(vector<int> & v, int a, int m) {
    int res = 0;
    int money = 0;
    auto it1 = upper_bound(v.begin(), v.end(), a);
    auto it2 = lower_bound(v.begin(), v.end(), m);
    if (res > 0)
        money += res * v.back();
    return money;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, a;
        cin >> n >> a;
        vector<int> v(n);
        for(auto&i : v)
            cin >> i;
        sort(v.begin(), v.end());
        int m;
        cin >> m;
        while(m--) {
            int mi;
            cin >> mi;
            cout << solve(v, a, mi) << " ";
        }
        cout << endl;
    }
}
