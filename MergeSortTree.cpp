struct node{
    vector<ll> arr;
};
node t[4*N];
node merge(node a,node b){
    node ans;
    ll i=0,j=0;
    ll n=a.arr.size(),m=b.arr.size();
    while(i<n and j<m){
        if(a.arr[i]<b.arr[j]){
            ans.arr.push_back(a.arr[i]);
            i++;
        }
        else{
            ans.arr.push_back(b.arr[j]);
            j++;
        }
    }
    while(i<n){
        ans.arr.push_back(a.arr[i]);
        i++;
    }
    while(j<m){
        ans.arr.push_back(b.arr[j]);
        j++;
    }
    return ans;
}
void build(ll id,ll l,ll r,vector<pair<ll,ll>> &c){
    if(l==r){
        t[id].arr.push_back(//tree node val);
        return;
    }
    ll mid=(l+r)/2;
    build(2*id,l,mid,c);
    build(2*id+1,mid+1,r,c);
    t[id]=merge(t[2*id],t[2*id+1]);
}
ll query(ll id,ll l,ll r,ll lq,ll rq,ll val){
    if(r<lq or l>rq)    return 0;
    if(lq<=l and rq>=r){
        ll ans =upper_bound(t[id].arr.begin(),t[id].arr.end(),val)-t[id].arr.begin();
        ll te = t[id].arr.size();
        return te-ans;
    }
    ll mid=(l+r)/2;
    return query(2*id,l,mid,lq,rq,val)+query(2*id+1,mid+1,r,lq,rq,val);
}
