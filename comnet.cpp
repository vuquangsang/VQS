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

ll n, k, a, b;
vector<ll> g[MF];
void input()
{
    cin >> n >> k >> a >> b;
    ll x, y;
    fr(i, 2, n) {
        cin >> x  >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}
namespace sub1
{
    bool vis[MF];
    ll f[MF];
    ll bfs(ll s, ll t)
    {

        queue<ll> q;
        fr(i, 1, n) f[i] = 0;
        memset(vis, 0, sizeof(vis));
        q.push(s);
        while(!q.empty()) {
            ll u = q.front();
            q.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            for(int v : g[u]) {
                if(!vis[v]) {
                    f[v] = f[u] + 1;
                    q.push(v);
                }
            }
        }
        return f[t];
    }
    void slv()
    {
        ll res = 0;
        fr(i, 1, n) {
            fr(j, 1, n) {
                if(i == j) continue ;
                ll value = bfs(i, j);
       //         cout << i << " " << j << " " << value << el;
                if(value >= a && value <= b) res++;
            }
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
        if(k == 2 )sub1::slv();
    //    sub2::slv();
    }
}



