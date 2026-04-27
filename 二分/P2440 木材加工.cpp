#include <iostream>
using namespace std;

//一遍过^_^
int l[100005]={0};
int main()
{
    int n,k,mid;
    long long int sum=0;
    int tmp =0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
        sum+=l[i];
    }

    int left=1;
    int right=sum/k;
    if(right == 0)
    {
        cout<<"0\n";
        return 0;
    }

    while(left <= right)
    {
        mid = left + (right-left)/2;
        tmp=0;
        for(int i=0;i<n;i++)
        {
            tmp+=l[i]/mid;//段数计算
        }
        if(tmp < k)
            right=mid-1;
        else    
            left=mid+1;
    }
    cout<<left-1<<endl;
    return 0;   
}