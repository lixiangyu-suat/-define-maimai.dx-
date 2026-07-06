#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int t;
    vector<int> g;
    for (int i = 0; i < n; i++){
        cin >> t;
        auto it = lower_bound(g.begin(), g.end(), t);
        if (it == g.end()){
            g.push_back(t);
        }
        else{
            (*it) = t;
        }
    }
    cout << g.size();
    return 0;

}