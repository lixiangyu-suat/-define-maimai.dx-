#include <bits/stdc++.h>
using namespace std;

int log2(long long x, long long y){
    int t = 0;
    while (true){
        if (x > y) break;
        t++;
        x *= 2;
    }
    return t;
}
int main(){
    long long x, y;
    cin >> x >> y;

    cout << log2(x, y) << endl;
    return 0;
}