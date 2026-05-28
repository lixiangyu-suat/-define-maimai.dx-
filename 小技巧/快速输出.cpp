#include <iostream>
using namespace std;

void write(int x)
{
    if(x < 0) 
    {
        _putwchar_nolock('-');//win版本,Linux使用 _putchar_unlocked()
        x=-x;
    }
    if(x > 9)
        write(x/10);

    _putchar_nolock(x%10 + '0');
}
int main ()
{
    write(-12345);
    _putchar_nolock('\n');
    return 0;
}