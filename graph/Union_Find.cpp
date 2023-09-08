// path compression

struct Union_Find{
    int n;
    vector<int> p;

    Union_Find(int _n): n(_n){
        p.resize(n);
        for(int i=0; i<n; i++) p[i]=i;
    }

    int find(int a){
        if(p[a]==a) return a;
        return p[a]=find(p[a]);
    }

    bool merge(int a, int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        p[b]=a;
        return true;
    }

    bool isUnion(int a, int b){
        return find(a)==find(b);
    }
}

// rank compression

struct Union_Find{
    int n;
    vector<int> p, d;

    Union_Find(int _n): n(_n){
        p.resize(n);
        d.resize(n);
        for(int i=0; i<n; i++) p[i]=i;
        for(int i=0; i<n; i++) d[i]=1;
    }

    int find(int a){
        if(p[a]==a) return a;
        return find(p[a]);
    }

    bool merge(int a, int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(d[a]<d[b]) p[a]=b;
        else if(d[a]>d[b]) p[b]=a;
        else d[a]++, p[d]=a;
        return true;
    }

    bool isUnion(int a, int b){
        return find(a)==find(b);
    }
}
