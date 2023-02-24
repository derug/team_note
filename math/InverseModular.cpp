const int MAX, MOD;
long long iv[MAX+1];

void init(){
  iv[1] = 1;
  for(int i=2; i<MAX; i++){
    iv[i]=MOD-(MOD/i)*iv[MOD%i]%MOD;
  }
}
