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

const int MAX = 5e4 + 2;
int n, q, a[MAX];
vector<int> g[MAX];
void input()
{
    cin >> n >> q; fr(i, 1, n) cin >> a[i];
    fr(i, 2, n) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}
namespace sub1
{

    struct qr
    {
        int l, r, id;
        bool operator <(qr const&a) const
        {
            if(l/BLOCK != a.l/BLOCK) return l/BLOCK < a.l/BLOCK;
            return r < a.r;
        }
    } Q[MAX];
    int time = 0, euler[MAX], in[MAX], out[MAX], res = 0, cnt[MAX], ans = 0, result[MAX];
    void DFS(ll u, ll p)
    {
//        cout  << u << " ";
        euler[++time] = a[u];
        in[u] = time;
        for(int v : g[u]) if(v != p) {
            DFS(v, u);
        }
        out[u] = time;
    }
    void add(int x)
    {
        cnt[euler[x]]++;
        if(maxi(res, cnt[euler[x]])) ans = euler[x];
    }
    void del(int x)
    {

        if(res == cnt[euler[x]]) res--;
        cnt[euler[x]]--;

    }
    void slv()
    {
        DFS(1, 0);
//        cout << el; fr(i, 1, n) cout << euler[i] << " "; cout << el;
//        fr(i, 1, n) cout << in[i] << " " << out[i] << el;
        fr(i, 1, n) Q[i] = {in[i], out[i], i};
        sort(alla(Q, n));
//        fr(i, 1, n) cout << Q[i].id << " "; cout << el;
        int l = Q[1].l, r = Q[1].r;
        fr(i, l, r) add(i);
        if(res > (r - l + 1)/2) result[Q[1].id] = ans;
        else result[Q[1].id] = -1;
        cout << el;
        fr(i, 2, n) {
            while(r > Q[i].r) del(r--);
            while(l < Q[i].l) del(l++);
            while(r < Q[i].r) add(++r);
            while(l > Q[i].l) add(--l);


            if(res > (r - l + 1)/2) result[Q[i].id] = ans;
            if(Q[i].id == 3) {
                cout << res << " " << ans << el;
            }
            else result[Q[i].id] = -1;
        }
        fr(i, 1, q) {
            int x;
            cin >> x;
            cout << result[x] << el;
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
    #define TASK "task"
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


