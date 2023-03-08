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
        if(nl==nr) return sgt[node]=arr[nl];
        int mid=nl+nr>>1;
        return sgt[node]=init(nl,mid,node*2)+init(mid+1,nr,node*2+1);
    }

    void update_lazy(int nl, int nr, int node){
        if(lazy[node]){
            sgt[node]+=(nr-nl+1)*lazy[node];
            if(l!=r){
                lazy[node*2]+=lazy[node];
                lazy[node*2+1]+=lazy[node];
            }
            lazy[node]=0;
        }
    }

    ll update(int l, int r, ll val, int nl, int nr, int node){
        update_lazy(nl,nr,node);
        if(r<nl||nr<l) return sgt[node];
        if(l<=nl&&nr<=r){
            sgt[node]+=(nr-nl+1)*val;
            if(nl!=nr){
                lazy[node*2]+=val;
                lazy[node*2+1]+=val;
            }
            return sgt[node];
        }
        int mid=nl+nr>>1;
        return sgt[node]=update(l,r,val,nl,mid,node*2)+update(l,r,val,mid+1,nr,node*2+1);
    }

    ll query(int l, int r, int nl, int nr, int node){
        update_lazy(nl,nr,node);
        if(r<nl||nr<l) return 0;
        if(l<=nl&&nr<=r) return sgt[node];
        int mid=nl+nr>>1;
        return query(l,r,nl,mid,node*2)+query(l,r,mid+1,nr,node*2+1);
    }
};
