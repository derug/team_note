const int MAX, INF;

struct Edge{
    int to, c, f=0;
    Edge* rev;
    Edge(){}
    Edge(int to, int c): to(to), c(c){}
    int spare(){
        return c-f;
    }
    void add(int am){
        f+=am;
        rev->f-=am;
    }
};

int n;
vector<Edge*> adj[MAX];

void makeEdge(int from, int to, int c){
    Edge *e1=new Edge(to,c), *e2=new Edge(from,0);
    e1->rev=e2; e2->rev=e1;
    adj[from].push_back(e1);
    adj[to].push_back(e2);
}

int maxFlow(int s, int t){
    int total=0;
    while(1){
        vector<int> prev(n+1,-1);
        vector<Edge*> path(n+1);
        queue<int> Q;
        Q.push(s);
        while(!Q.empty()&&prev[t]==-1){
            int cur=Q.front(); Q.pop();
            for(Edge* e: adj[cur]){
                int next=e->to;
                if(e->spare()>0&&prev[next]==-1){
                    prev[next]=cur;
                    path[next]=e;
                    Q.push(next);
                }
            }
        }
        if(prev[t]==-1) break;
        int am=INF;
        for(int i=t; i!=s; i=prev[i])
            am=min(am,path[i]->spare());
        for(int i=t; i!=s; i=prev[i])
            path[i]->add(am);
        total+=am;
    }
    return total;
}
