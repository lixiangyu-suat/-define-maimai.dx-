#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int p, c;
    int sum = INT_MAX;
    for (int i = 0; i < 3; i++){
        cin >> p >> c;
        sum = min(sum, (n-1+p)/p * c);
    }
    cout << sum;
    return 0;
}