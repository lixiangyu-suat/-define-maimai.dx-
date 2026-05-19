#include <vector>
#include <iostream>
#include <numeric>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> b(n+1), c(n+1);
        int x, y;
        cin >> x;
        for (int i = 1; i < n; i++){
            cin >> y;
            c[i] = gcd(x, y); //b[1....n], c[1....n-1]
            x = y;
        }
        
        for (int i = 1; i <= n; i++) cin >> b[i];
        int cnt = 0; c[0] = c[n] = 1;
        for (int i = 1; i <= n; i++) if (b[i] > lcm(c[i-1], c[i])) cnt++;
        cout << cnt << '\n';
    }
    return 0;
}