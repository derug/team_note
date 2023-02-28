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

ull gcd(ull a, ull b){
    if(!b) return a;
    return gcd(b,a%b);
}

ull pollard_rho(ull n){
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<ull> dist(1,n-1);
    ull a, b, c, g=1;
    a=b=dist(gen);
    c=dist(gen);
    function<ull(ull)> f=[&](ull x){
        return addmod(mulmod(x,x,n),c,n);
    };
    while(g==1){
        a=f(a);
        b=f(f(b));
        g=gcd(a>b?a-b:b-a,n);
    }
    return g;
}

// 무작위 순서로 소인수분해
void factorize(ull n, vector<ull>& f){
    if(n==1) return;
    if(n%2==0){
        f.push_back(2);
        factorize(n/2, f);
    }
    else if(is_prime(n)){
        f.push_back(n);
    }
    else{
        ull p=pollard_rho(n);
        factorize(p, f);
        factorize(n/p, f);
    }
}
