typedef unsigned long long ull;

struct Random{
    mt19937 gen;
    Random(){ gen.seed(chrono::steady_clock::now().time_since_epoch().count()); }
    int get(int l, int r){ return uniform_int_distribution<int>(l,r)(gen); }
    template<typename T>
    void shuffle(vector<T>& v){ std::shuffle(v.begin(), v.end(), gen); }
};

struct PolyHash{
    static const int MOD=2147483647;
    static vector<int> pow1;
    static vector<ull> pow2;
    static int base;
    static Random rnd;

    static inline int diff(int a, int b){ return (a-=b)<0?a+MOD:a; }
    static inline int mod(ull x){
        x+=MOD; x=(x>>31)+(x&MOD);
        return (x>>31)+(x&MOD);
    }
    static void genBase(int l, int r=MOD-1){
        base=rnd.get(l+1,r);
        if(base%2==0) base--;
    }

    vector<int> p1;
    vector<ull> p2;

    PolyHash(const string& s): p1(s.size()+1,0), p2(s.size()+1,0){
        while(pow1.size()<=s.size()){
            pow1.push_back(mod((ull)pow1.back()*base));
            pow2.push_back(pow2.back()*base);
        }
        for(int i=0; i<s.size(); i++){
            p1[i+1]=mod(p1[i]+(ull)s[i]*pow1[i]);
            p2[i+1]=p2[i]+s[i]*pow2[i];
        }
    }

    // inline pair<int,ull> operator()(const int pos, const int len, const int mxPow=0){

    // }
};

int PolyHash::base(PolyHash::MOD);
vector<int> PolyHash::pow1{1};
vector<ull> PolyHash::pow2{1};
Random PolyHash::rnd;
