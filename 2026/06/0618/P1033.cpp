#include <bits/stdc++.h>
using namespace std;

int main(){
    double h, s1, v, L, k;
    int n;
    cin >> h >> s1 >> v >> L >> k >> n;
    double t = sqrt((h-k)/5);

    double l, r;
    l = s1-v*t;
    r = l+L;
    int l0 = l;
    int r0 = r;
    if (l - l0 < 1.0e-4) l0 = l0 + 1;
    else ; //l0 = l0;

    if (r-r0 < 1-1.0e-4) ;
    else r0 = r0 + 1;

    l0 = min(l0, n-1);
    l0 = max(l0, 0);
    r0 = min(r0, n-1);
    r0 = max(r0, 0);
    
    if (r0 < 0) r0 = 0;

    cout << (r0-l0+1);
    return 0;

}