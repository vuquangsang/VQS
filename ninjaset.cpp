/* Try to do something */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll,ll>  pll;
typedef vector<int> vi;
typedef vector<pii> vii;

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
#define     sz(a) (int)a.size()
#define     uni(V) sort(all(V)), V.resize(unique(all(V)) - V.begin())


const int N = 2e5 + 5, base = 311, sm = 1e9 + 7;
const long long inf  = 1e18 + 2;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

int n;
pii a[N];
int v[N], p[N];
void input()
{
    cin >> n;
    fr(i, 1, n) {
       cin >> v[i] >> p[i];
       a[i] = {v[i], p[i]};
    }
}
namespace sub1
{

    struct ninja
    {
        int u, p, b;
    } qr[N];
    vector<int> g[N];
    int dp[N];
    int root = 1, h[N], up[N][21];
    void DFS(int u, int p)
    {
        up[u][0] = p;
        fr(j, 1, lg(n)) up[u][j] = up[up[u][j - 1]][j - 1];
        for(int v : g[u]) if(v != p) {
            h[v] = h[u] + 1;
            DFS(v, u);
        }
    }
    int get_par(int u, int k)
    {
        fr(j, 0, lg(n)) {
            if(k & (1 << j)) u = up[u][j];
        }
        return u;
    }
    bool check(int u, int v)
    {
        int dist = h[u] - h[v];
        if(get_par(u, dist) == v && a[u].fi < a[v].fi) return 1;
        else if(get_par(u, dist) != v) return 1;
        return 0;
    }
    bool cmp(ninja a, ninja b)
    {
        if(a.p == b.p) return h[a.u] < h[b.u];
        return a.p > b.p;
    }
    void slv()
    {
        fr(i, 1, n) dp[i] = 1;
        fr(i, 1, n) {
            g[a[i].se].pb(i);
        }
        DFS(1, 1);

        fr(i, 1, n) {
            qr[i] = {i, a[i].fi, a[i].se};
        }

        sort(qr + 1, qr + n + 1, cmp);
//        cout << el; fr(i, 1, n) cout << qr[i].u << " " << qr[i].p << " " el;
//        cout << el; fr(i, 1, n) {
//            cout << up[i][0] << " ";
//        } cout << el;
//        cout << el; fr(i, 1, n) {
//            cout << qr[i].u << " " << qr[i].p << " " << h[qr[i].u] << el;
//        }

        fr(i, 2, n) {
            fr(x, 1, i - 1) {
                if(check(qr[i].u, qr[x].u)) {
                    maxi(dp[i], dp[x] + 1);
                }
            }
        }
        cout << *max_element(alla(dp, n));
    }
}
namespace sub2
{
    multiset<int> st[N];
    int x[N];
    void slv()
    {
        fr(i, 1, n) x[i] = i;
        frd(i, n, 1) {
            auto it = st[x[i]].lower_bound(v[i]);
            if(it != st[x[i]].end()) {
                st[x[i]].erase(it);
            }
            st[x[i]].insert(v[i]);
            if(st[x[i]].size() < st[x[p[i]]].size()) {
                st[x[p[i]]].insert(all(st[x[i]]));
            }
            else {
                st[x[i]].insert(all(st[x[p[i]]]));
                x[p[i]] = x[i];
            }
        }
        cout << (int)st[x[0]].size();
    }
}

main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #define TASK "tas"
    if(fopen(TASK".INP", "r")) {
        freopen(TASK".INP", "r", stdin);
        freopen(TASK".OUT", "w", stdout);
    }

    bool qs = 0;

    int tt = 1;
    if(qs) cin >> tt;
    while(tt--) {
        input();
        sub2::slv();
    }
    cerr << "\nTime" << 0.001 * clock() << "s "; return 0;


}




