// 아호-코라식 일대다 패턴 매칭 찾기
// map을 사용하는 방법 (속도 느림, 메모리 적음)
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

    bool find(string& s, int idx){
        if(idx==s.size()) return check;
        else{
            if(ch[s[idx]]==nullptr)
                return false;
            return ch[s[idx]]->find(s,idx+1);
        }
    }
};

void pi(Trie* root){
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
            Q.push(next);
        }
    }
}

vector<int> find(Trie* root, string& s){
    int n=s.size();
    Trie* cur=root;
    vector<int> pos;
    
    for(int i=0; i<n; i++){
        while(cur!=root&&cur->ch[s[i]]==nullptr)
            cur=cur->fail;
        if(cur->ch[s[i]]!=nullptr)
            cur=cur->ch[s[i]];
        if(cur->check)
            pos.push_back(i);
    }
    return pos;
}
// array를 사용하는 방법 (속도 빠름, 메모리 많음)
// a~z까지
struct Trie{
    Trie* ch[26];
    Trie* fail;
    bool check;

    Trie(): check(false), fail(nullptr) {
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

void pi(Trie* root){
    queue<Trie*> Q;

    root->fail=root;
    Q.push(root);
    while(!Q.empty()){
        Trie* cur=Q.front(); Q.pop();
        for(int i=0; i<26; i++){
            Trie* next=cur->ch[i];
            if(next==nullptr) continue;
            if(cur==root) next->fail=root;
            else{
                Trie* prev=cur->fail;
                while(prev!=root&&prev->ch[i]==nullptr)
                    prev=prev->fail;
                if(prev->ch[i]!=nullptr)
                    prev=prev->ch[i];
                next->fail=prev;
            }
            if(next->fail->check)
                next->check=true;
            Q.push(next);
        }
    }
}

vector<int> find(Trie* root, string& s){
    int n=s.size();
    Trie* cur=root;
    vector<int> pos;
    
    for(int i=0; i<n; i++){
        while(cur!=root&&cur->ch[s[i]-'a']==nullptr)
            cur=cur->fail;
        if(cur->ch[s[i]-'a']!=nullptr)
            cur=cur->ch[s[i]-'a'];
        if(cur->check)
            pos.push_back(i);
    }
    return pos;
}
