typedef long long ll;

const ll MAX, INF;

struct Seg{
    ll arr[MAX], sgt[MAX*4];
    
    Seg(){
        memset(arr,0,sizeof(arr));
        memset(sgt,0,sizeof(sgt));
    }

    ll init(int nl, int nr, int node){
        if(nl==nr) return sgt[node]=arr[nl];
        int mid=nl+nr>>1;
        return sgt[node]=min(init(nl,mid,node*2), init(mid+1,nr,node*2+1));
    }

    ll update(int idx, ll val, int nl, int nr, int node){
        if(idx<nl||nr<idx) return sgt[node];
        if(nl==nr) return sgt[node]=min(sgt[node], val);
        int mid=nl+nr>>1;
        return sgt[node]=min(update(idx,val,nl,mid,node*2), update(idx,val,mid+1,nr,node*2+1));
    }

    ll query(int l, int r, int nl, int nr, int node){
        if(r<nl||nr<l) return INF;
        if(l<=nl&&nr<=r) return sgt[node];
        int mid=nl+nr>>1;
        return min(query(l,r,nl,mid,node*2), query(l,r,mid+1,nr,node*2+1));
    }
};

// ver. 2

ll init(int idx, int s, int e)
{
	if (s == e) return T[idx] = a[s];
	int m = s + e >> 1;
	return T[idx] = init(idx * 2, s, m) + init(idx * 2 + 1, m + 1, e);
}
ll upd(int idx, int s, int e, int t, ll val)
{
	if (t < s || e < t) return T[idx];
	if (s == e) return T[idx] = val;
	int m = s + e >> 1;
	return T[idx] = upd(idx * 2, s, m, t, val) + upd(idx * 2 + 1, m + 1, e, t, val);
}
ll qry(int idx, int s, int e, int l, int r)
{
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return T[idx];
	int m = s + e >> 1;
	return qry(idx * 2, s, m, l, r) + qry(idx * 2 + 1, m + 1, e, l, r);
}

