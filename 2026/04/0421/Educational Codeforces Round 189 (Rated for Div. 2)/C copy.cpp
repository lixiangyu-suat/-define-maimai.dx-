#include <bits/stdc++.h>
using namespace std;

char wall[200005][2];
bool vis[200005][2];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" ,stdin);
    #endif

    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int k = 0; k < 2; k++) for (int i = 0; i < n; i++) {cin >> wall[i][k];vis[i][k] = false;}
                
        int cnt = 0;
        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < n; i++){
                if (vis[i][k]) continue;
                vis[i][k] = true;

                if (k == 0 && wall[i][k] == wall[i][k+1]){
                    vis[i][k+1] = true;
                }else if (i < n-1 && wall[i][k] == wall[i+1][k]){
                    vis[i+1][k] = true; ///!!!!代码码字错误
                }else{
                    cnt++;
                    if (k == 0) {
                        vis[i][k+1] = true;
                        wall[i][k+1] = wall[i][k];
                    }
                    else {
                        vis[i+1][k] = true;
                        wall[i+1][k] = wall[i][k];
                    }
                }
            }
        }
        cout << cnt << endl;
    }
    
    return 0;
}