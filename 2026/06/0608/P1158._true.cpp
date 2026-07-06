#include <bits/stdc++.h>
using namespace std;

int sq(int x, int y, int x0, int y0){
    return (x-x0)*(x-x0) + (y-y0)*(y-y0);
}

int main(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n; cin >> n;

    int md1 = 0, md2 = 0;
    int d1, d2;

    vector<pair<int, int>> d(n);

    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;

        d1 = sq(x, y, x1, y1);
        d2 = sq(x, y, x2, y2);

        d[i] = {d1, d2};
    }

    sort(d.begin(), d.end(), [&](pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    });

    vector<int> nxt(n+1);// md2依赖采用idx---n-1时的最大值（要求的md2）
    int ans = 0x3f3f3f3f;
    for (int j = n-1; j >= 0; j--){
        nxt[j] = max(nxt[j+1], d[j].second);
    }
    for (int i = 0; i < n; i++){
        md1 = d[i].first; md2 = nxt[i+1];
        ans = min(ans, md1+md2);
    }
    ans = min(ans, nxt[0]);
    cout << ans;

    return 0;
}