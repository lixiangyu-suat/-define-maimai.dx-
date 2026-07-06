#include <bits/stdc++.h>
using namespace std;

struct MSG{
    int L, R, e;
};
bool cmp(MSG& a, MSG& b){
    return a.e > b.e;
}

const int N = 1e5+5;
int p[N*2], temp[2*N], m;
MSG msg[N];

int find(int x){
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}
void unite(int a, int b){
    int ar = find(a);
    int br = find(b);
    if (ar != br){
        p[ar] = br;
    }
}
bool cnt(int a, int b){
    return find(a) == find(b);
}

int link(int i){
    return lower_bound(temp+1, temp+m+1, i) - temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    temp[0] = -1;

    while (T--){
        int n; cin >> n;

        

        int k = 1;
        for (int i = 0; i < n; i++){
            cin >> msg[i].L >> msg[i].R >> msg[i].e;
            temp[k++] = msg[i].L; temp[k++] = msg[i].R;
        }
        sort(temp+1, temp+k);
        m = unique(temp+1, temp+k) - temp + 1;
        sort(msg, msg+n, cmp);

        for (int i = 1; i <= m; i++) p[i] = i;
        bool ok = true;
        for (int i = 0; i < n; i++){
            int op = msg[i].e;
            int l = msg[i].L;
            int r = msg[i].R;

            if (!ok) break;
            if (op == 1) {
                unite(link(l), link(r));
            }
            else{
                if (cnt(link(l), link(r))) {
                    ok = false;
                }
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}