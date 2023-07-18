// 각 글자를 중심으로 했을 때 최대 회문 길이 배열
vector<int> Manacher(const string& s){
    int n=s.size();
    string t="";
    for(int i=0; i<n; i++){ t+='.'; t+=s[i]; }
    t+='.';
    n=t.size();

    int r=0, p=0;
    vector<int> A(n);
    for(int i=0; i<n; i++){
        if(i<=r) A[i]=min(r-i,A[2*p-i]);
        while(0<=i-A[i]-1&&i+A[i]+1<n&&t[i-A[i]-1]==t[i+A[i]+1]) A[i]++;
        if(r<i+A[i]) r=i+A[i], p=i;
    }
    return A;
}
