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

const int MAX = 1e5 + 2;
ll a[MAX], b[MAX], n;
void input()
{
    cin >> n;
    fr(i, 1, n) cin >> a[i];
    fr(i, 1, n) cin >> b[i];
}
namespace sub1
{

    struct line
    {
        ll l, r, p;
    };
    ll f[MAX];
    deque<line> dq;
    ll w(ll j, ll i) {
        return 1LL*b[j]*a[i];
    }
    void slv()
    {
        dq.pb({2, n, 1});
        fr(i, 2, n) {
            int p = dq.front().p;
            f[i] = f[p] + w(p, i);

            ++dq.front().l;
            if(dq.front().l > dq.front().r) dq.pop_front();

            while(!dq.empty()) {
                int l = dq.back().l;
                int p = dq.back().p;
                if(f[i] + w(i, l) < f[p] + w(p, l)){
                    dq.pop_back();
                }
                else break;
            }

            if(dq.empty()) {
                dq.push_back({i + 1, n, i});
            }
            else{
                auto& [l, r, p] = dq.back();
                int low = l, high = r, pos = r + 1, m;
                while(low <= high) {
                    m = (low + high) >> 1;
                    if(f[i] + w(i, m) < f[p] + w(p, m)) {
                        pos = m;
                        high  = m - 1;
                    }
                    else low = m + 1;
                }
                r = pos - 1;
                if(pos <= n) dq.push_back({pos, n, i});
            }
        }
        cout << f[n];
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


