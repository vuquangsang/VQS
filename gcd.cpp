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

struct node{ll x,y,w;};
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
void input()
{
    cin >> n;
}
namespace sub1
{

    map<ll,stack<ll>> mp;
    ll t[MF], leave[MF];
    void build(ll id, ll l, ll r)
    {
        if(l == r) {
            leave[l] = id;
            return ;
        }
        ll m = (r + l) >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);
    }
    void upd(ll i, ll val)
    {
        ll id = i;
        t[id] = val;
        while(id > 0) {
            id/=2;
            t[id] = gcd(t[id << 1], t[id << 1 | 1]);
        }
    }
    void slv()
    {
        ll k, x;
        ll ans = 0;
        int T = (1 << int(ceil(log2(n))));
        fr(i, T, T + n - 1){
            cin >> k >> x;
            if(k == 1) {
                ans++;
                mp[x].push(i);
                upd(i, x);
            }
            else {
                ans--;
                ll p = mp[x].top();
                mp[x].pop();
                upd(p, 0);
            }
            if(!ans) cout << 1 << el;
            else cout << t[1] << el;
        }
    }
}
namespace sub2
{
    vector<ll> v;
    node qr[MF];
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
        t[id] = gcd(t[id << 1] , t[id << 1 | 1]);
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return  0;
        if(u <= l && r <= v) return  t[id];
        ll m = (r + l) >> 1;
        return gcd(get(id << 1, l, m, u, v) , get(id << 1 | 1, m + 1, r, u, v));
    }
    void slv()
    {
        fr(i, 1, n) {
            cin >> qr[i].x >> qr[i].y;
            qr[i].w = qr[i].y;
            v.pb(qr[i].w);
        }
        sort(all(v)) ;
        fr(i, 1, n) qr[i].w = lower_bound(all(v), qr[i].w) - v.begin() + 1;
        ll ans = 0;
        fr(i, 1, n) {
            if(qr[i].x == 1) {
                ans++;
                upd(1, 1, n, qr[i].w, qr[i].y);
            }
            else{
                ans--;
                upd(1, 1, n, qr[i].w, 0);
            }
            if(!ans) cout << 1 << el;
            else cout << t[1] << el;
        }
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


