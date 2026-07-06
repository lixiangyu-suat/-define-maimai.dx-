#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<int, int> I; //I[x]里面的区间（I[x], x)一定是有重叠的而且是包含关系
    for (int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        if (I.count(r) == 0) I[r] = 0;
        I[r] = max(I[r], l);
    }
    int cnt = 0;
    int curR = 0;
    for (auto [r, l] : I){
        if (l >= curR){
            curR = r;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}