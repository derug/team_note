// 문자열 s와 i번째로 시작하는 부분 문자열의 최장 공통 접두사 길이 배열
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
