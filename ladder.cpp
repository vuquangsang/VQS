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


const int N = 2e6 + 5, base = 311, sm = 1e9 + 7;
const long long inf  = 1e18 + 2;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}


int n, q;
int a[N];
void input()
{
    cin >> n >> q;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    pair<int, int> st[4*N];
    int pre[N], suf[N];

    pii MER(pii a, pii b)
    {
        pii res;
        res.fi = max(a.fi, b.fi);
        if(a.fi > b.fi) res.se = a.se;
        else res.se = b.se;
        return res;
    }
    void build(int id, int l, int r)
    {
        if(l == r)  {
            st[id] = {a[l], l};
            return;
        }
        int mid = (r + l) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        st[id] = MER(st[id << 1], st[id << 1 | 1]);
    }
    pii get(int id, int l, int r, int u, int v)
    {
        if(r < u || v < l) return {0, 0};
        if(u <= l && r <= v) return st[id];
        int mid = (r + l) >> 1;
        return MER(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }
    void slv()
    {
        build(1, 1, n);

        fr(i, 1, n) {
            if(a[i] >= a[i - 1]) pre[i] = pre[i - 1] + 1;
            else pre[i] = 1;
        }
        frd(i, n, 1) {
            if(a[i] >= a[i + 1]) suf[i] = suf[i + 1] + 1;
            else suf[i] = 1;
        }

        while(q--) {
            int x, y;
            cin >> x >> y;
            int pos = get(1, 1, n, x, y).se;
            if(pre[pos] >= pos - x + 1 && suf[pos] >= y - pos + 1) cout << "Yes" << el;
            else cout << "No" << el;
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
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #define TASK ""
    if(fopen(TASK".INP", "r")) {
        freopen(TASK".INP", "r", stdin);
        freopen(TASK".OUT", "w", stdout);
    }

    bool qs = 0;

    int tt = 1;
    if(qs) cin >> tt;
    while(tt--) {
        input();
        sub1::slv();
    }
    cerr << "\nTime" << 0.001 * clock() << "s "; return 0;


}



