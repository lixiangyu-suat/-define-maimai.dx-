#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5+5;
int tmp[N];

int merge_sort(vector<int>& a, int l, int r){
    if (l >= r) return 0;
    int mid = (r-l)/2 + l;

    int cnt1 = merge_sort(a, l, mid);
    int cnt2 = merge_sort(a, mid+1, r);
    int cnt3 = 0;

    int i = l, j = mid+1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] > a[j]){
            tmp[k++] = a[i++];
            cnt3 += (r-j+1);
        }
        else {
            tmp[k++] = a[j++];
            //cnt3 += (r-i+1);
        }
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int u = l; u <= r; u++) a[u] = tmp[u];
    
    return (cnt1 + cnt2 + cnt3);
}

signed main(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int cnt = merge_sort(a, 0, n-1);
    cout << cnt;
    return 0;
}