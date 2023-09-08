const int MAX;

vector<int> adj[MAX];

struct SCC{
    int n, sn, idx;
    vector<int> col, par;
    vector<bool> fin;
    vector<vector<int>> scc;
    stack<int> S;

    SCC(int _n): n(_n), sn(0), idx(0){
        col.resize(n);
        par.resize(n);
        fin.resize(n);
    }

    int dfs(int a){
        par[a]=++idx;
        S.push(a);
        
        int res=par[a];
        for(int b: adj[a]){
            if(!par[b])
                res=max(res,dfs(b));
            else if(!fin[b])
                res=max(res,par[b]);
        }

        if(res==par[a]){
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

        return res;
    }

    void makeSCC(){
        for(int i=0; i<n; i++)
            if(!par[i]) dfs(i);
    }
}
