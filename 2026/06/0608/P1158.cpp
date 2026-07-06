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
        int ma = min(a.first, a.second), mb = min(b.first, b.second);
        int xa = max(a.first, a.second), xb = max(b.first, b.second);

        if (ma == mb) return xa > xb;
        return ma > mb;
    });
    for (int i = 0; i < n; i++){
        auto& [d1, d2] = d[i];

        if (d1 <= md1 || d2 <= md2) continue;
        else if (d1 <= d2){
            if (d1 + md2 >= d2 + md1) md2 = d2;
            else {
                md1 = d1;
            }
        }
        else{
            if (d2 + md1 >= d1 + md2) md1 = d1;
            else {
                md2 = d2;
            }
        }
    }
    cout << (d1+d2);
    return 0;
}