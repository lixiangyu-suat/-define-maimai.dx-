#include <bits/stdc++.h>
using namespace std;
vector<int> a;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int n, k; cin >> n >> k;
    a.resize(n+1);
    deque<int> dq;//下标
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        if (!dq.empty() && i-dq.front() >= k) dq.pop_front();
        while (!dq.empty() && a[i] <= a[dq.back()]){//单调递增
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k) cout << a[dq.front()] << ' ';
    }
    cout << endl;
    dq.clear();
    for (int i = 1; i <= n; i++){
        if (!dq.empty() && i-dq.front() >= k) dq.pop_front();
        while (!dq.empty() && a[i] >= a[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k) cout << a[dq.front()] << ' ';
    }
    //窗口左边界： L = i-k+1
    return 0;
}