#include <bits/stdc++.h>
using namespace std;

const int m1 = 10;
const int vm = 4;
const int v1 = 17;
const int v2 = 60;

int main(){
    int M, S, T;
    cin >> M >> S >> T;
    int t = T;
    int s = 0;
    int m = M;

    bool finished = false;
    while (t && !finished){
        int ds = S-s;
        if (m >= m1){
            t--;
            s += v2;
            m -= m1;
        }
        else if (ds <= 2*v1){
            t--;
            s += v1;
        }
        else if (m >= m1-vm && t >= 2){
            t-=2;
            s += v2;
            m -= (m1-vm);
        }
        else if (ds <= 3*v1){
            t--;
            s += v1;
        }
        else if (m >= m1-2*vm && t >= 3){
            t-=3;
            s += v2;
            m -= (m1-2*vm);
        }
        else if (ds <= 4*v1){
            t--;
            s += v1;
        }
        else if (t >= 4){
            t-=4;
            s += v2;
            m -= (m1-3*vm);
        }
        else {
            t--;
            s += v1;
        }

        if (s >= S){
            finished = true;
        }
    }

    if (finished){
        cout << "YES\n" << (T-t);
    }
    else{
        cout << "NO\n" << s;
    }
    cout.flush();

    return 0;
}

// int main(){
//     while (1) test();
// }