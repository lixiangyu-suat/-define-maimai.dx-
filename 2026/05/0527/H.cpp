#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int M[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int sum[13];
int Y = 2017, m0 = 1, d0 = 1;

int cnt(int y, int m, int d){
    int dy = y-Y;
    int dd = sum[m-m0] + d-d0;
    int ans = dy*365 + dd;
    if (y < 2020){

    }
    else if (y == 2020){
        if (m > 2){
            ans++;
        }
    }
    else if(y < 2024){
        ans++;
    }
    else if(y == 2024){
        ans++;
        if (m>2) ans++;
    }
    else{
        ans+=2;
    }
    return ans;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int y, m, d;
    cin >> y >> m >> d;

    sum[0] = 0;
    for (int i = 1; i <= 12; i++){
        sum[i] = sum[i-1] + M[i-1];
    }
    int day2 = cnt(2025, 9, 18);
    int day1 = cnt(y, m, d);
    //cout << day2 << ' ' << day1 << ' ' << (day2 - day1) << endl;
    cout << (day2-day1) << endl;
    return 0;

}
// int main(){
//     while (1) test();
// }