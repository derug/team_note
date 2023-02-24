const int MAX;
bool isPrime[MAX+2];
vector<int> prime;

void findPrime(){
  memset(isPrime,true,sizeof(isPrime));
  isPrime[0]=isPrime[1]=false;
  for(long long i=2; i*i<=MAX; i++){
    if(isPrime[i]){
      prime.push_back(i);
      for(long long j=i*i; j<=MAX; j+=i)
        isPrime[j]=false;
    }
  }
}

vector<pair<int,int>> prime_fact(int n){
  vector<pair<int,int>> tmp;
  if(n==1) return tmp;
  for(int p: prime){
    if(n<=MAX&&isPrime[n]){tmp.push_back({n,1}); return tmp;}
    if(n%p==0) tmp.push_back({p,0});
    while(n%p==0){
      tmp.back().second++;
      n/=p;
    }
  }
  if(n>1) tmp.push_back({n,1});
  return tmp;
}

int num_of_divisors(int n){
  auto factor = prime_fact(n);
  int tmp=1;
  for(auto a: factor)
    tmp*=a.second + 1;
  return tmp;
}

int euler_phi(int n){
  auto factor = prime_fact(n);
  int tmp=n;
  for(auto a: factor)
    tmp=tmp/a.first*(a.first-1);
  return tmp;
}
