#include <bits/stdc++.h>
using namespace std;

vector<int> cutdown(vector<int>& d, int l, int r, int x){
    vector<int> ans;
    for (int i = l; i <= r; i++){
        d[i] -= x;
        if (d[i] == 0) ans.push_back(i);
    }
    return ans;
}

void resetborder(vector<int>& nxt0, int l, vector<int>& zero){
    while (!zero.empty()){
        int rightborder = zero.back();
        zero.pop_back();

        int leftborder = (!zero.empty()) ? zero.back() + 1 : l;
        for (int i = rightborder; i >= leftborder; i--){
            nxt0[i] = rightborder;
        }
    }
}
int main(){
    int n; cin >> n;
    vector<int> d(n+1), nxt0(n+1, n);
    for (int i = 0; i < n; i++){
        cin >> d[i];
    }

    int idx = 0;
    long long cnt = 0;
    while (idx < n){
        if (d[idx] == 0){
            idx++;
            continue;
        }
        int mind = *min_element(d.begin()+idx, d.begin()+nxt0[idx]);
        vector<int> newzero = cutdown(d, idx, nxt0[idx]-1, mind);
        resetborder(nxt0, idx, newzero);
        cnt += mind;
    }
    cout << cnt;
    return 0;
}