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

ll n, a[MF];
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i];
}
namespace sub1
{
    vector<ll> v;
    map<ll,ll> mp;
    ll t[MF], f[MF];
    void upd(ll id, ll l, ll r, ll i, ll val)
    {
        if(i > r || i< l) return ;
        if(l == r) {
            maxi(t[id], val);
            return ;
        }
        int m = (r + l) >> 1;
        upd(id << 1, l, m, i, val);
        upd(id << 1 | 1, m + 1, r, i, val);
        t[id] = max(t[id << 1], t[id << 1 | 1]);
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return t[id];
        int m = (r + l) >> 1;
        return max(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
    }
    void slv()
    {
        fr(i, 1, n) v.pb(a[i]);
        sort(all(v));
        v.resize(unique(all(v)) - v.begin());
        fr(i, 0, v.size() - 1) {
            mp[v[i]] = i + 1;
        }
        fr(i, 1, n) a[i] = mp[a[i]];
        upd(1, 1, 2*1e5, a[1], 1);
        fr(i, 2, n) {
            f[i] = get(1, 1, 2*1e5, 1, a[i] - 1);
            upd(1, 1, 2*1e5, a[i], i);
        }
        fr(i, 1, n) cout << f[i] << " ";
    }
}
namespace sub2
{
    stack<ll> s;
    ll f[MF];
    void slv()
    {
        f[1] = 0;
        s.push(1);
        fr(i, 2, n) {
            while(!s.empty() && a[i] <= a[s.top()]) s.pop();
            if(s.empty()) f[i] = 0;
            else f[i] = s.top();
            s.push(i);
        }
        fr(i, 1, n) cout << f[i] << " ";
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
        sub2::slv();
    //    sub2::slv();
    }
}



