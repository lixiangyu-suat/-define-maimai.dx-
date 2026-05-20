#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
#include <numeric>
#include <cmath>
using namespace std;



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
        int n, k, g, s;
        int bullet = 0;
        cin >> n >> k;
        while(n--) {
            int o, x;
            cin >> o >> x;
            if (o == 1) {
                bullet += x * k;
                g += x;
            }
            else if (o == 2) {
                bullet += x;
                s += x;
            }
            else {
                if (bullet < x) {
                    cout << -1 << "\n";
                    break;
                }

            }
        }
    }`
}
