#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005;

int n;
vector<int> a, sum;

bool check(int L){
    int k = sum[0] / L;
    int r = sum[0] - k * L;
    for (int i = 1; i < n; i++){
        if (r == 0){
            k = sum[i] / L;
            r = sum[i] - k*L;
        }
        else{
            if (k < sum[i] / L){
                k = sum[i] / L;
                r = sum[i] - k*L;
                if (r != 0){
                    return false;
                }
            }
            else if (k == sum[i] / L){
                r = sum[i] - k*L;
            }  
        }
    }
    return true;
}
int search(int l, int r){
    int mid, ans = -1;
    while (l <= r){
        mid = (r-l)/2 + l;

        if (check(mid)){
            ans = mid;
            r = mid-1;
        }
        else {
            l = mid + 1;
        }
    }
    return ans;
}
signed test(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    a.resize(n);
    sum.resize(n);

    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (i == 0) sum[i] = a[i];
        else sum[i] = sum[i-1] + a[i];
    }

    int L = search(1, sum[n-1]);
    cout << L << endl;
    return 0;

}

signed main(){
    while (1) test();
}