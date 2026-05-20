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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int m = 0;
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        int bi;
        cin >> bi;
        cnt[bi]++;
        if (m < bi)
            m = bi;
    }
    m = m + 1; // MOD
    int cnt_of_0 = cnt[0];

    vector<int> a;
    for (int i = 0; i < cnt_of_0; i++)
    {
        for (auto &[num, c] : cnt)
        {
            if (c > 0)
            {
                a.push_back(num + i * m);
                c--;
            }
        }
    }

    /*
    cout << "maybe a : ";

    for (auto u : a)
    {
        cout << u << ' ';
    }
    cout << endl;
    */

    int idx = 0;
    for (auto ai : a)
    {
        if (ai == idx)
        {
            idx++;
        }
        else
        {
            break;
        }
    }
    int ans = idx + 1;
    cout << ans << endl;

    return 0;
}

/*
int main()
{
    while (true)
    {
        int u = test();
    }
}
    */
