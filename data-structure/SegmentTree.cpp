const int MAX, INF;
int arr[MAX], sgt[MAX*4];

int init(int l, int r, int node){
  if(l==r) return sgt[node]=arr[l];
  int mid=l+r>>2;
  return seg[node]=min(init(l, mid, node*2), init(mid+1, r, node*2+1));
}

int update(int idx, int val, int nl, int nr, int node){
  if(idx<nl||nr<idx) return seg[node];
  if(nl==nr) return seg[node]=min(seg[node], val);
  int mid=nl+nr>>1;
  return seg[node]=min(update(idx,val,nl,mid,2*node), update(idx,val,mid+1,nr,2*node+1));
}

int query(int l, int r, int nl, int nr, int node){
  if(r<nl||nr<l) return INF;
  if(l<=nl&&nr<=r) return sgt[node];
  int mid=nl+nr>>1;
  return min(query(l, r, nl, mid, 2*node), query(l, r, mid+1, nr, 2*node+1));
}
