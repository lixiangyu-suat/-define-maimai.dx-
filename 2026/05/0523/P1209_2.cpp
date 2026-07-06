#include <bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int m, s, c;
    cin >> m >> s >> c;

    vector<int> a(c), d(c);
    for (int i = 0; i < c; i++) cin >> a[i];
    if (m >= c){
        cout << c;
        return 0;
    }

    d[0] = 1; //第0个牛占的空间（包括相对前一头牛的距离）

    sort(a.begin(), a.end());
    for (int i = 1; i < c; i++) d[i] = a[i] - a[i-1];
    sort(d.begin(), d.end(), greater<int>());

    int cost = a[c-1] - a[0] + 1; //大木板;
    for (int i = 0; i < m-1; i++){
        cost -= (d[i] - 1);
    }
    cout << cost;
    return 0;
}