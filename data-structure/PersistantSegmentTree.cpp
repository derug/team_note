const ll MAX;

struct Node{
    ll val;
    Node *l, *r;
    Node(): val(0), l(nullptr), r(nullptr) {}
    Node(ll _val): val(_val), l(nullptr), r(nullptr) {}
};

struct PST{
    ll arr[MAX];
    vector<Node*> root;
    
    PST(){
        memset(arr,0,sizeof(arr)); 
        root.push_back(new Node());
    }

    ll init(int nl, int nr) { return init(nl,nr,root[0]); }
    ll init(int nl, int nr, Node* node){
        if(nl==nr) return node->val=arr[nl];
        int mid=nl+nr>>1;
        node->l=new Node(); node->r=new Node();
        return node->val=init(nl,mid,node->l)+init(mid+1,nr,node->r);
    }

    ll add(int idx, ll val, int nl, int nr) {
        Node* prv=root.back();
        Node* cur=new Node();
        root.push_back(cur);
        return add(idx,val,nl,nr,prv,cur);
    }
    ll add(int idx, ll val, int nl, int nr, Node* prv, Node* cur){
        if(idx<nl||nr<idx) return cur->val;
        if(nl==nr) return cur->val=val;
        int mid=nl+nr>>1;
        if(idx<=mid) cur->l=new Node(), cur->r=prv->r;
        else cur->l=prv->l, cur->r=new Node();
        return cur->val=add(idx,val,nl,mid,prv->l,cur->l)+add(idx,val,mid+1,nr,prv->r,cur->r);
    }

    ll query(int l, int r, int nl, int nr, int q){ return query(l,r,nl,nr,root[q]); }
    ll query(int l, int r, int nl, int nr, Node* cur){
        if(r<nl||nr<l) return 0;
        if(l<=nl&&nr<=r) return cur->val;
        int mid=nl+nr>>1;
        return query(l,r,nl,mid,cur->l)+query(l,r,mid+1,nr,cur->r);
    }
};
