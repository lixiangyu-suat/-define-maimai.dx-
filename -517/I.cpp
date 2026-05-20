#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
#include <numeric>
#include <cstring>
#include <string>
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
    while (t--)
    {
        string s, t;
        cin >> s;
        cin >> t;

        bool foundsth = false;
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                string sub1 = "", sub2 = "";
                sub1 += (char)('a' + i);
                sub2 += (char)('a' + j);

                bool f = false;
                int idx1 = 0, idx2 = 0;
                if (s.find(sub1, idx1) != string::npos && t.find(sub1, idx2) != string::npos)
                {
                    idx1 = s.find(sub1, idx1) + 1;
                    idx2 = t.find(sub1, idx2) + 1;
                    f = true;
                }
                if (f == false)
                    continue;
                f = false;

                if (s.find(sub2, idx1) != string::npos && t.find(sub2, idx2) != string::npos)
                {
                    f = true;
                }
                if (f == true)
                {
                    cout << (sub1 + sub2) << endl;
                    foundsth = true;
                    break;
                }
                else
                {
                    continue;
                }
            }
            if (foundsth)
                break;
        }

        if (!foundsth)
            cout << "HENG!" << endl;
    }
    return 0;
}
