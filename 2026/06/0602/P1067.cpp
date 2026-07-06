#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& a, int i){
    if (i >= 1){
        if (a[i] == 1) {

        }
        else if (a[i] == -1){
            cout << "-";
        }
        else cout << a[i];

        if (i > 1){
            cout << "x^" << i;
        }
        else if (i == 1){
            cout << "x";
        }
    }
    else {
        cout << a[i];
    }
}
int main(){
    int n;
    cin >> n;

    int maxn = n;

    vector<int> a(n+1);
    while (n>=0){
        cin >> a[n--];
    }

    int i = maxn;
    print(a, i);

    for (i = maxn-1; i >= 0; i--){
        if (a[i] == 0) continue;
        else{
            if (a[i] > 0) cout << "+";
        }
        print(a, i);
    }
    cout << endl;
    return 0;
}

// int main(){
//     while (1){
//         test();
//         cout << "\n";
//         cout.flush();
//     }
// }