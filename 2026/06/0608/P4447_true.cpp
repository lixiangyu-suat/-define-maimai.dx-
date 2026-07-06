// #include <bits/stdc++.h>
// using namespace std;

// struct cmp{ //struct 类型名
//     bool operator()(const pair<int, int>& a, const pair<int, int>& b){
//         if (a.first == b.first) return a.second > b.second;
//         return a.first < b.first;
//     }
// };

// int main(){
//     int n; cin >> n;
//     vector<int> a(n);
//     priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> g;
//     for (int i = 0; i < n; i++) cin >> a[i];

//     sort(a.begin(), a.end());

//     for (int i = 0; i < n; i++){
//         if (g.empty() || g.top().first + 1 != a[i]) g.push({a[i], 1});
//         else{
//             auto [id, len] = g.top();
//             g.pop();
//             g.push({a[i], len+1});
//         }
//     }

//     int ans = INT_MAX;

//     while (!g.empty()){
//         auto u = g.top();
//         int len = u.second;
//         g.pop();
//         ans = min(ans, len);
//     }
//     cout << ans;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    
    map<int, priority_queue<int, vector<int>, greater<int>>> g;//不是greater<int>()

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++){
        // if (g[preid].empty()) g[i].push(1); 改为g[a[i]]，不是g[preid]
        int preid = a[i]-1;
        if (g[preid].empty()) g[a[i]].push(1); //上一个id衔接不上就把a[i]加到队列里面，维护{a[i], len}
        else{
            int len = g[preid].top();
            g[preid].pop();
            g[a[i]].push(len+1);
        }
    }

    int ans = INT_MAX;

    for (auto& [id, pq] : g){
        while (!pq.empty()){
            int len = pq.top();
            ans = min(ans, len);
            pq.pop();
        }
    }
    cout << ans;
    return 0;
}