/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

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

const ll MN = 1e9+7;
const long long inf = 1e18+7;
const ll base = 311;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
struct pll{ll fi,se;};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

const int MAX = 1e4 + 2;
int n, m, k, T, a[MAX];
vector<pll> g[MAX];
void input()
{
    cin >> n >> m  >> k >> T;
    fr(i, 1, k) cin >> a[i];
    int x, y, w;
    fr(i, 1, m) {
        cin >> x >> y >> w;
        g[x].pb({y, w});
        g[y].pb({x, w});
    }
}
namespace sub1
{
    struct eg
    {
        int u, w;
        bool operator<(eg const&a) const
        {
            return w > a.w;
        }
    };
    int par[MAX];
    bool dd[MAX];
    ll f[MAX];
    void dij(int s)
    {
        fr(i, 1, n) dd[i] = 0, f[i] = inf;
        f[s] = 0;
        priority_queue<eg> pq;
        pq.push({s, 0});
        while(pq.size()) {
            int u = pq.top().u;
            pq.pop();
            if(dd[u]) continue;
            dd[u] = 1;
            for(pll t : g[u]) {
                int v = t.fi;
                int w = t.se;
                if(mini(f[v], f[u] + w)) {
                    par[v] = u;
                    pq.push({v, f[v]});
                }
            }
        }

    }
    void slv()
    {
        dij(a[1]);
        cout << f[T] << el;
        int cur = T;
        vector<pll> path;
        while(cur != a[1]) {
            path.pb({par[cur], cur});
            cur = par[cur];
        }
        reverse(all(path));
        cout << path.size() << el;
        for(auto x : path) cout << 1 << " " << x.fi << " " << x.se << el;
    }
}
namespace sub2
{
    struct eg
    {
        int u, w;
        bool operator<(eg const&a) const
        {
            return w > a.w;
        }
    };
    bool dd[MAX];
    ll f[10][MAX];
    int key[MAX];
    void dij(int s, ll f[])
    {
        fr(i, 1, n) dd[i] = 0, f[i] = inf;
        f[a[s]] = 0;
        priority_queue<eg> pq;
        pq.push({a[s], 0});
        while(pq.size()) {
            int u = pq.top().u;
            pq.pop();
            if(dd[u]) continue;
            dd[u] = 1;
            for(pll t : g[u]) {
                int v = t.fi;
                int w = t.se;
                if(mini(f[v], f[u] + w) && !dd[v]) {
                    pq.push({v, f[v]});
                }
            }
        }
    }
    void slv()
    {
        sort(alla(a, k));
        fr(i, 1, k) key[a[i]] = i;
        ll res = 0;
        fr(i, 1, k) dij(a[i], f[i]);
        fr(i, 1, k) res+=f[key[a[i]]][T];

        do {
            ll ans = 0;
            fr(i, 2, k) {
                ll value = f[key[a[i - 1]]][a[i]];
                ans = ans + value/(i - 1);
            }
            ans = ans + f[key[a[k]]][T]/k;
            mini(res, ans);
        } while(next_permutation(alla(a, k)));
        cout << res;
    }
}

main()
{
    #define TASK "TAXI"
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


