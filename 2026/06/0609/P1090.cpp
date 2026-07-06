#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //freopen("./in.txt", "r", stdin);
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        pq.push(x);
    }
    
    int sum = 0;
    for (int i = 1; i < n; i++){
        int a1 = pq.top(); pq.pop();
        int a2 = pq.top(); pq.pop();
        sum += (a1+a2);
        pq.push(a1+a2);
    }
    cout << sum;
    return 0;
}