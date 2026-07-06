#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5+5;
int cnt[11];
int pow(int x, int n){
    while (n>1){
        n--;
        x *= 10;
    }
    return x;
}
int getbit(int x){
    int c = 0;
    while (x){
        c++;
        x /= 10;
    }
    return c;
}
int min(int x, int y){
    if (x <= y) return x;
    return y;
}

int SJ(int m, int d){
    int r = 0;
    string month = to_string(m);

    for (int i = month.length(); i > 0; i--){
        string x1 = month.substr(0, i);
        string x1_rev = x1;
        reverse(x1_rev.begin(), x1_rev.end());
        if (x1_rev == to_string(d))
    }
    return r;
}

signed main(){
    // while (true){
    //     int a, b;
    //     cin >> a >> b;
    //     cout << SJ(a, b) << endl;
    // }
    memset(cnt, 0, sizeof(cnt));
    cnt[1] = 10;
    cnt[2] = 10;
    for (int i = 3; i <= 10; i++){
        cnt[i] = 9*cnt[i-2];
    }
    for (int i = 2; i <= 10; i++){
        cnt[i] = cnt[i-1] + cnt[i]; //cnt : 0---10^i - 1的回文数个数
    }
    for (int i = 1; i <= 10; i++){
        cnt[i]--;
    }

    int T; cin >> T;
    int c; cin >> c;
    while (T--){
        int tot = 0;
        int n; cin >> n;
        vector<int> d(n+1);
        for (int i = 1; i <= n; i++){
            cin >> d[i];
        }
        for (int i = 1; i <= n; i++){
            int sub = 0;
            int day = pow(10, d[i])-1;
            if (getbit(i) < getbit(day)){
                sub += cnt[getbit(day)-getbit(i)];
            }
            sub += SJ(i, day);
            cout << "i=" << i << " ,sub = " << sub << endl;
            //cout << sub << ' ';
            tot += sub;
        }
        cout << tot << endl;
    }
}