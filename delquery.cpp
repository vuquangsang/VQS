/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

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
struct pll
{
    ll fi, se;
    bool operator <(pll const&a) const
    {
        if(this->se == a.se) return this->fi < a.fi;
        return this-> se < a.se;
    }
};
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

int n, m, q;
vector<int> g[MF];
ll A[MF], B[MF], del[MF], Q[MF];
set<ll> c[MF];
void input()
{
    cin >> n >> m;
    int x, y;
    fr(i, 1, m) {
        cin >> x >> y;
        A[i] = x;
        B[i] = y;
        c[x].insert(i);
    }
    cin >> q;
    fr(i, 1, q) {
        cin >> x >> y;
        if(x == 1) {
            del[y] = i;
            Q[i] = -y;
        }
        else{
            Q[i] = y;
        }
    }
}
namespace sub1
{
    ll f[MF], vao[MF];
    vector<ll> T[MF];
    bool dd[MF];
    void build()
    {
        fr(i, 1, n) dd[i] = 0;
        priority_queue<pll> q;
        f[1] = inf;
        q.push({1, f[1]});
        while(!q.empty()){
            int u = q.top().fi;
            q.pop();
            if(dd[u]) continue ;
            dd[u] = 1;
            if(f[u] < inf) T[f[u]].pb(u);
            for(int j : c[u]) {
                ll v = B[j];
                ll w = min(del[j], f[u]);
                vao[v]++;
                if(maxi(f[v], w)){
                    q.push({v, f[v]});
                }
            }
        }
    }
    void slv()
    {
        fr(i, 1, m) del[i] = inf;
        build();
        fr(i, 1, q) {
            for(int x : T[i]) {
                for(int j : c[x]) {
                    int v = B[j];
                    vao[v]--;
                }
            }
            if(Q[i] > 0) cout << vao[Q[i]] << el;
            else {
                int id = -Q[i];
                int u = A[id];
                int v = B[id];
                if(f[u] > i) {
                    vao[v]--;
                    c[u].erase(id);
                }
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



