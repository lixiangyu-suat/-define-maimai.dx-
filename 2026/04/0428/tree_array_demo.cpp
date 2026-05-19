#include <bits/stdc++.h>
using namespace std;

int main(){
    int x; cin >> x;
    int sum, n;
    
    vector<int> s(n);
    for (int i = x; i > 0; i -= (i & -i)){
        int len = i & -i;
        sum += s[i]-s[i-len];
    }
}