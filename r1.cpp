/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

//#define   ll int
#define     lg(x) __lg(x)
#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll int
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
const long long inf = 1e9+7;
const ll N = 1005;
const ll base = 311;
const ll F = 1e5 + 2;
const ll BLOCK = 320;
const int dx[5] = {0, -1, 1, 0 , 0};
const int dy[5] = {0, 0, 0, -1, 1};
const short LO = 17;

struct node{ll key,x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};
ll mod(ll a, ll b) {return ((a%MN)*(b%MN))%MN;}
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}
ll gcd(ll a, ll b) {return __gcd(a, b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

const int MAX = 2e5 + 7;
ll n, q, a[MAX];
bool check = 1, check2 = 1;
map<ll,ll> cnt;
node Q[MAX];
void input()
{
    cin >> n >> q;
    fr(i, 1, n) cin >> a[i];
    fr(i, 1, q) cin >> Q[i].key >> Q[i].x >> Q[i].y;
    fr(i, 2, n) {
        if(a[i] < a[i - 1]) check = 0;
        cnt[a[i]]++;
    }
    fr(i, 1, q) if(Q[i].key == 1) {
        check = 0, check2 = 0;
    }
    cnt[a[1]]++;
    fr(i, 1, n) if(cnt[i] != 1) check2 = 0;
}
namespace sub1
{


    void slv()
    {
        ll key, p, x, l, r;
        fr(t, 1, q){
            key = Q[t].key;
            if(key == 1) {
                p = Q[t].x;
                x = Q[t].y;
                a[p] = x;
            }
            else {
                l = Q[t].x, r = Q[t].y;
                ll ma = -inf, mi = inf;
                fr(i, l, r) maxi(ma, a[i]), mini(mi, a[i]);
                ll res = inf, ans = 0;
                fr(u, l, r) {
                    ll m1 = -inf, m2 = inf;
                    fr(v, u, r) {
                        maxi(m1, a[v]);
                        mini(m2, a[v]);
                        if(m1 == ma && m2 == mi) {
                            if(mini(res, v - u + 1)) {
                                ans = 1;
                            }
                            else if(res == v - u + 1) ans++;
                        }
                    }
                }
                cout << res << " " << ans << el;

            }
        }
    }
}
namespace sub2
{
    ll cal(ll l, ll r, ll x, bool k) {
        ll m, pos;
        while(l <= r) {
            m = (r + l) >> 1;
            if(k == 0) {
                if(a[m] <= x) pos = m, l = m + 1;
                else r = m - 1;
            }
            else{
                if(a[m] >= x) pos = m, r = m - 1;
                else l = m + 1;
            }
        }
        return pos;
    }
    void slv()
    {
        ll key, l, r;
        fr(i, 1, q) {
            l = Q[i].x;
            r = Q[i].y;
            cout << cal(l, r, a[r], 1) - cal(l, r, a[l], 0) + 1 << " " << 1 << el;
        }
    }
}
namespace sub3
{
    ll pos[MAX], ma[MAX][LO + 1], mi[MAX][LO + 1];
    void build_rmq()
    {
        fr(i, 1, n) {
            ma[i][0] = a[i];
            mi[i][0] = a[i];
        }
        for(int j = 1; (1 << j) - 1 <= n; j++) {
            for(int i = 1; i + (1 << j) - 1 <= n; i++){
                ma[i][j] = max(ma[i][j - 1], ma[i + (1 << (j - 1))][j - 1] );
                mi[i][j] = min(mi[i][j - 1], mi[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    ll get_max(ll l, ll r) {
        ll j = lg(r - l + 1);
        return max(ma[l][j], ma[r - (1 << j) + 1][j]);
    }
    ll get_min(ll l, ll r)
    {
        ll j = lg(r - l + 1);
        return min(mi[l][j], mi[r - (1 << j) + 1][j]);
    }
    void slv()
    {
        fr(i, 1, n) pos[a[i]] = i;
        build_rmq();
        ll key, l, r;
        fr(i, 1, q) {
            ll x = Q[i].x;
            ll y = Q[i].y;
            ll max_a = get_max(x, y);
            ll min_a = get_min(x, y);
            cout << abs(pos[max_a] - pos[min_a]) + 1 << " " << 1 << el;
        }
    }
}

namespace sub4
{

    void slv()
    {

        ll key, x, y;
        fr(qr, 1, q) {
            priority_queue<ll, vector<ll>, greater<ll>> pq;
            key  = Q[qr].key;
            x = Q[qr].x;
            y = Q[qr].y;
            if(key == 1) {
                a[x] = y;
            }
            else{
                ll max_a = -inf, min_a = inf;
                fr(i, x, y) {
                    maxi(max_a, a[i]);
                    mini(min_a, a[i]);
                }
                fr(i, x, y) {
                    if(a[i] == min_a) pq.push(i);
                }
                ll res = inf, ans = 0;
                fr(i, x, y) {
                    if(a[i] == max_a){
                        while(!pq.empty() && pq.top() < i) pq.pop();
                        if(!pq.empty()) {
                            if(mini(res, pq.top() - i + 1)) {
                                ans = 1;
                            }
                            else if(res == pq.top() - i + 1) ans++;
                        }
                    }
                }
                while(!pq.empty()) pq.pop();
                fr(i, x, y) {
                    if(a[i] == max_a) pq.push(i);
                }
                fr(i, x, y) {
                    if(a[i] == min_a) {
                        while(!pq.empty() && pq.top() < i) pq.pop();
                        if(!pq.empty()) {
                            if(mini(res, pq.top() - i + 1)) ans = 1;
                            else if(res == pq.top() - i + 1) ans++;
                        }
                    }
                }
                cout << res << " " << ans << el;
            }
        }
    }
}
namespace sub5
{
    struct IT
    {
        ll ans, ma, mi, pos_ma, pos_mi, num;
    } t[8*F];
    IT MERGE(IT a, IT b)
    {
        IT res;
        res.ma = max(a.ma, b.ma);
        res.mi = min(a.mi, b.mi);
        res.pos_ma = (a.ma > b.ma ? a.pos_ma : b.pos_ma);
        res.pos_mi = (a.mi < b.mi ? a.pos_mi : b.pos_mi);
        res.ans = abs(res.pos_ma - res.pos_mi);
        res.num = 1;
        if(a.ans == res)
        if(a.mi == b.mi && a.ma == b.ma)
        {
            res.ans = min({res.ans, a.ans, b.ans});
            ll m1 = abs(b.pos_mi - a.pos_ma);
            ll m2 = abs(b.pos_ma - a.pos_mi);
            if(mini(res.ans, m1)) {
                res.pos_mi = b.pos_mi;
                res.pos_ma = a.pos_ma;
            }
            if(mini(res.ans, m2)) {
                res.pos_mi = a.pos_mi;
                res.pos_ma = b.pos_ma;
            }
        }
        return res;
    }
    void upd(ll id, ll l, ll r, ll i)
    {
        if(i > r || i < l) return;
        if(l == r) {
            t[id] = {1, a[l], a[l], l, l, 1};
            return;
        }
        int m = (r + l) >> 1;
        upd(id << 1, l, m, i);
        upd(id << 1 | 1, m + 1, r, i);
        t[id] = MERGE(t[id << 1], t[id << 1 | 1]);
    }
    IT get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return {-inf, -inf, inf, -inf, inf};
        if(u <= l && r <= v) return t[id];
        int m = (r + l) >> 1;
        return MERGE(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
    }
    void slv()
    {
        ll k, x, y;
        fr(i, 1, n) upd(1, 1, n, i);
        fr(i, 1, q) {
            ll k = Q[i].key;
            ll x = Q[i].x;
            ll y = Q[i].y;
            if(k == 1) {
                a[x] = y;
                upd(1, 1, n, i);
            }
            else {
                cout << get(1, 1, n, x, y).ans << el;
            }
        }
    }
}
main()
{
    #define TASK "transform"
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
        if(n <= 800 && q <= 800) sub1::slv();
        else if(check) sub2::slv();
        else if(check2) sub3::slv();
        else if(q <= 400) sub4::slv();
        else sub5::slv();
    //    sub2::slv();
    }
}

