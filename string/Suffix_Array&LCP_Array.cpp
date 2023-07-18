// 접미사 배열의 사전 순 배열 
// O(Nlog^2N) 에서 정렬을 counting sort로 바꾸면 O(NlogN)이 가능
vector<int> Suffix(string& s){
    int n=s.size();
    vector<int> suf(n);
    vector<int> g(n);

    for(int i=0; i<n; i++) suf[i]=i;
    sort(suf.begin(), suf.end(), [&](int p, int q){
        return s[p]<s[q];
    });
    for(int i=1; i<n; i++){
        g[suf[i]]=g[suf[i-1]];
        if(s[suf[i]]!=s[suf[i-1]]) g[suf[i]]++;
    }

    for(int t=1; t<n; t<<=1){
        sort(suf.begin(), suf.end(), [&](int p, int q){
            if(g[p]==g[q])
                return (p+t<n?g[p+t]:-1)<(q+t<n?g[q+t]:-1);
            return g[p]<g[q];
        });
        vector<int> sg(n);
        for(int i=1; i<n; i++){
            sg[suf[i]]=sg[suf[i-1]];
            if((g[suf[i]]!=g[suf[i-1]])
               ||((suf[i]+t<n?g[suf[i]+t]:-1)!=(suf[i-1]+t<n?g[suf[i-1]+t]:-1)))
                sg[suf[i]]++;
        }
        for(int i=0; i<n; i++) g[i]=sg[i];
    }
    return suf;
}
// suffix array에서 인접한 최장 공통 접두사 길이 배열
vector<int> LCP(string& s, vector<int>& suf){
    int n=s.size();
    vector<int> r(n);
    vector<int> lcp(n,-1);
    for(int i=0; i<n; i++) r[suf[i]]=i;
    int k=0;
    for(int i=0; i<n; i++){
        if(r[i]){
            int j=suf[r[i]-1];
            while(i+k<n&&j+k<n&&s[i+k]==s[j+k]) k++;
            lcp[r[i]]=k;
            if(k) k--;
        }
    }
    return lcp;
}
