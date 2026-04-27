#include <iostream>
using namespace std;

bool measure(int mid,int* sign,int n,int k)
{
    int i=0;
    int cnt=0;
    int loc=0;

    while(i<n)
    {
        if(sign[i]-loc > mid)//距离大于m->在距离loc mid处插一个，插入路标数加一
        {
            cnt++;
            loc+=mid;
        }
        else//距离小于等于mid->跳下一对路标
        {
            loc=sign[i];
            i++;
        }

    }

    if(cnt > k)
        return false;
    else
        return true;
}
int main ()
{
    int l,n,k,mid;
    cin>>l>>n>>k;
    int sign[n+1];
    sign[n]=l;
    for(int i=0;i<n;i++)
        cin>>sign[i];

    int left=1;
    int right=l;

    while(left <= right)
    {
        mid=left+(right-left)/2;
        if(measure(mid,sign,n,k))
            right=mid-1;
        else    
            left=mid+1;
    }
    cout<<right+1<<endl;
    return 0;
}