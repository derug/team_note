ll MEX(vector<ll> v)
{
    sort(v.begin(), v.end());
    ll ret = 0;
    for(int i=0;i<v.size();i++)
        if(v[i] == ret) ret++;
        else if(v[i] > ret) return ret;
    return ret;
}
