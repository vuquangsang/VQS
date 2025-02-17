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

ll n, k, p;
vector<ll> g[MF];
void input()
{
    cin >> n >> k >> p;
    ll x, y;
    fr(i, 2, n) {
        cin  >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

}
namespace sub1
{
    #define MAX 22
    bool vis[MAX];
    vector<int> path[MAX][MAX];
    int par[MF];
    void dfs(ll u, ll r)
    {
        for(int x = u; x > 0; x = par[x]) path[r][u].pb(x);
        for(int v : g[u]) if(v != par[u]) {
            par[v] = u; dfs(v, r);
        }

    }
    void slv()
    {
        fr(i, 1, n) {
            par[i] = 0;
            dfs(i, i);
        }
        int res = 0;
        REP(msk, 0, Mask(n)) if(c_bit(msk) == k) {

            memset(vis, false, sizeof(vis));
            fr(i, 1, n) {
                if(BIT(msk, i - 1)) {
                    fr(j, i + 1, n) if(BIT(msk, j - 1)) {
                        for(int u : path[i][j]) vis[u] = true;
                    }
                }
            }
            fr(u, 1, n) if(vis[u] && !BIT(msk, u - 1)) res++;
        }
        cout << res;
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
        if(n <= 20) sub1::slv();
    //    sub2::slv();
    }
}



