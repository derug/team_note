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
            scc.emplace_back();
            while(1){
                int t=S.top(); S.pop();
                scc.back().push_back(t);
                col[t]=sn;
                fin[t]=true;
                if(t==a) break;
            }
            sn++;
        }

        return low[a];
    }

    void makeSCC(){
        for(int i=0; i<n; i++)
            if(!dfn[i]) dfs(i);
        
        sadj.resize(sn);
        for(int i=0; i<sn; i++)
            for(int a: scc[i])
                for(int b: adj[a])
                    if(col[a]!=col[b])
                        sadj[col[a]].push_back(col[b]);
        
        for(int i=0; i<sn; i++){
            sort(sadj[i].begin(), sadj[i].end());
            sadj[i].erase(unique(sadj[i].begin(), sadj[i].end()), sadj[i].end());
        }
    }
};
