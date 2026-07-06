#include <bits/stdc++.h>
using namespace std;

int main(){
    double h, s1, v, L, k;
    int n;
    cin >> h >> s1 >> v >> L >> k >> n;

    int cnt = 0;
    double t1, t2;
    t1 = sqrt( (h-k)/5 );
    t2 = sqrt(h/5);

    double l, r;
    for (int x = n-1; x >= 0; x--){
        
        l = s1-t2*v;
        r = s1+L-t1*v;
        
        if ((l < x && x < r) || abs(l-x) < 1e-4 || abs(r-x) < 1e-4) {
            cnt++;
        }
    }
    
    cout << cnt;
    return 0;

}