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

ll n, a[MF], q;
vector<ll> g[MF];
void input()
{
    cin >> n >> q;
    fr(i, 1, n) cin >> a[i];
    ll x, y;
    fr(i, 1, n - 1){
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}
namespace sub1
{
    vector<ll> euler;
    ll time = 0, in[MF], out[MF], t[MF];
    void dfs(ll u, ll p)
    {
        euler.pb(u);
        in[u] = ++time;
        for(int v : g[u]){
            if(v == p) continue ;
            dfs(v, u);
        }
        out[u] = time;
    }
    void  upd(ll id, ll l, ll r, ll i, ll val)
    {
        if(i > r || i < l) return ;
        if(l == r){
            t[id]+=val;
            return;
        }
        ll m = (r + l) >> 1;
        upd(id << 1, l, m, i, val);
        upd(id << 1 | 1, m + 1, r, i, val);
        t[id] = t[id << 1] + t[id << 1 | 1];
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return t[id];
        ll m = (r + l) >> 1;
        return get(id << 1, l, m,  u,  v) + get(id << 1 | 1, m + 1, r, u, v);
    }
    void slv()
    {
        euler.pb(0);
        dfs(1, 0);
        fr(i, 1, n){
            upd(1, 1, n, in[i], a[i]);
            upd(1, 1, n, out[i] + 1, - a[i]);
        }
        ll key, x, val;
        fr(i, 1, n) cout << in[i] << " " << out[i] << el; return ;
        while(q--){
            cin >> key >> x;
            if(key == 1){
                cin >> val;
                upd(1, 1, n, in[x],val - a[x]);
                upd(1, 1, n, out[x] + 1, a[x] - val);
                a[x] = val;

            }
            else {
                cout << get(1, 1, n, 1, in[x]) << endl;
            }
        }
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

