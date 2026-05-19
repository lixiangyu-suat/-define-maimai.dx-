#include <bits/stdc++.h>
using namespace std;

int calcd(int x, int a, int b){
    // 防止 a * b > x 导致 c 出现负数（题目要求非负整数）
    if (a * b > x) return 0x3f3f3f3f; 
    
    int c = x - a * b;
    int M = max({a, b, c});
    int m = min({a, b, c});
    return (M-m);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; 
    if (cin >> t) {
        while (t--){
            int x; cin >> x;
            int mind = 0x3f3f3f3f;
            
            for (int a = sqrt(x); a >= 0; a--){
                // 必须使用理论下限进行剪枝，而不是用当前 d 值
                if (x / (a + 1) - a >= mind) break;
                
                // 保证 b >= a，维持单调性前提
                int b1 = max(a, x / (a + 1)); 
                int b2 = b1 + 1;
                
                int d1 = calcd(x, a, b1);
                int d2 = calcd(x, a, b2);
                int d = min(d1, d2);
                
                mind = min(mind, d);
            }
            cout << mind << endl;
        }
    }
    return 0;
}