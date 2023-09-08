struct Edge{
    int u, v, d;
    Edge(){}
    Edge(int _u, int _v, int _d): u(_u), v(_v), d(_d){}
}

int find(int a, vector<int>& p){
    if(p[a]==a) return a;
    return p[a]=find(p[a],p);
}

bool merge(int a, int b, vector<int>& p){
    int a=find(a,p); int b=find(b,p);
    if(a==b) return false;
    p[b]=a;
    return true;
}

int Kruskal(int n, vector<Edge>& edge){
    int ans=0, cnt=0;
    vector<int> p(n+1);
    iota(p.begin(), p.end(), 0);
    sort(edge.begin(), edge.end(), [](Edge& e1, Edge e2){
        return e1.d<e2.d;
    });
    for(Edge e : edge){
        if(merge(e.u, e.v, p)) ans+=e.d, cnt++;
        if(cnt==n-1) break;
    }
    if(cnt<n-1) return -1;
    return ans;
}
