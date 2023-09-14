typedef long long ll;

struct Line{
    ll a, b;
};

inline double cross(Line& l1, Line& l2){
    return 1.0*(l1.b-l2.b)/(l2.a-l1.a);
}

struct CHT{
    vector<Line> st;
    void push(Line l){
        while(st.size()>1){
            int sz=st.size()-1;
            if(cross(l,st[sz])<cross(st[sz],st[sz-1]))
                st.pop_back();
            else break;
        }
        st.push_back(l);
    }
    ll query(ll x){
        int le=0, ri=st.size()-1;
        while(le<ri){
            int mid=(le+ri)/2;
            if(cross(st[mid],st[mid+1])<x) le=mid+1;
            else ri=mid;
        }
        return st[le].a*x+st[le].b;
    }
};
