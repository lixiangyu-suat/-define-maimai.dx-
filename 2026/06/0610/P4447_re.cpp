#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    map<int, priority_queue<int, vector<int>, greater<int>>> len;
    for (int i = 0; i < n; i++){
        int pre = a[i] - 1;
        int cur = a[i];
        if (len[pre].empty()) len[cur].push(1);
        else{
            int t = len[pre].top();
            len[cur].push(t+1);
            len[pre].pop();
        }
    }

    int ans = INT_MAX;
    for (auto [ai, pq] : len){
        while (!pq.empty()){
            int l = pq.top();
            ans = min(ans, l);
            pq.pop();
        }
    }
    cout << ans;
}