// #include <bits/stdc++.h>
// using namespace std;

// int ans[16] = {0};
// int main(){
//     int k; cin >> k;
//     int n = 0;
//     double s = 0;
//     int idx = 1;
//     while (true){
//         n++;
//         s += (1.0 / n);
//         if (s > idx){
//             cout << " " << n << ",";
//             idx++;
//         }
//         if (idx == 16) break;
//     }
//     //cout << ans[k];
//     return 0;
// }

#include <bits/stdc++.h>
int ans[16] = {0, 2, 4, 11, 31, 83, 227, 616, 1674, 4550, 12367, 33617, 91380, 248397, 675214, 1835421};
int main(){ int k; std::cin >> k; std::cout << ans[k]; }