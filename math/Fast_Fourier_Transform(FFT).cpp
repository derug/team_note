const double PI=acos(-1);

void fft(vector<complex<double>>& f, bool invert){
    int n=f.size();
    for(int i=1, j=0; i<n; i++){
        int bit=n>>1;
        for(;j>=bit;bit>>=1) j-=bit;
        j+=bit;
        if(i<j) swap(f[i],f[j]);
    }
    for(int k=2; k<=n; k<<=1){
        double ang=2*PI/k*(invert?-1:1);
        complex<double> w(cos(ang), sin(ang));
        for(int i=0; i<n; i+=k){
            complex<double> wp(1);
            for(int j=0; j<k/2; j++){
                complex<double> u=f[i+j], v=wp*f[i+j+k/2];
                f[i+j]=u+v;
                f[i+j+k/2]=u-v;
                wp*=w;
            }
        }
    }
    if(invert) for(int i=0; i<n; i++) f[i]/=n;
}

vector<int> multiply(const vector<int>& a, const vector<int>& b){
    vector<complex<double>> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n=1, sz=a.size()+b.size()-1;
    while(n<a.size()+b.size()) n<<=1;
    fa.resize(n); fb.resize(n);
    vector<int> c(n);
    fft(fa,false); fft(fb,false);
    for(int i=0; i<n; i++) fa[i]*=fb[i];
    fft(fa,true); c.resize(sz);
    for(int i=0; i<n; i++) c[i]=round(fa[i].real());
    return c;
}
