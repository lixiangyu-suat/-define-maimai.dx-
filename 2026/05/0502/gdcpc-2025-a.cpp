#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    if (n < m) swap(n, m);
    while (k > 1 && n != m){
        n--; k--;
    }
    if (k == 1){
        cout << ((ll)n * m);
        return 0;
    }
    
    while (k > 2){
        n--; swap(n, m); 
        if (n == m) k-=2;
        else k-=1;
    }
    if (n != m) cout << ((ll)n * m);
    else if (k==1) cout << ((ll)n * m);
    else cout << ((ll)(n-1) * m);
    return 0;
}
/*
int main(){
    while (1) {
        test();
    }
}
    */