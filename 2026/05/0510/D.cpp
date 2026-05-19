#include <bits/stdc++.h>
using namespace std;
#define int long long

int pow(int a, int n){
    if (n == 0) return 1;
    int half = pow(a, n/2);
    if (n & 2 == 0) return half *half;
    else return half * half * a;
}
signed main(){
    int t; cin >> t;
    while (t--){
        int x; cin >> x;
        int k = 0;
        int s = 0;
        while (x){
            int a = x % 10;
            s += a * (pow(2, k));
            k++;
            x /= 10;
        }
        cout << s << endl;
    }
    return 0;
}