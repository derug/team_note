#define all(x) (x).begin(), (x).end()

const int MAX;

struct MSTree{
    int arr[MAX];
    vector<int> tree[4*MAX];

    MSTree(){
        memset(arr,0,sizeof(arr));
    }

    void init(int nl, int nr, int node){
        if(nl==nr){
            tree[node].push_back(arr[nl]);
            return;
        }
        int mid=nl+nr>>1;
        init(nl,mid,node*2);
        init(mid+1,nr,node*2+1);
        tree[node].resize(tree[node*2].size()+tree[node*2+1].size());
        merge(all(tree[node*2]),all(tree[node*2+1]),tree[node].begin());
    }

    int query(int l, int r, int k, int nl, int nr, int node){
        if(r<nl||nr<l) return 0;
        if(l<=nl&&nr<=r) return tree[node].end()-upper_bound(all(tree[node]),k);
        int mid=nl+nr>>1;
        return query(l,r,k,nl,mid,node*2)+query(l,r,k,mid+1,nr,node*2+1);
    }
};
