/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

#define     int int
#define     fr(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define     frd(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define     el "\n"
#define     pb(x) push_back(x)

template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}

const int MF = 1e6 + 2;

struct query
{
    int n, m, k;
} Q[MF];
const int MAX  = 1e6;
int p, n, m, k, t;
long long fac[MF], mod_fac[MF];
int mod(int a, int b) {return 1LL*a*b%p;}

int Pow(int a, int n)
{
    if(!n) return 1;
    int res = Pow(a, n/2);
    res = mod(res, res);
    if(n&1) res = mod(res, a);
    return res;
}

namespace sub1
{

    // chọn ra k khóm hoa sao cho xi != x(i + 1) -> chọn k trong n - 1 -> C(k, n - 1)
    // khi chia ra làm k khóm hoa thì tạo thành k + 1 đoạn liên tiếp có giá trị bằng nhau -> chọn m loại hoa có
    // đoạn trái nhất thì có m  cách chọn
    // đoạn trái nhì có m - 1 cách chọn
    // đoạn trái ba có m - 1 cách chọn
    // .. có m - 1 cách chọn -> số cách chọn  = m*(m - 1)^k
    // suy ra đáp án chính là C(k, n - 1)*m*(m - 1)^k



    // CHỈ SỬ DỤNG ĐƯỢC KHI N <= 1E6

    int C(int k, long long n)
    {
        if(k > n) return 0;
        return mod(mod_fac[k], mod(fac[n], mod_fac[n - k]));
    }
    void slv(int n, int m, int k)
    {
        cout << mod(C(k, n - 1), mod(m, Pow(m - 1, k))) << el;
    }
}
namespace sub2
{
    int C(int k, long long n )
    {
        n%=p;
        if(n < k) return 0;
        int res = mod_fac[k];
        for(int i = 0; i < k; i++) res = 1LL*res*(n - i)%p;
        return res;
    }
    void slv(int n, int m, int k)
    {
        cout << mod(C(k, n - 1), mod(m, Pow(m - 1, k))) << el;
    }
}
namespace sub3
{
    // AP DUNG CHO MOD BAT KY
    // DPT ~On
    // DPT truy van ~On
    const int MAXN = 1e6 + 2;
    int prime[MAXN];
    vector<int> v;
    void snt()
    {
        for(int i = 2; i*i < MAXN; i++) if(!prime[i]) {
            for(int j = i*i; j < MAXN; j+=i) prime[j] = 1;
        }
        fr(i, 2, MAXN - 1) if(!prime[i]) v.pb(i);
    }
    int fracExp(int n, int p)  // tra ve so mu cua p trong n!
    {
        int res = 0;
        long long pw = p;
        while(pw <= n) {
            res+=n/pw; pw*=p;
        }
        return res;
    }
    int C(int k, int n)
    {
        if(k > n) return 0;
        int res=  1;
        for(int p  : v) if(p <= n) {
            int exp = fracExp(n, p) - fracExp(k, p) - fracExp(n - k, p);
            res= 1ll*res*Pow(p, exp)%p;
        }
        return res;
    }
    void slv(int n, int m, int k)
    {
        snt();
        cout << mod(C(k, n - 1), mod(m, Pow(m - 1, k))) << el;
    }
}
main()
{
    #define TASK "flowers"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if( fopen( TASK".INP", "r") ){
        freopen( TASK".INP", "r", stdin);
        freopen( TASK".OUT", "w", stdout);
    }
    cin >> t >> p;
    fr(i, 1, t) {
        cin >> Q[i].n >> Q[i].m >> Q[i].k;
    }

    fac[0] = 1;
    mod_fac[0] = 1;
    fr(i, 1, MAX) fac[i] = mod(fac[i - 1], i);
    fr(i, 1, MAX) mod_fac[i] = Pow(fac[i], p - 2);
    fr(i, 1, t) {
        int n = Q[i].n;
        int m = Q[i].m;
        int k = Q[i].k;
        if(t <= 50 && p == 998244353) sub2::slv(n, m, k);
        else if(t <= 50 && p == 220797) sub3::slv(n, m, k);
        else sub1::slv(n, m, k);
    }
    cerr << el << clock() << " " << "ms" << el;
}



