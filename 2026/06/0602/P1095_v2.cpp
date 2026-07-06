#include <bits/stdc++.h>
using namespace std;

const int m1 = 10;
const int vm = 4;
const int v1 = 17;
const int v2 = 60;

int main(){
    int M, S, T;
    cin >> M >> S >> T;
    int m = M;

    int maxdist = 0, greeddist = 0, steaddist = 0;
    for (int t = 1; t <= T; t++){
        //方案1
        if (m >= m1){
            m -= m1;
            greeddist += v2;
        }
        else{
            m += vm;
        }
        //方案2
        steaddist += v1;

        maxdist = max(steaddist, greeddist);
        steaddist = max(steaddist, greeddist);

        if (maxdist >= S){
            cout << "Yes\n" << t;
            cout.flush();
            return 0;
        }
    }
    cout << "No\n" << maxdist;
    cout.flush();
    return 0;
}