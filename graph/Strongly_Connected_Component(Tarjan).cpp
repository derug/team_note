struct SCC{
    int n, sn, idx;
    vector<int> col, low, dfn;
    vector<bool> fin;
    vector<vector<int>> scc;
    vector<vector<int>> adj, sadj;
    stack<int> S;

    SCC(int _n): n(_n), sn(0), idx(0){
        col.resize(n);
        low.resize(n);
        dfn.resize(n);
        fin.resize(n);
        adj.resize(n);
    }

    int dfs(int a){
        S.push(a);
        low[a]=dfn[a]=++idx;

        for(int b: adj[a]){
            if(!dfn[b])
                low[a]=min(low[a],dfs(b));
            else if(!fin[b])
                low[a]=min(low[a],dfn[b]);
        }

        if(low[a]==dfn[a]){
            vector<int> tmp;
            while(1){
                int t=S.top(); S.pop();
                tmp.push_back(t);
                col[t]=sn;
                fin[t]=true;
                if(t==a) break;
            }
            scc.push_back(tmp);
            sn++;
        }

        return low[a];
    }

    void makeSCC(){
        for(int i=0; i<n; i++)
            if(!dfn[i]) dfs(i);
        for(int i=0; i<sn; i++){
            vector<int> tmp;
            vector<bool> mark(sn);
            for(int a: scc[i])
                for(int b: adj[a])
                    if(col[a]!=col[b])
                        mark[col[b]]=true;
            for(int j=0; j<sn; j++)
                if(mark[j])
                    tmp.push_back(j);
            sadj.push_back(tmp);
        }
    }
};
