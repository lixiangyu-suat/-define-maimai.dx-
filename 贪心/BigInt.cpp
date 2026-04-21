#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

struct BigInt {
    vector<int> d;     // 存储数字，逆序存储：d[0] 是个位
    bool is_neg;       // 符号位：true 为负数，false 为正数

    // 默认构造函数
    BigInt() : is_neg(false) { d.push_back(0); }

    // 从 long long 构造
    BigInt(long long v) {
        if (v < 0) { is_neg = true; v = -v; } 
        else is_neg = false;
        do { d.push_back(v % 10); v /= 10; } while (v > 0);
    }

    // 从字符串构造
    BigInt(string s) {
        is_neg = false;
        if (s.empty()) { d.push_back(0); return; }
        if (s[0] == '-') { is_neg = true; s = s.substr(1); }
        for (int i = s.length() - 1; i >= 0; i--) {
            d.push_back(s[i] - '0');
        }
        trim();
    }

    // 去除前导零，并处理 -0 的情况
    void trim() {
        while (d.size() > 1 && d.back() == 0) d.pop_back();
        if (d.size() == 1 && d[0] == 0) is_neg = false;
    }

    // 绝对值比较：|this| < |b| 返回 true
    bool absLess(const BigInt& b) const {
        if (d.size() != b.d.size()) return d.size() < b.d.size();
        for (int i = d.size() - 1; i >= 0; i--) {
            if (d[i] != b.d[i]) return d[i] < b.d[i];
        }
        return false;
    }

    // 绝对值加法：|this| + |b|
    BigInt absAdd(const BigInt& b) const {
        BigInt res; 
        res.d.clear();
        int carry = 0;
        for (size_t i = 0; i < max(d.size(), b.d.size()) || carry; ++i) {
            int sum = carry;
            if (i < d.size()) sum += d[i];
            if (i < b.d.size()) sum += b.d[i];
            res.d.push_back(sum % 10);
            carry = sum / 10;
        }
        return res;
    }

    // 绝对值减法：|this| - |b|，前提要求 |this| >= |b|
    BigInt absSub(const BigInt& b) const {
        BigInt res; 
        res.d.clear();
        int borrow = 0;
        for (size_t i = 0; i < d.size(); ++i) {
            int diff = d[i] - borrow - (i < b.d.size() ? b.d[i] : 0);
            if (diff < 0) { diff += 10; borrow = 1; }
            else borrow = 0;
            res.d.push_back(diff);
        }
        res.trim();
        return res;
    }

    // 重载加法
    BigInt operator+(const BigInt& b) const {
        if (is_neg == b.is_neg) {
            BigInt res = absAdd(b);
            res.is_neg = is_neg;
            return res;
        }
        if (absLess(b)) {
            BigInt res = b.absSub(*this);
            res.is_neg = b.is_neg;
            return res;
        }
        BigInt res = absSub(b);
        res.is_neg = is_neg;
        return res;
    }

    // 重载减法
    BigInt operator-(const BigInt& b) const {
        BigInt neg_b = b;
        neg_b.is_neg = !neg_b.is_neg;
        return *this + neg_b;
    }

    // 重载乘法
    BigInt operator*(const BigInt& b) const {
        BigInt res; 
        res.d.assign(d.size() + b.d.size(), 0);
        for (size_t i = 0; i < d.size(); ++i) {
            long long carry = 0;
            for (size_t j = 0; j < b.d.size() || carry; ++j) {
                long long cur = res.d[i + j] + 1LL * d[i] * (j < b.d.size() ? b.d[j] : 0) + carry;
                res.d[i + j] = cur % 10;
                carry = cur / 10;
            }
        }
        res.is_neg = (is_neg != b.is_neg);
        res.trim();
        return res;
    }

    // 重载除法
    BigInt operator/(const BigInt& b) const {
        if (b.d.size() == 1 && b.d[0] == 0) throw runtime_error("Division by zero");
        
        BigInt res;
        res.d.assign(d.size(), 0);
        BigInt current = BigInt(0);
        BigInt abs_b = b; 
        abs_b.is_neg = false; // 取除数的绝对值用于计算

        // 从高位到低位模拟长除法
        for (int i = d.size() - 1; i >= 0; i--) {
            current = current * BigInt(10) + BigInt(d[i]);
            
            // 二分法试商 (0~9)
            int l = 0, r = 9, ans = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (!current.absLess(abs_b * BigInt(mid))) {
                    ans = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            res.d[i] = ans;
            current = current - abs_b * BigInt(ans);
        }
        res.is_neg = (is_neg != b.is_neg);
        res.trim();
        return res;
    }

    // 重载取模
    BigInt operator%(const BigInt& b) const {
        BigInt q = *this / b;
        return *this - q * b;
    }
    
// 重载小于号 <
    bool operator<(const BigInt& b) const {
        // 1. 符号不同时，负数永远小于正数
        // （注意：之前的 trim() 已经保证了 0 不会带负号，所以逻辑是安全的）
        if (is_neg != b.is_neg) {
            return is_neg; 
        }
        // 2. 同为正数时，绝对值小的数更小
        if (!is_neg) {
            return absLess(b);
        }
        // 3. 同为负数时，绝对值大的数反而更小（例如 -5 < -3）
        return b.absLess(*this);
    }

    // 重载大于号 >
    bool operator>(const BigInt& b) const {
        // 大于等价于 b 小于自己，直接复用 < 运算符即可
        return b < *this;
    }

    // 重载 += 运算符
    BigInt& operator+=(const BigInt& b) {
        // 直接复用已经写好的 operator+
        *this = *this + b;
        return *this;
    }

    // 重载 *= 运算符
    BigInt& operator*=(const BigInt& b) {
        // 直接复用已经写好的 operator*
        *this = *this * b;
        return *this;
    }

    // 重载输入输出流
    friend ostream& operator<<(ostream& os, const BigInt& b) {
        if (b.is_neg && !(b.d.size() == 1 && b.d[0] == 0)) os << '-';
        for (int i = b.d.size() - 1; i >= 0; i--) os << b.d[i];
        return os;
    }

    friend istream& operator>>(istream& is, BigInt& b) {
        string s;
        if (is >> s) b = BigInt(s);
        return is;
    }
};

int main() {
    BigInt a, b;
    
    cout << "请输入第一个大整数 A: ";
    cin >> a;
    cout << "请输入第二个大整数 B: ";
    cin >> b;

    cout << "\n运算结果:\n";
    cout << "A + B = " << (a + b) << "\n";
    cout << "A - B = " << (a - b) << "\n";
    cout << "A * B = " << (a * b) << "\n";
    
    // 捕获除数为零的异常
    try {
        cout << "A / B = " << (a / b) << "\n";
        cout << "A % B = " << (a % b) << "\n";
    } catch (const runtime_error& e) {
        cout << "A / B = Error (" << e.what() << ")\n";
        cout << "A % B = Error\n";
    }

    return 0;
}