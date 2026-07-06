#include <bits/stdc++.h>
using namespace std;

class BigInt {
private:
    std::vector<int> digits; // 存储数字，低位在低索引 (即反向存储)
    bool is_negative;        // 符号位

    // 移除前导零并处理 -0 的情况
    void trim() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            is_negative = false;
        }
    }

    // 绝对值比较：返回 1 (a > b), -1 (a < b), 0 (a == b)
    static int cmpAbs(const BigInt& a, const BigInt& b) {
        if (a.digits.size() != b.digits.size()) {
            return a.digits.size() > b.digits.size() ? 1 : -1;
        }
        for (int i = a.digits.size() - 1; i >= 0; --i) {
            if (a.digits[i] != b.digits[i]) {
                return a.digits[i] > b.digits[i] ? 1 : -1;
            }
        }
        return 0;
    }

    // 绝对值加法
    static BigInt addAbs(const BigInt& a, const BigInt& b) {
        BigInt res;
        res.digits.clear();
        int carry = 0;
        int maxSize = std::max(a.digits.size(), b.digits.size());
        for (int i = 0; i < maxSize || carry; ++i) {
            int sum = carry;
            if (i < a.digits.size()) sum += a.digits[i];
            if (i < b.digits.size()) sum += b.digits[i];
            res.digits.push_back(sum % 10);
            carry = sum / 10;
        }
        return res;
    }

    // 绝对值减法 (假定 a >= b)
    static BigInt subAbs(const BigInt& a, const BigInt& b) {
        BigInt res;
        res.digits.clear();
        int borrow = 0;
        for (int i = 0; i < a.digits.size(); ++i) {
            int diff = a.digits[i] - borrow - (i < b.digits.size() ? b.digits[i] : 0);
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            res.digits.push_back(diff);
        }
        res.trim();
        return res;
    }

public:
    // 默认构造函数
    BigInt() : is_negative(false) {
        digits.push_back(0);
    }

    // 从 long long 构造
    BigInt(long long v) {
        is_negative = (v < 0);
        if (is_negative) v = -v;
        if (v == 0) digits.push_back(0);
        while (v > 0) {
            digits.push_back(v % 10);
            v /= 10;
        }
    }

    // 从 std::string 构造
    BigInt(const std::string& s) {
        if (s.empty()) {
            is_negative = false;
            digits.push_back(0);
            return;
        }
        is_negative = (s[0] == '-');
        int start = (s[0] == '-' || s[0] == '+') ? 1 : 0;
        for (int i = s.size() - 1; i >= start; --i) {
            if (isdigit(s[i])) {
                digits.push_back(s[i] - '0');
            } else {
                throw std::invalid_argument("Invalid string for BigInt");
            }
        }
        if (digits.empty()) digits.push_back(0);
        trim();
    }

    // ================= 比较运算符 =================
    bool operator==(const BigInt& other) const {
        return is_negative == other.is_negative && digits == other.digits;
    }
    bool operator!=(const BigInt& other) const { return !(*this == other); }
    
    bool operator<(const BigInt& other) const {
        if (is_negative != other.is_negative) return is_negative;
        int absCmp = cmpAbs(*this, other);
        return is_negative ? (absCmp > 0) : (absCmp < 0);
    }
    bool operator>(const BigInt& other) const { return other < *this; }
    bool operator<=(const BigInt& other) const { return !(*this > other); }
    bool operator>=(const BigInt& other) const { return !(*this < other); }

    // ================= 算术运算符 =================
    BigInt operator+(const BigInt& other) const {
        if (is_negative == other.is_negative) {
            BigInt res = addAbs(*this, other);
            res.is_negative = is_negative;
            return res;
        } else {
            int cmp = cmpAbs(*this, other);
            if (cmp >= 0) {
                BigInt res = subAbs(*this, other);
                res.is_negative = is_negative;
                return res;
            } else {
                BigInt res = subAbs(other, *this);
                res.is_negative = other.is_negative;
                return res;
            }
        }
    }

    BigInt operator-(const BigInt& other) const {
        BigInt temp = other;
        temp.is_negative = !temp.is_negative;
        return *this + temp;
    }

    BigInt operator*(const BigInt& other) const {
        BigInt res;
        res.digits.assign(digits.size() + other.digits.size(), 0);
        res.is_negative = (is_negative != other.is_negative);

        for (size_t i = 0; i < digits.size(); ++i) {
            for (size_t j = 0; j < other.digits.size(); ++j) {
                res.digits[i + j] += digits[i] * other.digits[j];
                res.digits[i + j + 1] += res.digits[i + j] / 10;
                res.digits[i + j] %= 10;
            }
        }
        res.trim();
        return res;
    }

    BigInt operator/(const BigInt& other) const {
        if (other == BigInt(0)) {
            throw std::runtime_error("Division by zero");
        }
        BigInt res, current;
        res.digits.assign(digits.size(), 0);
        res.is_negative = (is_negative != other.is_negative);

        BigInt absOther = other;
        absOther.is_negative = false;

        // 模拟手工除法
        for (int i = digits.size() - 1; i >= 0; --i) {
            current.digits.insert(current.digits.begin(), digits[i]);
            current.trim();
            
            while (cmpAbs(current, absOther) >= 0) {
                current = subAbs(current, absOther);
                res.digits[i]++;
            }
        }
        res.trim();
        return res;
    }

    BigInt operator%(const BigInt& other) const {
        if (other == BigInt(0)) {
            throw std::runtime_error("Modulo by zero");
        }
        BigInt res = *this - (*this / other) * other;
        // C++ 风格取模：结果符号与被除数相同
        return res;
    }

    // ================= 输入输出重载 =================
    friend std::ostream& operator<<(std::ostream& os, const BigInt& b) {
        if (b.is_negative) os << '-';
        for (int i = b.digits.size() - 1; i >= 0; --i) {
            os << b.digits[i];
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, BigInt& b) {
        std::string s;
        is >> s;
        b = BigInt(s);
        return is;
    }
};