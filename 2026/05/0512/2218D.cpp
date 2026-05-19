#include <bits/stdc++.h>
using namespace std;

const int N = 200000;
vector<long long> p(10005), isprime(N, true);
vector<long long> ans(10005);
int main(){
    int t; cin >> t;

    int idx = 0;
    for (long long i = 2; i < N; i++){
        if (!isprime[i]) continue;
        if (idx > 10000) break;
        p[idx++] = i;
        for (long long j = i*i; j < N; j+=i){
            isprime[j] = false;
        }
    }

    for (int i = 0; i < 10000; i++){
        ans[i] = p[i] * p[i+1];
    }

    while (t--){
        int n; cin >> n;
        for (int i = 0; i < n; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}