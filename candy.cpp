/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

//#define   ll int
#define     lg(x) __lg(x)
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
struct pll{ll fi,se,id;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

struct eg
{
    ll x, y, w;
};
ll n, m;
const int MAXM = 1e4 + 10;
const int MAXN = 500 + 2;
vector<pll> g[MAXN];
eg Q[MAXM];
void input()
{
    cin >> n >> m;
    fr(i, 1, m)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        g[x].pb({y, w, i});
        g[y].pb({x, w, i});
        Q[i] = {x, y, w};

    }
}
namespace sub1
{

    ll dist[MAXN][MAXN], f[MAXN][MAXN];
    void slv()
    {
        memset(f, 0x3f, sizeof f);
        fr(i, 1, m) {
            ll x = Q[i].x;
            ll y = Q[i].y;
            ll w = Q[i].w;
            mini(f[x][y], w);
            mini(f[y][x], w);
        }
        fr(i, 1, n) f[i][i] = 0;
        fr(k, 1, n) fr(i, 1, n) fr(j, 1, n){
            mini(f[i][j], f[i][k] + f[k][j]);
        }
        fr(i, 1, m) {
            memset(dist, 0x3f, sizeof dist);
            fr(j, 1, m) if(i != j) {
                ll x = Q[j].x;
                ll y = Q[j].y;
                ll w = Q[j].w;
                mini(dist[x][y], w);
                mini(dist[y][x], w);
            }
            fr(u, 1, n) dist[u][u] = 0;
            fr(k, 1, n) fr(u, 1, n) fr(v, 1, n) {
                mini(dist[u][v], dist[u][k] + dist[k][v]);
            }
            ll ans = 0;
            fr(u, 1, n){
                fr(v, u + 1, n) {
                    if(f[u][v] != dist[u][v]) ans++;
                }
            }
            cout << ans << el;
        }
    }
}
namespace sub2
{
    struct line
    {
        ll u, w;
        bool operator<(line const&a) const
        {
            return this-> w > a.w;
        }
    };
    ll cnt[MAXN][MAXN], f[MAXN][MAXN];
    bool dd[MAXN];
    bool vis[MAXN][MAXN];
    ll  par[MAXN][MAXN], res[MAXM], p[MAXN][MAXN];
    void dij(ll s, ll f[], ll cnt[])
    {
        fr(i, 1, n) f[i] = inf, dd[i] = 0;
        f[s] = 0;
        cnt[s] = 1;
        priority_queue<line> q;
        q.push({s, f[s]});
        while(!q.empty()) {
            ll u = q.top().u;
            q.pop();
            if(dd[u]) continue;
            dd[u] = 1;
            for(auto t : g[u]) {
                ll v = t.fi;
                ll w = t.se;
                ll id = t.id;
                if(mini(f[v], f[u] + w)) {
                    par[s][v] = id;
                    p[s][v] = u;
                    cnt[v] = cnt[u];
                    q.push({v, f[v]});
                }
                else if(f[v] == f[u] + w) cnt[v]+=cnt[u];
            }
        }
    }
    bool check(ll from, ll to, ll id)
    {
        ll u = from;
        ll v = to;
        ll x = Q[id].x, y = Q[id].y, w = Q[id].w;
        if(f[u][v] == f[u][x] + w + f[y][v] && cnt[u][v] == cnt[x][u]*cnt[v][y]) return 1;
        swap(u, v);
        if(f[u][v] == f[u][x] + w + f[y][v] && cnt[u][v] == cnt[x][u]*cnt[v][y]) return 1;
        return 0;
    }
    void countPath(ll from, ll to)
    {
        ll cur = to;
        while(cur != from) {
            ll id = par[from][cur];
            if(check(from, to, id)) res[id]++;
            cur = p[from][cur];
         }
    }
    void slv()
    {
        fr(i, 1, n) {
            dij(i, f[i], cnt[i]);
        }
//        fr(i, 1, m) {
//            ll x = Q[i].x;
//            ll y = Q[i].y;
//            ll w = Q[i].w;
//            ll result = 0;
//            fr(u, 1, n){
//                fr(v, u + 1, n) {
//                    bool ok = 0;
//                    if(check(u, v, x, y, w)) ok = 1;
//                    if(check(u, v, y, x, w)) ok = 1;
//                    result+=ok;
//                }
//            }
//            cout << result << el;
//        }
        fr(i, 1, n - 1) fr(j, i + 1, n) {
            countPath(i, j);
        }
        fr(i, 1, m) cout << res[i] << el;
    }
}
main()
{
    #define TASK "candy"
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
        sub2::slv();
    //    sub2::slv();
    }
}

