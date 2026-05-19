#include <bits/stdc++.h>
using namespace std;

int getmaxbit(int t){
    int l = 0, r = 31;
    while (l < r){
        int mid = (l+r)/2;
        if ((t >> mid) > 1) l = mid+1;
        else r = mid;
    }
    return l;
}
int main(){
    int n, x; cin >> n >> x;
    vector<vector<int>> b(32);
    for (int i = 0; i < n; i++){
        int t, maxbit; cin >> t;
        maxbit = getmaxbit(t);
        b[maxbit].push_back(t);
    }
    int xh = getmaxbit(x);
    int l = xh;
    
}