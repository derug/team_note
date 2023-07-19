struct Trie{
    map<char,Trie*> ch;
    bool check;
    
    Trie(): check(false) {}
    
    ~Trie(){
        for(auto it=ch.begin(); it!=ch.end(); it++)
            delete it->second;
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
    
    bool find(string& s, int idx){
        if(idx==s.size()) return check;
        else{
            if(ch[s[idx]]==nullptr)
                return false;
            return ch[s[idx]]->find(s,idx+1);
        }
    }
};
