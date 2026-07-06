#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int> t;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    t.resize(a);
    for (int i = 0; i < a; i++){
        cin >> t[i];
    }
    set<int> A(t.begin(), t.end());

    t.resize(b);
    for (int i = 0; i < b; i++){
        cin >> t[i];
    }
    set<int> B(t.begin(), t.end());

    t.resize(c);
    for (int i = 0; i < c; i++){
        cin >> t[i];
    }
    set<int> C(t.begin(), t.end());

    bool ans = true;
    set<int> extra;
    for (auto x : A){
        if (ans == false) break;
        for (auto y : B){
            if (C.find(x+y) == C.end()){
                ans = false;
                break;
            }
            extra.insert(x+y);
        }
    }
    if (ans == true && extra.size() == C.size()){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0;

}

// int main(){
//     while (1)
//     int t = test();
// }