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

const int MAX = 1e5 + 2;
struct rectange
{
    int x, y, u, v;
};
int n;
rectange a[MAX];
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i].x >> a[i].y >> a[i].u >> a[i].v;
}
namespace sub1
{

    struct segment
    {
        int x, y1, y2, val;
    } seg[MAX + 10];
    bool cmp(segment a, segment b) {return a.x < b.x;}
    pair<ll,ll> t[4*MAX + 10];
    map<ll,ll> pos, posx;
    void upd(ll id, ll l, ll r, ll u, ll v, ll val)
    {
        if(r < u || v < l) return;
        if(u <= l && r <= v) {
            t[id].se+=val;
            if(t[id].se != 0) t[id].fi = posx[r] - posx[l] + 1;
            else if(l != r) t[id].fi = t[id << 1].fi + t[id << 1 | 1].fi;
            else t[id].fi = 0;
            return;
        }
        int m = (r + l) >> 1;
        upd(id << 1, l, m, u, v, val);
        upd(id << 1 | 1, m + 1, r, u, v, val);
        if(t[id].se != 0) t[id].fi = posx[r] - posx[l] + 1;
        else t[id].fi = t[id << 1].fi + t[id << 1 | 1].fi;
    }

    vector<int> V;
    void compress()
    {
        fr(i, 1, n) {
//            V.pb(a[i].x);
            V.pb(a[i].y);
//            V.pb(a[i].u);
            V.pb(a[i].v);
        }
        sort(all(V));
        V.resize(unique(all(V)) - V.begin());
        fr(i, 0, V.size() - 1) {
            pos[V[i]] = i;
            posx[i] = V[i];
        }
    }
    void slv()
    {
        int d = 0;
        fr(i, 1, n) {
            int x = a[i].x;
            int y = a[i].y;
            int u = a[i].u;
            int v = a[i].v;
            seg[++d] = {x, y, v, 1};
            seg[++d] = {u, y, v, -1};
        }
        sort(alla(seg, d), cmp);
        compress();
        fr(i, 1, n) cout << pos[a[i].y] << " " << pos[a[i].v] << el;
        fr(i, 1, 4e5) t[i] = {0, 0};
        ll res = 0;
        fr(i, 1, d) {
            upd(1, 0, MAX, pos[seg[i].y1], pos[seg[i].y2] - 1, seg[i].val);
            res+=(seg[i + 1].x - seg[i].x)*t[1].fi;
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
        sub1::slv();
    //    sub2::slv();
    }
}


