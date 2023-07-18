//
vector<int> Z(string s){
    int n=s.size();
    vector<int> z(n);
    z[0]=n;

    int l=0, r=0;
    for(int i=1; i<n; i++){
        if(z[i-l]<r-i+1) z[i]=z[i-l];
        else{
            if(i>r) r=i;
            l=i;
            while(r<n&&s[r-l]==s[r]) r++;
            z[i]=r-l; r--;
        }
    }
    return z;
}
