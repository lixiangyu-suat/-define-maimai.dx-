#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T, c;
    cin >> T >> c;
    while (T--){
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> l(n), b(m);
        for (int i = 0; i < n; i++){
            cin >> l[i];
        }
        for (int i = 0; i < m; i++){
            cin >> b[i];
        }
        for (int i = 0; i < q; i++){
            int op; cin >> op;
            if (op == 1){
                int v;
                cin >> v;
                for (int j = 0; j < v; j++){

                }
            }
        }
    }
}