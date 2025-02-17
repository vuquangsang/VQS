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

const int MAX = 1e3 + 2;
int n, k, a[MAX];
void input()
{
    cin >> n >> k;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    void DFS(ll u, ll p)
    {
        cout << u << el;
        for(int v : g[u]) if(v != p) {
            DFS(v, u);
        }
    }
    vector<int> g[MAX], G[MAX];
    bool dd[MAX];
    int num[MAX], low[MAX], del[MAX], var[MAX], cur = 0, A[MAX], sl[MAX], B[MAX], time = 0, scc = 0;
    ll f[MAX];
    stack<ll> st;
    void dfs(int u, int p)
    {
        low[u] = num[u] = ++time;
        st.push(u);
        for(int v : g[u]) {
            if(del[v]) continue;
            if(!num[v]) {
                dfs(v, u);
                mini(low[u], low[v]);
            }
            else mini(low[u], num[v]);
        }
        if(low[u] == num[u]) {
            scc++;
            ll v;
            do {
                v = st.top();
                st.pop();
                del[v] = scc;
                sl[scc]++;
            } while(u != v);
        }
    }
    void find(ll u, ll p, ll cur)
    {
        B[cur]+=sl[u];
        for(int v : G[u]) {
            if(v == p) continue;
            find(v, u, cur);
        }
    }
    void slv()
    {
        fr(i, 1, n) {
            g[a[i]].pb(i);
        }
        fr(i, 1, n) if(!del[i]) dfs(i, 0);
        fr(i, 1, n) {
            for(int v : g[i]) {
                if(del[i] != del[v]) {
                    G[del[i]].pb(del[v]);
                    var[del[v]]++;
                }
            }
        }
        queue<ll> ds;
        ll cur = 0;
        fr(i, 1, scc) {
            if(!var[i]) {
                cur++;
                A[cur] = sl[i];
                find(i, 0, cur);
                B[cur]-=A[cur];
            }
        }
        dd[0] = 1;
        fr(i, 1, cur) {
            frd(j, k, A[i]){
                if(dd[j - A[i]]) {
                    dd[j] = 1;
                    maxi(f[j], f[j - A[i]] + B[i]);
                }
            }
        }
        ll ans = 0;
        fr(i, 1, k) {
            if(dd[i]) {
                maxi(ans, min(1ll*k, i + f[i]));
            }
        }
        cout << ans;
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


