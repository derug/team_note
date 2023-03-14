const int MAX, INF;

vector<pair<int,int>> adj[MAX]; //(번호, 가중치)

vector<int> SPFA(int n, int start){
    vector<int> dst(n+1, INF);
    vector<int> visited(n+1);
    vector<bool> inQ(n+1);
    queue<int> Q;
    
    Q.push(start);
    dst[start]=0;
    ++visited[start];
    inQ[start]=true;
    while(!Q.empty()){
        int cur=Q.front(); Q.pop();
        inQ[cur]=false;
        for(auto p: adj[idx]){
            int next=p.first;
            int ndst=dst[cur]+p.second;
            if(ndst<dst[next]){
                dst[next]=ndst;
                if(!inQ[next]){
                    Q.push(next);
                    inQ[next]=true;
                    if(++visited[next]>=n)
                        return vector<int>();
                }
            }
        }
    }
    return dst;
}
