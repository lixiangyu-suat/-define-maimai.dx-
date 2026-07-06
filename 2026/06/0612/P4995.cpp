#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;

    vector<int> a(n+1), f(n+1);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int l = 0, r = n, k = 0;
    bool flag = false; // 选用小的石头（地面=高度为0的石头）
    
    while (l <= r){
        if (flag == 0) f[k++] = a[l++];
        else f[k++] = a[r--];
        flag = !flag;
    }

    long long energy = 0;
    for (int i = 1; i <= n; i++){
        energy += (f[i] - f[i-1]) * (f[i] - f[i-1]);
    }
    cout << energy;
    return 0;
}