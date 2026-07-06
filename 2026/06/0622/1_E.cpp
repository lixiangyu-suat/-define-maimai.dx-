#include <bits/stdc++.h>
using namespace std;

int main(){
    int unhappy_day = 0;
    int unhappy = 8;
    for (int i = 1; i <= 7; i++){
        int a, b; cin >> a >> b;
        if (a + b > unhappy) {
            unhappy_day = i;
            unhappy = a + b;
        }
    }
    cout << unhappy_day;
    return 0;
}