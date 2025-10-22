#include<bits/stdc++.h>

using namespace std;

template<int M>
struct Modular{
    static const int32_t MOD=M;
    int32_t value;
    constexpr Modular(): value(0) {}
    template<typename T> Modular(const T& v): value(v%MOD) { if(value<0) value+=MOD; }

    template<typename T> static T inv(T x, T m) { return x>1?m-1LL*inv(m%x,x)*m/x:1; }
    static Modular power(Modular x, int64_t p){
        Modular result=1;
        while(p>0) {
            if(p&1) result*=x;
            x*=x; p>>=1;
        }
        return result;
    }
    static Modular root(int32_t n){
        vector<int32_t> fact;
        // int32_t phi=euler_totient(n);
        int32_t phi=n-1;
        int32_t m=phi;
        for(int32_t d=2; d*d<=m; d++){
            if(m%d==0){
                fact.push_back(d);
                while(m%d==0) m/=d;
            }
        }
        if(m>1) fact.push_back(m);
        for(int32_t rt=2; rt<n; rt++){
            bool found=true;
            for(int32_t d: fact){
                if(power(rt,phi/d)==1){
                    found=false;
                    break;
                }
            }
            if(found) return rt;
        }
    }
    static const Modular& root() {
        static const Modular rt=root(M);
        return rt;
    }

    template<typename T> operator T() const { return static_cast<T>(value); }
    const int32_t operator ()() const { return value; }

    friend Modular operator +(const Modular& lhs, const Modular& rhs) { return Modular(lhs)+=rhs; }
    friend Modular operator -(const Modular& lhs, const Modular& rhs) { return Modular(lhs)-=rhs; }
    friend Modular operator *(const Modular& lhs, const Modular& rhs) { return Modular(lhs)*=rhs; }
    friend Modular operator /(const Modular& lhs, const Modular& rhs) { return Modular(lhs)/=rhs; }

    Modular& operator +=(const Modular& other) { value+=other.value; value-=(value>=MOD)*MOD; return *this; }
    Modular& operator -=(const Modular& other) { value-=other.value; value+=(value<0)*MOD; return *this; }
    Modular& operator *=(const Modular& other) { value=1LL*value*other.value%MOD; return *this; }
    Modular& operator /=(const Modular& other) { value=1LL*value*inv(other.value,MOD)%MOD; return *this; }
    Modular& operator ++() { return *this+=1; }
    Modular& operator --() { return *this-=1; }
    Modular operator ++(int) { Modular result(*this); *this+=1; return result; }
    Modular operator --(int) { Modular result(*this); *this-=1; return result; }
    Modular operator -() const { return Modular(-value); }

    friend bool operator <(const Modular& lhs, const Modular& rhs) { return lhs.value<rhs.value; }
    friend bool operator ==(const Modular& lhs, const Modular& rhs) { return lhs.value==rhs.value; }
    friend bool operator >(const Modular& lhs, const Modular& rhs) { return lhs.value>rhs.value; }
    friend bool operator !=(const Modular& lhs, const Modular& rhs) { return lhs.value!=rhs.value; }
    friend bool operator <=(const Modular& lhs, const Modular& rhs) { return lhs.value<=rhs.value; }
    friend bool operator >=(const Modular& lhs, const Modular& rhs) { return lhs.value>=rhs.value; }

    friend const int32_t abs(const Modular& number) { return number.value; }
    friend string to_string(const Modular& number) { return to_string(number.value); }
    friend istream& operator >>(istream& is, Modular& number) { long long x; is >> x; number=Modular(x); return is; }
    friend ostream& operator <<(ostream& os, const Modular& number) { return os << number(); }
};

const int MOD=1e9+7;
using ModInt=Modular<MOD>;
