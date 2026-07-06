#include <bits/stdc++.h>
using namespace std;

const int N = 1e2+5;
int a[N];

int n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--){
        vector<int> remain;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n);

        cout << a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i-1]) cout << ' ' << a[i];
            else remain.push_back(a[i]);
        }
        for (auto v : remain) cout << ' ' << v;
        cout << "\n";
    }
    return 0;
}