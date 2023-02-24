typedef unsigned long long ull;

ull sq(ull n, ull r, ull p){
    if(r==0) return 1;
    if(r&1) return n*sq(n,r-1,p)%p;
    ull s=sq(n, r/2, p);
    return s*s%p;
}

bool is_prime(ull n){
    if(n==2) return true;
    if(n%2) return false;
    ull d=n-1, r=0;
    while(d%2==0){d/=2; r++;}
    
    int a[5]={2, 3, 5, 7, 11};
    for(int k=0; k<5; k++){
        if(a[k]==n) return true;
        ull s=sq(a[k], d, n);
        if(s==1||s==n-1) continue;
        for(int i=1; i<r; i++){
            s=sq(s, 2, n);
            if(s==n-1) break;
        }
        if(s!=n-1) return false;
    }
    return true;
}

//폴라드 로 추가 예정
