typedef long long ll;

const int MAX;
struct SegmentTree{
    ll arr[MAX], sgt[4*MAX], lazy[4*MAX];

    SegmentTree(){
        memset(sgt,0,sizeof(sgt));
        memset(lazy,0,sizeof(lazy));
    }

    ll init(int l, int r, int idx){
        if(l==r) return sgt[idx]=arr[l];
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
