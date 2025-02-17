#include <bits/stdc++.h>
using namespace std;

#define     TASK ""
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

const ll MN = 1e9+7;
const ll MF = 1e6+7;
const ll inf = 1e18+7;
const ll N = 1005;
const ll H = 311;
const ll F = 1e5 + 3;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
ll sum(ll a, ll b) {return (a + b)%MN;}

ll n, a, b;
vector<ll> g[MF];
void input()
{
    cin >> n >> a >> b;
    ll x, y;
    fr(i, 1, n) g[i].clear();
    fr(i, 1, n - 1){
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}
namespace sub1
{
    ll h[MF], p[MF], maxtoPar[MF], d[MF], Maxx[MF];
    pll Max[MF];
    void dfs(ll u)
    {
        Max[u] = {-inf, -inf};
        h[u] = 0;
        for(int v : g[u]) if(v != p[u]){
            p[v] = u;
            d[v]= d[u] + 1;
            dfs(v);
            h[u] = max(h[u], h[v] + 1);
            if(h[v] + 1 > Max[u].fi) {
                Max[u].se = Max[u].fi;
                Max[u].fi = h[v] + 1;
            }
            else Max[u].se = max(Max[u].se, h[v] + 1);
        }
    }
    void reDFS(ll u)
    {
        for(int v : g[u]) if(v != p[u]) {
            maxtoPar[v] = maxtoPar[u] + 1;
            ll tmp = Max[u].fi;
            if(h[v] + 1 ==  tmp) tmp = Max[u].se;
            maxtoPar[v] = max(maxtoPar[v], tmp + 1) ;
            reDFS(v);
        }
    }
    void slv()
    {
        d[a] = maxtoPar[a] = p[a] = 0;
        dfs(a);
        reDFS(a);
        fr(i, 1, n) Maxx[i] = max(Max[i].fi, maxtoPar[i]);
        ll cdist = (d[b] + 1) / 2;
        ll pdist = cdist;
        ll root = b;
        while(cdist--) root = p[root];
        cout << 2*(n - 1) + pdist - Maxx[root] << el;
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
    bool qs = 1;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        sub1::slv();
    //    sub2::slv();
    }
}









