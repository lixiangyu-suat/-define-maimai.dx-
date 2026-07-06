#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
pair<int, int> pos[N];
int sum[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, d, s;
    cin >> n >> m >> d;
    int maxnum = n*m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> s;
            pos[s] = {i, j};
        }
    }

    for (int i = 1; i <= d; i++){ // not i < d : A:1---n*m
        sum[i] = 0;
        for (int j = i+d; j <= maxnum; j+=d){
            sum[j] = sum[j-d] + abs(pos[j].first - pos[j-d].first) + abs(pos[j].second - pos[j-d].second);
        }
    }

    int q; cin >> q;
    int l, r;
    while (q--){
        cin >> l >> r;
        cout << sum[r] - sum[l] << "\n";
    }
    return 0;
}