#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    double m, h; cin >> m >> h;

    double BMI = m / (h*h);
    if (BMI < 18.5) cout << "Underweight";
    else if (BMI < 24) cout << "Normal";
    else cout << BMI << "\n" << "Overweight";
    return 0;
}