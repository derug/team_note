int a[5]={2, 3, 5, 7, 11};

unsigned long long sq(unsigned long long n, unsigned long long r, unsigned long long p){
    if(r==1) return n;
    ull s=sq(n, r/2, p);
    s=s*s%p;
    if(r%2) return n*s%p;
    return s;
}

bool check(ull n){
    ull d=n-1, r=0;
    while(d%2==0){
        d/=2;
        r++;
    }
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
