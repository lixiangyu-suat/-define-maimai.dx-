#include <bits/stdc++.h>
using namespace std;

struct COIN{
    int m;
    int v;
};

int main(){
    int N, T;
    cin >> N >> T;
    vector<COIN> coins(N);
    for (int i = 0; i < N; i++){
        int m, v;
        cin >> m >> v;
        coins[i] = {m, v};
    }
    sort(coins.begin(), coins.end(), [&](COIN& a, COIN& b){
        return a.v * b.m > b.v * a.m;
    });

    double sum = 0.0;
    for (int i = 0; i < N; i++){
        if (T == 0) break;
        else if (T <= coins[i].m){
            sum += (double)coins[i].v * T / coins[i].m;
            T = 0;
        }
        else{
            sum += coins[i].v;
            T-=coins[i].m;
        }
    }
    printf("%.2f", sum);
    return 0;
}