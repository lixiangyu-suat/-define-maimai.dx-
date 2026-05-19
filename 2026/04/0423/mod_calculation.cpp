#include <bits/stdc++.h>

template <int M>
struct ModInt{
    int v;
    struct PassMod{};
    ModInt(long long x) {
        v = x % M;
    }
    ModInt() : v(0) {}
    ModInt(int x, PassMod u) : v(x) {}

    friend ModInt operator+ (ModInt& l, ModInt& r){
        long long res = l.v + r.v;
        if (res > M) res -= M;
        else if (res < 0) res += M;
        PassMod passmod;
        return ModInt(res, passmod);
    }

    friend ModInt operator- (ModInt& l, ModInt& r){
        long long res = l.v - r.v;
        if (res > M) res -= M;
        else if (res < 0) res += M;
        PassMod passmod;
        return ModInt(res, passmod);
    }

    friend ModInt operator* (ModInt& l, ModInt& r){
        int res = 1LL * l.v * r.v % M;
        PassMod passmod;
        return ModInt(res, passmod);
    }

    ModInt pow(long long b) const { 
        ModInt res{1}, po{*this}; //列表初始化(一致性初始化（Uniform Initialization）)
        for (; b; b >>= 1){
            if (b&1) res = res * po;
            po = po * po;
        }
        return res;
    }

};

const int MOD = 1e9+7;
int main(){
    while (1){
        long long x;
        std::cin >> x;
        ModInt<MOD> a{x}; 
        ModInt<MOD> b{23333}; 
        
        ModInt<MOD> c{616};
        ModInt<MOD> d{};//这里默认用0
        c = c.pow(0);
        c = c.pow(616);

        ModInt<MOD> e(a*b);
        std::cout << a.v << ' ' << b.v << std::endl;
        std::cout << c.v << ' ' << d.v << std::endl;
        std::cout << e.v << std::endl;
    }
    return 0;
}