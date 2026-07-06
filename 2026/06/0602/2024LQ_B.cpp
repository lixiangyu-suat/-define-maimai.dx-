#include <bits/stdc++.h>
using namespace std;
#define int long long

const int M = 20240601000;

signed main(){
    int sum = 0;
    for (int k = 1; k * k <= M; k++){
        int a = (M-k*k) / (2*k);
        if (a * 2 * k == M - k*k){
            int n = a * a + M/2;
            sum += n;
        }
    }
    cout << sum << endl;
}