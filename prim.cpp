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

struct node{ll x,y,w,k;};
struct bg{ll id,ts;};
struct pll{ll fi,se,k;};
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

ll n, m;
node a[MF];
void input()
{
    cin >> n >> m;
}
namespace sub1
{

    bool cmp(node a, node b) {return a.w < b.w;}
    bool cmp1(pll a, pll b) {return a.k < b.k;}
    struct data
    {
        ll u, w;
        bool operator<(data const&a) const
        {
            return w > a.w;
        }
    };
    priority_queue<data> q;
    data g[MF];
    ll d = 0;
    bool vis[MF];
    ll f[MF];
    void DIJ()
    {
        fr(i, 1, n) f[i] = inf;
        f[1] = 0;
        q.push({1, 0});
        while(!q.empty()){
            ll u = q.top().u;
            ll w = q.top().w;
            q.pop();
            if(vis[u]) continue ;
            vis[u] = 1;
        }
    }
}
namespace sub2
{
    void slv()
    {
        fr(i, 1, m) {
            ll x, y, w;
            cin >> x >> y >> w;
            g[x].pb({y, w});
            g[y].pb({x, w});
        }
        DIJ();

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


