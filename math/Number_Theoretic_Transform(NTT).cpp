const int MOD=998244353;
using ModInt=Modular<MOD>;

void ntt(vector<ModInt>& f, bool invert){
    int n=f.size();
    for(int i=1, j=0; i<n; i++){
        int bit=n>>1;
        for(;j>=bit;bit>>=1) j-=bit;
        j+=bit;
        if(i<j) swap(f[i],f[j]);
    }
    for(int k=2; k<=n; k<<=1){
        ModInt ang=(ModInt::mod()-1)/k;
        ModInt w=ModInt::power(ModInt::root(),ang);
        if(invert) w=1/w;
        for(int i=0; i<n; i+=k){
            ModInt wp(1);
            for(int j=0; j<k/2; j++){
                ModInt u=f[i+j], v=wp*f[i+j+k/2];
                f[i+j]=u+v;
                f[i+j+k/2]=u-v;
                wp*=w;
            }
        }
    }
    if(invert) for(int i=0; i<n; i++) f[i]/=n;
}

vector<ModInt> multiply(vector<ModInt> a, vector<ModInt> b){
    int n=1, sz=a.size()+b.size()-1;
    while(n<a.size()+b.size()) n<<=1;
    a.resize(n); b.resize(n);
    ntt(a,false); ntt(b,false);
    for(int i=0; i<n; i++) a[i]*=b[i];
    ntt(a,true); a.resize(sz);
    return a;
}
