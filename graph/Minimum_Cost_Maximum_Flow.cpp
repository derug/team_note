const int MAX, INF;

struct Edge{
    int to, c, d, f=0;
    Edge* rev;
    Edge(int to, int c, int d): to(to), c(c), d(d){}
    int spare(){
        return c-f;
    }
    void add(int am){
        f+=am;
        rev->f-=am;
    }
};

vector<Edge*> adj[MAX];

void makeEdge(int from, int to, int c, int d){
    Edge *e1=new Edge(to,c,d), *e2=new Edge(from,0,-d);
    e1->rev=e2; e2->rev=e1;
    adj[from].push_back(e1);
    adj[to].push_back(e2);
}

pair<int,int> MCMF(int s, int t){
    int minCost=0, maxFlow=0;
    while(1){
        vector<int> prev(MAX,-1);
        vector<Edge*> path(MAX);
        vector<int> dst(MAX,INF);
        vector<bool> inQ(MAX);
        queue<int> Q;
        Q.push(s);
        dst[s]=0;
        inQ[s]=true;
        while(!Q.empty()){
            int cur=Q.front(); Q.pop();
            inQ[cur]=false;
            for(Edge* e: adj[cur]){
                int next=e->to, c=e->spare();
                int ndst=dst[cur]+e->d;
                if(c>0&&ndst<dst[next]){
                    prev[next]=cur;
                    path[next]=e;
                    dst[next]=ndst;
                    if(!inQ[next]){
                        Q.push(next);
                        inQ[next]=true;
                    }
                }
            }
        }
        if(prev[t]==-1) break;
        int am=INF;
        for(int i=t; i!=s; i=prev[i])
            am=min(am,path[i]->spare());
        for(int i=t; i!=s; i=prev[i]){
            minCost+=am*path[i]->d;
            path[i]->add(am);
        }
        maxFlow+=am;
    }
    return {minCost,maxFlow};
}
