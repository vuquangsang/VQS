#include <bits/stdc++.h>
using namespace std;

#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll long long
#define     fi first
#define     se second
#define     fr(i,a,b) for(int i=a;i<=b;i++)
#define     frd(i,a,b) for(int i=a;i>=b;i--)
const ll MN=1e9+7;
const ll MF=1e6+7;
const ll inf=1e18+7;

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};

ll t,n,m,f[MF];
vector<ll> rd[MF];
queue<ll> q;
bool b[MF]={0};
void input()
{
    cin>>t;
}
void bfs(ll x)
{
    f[x]=0;
    q.push(x);
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        b[u]=1;
        for(int i=0;i<rd[u].size();i++){
            ll v=rd[u][i];
            if(!b[v] || f[v]>f[u]+1){
                q.push(v);
            }
            f[v]=min(f[v],f[u]+1);
        }
    }
}
void slv()
{
    while(t--){
        cin>>n>>m;
        ll x,y,w;
        fr(i,1,m){
            cin>>x>>y>>w;
            rd[x].pb(y);
            rd[y].pb(x);
        }
        ll u,v;
        cin>>u>>v;
        if(u==v){
            cout<<0<<el;
            fr(i,1,n){
                rd[i].clear();
            }
            continue;
        }
        fr(i,1,n){
            f[i]=inf;
            b[i]=0;
        }
        bfs(u);
        cout<<f[v]-1<<el;

    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool qs=0;
    ll ntest=1;
    if(qs) cin>>ntest;
    fr(i,1,ntest){
        input();
        slv();
    }
}


