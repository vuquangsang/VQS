#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops");
#pragma GCC optimize("O3")

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

struct node{ll t,w;};
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

ll n;
node a[MF];
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i].t;
    fr(i, 1, n) cin >> a[i].w;
}
namespace sub1
{
    priority_queue<ll, vector<ll>, greater<ll>> q;
    bool cmp(node a, node b)
    {
        return a.w > b.w;
    }
    bool vis[MF];
    ll t[MF];
    void upd(ll id, ll l, ll r , ll i, ll val)
    {
        if(i > r | i < l) return ;
        if(l == r) {
            t[id] = val;
            return ;
        }
        ll m = (r + l) >> 1;
        upd(id << 1, l, m, i, val);
        upd(id << 1 | 1, m + 1, r, i,  val);
        t[id] = t[id << 1] + t[id << 1 | 1];
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return  0;
        if(u <= l && r <= v) return  t[id];
        ll m = (r + l) >> 1;
        return get(id << 1, l, m, u, v) + get(id << 1 | 1, m + 1, r, u, v);
    }
    ll cal(ll l, ll r)
    {
        ll m;
        if(l > r) return -1;
        ll d = l, c = r;
        while(r - l > 1) {
            m = (r + l) >> 1;
            ll value = get(1, 1, n, m, c);
    //        cout << value << " " << c << " " << m << el;
            if(value < c - m + 1) l = m;
            else r = m;
        }
        if(!vis[r]) return r;
        if(!vis[l]) return l;
        return -1;
    }
    void slv()
    {
        sort(alla(a, n), cmp);
        ll res = 0;
        fr(i, 1, n) {
            if(a[i].t > n) res+=a[i].w;
            else {
                if(!vis[a[i].t]) {
                    res+=a[i].w;
                    vis[a[i].t] = 1;
                    upd(1, 1, n, a[i].t, 1);
                //    cout << get(1, 1, n, a[i].t, a[i].t);
                }
                else {
           //         cout << "i" << " " << i << " " ;
                    ll id = cal(1, a[i].t - 1);
                    if(id == -1) continue;
           //         cout << id << " " ;
                    res+=a[i].w;
                    vis[id] = 1;
                    upd(1, 1, n, id, 1);
            //        cout << res << el;
               /*     frd(j, a[i].t - 1, 1){
                        if(!vis[j]) {
                            res+=a[i].w;
                            vis[j] = 1;
                            break;
                        }
                    } */

                }

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
        sub1::slv();
    //    sub2::slv();
    }
}


