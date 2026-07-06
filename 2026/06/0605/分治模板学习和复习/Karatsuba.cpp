#include <bits/stdc++.h>
using namespace std;

using BigInt = vector<int>;

void remove_leading_zeros(BigInt &A){
    while (A.size() > 1 && A.back() == 0){
        A.pop_back();
    }
}
BigInt add(const BigInt &A, const BigInt &B){
    BigInt C;
    int carry = 0;
    for (size_t i = 0; i < max(A.size(), B.size()) || carry; ++i){
        if (i < A.size()) carry += A[i];
        if (i < B.size()) carry += B[i];
        C.push_back(carry % 10);
        carry /= 10;
    }
    return C;
}

BigInt sub(const BigInt &A, const BigInt &B){
    BigInt C;
    int borrow = 0;
    for (size_t i = 0; i < A.size(); ++i){
        int t = A[i] - borrow;
        if (i < B.size()) t -= B[i];
        if (t < 0){
            t += 10;
            borrow = 1;
        }else{
            borrow = 0;
        }
        C.push_back(t);
    }
    remove_leading_zeros(C);
    return C;
}

BigInt shift(const BigInt& A, int power){
    if (A.size() == 1 && A[0] == 0) return A;
    BigInt C(power, 0);
    C.insert(C.end(), A.begin(), A.end()); // 从左往右读是低位到高位
    return C;
}

BigInt multiply_naive(const BigInt &A, const BigInt &B){
    BigInt C(A.size() + B.size(), 0);
    for (size_t i = 0; i < A.size(); ++i){
        int carry = 0;
        for (size_t j = 0; j < B.size() || carry; ++j){
            long long cur = C[i+j] + (long long)A[i] * (j < B.size() ? B[j] : 0) + carry;
            C[i+j] = cur % 10;
            carry = cur / 10;
        }
    }
    remove_leading_zeros(C);
    return C;
}

BigInt karatsuba(const BigInt &A, const BigInt &B){
    int n = max(A.size(), B.size());

    if (n <= 32){
        return multiply_naive(A, B);
    }

    int m = n / 2;

    BigInt A0(A.begin(), A.begin() + min((int)A.size(), m));
    BigInt A1(A.begin() + min((int)A.size(), m), A.end());
    BigInt B0(B.begin(), B.begin() + min((int)B.size(), m));
    BigInt B1(B.begin() + min((int)B.size(), m), B.end());
    
    if (A0.empty()) A0 = {0};
    if (A1.empty()) A1 = {0};
    if (B0.empty()) B0 = {0};
    if (B1.empty()) B1 = {0};

    BigInt z0 = karatsuba(A0, B0);
    BigInt z2 = karatsuba(A1, B1);

    BigInt t1 = add(A1, A0);
    BigInt t2 = add(B1, B0);
    BigInt z1 = karatsuba(t1, t2);

    BigInt cross_term = sub(sub(z1, z2), z0);

    BigInt res = add(add(shift(z2, 2*m), shift(cross_term, m)), z0);
    return res;
}

BigInt to_BigInt(const string &s){
    BigInt A;
    for (int i = s.size() - 1; i >= 0; --i){
        A.push_back(s[i] - '0');
    }
    return A;
}

void print_BigInt(const BigInt &A){
    for (int i = A.size() - 1; i >= 0; --i){
        cout << A[i];
    }
    cout << endl;
}

int main() {
    string s1 = "1222222100000000000000000000000000000";
    string s2 = "100000000000000000000000000";
    
    BigInt A = to_BigInt(s1);
    BigInt B = to_BigInt(s2);
    
    BigInt res = karatsuba(A, B);
    
    cout << "Result: ";
    print_BigInt(res); // 输出符合预期的 40 位左右的大整数
    
    return 0;
}