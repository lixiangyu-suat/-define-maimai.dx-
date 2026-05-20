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

    string s;
    int n;
    cin >> n;
    cin >> s;

    int x = s[0] - '0';
    bool exist0 = false;
    for (int i = 0; i < n; i++)
    {
        int cur = s[i] - '0';
        if (cur == 0)
        {
            exist0 = true;
            break;
        }
    }
    if (exist0)
        for (int i = 0; i < n - 1; ++i)
        {
            cout << "&";
        }
    else
    {
        for (int i = 0; i < n - 2; ++i)
        {
            cout << "&";
        }
        cout << "^";
    }
    return 0;
}
