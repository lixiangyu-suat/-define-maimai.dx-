#include <bits/stdc++.h>
using namespace std;

struct nn{
    int p, n;
};
bool cmp(nn& a, nn&b) {
    return a.p < b.p;
}

int main(){
    int h, n;
    cin >> h >> n;

    vector<nn> fa(n);
    for (int i = 0; i < n; i++){
        int c, t;
        cin >> c >> t;
        fa[i] = {c, t};
    }

    sort(fa.begin(), fa.end(), cmp);

    int sum = 0;
    for (int i = 0; i < n; i++){
        auto [c, t] = fa[i];
        if (h <= t) {
            sum += c * h;
            break;
        }
        else{
            sum += c * t;
            h -= t;
        }
    }
    cout << sum;
    return 0;
}