#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
struct LN{
    long long v;
    int id;
}a[N];
int owner[N], tower[N];

bool cmp(LN& a, LN& b){
    return a.v > b.v;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--){
        int n, m, x, t;
        cin >> n >> m >> x;
        for (int i = 1; i <= n; i++){
            cin >> a[i].v;
            a[i].id = i;
        }
        sort(a+1, a+1+n, cmp);

        int i = 1;
        for (; i <= m; i++) {
            tower[i] = a[i].v; //memset
            owner[a[i].id] = i;
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        for (int j = 1; j <= m; j++){
            pq.push({tower[j], j});
        }
        for (; i <= n; i++){
            auto [h, idx] = pq.top();
            pq.pop();

            owner[a[i].id] = idx;
            pq.push({h + a[i].v, idx});
        }
        cout << "YES\n";
        for (int i = 1; i <= n; i++){
            cout << owner[i] << ' ';
        }
        cout << "\n";
    }
    return 0;
}