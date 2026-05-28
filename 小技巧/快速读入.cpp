#include <iostream>
using namespace std;

int main ()
{
    
    ios::sync_with_stdio(0);//取消scanf,printf兼容
    cin.tie(0);//解除自动刷新缓存区,使用cout.flush() / cout<<flush /cout<<endl 手动刷新
    // cout.tie(0);optional
    return 0;
}