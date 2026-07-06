#include <bits/stdc++.h>
using namespace std;

bool check(int x);
int search(int l, int r){//假如找最小值
    int mid, ans = -1;
    while (l <= r){
        mid = (r-l)/2 + l;
        //mid已经满足题意了，往更小的找
        if (check(mid)){
            ans = mid;
            r = mid - 1;
        }
        //mid还没有满足题意，往更大的找
        else{
            l = mid + 1;
        }
    }
    return ans;
}