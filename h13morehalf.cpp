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


const int MAX = 1e6 + 5;
int n, q, a[MAX];
vector<int> g[MAX];
void input()
{
    cin >> n >> q; fr(i, 1, n) cin >> a[i];
    int x, y;
    fr(i, 2, n) {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
}
namespace sub1
{
    ll rd(ll l , ll r )
	{
	    return l+1LL*rand()*rand()%(r -l + 1) ;
	}
    struct qr
    {
        int l, r, id;
        bool operator <(qr const&a) const
        {
            if(l/BLOCK != a.l/BLOCK) return l/BLOCK < a.l/BLOCK;
            return r < a.r;
        }
    } Q[MAX];
    int euler[MAX], in[MAX], out[MAX], time = 0, res[MAX], l, r, cnt[MAX];
    void DFS(ll u, ll p)
    {
        euler[++time] = u;
        in[u] = time;
        for(int v : g[u]) if(v != p) {
            DFS(v, u);
        }
        out[u] = time;
    }
	void cal(int i)
	{
        while(l < Q[i].l) cnt[a[euler[l++]]]--;
        while(l > Q[i].l) cnt[a[euler[--l]]]++;
        while(r < Q[i].r) cnt[a[euler[++r]]]++;
        while(r > Q[i].r) cnt[a[euler[r--]]]--;


        fr(t, 1, 30) {
            int color = a[euler[rd(Q[i].l, Q[i].r)]];
            int len = (Q[i].r - Q[i].l + 1)/2;
            if(cnt[color] > len) {
                res[Q[i].id] = color;
            }
        }
	}
    void slv()
    {
        l = 1, r = 0;
        DFS(1, 0);
//        fr(i, 1, 30) {
//            cout << a[euler[rd(in[2], out[2])]] << el;
//        } return;

        fr(i, 1, n) Q[i] = {in[i], out[i], i};
        sort(alla(Q, n));
//        fr(i, 1, n) cout << Q[i].id << el;
//        fr(i, 1, n) cout << i << " " << in[i] << " " << out[i] << el;
//        fr(i, 1, n) cout << euler[i] << " "; cout << el;
//        fr(i, 1, n) cout << a[euler[i]] << " "; cout << el;
        fr(i, 1, n) res[i] = -1;
        fr(i, 1, n) cal(i);
        int x;
        while(q-- ){
            cin >> x;
            cout << res[x] << el;
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


