#include <bits/stdc++.h>
using namespace std;

int main(){
    int need, tot = 0;
    int saved = 0;
    int over_m;
    bool ok = true;
    for (int i = 1; i <= 12; i++){
        tot+=300;
        cin >> need;
        tot -= need;
        if (tot < 0){
            over_m = i;
            ok = false;
            break;
        }
        else if (tot >= 100){
            saved += (tot/100) * 100;
            tot %= 100;
        }
    }

    if (ok) cout << (tot+saved*1.2);
    else cout << "-" << over_m;

    return 0;
}