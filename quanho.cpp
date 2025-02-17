#include <bits/stdc++.h>
using namespace std;

#define     TASK "quanho"
#define     lg(x) log2(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll long long
#define     fi first
#define     se second
#define     MASK(i) (1ll<<(i))
#define     c_bit(i) __builtin_popcountll(i)
#define     fr(i,a,b) for(int i=a;i<=b;i++)
#define     frd(i,a,b) for(int i=a;i>=b;i--)

const ll MN=1e9+7;
const ll MF=1e6+7;
const ll inf=1e18+7;
const ll N = 1005;
const ll H = 311;
const ll F = 1e5 + 3;

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
ll sum(ll a, ll b) {return (a + b)%MN;}

ll n, a[MF], m;
vector<init> g[MF];
vector<ll> lt(MF, inf);
vector<ll> f(MF, 0);
bool vis[MF] =  {0};
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i];
    cin >> m;
    ll x, y, w;
    fr(i, 1, m){
        cin >> x >> y >> w;
        g[x].pb({y, w});
        g[y].pb({x, w});
    }
}
namespace sub1
{
    priority_queue<init> q;
    void dij(ll s)
    {
        f[s] = a[s];
        lt[s] = 0;
        q.push({s, 0});
        while(!q.empty()){
            ll u = q.top().in;
            q.pop();
            if(vis[u]) continue ;
            vis[u] = 1;
            for(init it : g[u]){
                ll v = it.in;
                ll w = it.va;
                if(lt[v] > lt[u] + w){
                    lt[v] = lt[u] + w;
                    f[v] = f[u] + a[v];
                    q.push({v, lt[v]});
                }
                else if(lt[v] == lt[u] + w){
                    if(f[u] + a[v] > f[v]){
                        f[v] = f[u] + a[v];
                        q.push({v, lt[v]});
                    }
                }
            }
        }
    }
    void slv()
    {
        dij(1);
        if(lt[n] == inf) cout << "impossible";
        else cout << lt[n] << " " << f[n];
    }
}
namespace sub2
{
    void slv()
    {

    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if( fopen( TASK".INP", "r") ){
        freopen( TASK".INP", "r", stdin);
        freopen( TASK".OUT", "w", stdout);
    }
    bool qs = 0;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        sub1::slv();
    //    sub2::slv();
    }
}







