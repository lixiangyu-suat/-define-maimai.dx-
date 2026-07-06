#include <bits/stdc++.h>
using namespace std;
#define int long long

int a, b;

bool check(int k){
    return ((b * k  + 1) % a == 0);
}
int search(int l, int r){
    int mid, ans = -1;
    while (l <= r){
        mid = (r-l)/2 + l;
        if (check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    int x = (b * ans + 1) / a;
    return x;
}
signed main(){
    cin >> a >> b;
    
    int x = search(1, 1e9+7);
    cout << x;
    return 0;
}