#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
#include <numeric>
#include <cmath>
using namespace std;

bool judge(int x, int d, int a, int d0)
{
    if (x - d == a * (a + d0))
        return true;
    return false;
}
int search(int x, int d)
{
    for (int i = 0; i <= d; i++)
    {
        int sq = sqrt(x);
        int l = 0, r = sq;
        int mid;
        while (l < r)
        {
            mid = (r + l) / 2;
            if (judge(x, d, mid, i))
            {
                return i;
            }
        }
    }
    return d;
}
int main()
{

    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            cout << 0 << endl;
            continue;
        }
        int sq = sqrt(x);

        int a = sq;
        int b = x / a;

        int mind = 0x3fffffff;
        for (int u = b; u > a; u--)
        {
            int c = x - u * b;
            int M = max(u, max(b, c));
            int m = min(u, min(b, c));
            int d = M - m;
            if (d < mind)
                mind = d;
        }
        bool conti = true;
        while (conti)
        {
            swap(a, b);
            int c = x - a * b;
            int M = max(a, max(b, c));
            int m = min(a, min(b, c));
            int d = M - m;
            if (d < mind)
                mind = d;
            else
                break;
            a--;
        }

        int mind = search(x, mind);

        cout << mind << endl;
        // printf("a, b, c = %d %d %d, maxM=%d, minm=%d, M-m = %d\n", a, b, c, M, m, d);
    }

    return 0;
}
/*
a, b, c = 1 12 0, maxM = 12, minm = 0, M - m = 12 100 a, b, c = 10 10 0, maxM = 10, minm = 0, M - m = 10 a, b, c = 9 11 1, maxM = 11, minm = 1, M - m = 10 a, b, c = 8 12 4, maxM = 12, minm = 4, M - m = 8 a, b, c = 7 14 2, maxM = 14, minm = 2, M - m = 12 a, b, c = 6 16 4, maxM = 16, minm = 4, M - m = 12 a, b, c = 5 20 0, maxM = 20, minm = 0, M - m = 20 a, b, c = 4 25 0, maxM = 25, minm = 0, M - m = 25 a, b, c = 3 33 1, maxM = 33, minm = 1, M - m = 32 a, b, c = 2 50 0, maxM = 50, minm = 0, M - m = 50 a, b, c = 1 100 0, maxM = 100, minm = 0, M - m = 100 a, b,

if (a != b)
        {
            if (a > b)
            {
                swap(a, b);
            }
            int prea = a;
            for (int i = prea; i > 0; i--)
            {
                int na = a - i;
                int nb = b + i;
                int nc = x - na * nb;
                int nM = max(na, max(nb, nc));
                int nm = min(na, min(nb, nc));
                int nd = nM - nm;
                if (mind > nd)
                    mind = nd;
                else
                    break;
            }
        }
*/
