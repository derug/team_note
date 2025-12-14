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
