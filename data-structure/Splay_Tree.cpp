struct Node{
    Node *l, *r, *p;
    int cnt, key;

    Node(int _key){
        l=r=p=NULL;
        key=_key;
        cnt=1;
    }
};

struct SplayTree{
    Node* root;

    void update(Node *x){
        x->cnt=1;
        if(x->l) x->cnt+=x->l->cnt;
        if(x->r) x->cnt+=x->r->cnt;
    }
    
    void rotate(Node *x){
        Node *p=x->p;
        Node *b=NULL;
        if(!p) return;
        if(x==p->l){
            p->l=b=x->r;
            x->r=p;
        }
        else{
            p->r=b=x->l;
            x->l=p;
        }
        x->p=p->p;
        p->p=x;
        if(b) b->p=p;
        (x->p?p==x->p->l?x->p->l:x->p->r:root)=x;
        update(p);
        update(x);
    }

    void splay(Node *x){
        while(x->p){
            Node *p=x->p;
            Node *g=p->p;
            if(g) rotate((x==p->l)==(p==g->l)?p:x);
            rotate(x);
        }
    }

    void insert(int key){
        Node *p=root, **pp;
        if(!p){
            Node *x=new Node(key);
            root=x;
            return;
        }
        while(1){
            if(key<p->key){
                if(!p->l){
                    pp=&p->l;
                    break;
                }
                p=p->l;
            }
            else if(key>p->key){
                if(!p->r){
                    pp=&p->r;
                    break;
                }
                p=p->r;
            }
            else return;
        }
        Node *x=new Node(key);
        *pp=x;
        x->p=p;
        splay(x);
    }

    bool find(int key){
        Node *p=root;
        if(!p) return false;
        while(p){
            if(key<p->key){
                if(!p->l) break;
                p=p->l;
            }
            else if(key>p->key){
                if(!p->r) break;
                p=p->r;
            }
            else break;
        }
        splay(p);
        return key==p->key;
    }

    void erase(int key){
        if(!find(key)) return;
        Node *p=root;
        if(p->l&&p->r){
            root=p->l;
            root->p=NULL;
            Node *x=root;
            while(x->r) x=x->r;
            x->r=p->r;
            p->r->p=x;
            splay(x);
        }
        else if(p->l||p->r){
            root=(p->l?p->l:p->r);
            root->p=NULL;
        }
        else root=NULL;
        delete p;
    }

    void find_kth(int k){
        Node *x=root;
        while(x){
            while(x->l&&x->l->cnt>k) x=x->l;
            if(x->l) k-=x->l->cnt;
            if(!k--) break;
            x=x->r;
        }
        if(!x) return;
        splay(x);
    }
};
