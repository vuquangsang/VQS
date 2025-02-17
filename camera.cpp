#include <bits/stdc++.h>
using namespace std;

#define     TASK "camera"
#define     lg(x) log2(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll long long
#define     fi first
#define     se second
#define     MASK(i) (1ll<<(i))
#define     c_bit(i) __builtin_popcountll(i)
#define     fr(i,a,b) for(int i=a;i<=b;i++)
#define     frd(i,a,b) for(int i=a;i>=b;i--)

const ll MN = 1e9+7;
const ll MF = 1e6+7;
const ll inf = 1e18+7;
const ll N = 1005;
const ll H = 311;
const ll F = 1e5 + 3;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
ll sum(ll a, ll b) {return (a + b)%MN;}

ll n, k, r, t, a[MF];
void input()
{
    cin >> n >> k >> r >> t ;
    fr(i, 1, k) cin >> a[i];
}
namespace sub1
{
    vector<ll> v;
    ll st[MF];
    bool check[MF];
    void upd(ll id, ll l, ll r, ll i, ll val)
    {
        if(i > r || i < l) return ;
        if(l == r) {
            st[id]+=val;
            return ;
        }
        ll m = (r + l) >> 1;
        upd(id << 1, l, m, i, val);
        upd(id << 1 | 1, m + 1, r, i, val);
        st[id] = st[id << 1]  + st[id << 1 | 1];
    }
    ll get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return st[id];
        ll m = (r + l) >> 1;
        return get(id << 1, l, m, u, v) + get(id << 1 | 1, m + 1, r, u, v);
    }
    void slv()
    {
        fr(i, 1, k) {
            upd(1, 1, n, a[i], 1);
            check[a[i]] = 1;
        }
        fr(i, 1, n - r + 1) {
            if(get(1, 1, n, i, i + r - 1) >= t) continue ;
            else  {
                ll value = get(1, 1, n, i, i + r - 1) ;
                ll dis = t - value;
                ll d = 0;
                frd(x, i + r - 1, i) {
                    if(!check[x]) {
                        v.pb(x);
                        d++;
                        check[x] = 1;
                        upd(1, 1, n, x, 1);
                    }
                    if(d >= dis) break;
                }
            }
        }
        cout << v.size() << el;
        sort(all(v));
        for(auto x : v) cout << x << " " ;
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









