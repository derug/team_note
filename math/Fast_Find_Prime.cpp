typedef unsigned long long ull;

typedef unsigned long long ull;

inline ull addmod(ull a, ull b, ull p){
    a%=p, b%=p;
    return (a>=p-b?a-(p-b):a+b);
}

inline ull mulmod(ull a, ull b, ull p){
    a%=p, b%=p;
    ull r=0;
    while(b){
        if(b&1) r=addmod(r, a, p);
        a=addmod(a, a, p);
        b>>=1;
    }
    return r;
}

inline ull powmod(ull a, ull b, ull p){
    a%=p;
    ull r=1;
    while(b){
        if(b&1) r=mulmod(r, a, p);
        a=mulmod(a, a, p);
        b>>=1;
    }
    return r;
}

bool miller_rabin(ull a, ull n, ull r){
    if(a>=n) a%=n;
    if(a<=1) return true;
    ull d=n>>r, s=powmod(a, d, n);
    if(s==1||s==n-1) return true;
    while(--r){
        s=powmod(s, 2, n);
        if(s==1) return false;
        if(s==n-1) return true;
    }
    return false;
}

bool is_prime(ull n){
    if(n==2) return true;
    if(n<2||n%2==0) return false;
    ull d=n>>1, r=1;
    while((d&1)==0){d>>=1; r++;}
#define T(a) miller_rabin(a##ull, n, r)
    if(n<4759123141ull) return T(2)&&T(7)&&T(61);
    return T(2)&&T(325)&&T(9375)&&T(28178)&&T(450775)&&T(9780504)&&T(1795265022);
#undef T
}

//폴라드 로 추가 예정
