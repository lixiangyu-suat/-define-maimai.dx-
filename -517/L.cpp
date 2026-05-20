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

signed main()
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
        int n;
        cin >> n;
        int sum = 0;
        int mx = -1, minx = INT_MAX;
        int temp;
        for (int i = 0; i < n; ++i) {
            cin >> temp;
            mx = max(mx, temp);
            minx = min(minx, temp);
            sum += temp;
        }
        if ((minx + n - 1) % 2 == 1) {
            cout << "Insight" << "\n";
        }
        else {
            if ((sum - n * minx + minx + n-1) % 2 == 1) {
                cout << "Insight\n";
            }
            else
                cout << "Maya" << "\n";
        }
    }
}
