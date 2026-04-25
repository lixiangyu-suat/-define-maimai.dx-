#include <iostream>
using namespace std;

bool jump(int mid,int *stone,int n,int m)
{
    int now=0;
    int i=0;
    int cnt=0;

    while(i<n+1)
    {
        i++;
        if(stone[i]-stone[now] < mid)
            cnt++;
        else
            now=i;
    }

    if(cnt > m)
        return false;
    else    //cnt<=m
        return true;
}
int main()
{
    int l,n,m,mid;
    cin>>l>>n>>m;
    int stone[n+2];
    stone[0]=0;
    stone[n+1]=l;
    for(int i=1;i<=n;i++)
    {
        cin>>stone[i];
    }

    int right=l;
    int left=1;

    while(left <= right)
    {
        mid = left+(right-left)/2;

        if(jump(mid,stone,n,m))
            left=mid+1;
        else
            right=mid-1;
    }
    cout<<right<<endl;
    return 0;
}