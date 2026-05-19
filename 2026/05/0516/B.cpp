// #include <bits/stdc++.h>
// using namespace std;

// int a[1000005]={0};
// int g[1000005];
// int fre[1000005]={0};
// int ans[1000005]={0};
// int n,gmax;

// int f(int x,int y)
// {
//     if(x == 0)  return 0;
//     if (y == 1) return g[x]= x;
//     if(g[x] != -1)  return g[x];
//     int l=1;
//     int r=n;
//     int mid;
//     while(l <= r)
//     {
//         mid=r+(r-l)/2;
//         if(a[mid] >= x)
//             r=mid-1;
//         else
//             l=mid+1;
//     }    
//     cout<<l<<"===\n";
//     return  g[x]=x/a[l]+f(x%a[l],y-1);
// }

// void init()
// {
//     for(int i = 1; i <= a[n]; ++i) {
//         g[i] = -1;
//     }
    
//     for(int i=1;i<=a[n];++i)
//     {
//         f(i,n);
//     }
// cout<<"===\n";
//     gmax=0;
//     fre[0]=0;
//     for(int r=1;r<=a[n];++r)
//     {
//         fre[g[r]]++;
//         gmax=max(g[r],gmax);
//     }

//     ans[0]=fre[0];
//     for(int i=1;i<=gmax;++i)
//     {
//         ans[i]=ans[i-1]+fre[i];
//     }
// }

// int main ()
// {
//     int q;
//     cin>>n>>q;

//     for(int i=1;i<=n;++i)
//     {
//         cin>>a[i];
//     }

//     init();
    
//     for(int i=1;i<=a[n];++i)
//     {
//         cout<<g[i]<<" ";
//     }
//     // int m;
//     // while(q--)
//     // {
//     //     cin>>m;
//     //     if(m >=gmax)
//     //         cout<<ans[gmax]<<" ";
//     //     else
//     //         cout<<ans[m]<<" ";
//     // }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;


vector<int> a, g, fre, ans;
int n, gmax;

int f(int x, int y) {
    if (x == 0) return 0;
    if (y == 1) return g[x] = x;
    if (g[x] != -1) return g[x];
    auto it = upper_bound(a.begin(), a.end(), x) -1;
    int k = x / (*it);
    return g[x] = k + f (x % *(it), y-1);
} 

int main ()
{
    freopen("input.txt", "r", stdin);
    int q;
    cin>>n>>q;

    a.resize(n);
    for(auto & i : a) cin >> i;

    g.resize(a[n-1] +1, -1);
    fre.resize(a[n-1]+1);
    for(int i = 0; i <= a[n-1]; ++i) {
        f (i, n);
        //cout << i << " " << n << " "<<f(i, n) << endl;
    }
    gmax = *max_element(g.begin(), g.end());
    for(int i = 0; i <= a[n-1]; ++i) {
        fre[g[i]]++;
    }
    ans.resize(gmax+1);
    ans[0] = fre[0];
    for(int i = 1; i <= gmax; ++i) {
        if (i <= a[n-1])
            ans[i] = ans[i-1] + fre[i];
        else ans[i] = ans[i-1];
    }
    
    // for(int i=0;i<a[n-1];++i)
    // {
    //     cout<<g[i]<<" ";
    // }
    int m;
    while(q--)
    {
        cin>>m;
        if(m >=gmax)
            cout<<ans[gmax]<<" ";
        else
            cout<<ans[m]<<" ";
    }
    return 0;
}