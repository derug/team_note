// deg(P)<deg(Q)=d를 만족하는 형식적 멱급수 P(x)/Q(x)의 x^k의 항의 계수를 구하는 알고리즘
// 선형점화식 a_n=sum_{i=1}^{d}{c_i*a_{n-i}}에서 Q(x)=1-sum_{i=1}^{d}{c_i*x^i}라 둘 때,
// 생성함수 A(x)로 P(x)=A(x)*Q(x)를 만드는 것이 가능하다. 이 때, 항상 deg(P)<d 를 만족한다. 
// 시간복잡도: O(M(d)logN)

ModInt bostan_mori(vector<ModInt> p, vector<ModInt> q, ll k){
    vector<ModInt> r, u, v;
    while(k){
        r=q;
        for(int i=1; i<r.size(); i+=2) r[i]*=-1;
        u=multiply(p,r); v=multiply(q,r);
        p.clear(); q.clear();
        for(int i=k&1; i<u.size(); i+=2) p.push_back(u[i]);
        for(int i=0; i<v.size(); i+=2) q.push_back(v[i]);
        k>>=1;
    }
    return p[0]/q[0];
}
