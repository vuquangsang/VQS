/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

//#define   ll int
#define     lg(x) __lg(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll int
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
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

struct eg
{
    ll x, y, w, id;
};
const int MAX = 1e5 + 3;
const int MAXM = 2e5 + 3;
ll n, m, a;
eg Q[MAXM];
void input()
{
    cin >> n >> m >> a;
    fr(i, 1, m) cin >> Q[i].x >> Q[i].y >> Q[i].w, Q[i].id = i;
}
namespace sub1
{
    struct parent
    {
        ll u, w, id;
    };

    int f[MAX];
    vector<eg> e;
    vector<parent> g[MAX];
    parent par[MAX];
    int path[MAX];
    void DFS(ll u, ll p )
    {
        for(auto x : g[u]) {
            ll v = x.u, w = x.w, id = x.id;
            if(v == p) continue;
            par[v] = {u, w, id};
            DFS(v, u);
        }
    }
    ll goc(ll x)
    {
        while(f[x] > 0) x = f[x];
        return x;
    }
    void hn(ll r1, ll r2)
    {
        ll tmp = f[r1] + f[r2];
        if(f[r1] < f[r2]) {
            f[r1] = tmp;
            f[r2]= r1;
        }
        else {
            f[r2] = tmp;
            f[r1] = r2;
        }
    }
    void slv()
    {
        fr(i, 1, n) f[i] = -1;
        sort(Q + 1, Q + m + 1, [](eg a, eg b){return a.w < b.w;});
        ll d = 0 , ans = 0;
        fr(i, 1, m){
            ll x = Q[i].x;
            ll y = Q[i].y;
            ll w = Q[i].w;
            ll id = Q[i].id;
            ll r1 = goc(x);
            ll r2 = goc(y);
            if(r1 != r2) {
                hn(r1, r2);
                g[x].pb({y, w, id});
                g[y].pb({x, w, id});
            }
            else {
                DFS(x, 0);
                if(par[y].u == 0) swap(x, y);
                ll cur = y;
                ll time = 0;
                while(cur != x) {
                    path[++time] = par[cur].id;
                    cur = par[cur].u;
                }
                path[++time] = x;
                long long value = 1ll*w*w + a*(time);
                cout << value << el;
                cout << y << " " << time << el;
                fr(o, 1, time) cout << path[o] << " ";
                return;
            }
        }
        cout << "Poor girl";
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
    #define TASK "ginger"
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
    cerr << el << clock() << "ms";
}

