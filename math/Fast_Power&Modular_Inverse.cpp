const int MOD;

long long fastPow(long long a, long long b){
    if(b==0) return 1;
    if(b&1) return a*fastPow(a,b-1)%MOD;
    long long tmp=fastPow(a,b/2);
    return tmp*tmp%MOD;
}

inline long long divMod(long long a, long long b){
    b=fastPow(b, MOD-2);
    return a*b%MOD;
}
