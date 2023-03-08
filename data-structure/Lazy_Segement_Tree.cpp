typedef long long ll;

const ll MAX;

struct LazySeg{
    ll arr[MAX], sgt[4*MAX], lazy[4*MAX];

    SegmentTree(){
        memset(arr,0,sizeof(arr));
        memset(sgt,0,sizeof(sgt));
        memset(lazy,0,sizeof(lazy));
    }

    ll init(int nl, int nr, int node){
        if(nl==nr) return sgt[node]=arr[l];
        int mid=(l+r)/2;
        return sgt[idx]=init(l,mid,2*idx)+init(mid+1,r,2*idx+1);
    }

    void update_lazy(int l, int r, int idx){
        if(lazy[idx]){
            sgt[idx]+=(r-l+1)*lazy[idx];
            if(l!=r){
                lazy[2*idx]+=lazy[idx];
                lazy[2*idx+1]+=lazy[idx];
            }
            lazy[idx]=0;
        }
    }

    ll update(int nl, int nr, int l, int r, ll v, int idx){
        update_lazy(l,r,idx);
        if(nr<l||r<nl) return sgt[idx];
        if(nl<=l&&r<=nr){
            sgt[idx]+=(r-l+1)*v;
            if(l!=r){
                lazy[2*idx]+=v;
                lazy[2*idx+1]+=v;
            }
            return sgt[idx];
        }
        int mid=(l+r)/2;
        return sgt[idx]=update(nl,nr,l,mid,v,2*idx)
            +update(nl,nr,mid+1,r,v,2*idx+1);
    }

    ll query(int nl, int nr, int l, int r, int idx){
        update_lazy(l,r,idx);
        if(r<nl||nr<l) return 0;
        if(nl<=l&&r<=nr) return sgt[idx];
        int mid=(l+r)/2;
        return query(nl,nr,l,mid,2*idx)
            +query(nl,nr,mid+1,r,2*idx+1);
    }
};

const int MAX, INF;

struct Seg{
    int arr[MAX], sgt[MAX*4];

    int init(int l, int r, int node){
        if(l==r) return sgt[node]=arr[l];
        int mid=l+r>>2;
        return sgt[node]=min(init(l, mid, node*2), init(mid+1, r, node*2+1));
    }

    int update(int idx, int val, int nl, int nr, int node){
        if(idx<nl||nr<idx) return sgt[node];
        if(nl==nr) return sgt[node]=min(sgt[node], val);
        int mid=nl+nr>>1;
        return sgt[node]=min(update(idx,val,nl,mid,2*node), update(idx,val,mid+1,nr,2*node+1));
    }

    int query(int l, int r, int nl, int nr, int node){
        if(r<nl||nr<l) return INF;
        if(l<=nl&&nr<=r) return sgt[node];
        int mid=nl+nr>>1;
        return min(query(l, r, nl, mid, 2*node), query(l, r, mid+1, nr, 2*node+1));
    }
};
