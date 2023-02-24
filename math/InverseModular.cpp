const long long MAX, MOD;
long long iv[MAX];

void init(){
  iv[1] = 1;
  for(int i=2; i<MAX; i++){
    iv[i]=MOD-1LL*(MOD/i)*iv[MOD%i]%MOD;
  }
}
