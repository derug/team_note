struct KMP{
    string p, t;
    vector<int> c;
    vector<int> pos;

    KMP(){this->init();}

    void init(){
        c.clear();
        pos.clear();
    }
    
    void pi(string& s){
        p=s;
        c.resize(p.size()+1);
        int k=0;
        for(int i=1; i<p.size(); i++){
            while(k>0&&p[k]!=p[i]) k=c[k-1];
            if(p[k]==p[i]) c[i]=++k;
        }
    }
    
    void find(string& s){
        t=s;
        int k=0;
        for(int i=0; i<t.size(); i++){
            while(k>0&&t[i]!=p[k]) k=c[k-1];
            if(t[i]==p[k]){
                k++;
                if(k==p.size())
                    pos.push_back(i-p.size()+1);
            }
        }
    }
}
