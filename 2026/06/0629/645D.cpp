#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int p[N], block_size[N], tail[N]; //tail:以i为head的连通块的tail
bool istail[N];

int find(int x){
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

int joint(int a, int b){
    int ra = find(a);
    int rb = find(b);
    if (ra == rb) return block_size[ra];

    istail[a] = false;
    p[rb] = ra;
    block_size[ra] += block_size[rb];

    istail[tail[ra]] = false;//去掉一个尾巴
    tail[ra] = tail[rb];
    return block_size[ra];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;

    bool ok = false;
    int i = 1;
    
    for (int i = 1; i <= n; i++){
        tail[i] = p[i] = i;
        block_size[i] = 1;
        istail[i] = false;
    }

    int l, r;
    for (;i <= m; i++){
        cin >> l >> r;
        if (find(r) == r || istail[l]){
            int maxcntblock = joint(l, r); 
            if (maxcntblock == n) {
                ok = true;
                break;
            }
        }
    }
    int k = i+1;
    for (; k <= m; k++) cin >> l >> r;

    if (ok) cout << i;
    else cout << -1;
    return 0;
}