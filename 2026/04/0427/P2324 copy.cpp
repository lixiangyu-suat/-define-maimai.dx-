#include <bits/stdc++.h>
using namespace std;

bool found = false;
int target[5][5] = {
    {1,1,1,1,1},
    {0,1,1,1,1},
    {0,0,-1,1,1},
    {0,0,0,0,1},
    {0,0,0,0,0}
};
int dx[8] = {-2, -1, -2, -1, 2, 1, 2, 1};
int dy[8] = {-1, -2, 1, 2, -1, -2, 1, 2};

int curr[5][5];

int get_h(){
    int cnt = 0;//与结果不同的数量
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (curr[i][j] != -1 && curr[i][j] != target[i][j]) cnt++;
        }
    }
    return cnt;
}

void dfs(int limit, int step, int x, int y){
    int h = get_h();
    if (step+h > limit) return;
    if (h == 0) {
        found = true;
        return;
    }

    for (int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5){
            swap(curr[x][y], curr[nx][ny]);
            dfs(limit, step+1, nx, ny);
            swap(curr[x][y], curr[nx][ny]);
        }
        if (found) return;
    }
    return;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    
    int t; cin >> t;
    while (t--){
        found = false;
        int x, y;
        for (int i = 0; i < 5; i++){
            string s; cin >> s;
            while (s == "") cin >> s;
            for (int j = 0; j < 5; j++){
                if (s[j] == '1') curr[i][j] = 1;
                else if (s[j] == '0') curr[i][j] = 0;
                else {
                    curr[i][j] = -1;
                    x = i; y = j;
                }
            }
        }
        int limit = 0;
        for (; limit <= 15; limit++){
            dfs(limit, 0, x, y);
            if (found) {
                break;
            }
        }
        if (found) cout << limit << endl;
        else cout << -1 << endl;
    }
    return 0;
}