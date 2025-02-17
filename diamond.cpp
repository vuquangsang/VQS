/* Vu Quang Sang from Le Khiet High School for Gifted */
/*#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops");
#pragma GCC optimize("O3") */
#include <bits/stdc++.h>
using namespace std;

//#define   ll int
#define     lg(x) __lg(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll  int
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

struct node{ll u,id;};
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

ll n, m;
vector<node> g[MF];
node ke[MF];
bool cmp(node a, node b)
{
    if(g[a.u].size() == g[b.u].size()) return a.u < b.u;
    return g[a.u].size() < g[b.u].size();
}
void input()
{
    cin >> n >> m;
    ll x, y;
    fr(i, 1, m) {
        cin >> x >> y;
        g[x].pb({y, i});
        g[y].pb({x, i});
    }
    fr(i, 1, n) sort(all(g[i]), cmp);
}
namespace sub1
{

    // f[id] so lan tham gia vao tgian cua canh id
    ll f[MF];
    void slv()
    {
        long long res = 0;
        fr(u, 1, n) {
            for(node t : g[u]) {
                int v = t.u;
                int id = t.id;
                ke[v] = {u, id};
            }
            for(node t : g[u]) {
                int v = t.u;
                int id = t.id;
                if(g[v].size() > g[u].size() || (g[v].size() == g[u].size() && v > u)) break;
                for(node c : g[v]) {
                    int k = c.u, id2 = c.id;
                    if(g[k].size() > g[v].size() || (g[k].size() == g[v].size() && k > v)) break;
                    if(ke[k].u == u){
                        f[id]++;
                        f[id2]++;
                        int id1 = ke[k].id;
                        f[id1]++;
                        res-=3;
                    }
                }
            }
        }
        fr(i, 1, m) {
            res = res + f[i]*f[i];
        }
        cout << res/2;
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
    ios::sync_with_stdio(false);
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




