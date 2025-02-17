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
            if(a[l] == a[r]) {
                cout << 1 << " " << r - l + 1 << el;
                continue;
            }
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
    struct leaf
    {
        ll ma, mi, maxl, maxr, minl, minr, best, ans;
    } t[8*MAX];
    leaf MER(leaf a, leaf b)
    {
        leaf res;
        if(a.ma == -inf) return b;
        if(b.ma == -inf) return a;
        res = {-inf, inf, inf, -inf, inf, -inf, inf, 0};

        res.ma = max(a.ma, b.ma);
        res.mi = min(a.mi, b.mi);

        if(res.ma == a.ma) {
            mini(res.maxl, a.maxl);
            maxi(res.maxr, a.maxr);
        }
        if(res.ma == b.ma) {
            mini(res.maxl, b.maxl);
            maxi(res.maxr, b.maxr);
        }
        if(res.mi == a.mi) {
            mini(res.minl, a.minl);
            maxi(res.minr, a.minr);
        }
        if(res.mi == b.mi) {
            mini(res.minl, b.minl);
            maxi(res.minr, b.minr);
        }

        if(res.ma == a.ma && res.mi == a.mi) mini(res.best, a.best);
        if(res.ma == b.ma && res.mi == b.mi) mini(res.best, b.best);

       // mini(res.best, min(b.minl - a.maxr, b.maxl - a.minr) + 1);
        if(res.mi == b.mi && res.ma == a.ma) mini(res.best, b.minl - a.maxr + 1);
        if(res.ma == b.ma && res.mi == a.mi) mini(res.best, b.maxl - a.minr + 1);

        if(res.best == a.best && res.ma == a.ma && res.mi == a.mi) res.ans+=a.ans;
        if(res.best == b.best && res.ma == b.ma && res.mi == b.mi) res.ans+=b.ans;
        if(res.best == b.minl - a.maxr + 1 && res.mi == b.mi && res.ma == a.ma) res.ans++;
        if(res.best == b.maxl - a.minr + 1 && res.ma == b.ma && res.mi == a.mi) res.ans++;
        return res;

    }
    void upd(ll id, ll l, ll r, ll i, ll val)
    {
        if(i > r || i < l)  return;
        if(l == r) {
            t[id] = {val, val, l, l, l, l, 1, 1};
            return;
        }
        int m = (r + l) >> 1;
        upd(id << 1, l, m, i, val);
        upd(id << 1 | 1, m + 1, r, i, val);
        t[id] = MER(t[id << 1], t[id << 1 | 1]);
    }
    leaf get(ll id, ll l, ll r, ll u, ll v)
    {
        if(r < u || v < l) return {-inf, inf, inf, -inf, inf, -inf, inf, 0};
        if(u <= l && r <= v) return t[id];
        int m = (r + l) >> 1;
        return MER(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
    }
    void cal(leaf tmp)
    {
        cout << tmp.ma << " " << tmp.mi << " " << tmp.maxl << " " << tmp.maxr << " " << tmp.minl << " " << tmp.minr << " " << tmp.best << " " << tmp.ans << el;
    }
    void slv()
    {
        ll k, x, y;
        fr(i, 1, n) upd(1, 1, n, i, a[i]);
//        cal(t[3]); cal(t[5]);
//        cal(MER(t[5], t[3]));
        fr(i, 1, q) {
            k = Q[i].key;
            x = Q[i].x;
            y = Q[i].y;
            if(k == 1) {
                upd(1, 1, n, x, y);
            }
            else {
                leaf val = get(1, 1, n, x, y);
                cout << val.best << " " << val.ans << el;
            }
        }
    }
}
main()
{
    #define TASK "task"
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
        sub5::slv(); return 0;
        if(n <= 800 && q <= 800) sub1::slv();
        else if(check) sub2::slv();
        else if(check2) sub3::slv();
        else if(q <= 400) sub4::slv();
        else sub5::slv();
    }
}
