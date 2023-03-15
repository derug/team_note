typedef long long ll;

const int MAX;

struct BitSeg{
    ll fwt[MAX+1];
    
    BitSeg(){
        memset(fwt,0,sizeof(fwt));
    }
    
    void update(int idx, int val){
        while(idx<=MAX){
            fwt[idx]+=val;
            idx+=idx&-idx;
        }
    }
    
    ll query(int idx){
        int ret=0;
        while(idx){
            ret+=fwt[idx];
            idx-=idx&-idx;
        }
        return ret;
    }
}
