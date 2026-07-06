#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005;

int n;
vector<int> a, sum;

int search(int l, int r){
    int mid, ans = -1;
    while (l <= r){
        mid = (r-l)/2 + l;

        int L = mid;
        int u = a[1] % L;

        if (u + sum[n] - sum[1] <= L){
            ans = mid;
            r = mid-1;
        }
        else {
            l = mid + 1;
        }
    }
    return ans;
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    a.resize(n+1);
    sum.resize(n+1);

    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }

    int L = search(1, a[1]);
    if (L == -1){
        for (int i = 1; i <= n; i++){
            L = sum[i];
            if (sum[n] <= 2*L) break;
            else if (sum[n] < 3*L && a[i+1] == L) break;
        }
    }
    
    cout << L << endl;
    return 0;

}

// signed main(){
//     while (1) test();
// }