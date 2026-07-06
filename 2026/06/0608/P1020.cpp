#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 0, t;
    vector<int> a;
    while ( cin >> t ){
        a.push_back(t);
        n++;
    }

    vector<int> down, up;
    for (int i = 0; i < n; i++){
        if (down.empty() || a[i] <= down.back()) down.push_back(a[i]);
        else{
            auto it = upper_bound(down.begin(), down.end(), a[i], greater<int>());
            *it = a[i];
        }
    }
    cout << down.size() << "\n";

    for (int i = 0; i < n; i++){
        if (up.empty() || a[i] > up.back()) up.push_back(a[i]);
        else{
            auto it = lower_bound(up.begin(), up.end(), a[i]);
            *it = a[i];
        }
    }
    cout << up.size() << "\n";
    return 0;
}