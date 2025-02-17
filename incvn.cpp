#include <bits/stdc++.h>
using namespace std;

#define   ll int
#define     lg(x) __log(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
//#define     ll long long
#define     fi first
#define     se second
#define     Mask(i) (1ll<<(i))
#define     c_bit(i) __builtin_popcountll(i)
#define     fr(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define     frd(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define     REP(i, a, b) for(int i = (a), _b = (b); i < _b; i++)
#define     BIT(msk, i) (msk&(1 << i))

const ll MN = 5000000;
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

ll n, k, a[MF];
void input()
{
    cin >> n >> k;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    ll f[F][52], t[4*F][52];
    vector<ll> v;
    void upd(ll id, ll l, ll r , ll i, ll val, ll k)
    {
        if(i > r | i < l) return ;
        if(l == r) {
            t[id][k]+=val;
            t[id][k]%=MN;
            return ;
        }
        ll m = (r + l) >> 1;
        upd(id << 1, l, m, i, val, k);
        upd(id << 1 | 1, m + 1, r, i,  val, k);
        t[id][k] = (t[id << 1][k] + t[id << 1 | 1][k])%MN;
    }
    ll get(ll id, ll l, ll r, ll u, ll v, ll k)
    {
        if(r < u || v < l) return  0;
        if(u <= l && r <= v) return  t[id][k]%MN;
        ll m = (r + l) >> 1;
        return (get(id << 1, l, m, u, v, k) + get(id << 1 | 1, m + 1, r, u, v, k))%MN;
    }
    void slv()
    {

        fr(i, 1, n) v.pb(a[i]);
        sort(all(v));
        fr(i, 1, n) a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;
        f[1][1] = 1;
        upd(1, 1, n, a[1], 1, 1);
        fr(i, 2, n) {
            fr(len, 2, k){
                f[i][len] = get(1, 1, n, 1, a[i] - 1, len - 1);
                f[i][len]%=MN;
                upd(1, 1, n, a[i], f[i][len], len);
            }
            upd(1, 1, n, a[i], 1, 1);
            f[i][1] = 1;
        }
        ll res = 0;
        fr(i, 1, n){
            res+=f[i][k];
            res%=MN;
        }
        cout << res;
    }
}
namespace sub2
{
    ll f[F][52];
    void slv()
    {
        fr(i, 1, n) f[i][1] = 1;
        fr(i, 1, n) {
            fr(j, 1, i - 1) {
                if(a[i] > a[j]) {
                    fr(len, 2, k) {
                        f[i][len]+=f[j][len - 1];
                        f[i][len]%=MN;
                    }
                }
            }
        }
        ll res = 0;
        fr(i, 1, n) {
            res+=f[i][k];
            res%=MN;
        }
        cout << res;
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




