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

// ver. 2

const int MAX;

int T[MAX];

void upd(int idx, ll val)
{
	while (idx <= n) T[idx] += val, idx += idx & -idx;
}
void init(void)
{
	for (int i = 1; i <= n; i++) upd(i, a[i]);
}
ll qry(int idx)
{
	ll ret = 0;
	while (idx) ret += T[idx], idx -= idx & -idx;
	return ret;
}

