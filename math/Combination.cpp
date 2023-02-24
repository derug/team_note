const int MAX, MOD;
long long ft[MAX+1], nft[MAX+1], iv[MAX+1];

void init(){
  ft[0]=nft[0]=1;
  ft[1]=nft[1]=iv[1]=1;
  for(int i=2; i<=MAX; i++){
    iv[i]=MOD-(MOD/i)*iv[MOD%i]%MOD;
    ft[i]=ft[i-1]*i%MOD;
    nft[i]=nft[i-1]*iv[i]%MOD;
  }
}

inline long long comb(int n, int r){
  if(r<0||n<r) return 0;
  return ((ft[n]*nft[r]%MOD)*nft[n-r])%MOD;
}

long long bigComb(long long n, long long r){
  
}
