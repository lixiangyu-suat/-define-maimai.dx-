#include <bits/stdc++.h>
using namespace std;

int main(){
    int x; cin >> x;
    for (int i = 0; i < x; i++){
        int t;
        cin >> t;
        if (t >= 67) cout << 67 << endl;
        else if (t < -67) cout << -67 << endl;
        else cout << t+1 << endl;
    }
    return 0;
}