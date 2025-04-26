ll MEX(vector<ll> v)
{
    sort(v.begin(), v.end());
    ll ret = 0;
    for(int i=0;i<v.size();i++)
        if(v[i] == ret) ret++;
        else if(v[i] > ret) return ret;
    return ret;
}

struct Random{
    random_device rd;
    mt19937 gen;
    Random(){ gen.seed(rd()); }
    int get(int l, int r){ return uniform_int_distribution<int>(l,r)(gen); }
} rnd;

ll fastpow(ll x, ll y)
{
    if(!y) return 1;
    ll t=f(x, y/2);
    return t*t%MOD*(y&1?x:1)%MOD;
}
