#include <bits/stdc++.h>
using namespace std;

void merge_sort(vector<int>& arr, int l, int r){
    if (l >= r){
        return;
    }
    int mid = (r-l) / 2 + l;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid+1, r);

    int l1 = l, l2 = mid+1;
    int r1 = mid, r2 = r;

    int i = l1, j = l2, k = 0;
    vector<int> temp(r-l+1);
    while (i <= r1 && j <= r2){
        if (arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while (i <= r1) temp[k++] = arr[i++];
    while (j <= r2) temp[k++] = arr[j++];
    for (int u = l; u <= r; u++){
        arr[u] = temp[u-l];
    }
}

int main(){

}