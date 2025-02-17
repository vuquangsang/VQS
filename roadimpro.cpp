#include <bits/stdc++.h>
using namespace std;

//#define   ll int
#define     lg(x) __log(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll long long
#define     fi first
#define     se second
#define     Mask(i) (1ll<<(i))
#define     c_bit(i) __builtin_popcountll(i)
#define     fr(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define     frd(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define     REP(i, a, b) for(int i = (a), _b = (b); i < _b; i++)
#define     BIT(msk, i) (msk&(1 << i))

const ll MN = 1e9+7;
const ll MF = 1e6+7;
const long long inf = 1e18+7;
const ll N = 1005;
const ll base = 311;
const ll F = 1e5 + 2;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};
const short LO = 17;

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template<class X, class Y>
    bool mini(X &x, const Y &y)  {
        if(x > y) {
            x = y;
            return 1;
        }
        else return 0;
    }
template<class X, class Y>
    bool maxi(X &x, const Y &y)
    {
        if(x < y) {
            x = y;
            return 1;
        }
        else return 0;
    }
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

ll n, m, qr;
vector<pll> g[MF];
void input()
{
    cin >> n >> m >> qr;
    ll x, y, w;
    fr(i, 1, m) {
        cin >> x >> y >> w;
        g[x].pb({y, w});
    }
}
namespace sub1
{
    struct data
    {
        ll u, w, key;
        bool operator<(data const&a) const
        {
            return w > a.w;
        }
    };
    priority_queue<data> q;
    bool dd[MF][2];
    ll f[MF][2];
    ll dij(ll s, ll t)
    {
        fr(i, 1, n) {
            dd[i][0] = dd[i][1] = 0;
            f[i][0] = f[i][1] = inf;
        }
        q.push({1, 0, 0});
        f[1][0] = f[1][1] = 0;
        while(!q.empty()) {
            ll u = q.top().u;
            ll w = q.top().w;
            ll key = q.top().key;
            q.pop();
            if(dd[u][key]) continue ;
            dd[u][key] = 1;
            for(pll it : g[u]) {
                ll v = it.fi;
                ll w = it.se;
                if(key) {
                    if(f[v][key] > f[u][key] + w) {
                        f[v][key] = f[u][key] + w;
                        q.push({v, f[v][key], key});
                    }
                }
                else{
                    if(f[v][1] > f[u][0] + t) {
                        f[v][1] = f[u][0] + t;
                        q.push({v, f[v][1], 1});
                    }
                    if(f[v][0] > f[u][0] + w) {
                        f[v][0] = f[u][0] + w;
                        q.push({v, f[v][0], 0});
                    }
                }
            }
        }

        return min(f[s][1], f[s][0]);
    }
    void slv()
    {
        ll s, t;
        while(qr--) {
            cin >> s >> t;
            cout << dij(s, t) << el;
        }
    }
}
namespace sub2
{
    struct data
    {
        ll u, w, key;
        bool operator<(data const&a) const
        {
            return w > a.w;
        }
    };
    #define N 2000
    priority_queue<data> q;
    bool dd[N][2];
    ll f[N][2];
    void cal()
    {
        fr(i, 1, n) {
            dd[i][0] = dd[i][1] = 0;
            f[i][0] = f[i][1] = inf;
        }
        q.push({1, 0, 0});
        f[1][0] = f[1][1] = 0;
        while(!q.empty()) {
            ll u = q.top().u;
            ll w = q.top().w;
            ll key = q.top().key;
            q.pop();
            if(dd[u][key]) continue ;
            dd[u][key] = 1;
            for(pll it : g[u]) {
                ll v = it.fi;
                ll w = it.se;
                if(key) {
                    if(f[v][key] > f[u][key] + w) {
                        f[v][key] = f[u][key] + w;
                        q.push({v, f[v][key], key});
                    }
                }
                else{
                    if(f[v][1] > f[u][0] + t) {
                        f[v][1] = f[u][0] + t;
                        q.push({v, f[v][1], 1});
                    }
                    if(f[v][0] > f[u][0] + w) {
                        f[v][0] = f[u][0] + w;
                        q.push({v, f[v][0], 0});
                    }
                }
            }
        }
    }
    void slv()
    {
        cal();
        ll s, t
    }
}

main()
{
    #define TASK ""
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


