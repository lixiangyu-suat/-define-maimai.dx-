#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> l;
signed main(){
    # ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    # endif
    int n; cin >> n;
    l.resize(n+1); 
    int a, b; cin >> a >> b;
    l[0] = {a, b};
    
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        l[i] = {a, b};
    }

    sort(l.begin()+1, l.end(), [&](pair<int, int> a, pair<int,int> b){
        return a.first * a.second < b.first * b.second;
    });

    long long sum = 0, res = 1;
    for (int i = 1; i <= n; i++){
        res*=l[i-1].first;
        sum = (sum < res/l[i].second) ? res/l[i].second : sum;
    }
    cout << sum;
    

}