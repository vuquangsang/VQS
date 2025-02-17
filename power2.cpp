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

const int MAX = 1e6 + 2;
ll n, a[MAX];
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i];
}
namespace sub1
{

    ll mult(ll x, ll y, ll md) {
        ull q = (ld)x * y / md;
        ll res = ((ull)x * y - q * md);
        if (res >= md) res -= md;
        if (res < 0) res += md;
        return res;
    }

    // Hàm tính lũy thừa nhanh
    ll powMod(ll x, ll p, ll md) {
        if (p == 0) return 1;
        if (p & 1) return mult(x, powMod(x, p - 1, md), md);
        return powMod(mult(x, x, md), p / 2, md);
    }

    // Thuật toán Rabin Miller hỗ trợ kiểm tra các số nguyên tố lớn
    bool checkMillerRabin(ll x, ll md, ll s, int k) {
        x = powMod(x, s, md);
        if (x == 1) return true;
        while (k--) {
            if (x == md - 1) return true;
            x = mult(x, x, md);
            if (x == 1) return false;
        }
        return false;
    }

    // Hàm kiểm tra nhanh một số có nguyên tố hay không
    bool isPrime(ll x) {
        if (x == 2 || x == 3 || x == 5 || x == 7) return true;
        if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return false;
        if (x < 121) return x > 1;
        ll s = x - 1;
        int k = 0;
        while (s % 2 == 0) {
            s >>= 1;
            k++;
        }
        if (x < 1LL << 32) {
            for (ll z : {2, 7, 61}) {
                if (!checkMillerRabin(z, x, s, k)) return false;
            }
        } else {
            for (ll z : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
                if (!checkMillerRabin(z, x, s, k)) return false;
            }
        }
        return true;
    }

    ll gcd(ll x, ll y) { return y == 0 ? x : gcd(y, x % y); }

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    long long get_rand(long long r) {
        return uniform_int_distribution<long long>(0, r - 1)(rng);
    }

    void pollard(ll x, vector<ll> &ans) {
        if (isPrime(x)) {
            ans.push_back(x);
            return;
        }
        ll c = 1;
        while (true) {
            // Định nghĩa hàm f sử dụng cú pháp lambda function
            c = 1 + get_rand(x - 1);
            auto f = [&](ll y) {
                ll res = mult(y, y, x) + c;
                if (res >= x) res -= x;
                return res;
            };
            ll y = 2;
            int B = 100;
            int len = 1;
            ll g = 1;
            // Sử dụng thuật cải tiến của Brent ở đây
            while (g == 1) {
                ll z = y;
                for (int i = 0; i < len; i++) {
                    z = f(z);
                }
                ll zs = -1;
                int lft = len;
                while (g == 1 && lft > 0) {
                    zs = z;
                    ll p = 1;
                    for (int i = 0; i < B && i < lft; i++) {
                        p = mult(p, abs(z - y), x);
                        z = f(z);
                    }
                    g = gcd(p, x);
                    lft -= B;
                }
                if (g == 1) {
                    y = z;
                    len <<= 1;
                    continue;
                }
                if (g == x) {
                    g = 1;
                    z = zs;
                    while (g == 1) {
                        g = gcd(abs(z - y), x);
                        z = f(z);
                    }
                }
                if (g == x) break;
                assert(g != 1);
                // Thay vì kết thúc như thuật toán Brent,
                // tiếp tục phân tích hai phần g và x / g
                pollard(g, ans);
                pollard(x / g, ans);
                return;
            }
        }
    }

    // return list of all prime factors of x (can have duplicates)
    vector<ll> factorize(ll x) {
        vector<ll> ans;
        for (ll p : {2, 3, 5, 7, 11, 13, 17, 19}) {
            while (x % p == 0) {
                x /= p;
                ans.push_back(p);
            }
        }
        if (x != 1) {
            pollard(x, ans);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    // return pairs of (p, k) where x = product(p^k)
    vector<pair<ll, int>> factorize_pk(ll x) {
        auto ps = factorize(x);
        ll last = -1, cnt = 0;
        vector<pair<ll, int>> res;
        for (auto p : ps) {
            if (p == last)
                ++cnt;
            else {
                if (last > 0) res.emplace_back(last, cnt);
                last = p;
                cnt = 1;
            }
        }
        if (cnt > 0) {
            res.emplace_back(last, cnt);
        }
        return res;
    }
    void slv()
    {
        fr(i, 1, n) {
            ll
        }
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


