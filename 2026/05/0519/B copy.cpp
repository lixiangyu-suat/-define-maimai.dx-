#include <bits/stdc++.h>
using namespace std;

int calcd(int x, int a, int b){
    int c = x - a * b;
    int M = max(a, max(b, c));
    int m = min(a, min(b, c));
    return (M-m);
}
int main(){
    int t; cin >> t;
    while (t--){
        int x; cin >> x;
        int mind = 0x3f3f3f3f;
        for (int a = sqrt(x); a >= 0; a--){
            int b1 = x/(a+1);
            int b2 = b1+1;
            int d1 = calcd(x, a, b1);
            int d2 = calcd(x, a, b2);
            int d = min(d1, d2);
            if (d > mind) break;
            else mind = d;
        }
        cout << mind << endl;
    }
}