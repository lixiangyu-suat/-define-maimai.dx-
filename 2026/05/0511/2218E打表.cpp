#include <bits/stdc++.h>
using namespace std;

int get_rand(int min, int max){
    static mt19937 rng(42);
    //static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

int a[6];
int maxx;
void dfs(int n, int step){
    if (step == n) {
        int x = 0;
        int res = 0;
        for (int i = 0; i < n-1; i++){
            res ^= a[i];
            x ^= res;
        }
        x ^= a[n-1];
        if (x > maxx) maxx = x;
        return;
    }
    for (int i = 0; i < n; i++){
        swap(a[step], a[i]);
        dfs(n, step+1);
        swap(a[step], a[i]);
    }
}
int main(){
    for (int u = 0; u <= 100; u++)
    for (int n = 3; n <= 5; n++){
        memset(a, false, sizeof(a));
        maxx = 0;
        for (int i = 0; i < n; i++){
            a[i] = get_rand(1, 4);
        }

        for (int i = 0; i < n; i++){
            cout << a[i] << ' ';
        }cout << setw(8) << " ---- ";

        dfs(n, 0);
        cout << setw(3) << maxx << endl;
    }
}