#include <bits/stdc++.h>
using namespace std;

int get_rand(int min, int max){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<int>(min, max)(rng);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n = 1e7;
    cout << n << endl;
    for (int i = 0; i < n; i++){
        int t = get_rand(1, 1e5);
        cout << t << " ";
    }
    return 0;
}