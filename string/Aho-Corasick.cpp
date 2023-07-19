// 아호-코라식 일대다 패턴 매칭 찾기
struct Trie{
    map<char,Trie*> ch;
    Trie* fail;
    bool check;

    Trie(): check(false) {}

    ~Trie(){
        for(auto& p : ch)
            delete p.second;
    }

    void insert(string& s, int idx){
        if(idx==s.size())
            check=true;
        else{
            if(ch[s[idx]]==nullptr)
                ch[s[idx]]=new Trie;
            ch[s[idx]]->insert(s,idx+1);
        }
    }

    void pi(){
        Trie* root=this;
        queue<Trie*> Q;

        root->fail=root;
        Q.push(root);
        while(!Q.empty()){
            Trie* cur=Q.front(); Q.pop();
            for(auto& p : cur->ch){
                Trie* next=p.second;
                if(cur==root) next->fail=root;
                else{
                    Trie* prev=cur->fail;
                    while(prev!=root&&prev->ch[p.first]==nullptr)
                        prev=prev->fail;
                    if(prev->ch[p.first]!=nullptr)
                        prev=prev->ch[p.first];
                    next->fail=prev;
                }
                if(next->fail->check)
                    next->check=true;
                q.push(next);
            }
        }
    }
    
    vector<int> find(string& s){
        int n=s.size();
        Trie* cur=this;
        vector<int> pos;
        
        for(int i=0; i<n; i++){
            while(cur!=this&&cur->ch[s[i]]==nullptr)
                cur=cur->fail;
            if(cur->ch[s[i]]!=nullptr)
                cur=cur->ch[s[i]];
            if(cur->check)
                pos.push_back(i);
        }
        return pos;
    }
};
