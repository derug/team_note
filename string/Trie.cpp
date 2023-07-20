// map을 사용하는 방법 (속도 느림, 메모리 적음)
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
// array를 사용하는 방법 (속도 빠름, 메모리 큼)
// a~z까지만 있음
struct Trie{
    Trie* ch[26];
    bool check;
    
    Trie(): check(false) {
        for(int i=0; i<26; i++) ch[i]=nullptr;
    }
    
    ~Trie(){
        for(int i=0; i<26; i++)
            if(ch[i]) delete ch[i];
    }
    
    void insert(string& s, int idx){
        if(idx==s.size())
            check=true;
        else{
            if(ch[s[idx]-'a']==nullptr)
                ch[s[idx]-'a']=new Trie;
            ch[s[idx]-'a']->insert(s,idx+1);
        }
    }
    
    bool find(string& s, int idx){
        if(idx==s.size()) return check;
        else{
            if(ch[s[idx]-'a']==nullptr)
                return false;
            return ch[s[idx]-'a']->find(s,idx+1);
        }
    }
};
