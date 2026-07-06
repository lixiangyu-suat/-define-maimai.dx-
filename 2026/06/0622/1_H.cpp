#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int x = sqrt(2*n);
    int r = n-(x+1)*x/2;
    if (r <= 0){
        r = r+x;
        x = x-1;
    }
    int q = x+2-r;
    if ((x+1)&1) swap(q, r);
    printf("%d/%d", r, q);

    return 0;
}