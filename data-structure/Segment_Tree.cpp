typedef long long ll;

const ll MAX, INF;

struct Seg{
    ll arr[MAX], sgt[MAX*4];
    
    Seg(){
        memset(arr,0,sizeof(arr));
        memset(sgt,0,sizeof(sgt));
    }

    ll init(int nl, int nr, int node){
        if(nl==nr) return sgt[node]=arr[l];
        int mid=nl+nr>>2;
        return sgt[node]=min(init(nl, mid, node*2), init(mid+1, nr, node*2+1));
    }

    ll update(int idx, ll val, int nl, int nr, int node){
        if(idx<nl||nr<idx) return sgt[node];
        if(nl==nr) return sgt[node]=min(sgt[node], val);
        int mid=nl+nr>>1;
        return sgt[node]=min(update(idx,val,nl,mid,2*node), update(idx,val,mid+1,nr,2*node+1));
    }

    ll query(int l, int r, int nl, int nr, int node){
        if(r<nl||nr<l) return INF;
        if(l<=nl&&nr<=r) return sgt[node];
        int mid=nl+nr>>1;
        return min(query(l, r, nl, mid, 2*node), query(l, r, mid+1, nr, 2*node+1));
    }
};
