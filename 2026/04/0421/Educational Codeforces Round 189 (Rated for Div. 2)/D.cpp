#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" ,stdin);
    #endif

    int t; cin >> t;
    while (t--){
        long long cnt = 0;
        long long n, u; cin >> n >> u;
        if (n%2 == 0){//偶
            //cnt = (n-u+1)/4 + (u-1)/4 + (n-u-1)/4 + (u-1+2)/4;
            if (u+2<=n && u-1>=1){
                cnt = cnt + 1 + (n-u-2)/4 + (u-2)/4;
            }
            if (u+1<=n && u-2>=1){
                cnt = cnt + 1 + (n-u-1)/4 + (u-3)/4;
            }
            //if (u+1<=n && u-2>=1 && u+2<=n && u-1>=1) cnt--;
        }else{
            //cnt = (n-u+2)/4 + (u-2)/4 + (n-u)/4 + (u-4)/4;
            if (u<=n && u-3>=1){
                cnt = cnt + 1 + (n-u)/4 + (u-4)/4;
            }
            if (u+2<=n && u-1>=1){
                cnt = cnt + 1 + (n-u-2)/4 + (u-2)/4;
            }

        }
        cout << (cnt%MOD) << endl;
        
    }
    return 0;
}