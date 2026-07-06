#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> a(N);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    int idx = 0;
    while (cin >> t){
        a[idx++] = t;
    }

    int n = idx;
    vector<int> len;
    for (int i = 0; i < n; i++){
        if (len.empty() || len.back() >= a[i]) len.push_back(a[i]);
        else{
            auto it = upper_bound(len.begin(), len.end(), a[i], greater<int>());
            *it = a[i];
        }
    }
    cout << len.size();
    len.clear();

    for (int i = 0; i < n; i++){
        if (len.empty() || len.back() < a[i]) len.push_back(a[i]);
        else{
            auto it = lower_bound(len.begin(), len.end(), a[i]);
            *it = a[i];
        }
    }
    cout << endl << len.size();
    return 0;
}