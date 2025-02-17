#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MF=1e5+7;
ll t[4*MF],lazy[4*MF],a[MF];
void down(ll id)
{
    if(lazy[id]){
        t[id*2]+=lazy[id];
        lazy[id*2]+=lazy[id];
        t[id*2+1]+=lazy[id];
        lazy[id*2+1]+=lazy[id];
        lazy[id]=0;
    }
}
void update(ll id,ll l,ll r,ll u,ll v,ll val)
{
    if(r<u || l>v) return;
    if(u<=l && r<=v){
        t[id]+=val;
        lazy[id]+=val;
        return;
    }
    ll mid=(r+l)/2;
    down(id);
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    t[id]=min(t[id*2],t[id*2+1]);
}
ll get(ll id,ll l,ll r,ll u,ll v)
{
    if(r<u || l>v) return 1e16;
    if(u<=l && r<=v) return t[id];
    ll mid=(r+l)/2;
    down(id);
    return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        update(1,1,n,i,i,x);
    }
    ll type,l,r,x;
    for(int i=0;i<q;i++){
        cin>>type>>l>>r;
        if(type==1){
            cin>>x;
            update(1,1,n,l,r,x);
        }
        else{
            cout<<get(1,1,n,l,r)<<'\n';
        }
    }
}
