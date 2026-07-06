#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;

    int real_k = 0, sum_k = 0;
    int unreal_k = 0, unsum_k = 0;
    for (int i = 1; i <= n; i++){
        if (i % k){
            real_k++;
            sum_k += i;
        }
        else{
            unreal_k++;
            unsum_k += i;
        }
    }
    printf("%.1f %.1f", unsum_k / (double)unreal_k, sum_k / (double)real_k);
    return 0;
}