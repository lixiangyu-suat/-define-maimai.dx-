#include <bits/stdc++.h>
using namespace std;

int ori[3];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 3; i++) cin >> ori[i];
    sort(ori, ori+3);
    map<char, int> num;
    num['A'] = ori[0]; num['B'] = ori[1]; num['C'] = ori[2];

    cin.ignore();
    for (int i = 0; i < 3; i++){
        char t = cin.get();
        if (i != 0) cout << ' ';
        cout << num[t];
    }
    return 0;
}