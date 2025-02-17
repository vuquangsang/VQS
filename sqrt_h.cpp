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

struct node{ll l,r,id;};
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

ll n, a[MF], q;
node qr[MF];
void input()
{
    cin >> n; fr(i, 1, n) cin >> a[i];
    cin >> q;
    fr(i, 1, q){
        cin >> qr[i].l >> qr[i].r; qr[i].id = i;
    }
}
namespace sub1
{
    ll ans[MF];
    pll res;
    multiset<ll> st;
    bool cmp(node a, node b)
    {
        if(a.l/BLOCK != b.l/BLOCK) return a.l/BLOCK < b.l/BLOCK;
        return a.r < b.r;
    }
    void add(ll i)
    {
        if(!st.size()) {
            st.insert(a[i]);
            return;
        }
        auto id = st.lower_bound(a[i]);
        ll m1 = *id;
        ll m2 = *(--id);
        ll value = min(m1 - a[i], a[i] - m2);
        if(value < res.fi){
            res.se = res.fi;
            res.fi = value;
        }
        else mini(res.se, value);
    }
    void del(ll i)
    {
        st.erase(st.find(a[i]));
        auto id = st.lower_bound(a[i]);
        ll m1 = *id;
        ll m2 = *(--id);

    }
    void del(ll i)
    {
        res = inf;
        ll value = 0;
        st.erase(st.find(a[i]));
        for(auto it = st.begin(); it != st.end(); it++) {
            if(it == st.begin()) {
                value = *it;
                continue;
            }
            mini(res, *it - value);
            value = *it;
        }
    }
    void slv()
    {
        res = {inf, inf};
        sort(alla(qr, q), cmp);
        fr(i, qr[1].l, qr[1].r) add(i);
        ans[qr[1].id] = res;
        int l = qr[1].l, r = qr[1].r;
        fr(i, 2, q) {
            while(qr[i].r > r) add(++r);
            while(qr[i].l < l) add(--l);
            while(qr[i].r < r) del(r--);
            while(qr[i].l > l) del(l++);
            ans[qr[i].id] = res;
        }
        fr(i, 1, q) cout << ans[i] << el;
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



