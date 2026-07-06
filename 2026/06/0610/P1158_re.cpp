#include <bits/stdc++.h>
using namespace std;

int sq(int x, int y, int x1, int y1){
    return (int)(pow(x-x1, 2)+pow(y-y1, 2));
}

struct D{
    int d1;
    int d2;
};
vector<D> dis;

bool cmp(D& a, D& b){
    return a.d1 < b.d1;
}

int main(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int n; cin >> n;
    dis.resize(n);
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        int d1 = sq(x, y, x1, y1);
        int d2 = sq(x, y, x2, y2);
        dis[i] = {d1, d2};
    }
    sort(dis.begin(), dis.end(), cmp);
    
    vector<int> maxp2(n+1);
    for (int j = n-1; j >= 0; j--){
        maxp2[j] = max(maxp2[j+1], dis[j].d2);
    }

    int ans = INT_MAX;
    ans = min(ans, maxp2[0]);
    for (int i = 0; i < n; i++){
        ans = min(ans, maxp2[i+1] + dis[i].d1);
    }
    cout << ans;
    return 0;
}