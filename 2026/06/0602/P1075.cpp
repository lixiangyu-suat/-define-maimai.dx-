#include <bits/stdc++.h>
using namespace std;

bool isprime(int x){
    for (int i = 2; i * i <= x; i++){
        if (x % i == 0) return false;
    }
    return true;
}
int main(){
    int n; cin >> n;
    for (int i = 2; i * i <= n; i++){
        if (isprime(i)){
            if (n % i == 0){
                cout << (n / i);
                break;
            }
        }
    }
    return 0;
}