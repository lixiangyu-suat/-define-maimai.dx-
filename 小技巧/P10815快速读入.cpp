#include <iostream>
#include <cctype>
using namespace std;

inline int read()
{
    int c = _getchar_nolock();
    int f=1;
    int x=0;

    while(c < '0' || c > '9')
    {
        if(c == '-')
            f=-1;
        c=_getchar_nolock();//win版本,linux编译--getchar_unlocked()
    }

    while(c >= '0' && c <= '9')
    {
        x= x<<1 ＋ x<<2 ＋ c^48;
        c=_getchar_nolock();
    }

    return f*x;
}
int main ()
{
    
    int n;
    n=read();
    int tmp;
    long long int sum=0;
    for(int i=0;i<n;++i)
    {
        tmp=read();
        sum+=tmp;
    }

    cout<<sum<<endl;
    return 0;
}
