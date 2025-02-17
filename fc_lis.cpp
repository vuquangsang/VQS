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
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

int n;
pll a[F];
int ans = 0;
bool check = 1;
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i].fi >> a[i].se;
    fr(i, 1, n) ans+=a[i].se;
    fr(i, 2, n) {
        if(a[i].fi != a[i - 1].fi + a[i - 1].se) check = 0;
    }
}
namespace sub1
{

    ll pos[MF];
    ll f[MF];
    void slv()
    {
        int d = 0;
        fr(i, 1, n) {
            ll value = a[i].fi;
            fr(j, 1, a[i].se) {
                pos[++d] = value;
                value++;
            }
        }
  //      fr(i, 1, d) cout << pos[i] << " "; cout << el;
        fr(i, 1, d) f[i] = inf;
        ll res = 0;
        fr(i, 1, d) {
            ll id = lower_bound(f + 1, f + d + 1, pos[i]) - f;
            maxi(res, id);
            f[id] = pos[i];
        }
        cout << res;
    }
}
namespace sub2
{
    ll f[MF];
    void slv()
    {
        f[1] = a[1].se;
        fr(i, 2, n) {
            f[i] = a[i].se;
            fr(j, 1, i - 1) {
                ll value = a[j].fi + a[j].se - 1;
                if(value < a[i].fi){
                    maxi(f[i], f[j] + a[i].se);
                }
                else{
                    ll tmp = a[i].fi - a[j].fi;
          //          ll R = a[i].fi + a[i].se - 1;
                    maxi(f[i], f[j] - a[j].se + tmp + a[i].se);
                //    maxi(f[i], f[j] + R - value);
                }
            }
        }
   //     fr(i, 1, n) cout << f[i] << " "; cout << el;
        cout << *max_element(f + 1, f + n + 1);
    }
}
namespace sub3
{
    const int lim = 2*1e5;
    vector<ll> v;
    map<ll,ll> mp;
    ll pos[MF], f[MF], t[MF], posF[MF], st[MF];
    void upd(ll id, ll l, ll r, ll i, ll val, ll t[])
    {
        if(i > r || i < l) return;
        if(l == r) {
            maxi(t[id], val); return ;
        }
        int m= (r + l) >> 1;
        upd(id << 1, l, m, i, val, t);
        upd(id << 1 | 1, m + 1, r, i, val, t);
        t[id] = max(t[id << 1], t[id << 1 | 1]);
    }
    ll get(ll id, ll l, ll r, ll u, ll v, ll t[])
    {
        if(r < u || v < l) return -inf;
        if(u <= l && r <= v) return t[id];
        int m = (r + l) >> 1;
        return max(get(id << 1, l, m, u, v, t), get(id << 1 | 1, m + 1, r, u, v, t));
    }
    void slv()
    {
        fr(i, 1, n) {
            v.pb(a[i].fi + a[i].se - 1);
            v.pb(a[i].fi);
        }
        sort(all(v));
        v.resize(unique(all(v)) - v.begin());
        fr(i, 0, v.size() - 1) {
            mp[v[i]] = i + 1;
        }
        fr(i, 1, n) pos[i] = mp[a[i].fi + a[i].se - 1];
        fr(i, 1, n) posF[i] = mp[a[i].fi];
        fr(id, 1, 4*lim) st[id] = -inf;
        f[1] = a[1].se;
        upd(1, 1, lim, pos[1], f[1], t);
        upd(1, 1, lim, pos[1], f[1] - a[1].fi - a[1].se, st);
  //      cout << el;fr(i, 1, n) cout << pos[i] << " "; cout << el;
    //   fr(i, 1, n) cout << posF[i] << " "; cout << el;
        fr(i,2 , n) {
            f[i] = a[i].se;
            maxi(f[i], get(1, 1, lim, 1, posF[i] - 1, t) + a[i].se);
            maxi(f[i], get(1, 1, lim, posF[i], lim, st) + a[i].fi + a[i].se);
            upd(1, 1, lim, pos[i], f[i], t);
            upd(1, 1, lim, pos[i], f[i] - a[i].fi - a[i].se, st);
        }
    //    fr(i, 1, n) cout << f[i] << " " ; cout << el;
        cout << *max_element(alla(f, n));
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
    bool qs = 0, b = 1;
    ll mtt = 1;
    if(qs) cin >> mtt;
    fr(i, 1, mtt){
        input();
        bool debug = 0;
        if(debug) {
   //         sub1::slv(); cout << el;
   //         sub2::slv(); cout << el;
            sub3::slv();
            return 0;
        }
        if(check & b) cout << ans;
        else if(ans <= 1e5 && b) sub1::slv();
        else if(n <= 1e3 && b) sub2::slv();
        else sub3::slv();
    }
}



