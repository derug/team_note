//이거 엄청 느림 최적화 
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

int level[MAX], work[MAX];
vector<Edge*> adj[MAX];

void makeEdge(int from, int to, int c){
    Edge *e1=new Edge(to,c), *e2=new Edge(from,0);
    e1->rev=e2; e2->rev=e1;
    adj[from].push_back(e1);
    adj[to].push_back(e2);
}

bool DinicBFS(int s, int t){
    memset(level,-1,sizeof(level));
    queue<int> Q;
    Q.push(s);
    level[s]=0;
    while(!Q.empty()){
        int cur=Q.front(); Q.pop();
        for(Edge* e: adj[cur]){
            int next=e->to, c=e->spare();
            if(c>0&&level[next]==-1){
                level[next]=level[cur]+1;
                Q.push(next);
            }
        }
    }
    return (level[t]!=-1);
}

int DinicDFS(int cur, int t, int f){
    if(cur==t) return f;
    for(int& i=work[cur]; i<adj[cur].size(); i++){
        Edge* e=adj[cur][i];
        int next=e->to, c=e->spare();
        if(c>0&&level[next]==level[cur]+1){
            int ret=DinicDFS(next,t,min(f,c));
            if(ret){
                e->add(ret);
                return ret;
            }
        }
    }
    return 0;
}

int DinicMaxFlow(int s, int t){
    int total=0;
    while(DinicBFS(s,t)){
        memset(work,0,sizeof(work));
        while(1){
            int am=DinicDFS(s,t,INF);
            if(!am) break;
            total+=am;
        }
    }
    return total;
}
