#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
bool dp[N];
int a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a+1, a+n+1);

        dp[1] = (a[1] % 2);//或者写成if--else 不要忘记else!!
        for (int i = 2; i <= n; i++){
            if (dp[i-2]) dp[i] = true;
            else if ( (a[i] - a[i-1]) % 2 == 0){
                dp[i] = false;
            }
            else dp[i] = true;
        }
        cout << (dp[n] ? "Insight" : "Maya") << endl;
    }
    return 0;

}