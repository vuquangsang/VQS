#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i, a, b) for(int i = a; i <= (b); i++ )
const ll MN = 1e9 + 7;
const ll MF = 1e6 + 7;
const ll N = 1005;
const ll inf = 1e18 + 7;
ll n, k, a[MF], f[305][305][305];
template<class X, class Y>
    bool maxi(X &x, const Y &y) {
        if(x < y) {
            x = y;
            return 1;
        }
        else return 0;
    }

void doc()
{
    cin >> n >> k; fr(i, 1, n) cin >> a[i];
}
ll Sum(ll a, ll b)
{
    return abs(a - b);
}
ll cal(ll l, ll r, ll k)
{
    if(!k) return 0;
    if(l > r) {
        if(!k) return 0;
        return -inf;
    }
    ll &res = f[l][r][k];
    if(res != -1) return res;
    if(l + 1 <= r) {
        maxi(res, abs(a[l] - a[l + 1]) + cal(l + 2, r, k - 1));
        maxi(res, abs(a[r] - a[r - 1]) + cal(l, r - 2, k - 1));
        maxi(res, abs(a[l] - a[r]) + cal(l + 1, r - 1, k - 1));
    }
    maxi(res, cal(l + 1, r, k));
    maxi(res, cal(l, r - 1, k));
    return res;
}
void slv()
{
    memset(f, 255, sizeof(f));
    cout << cal(1, n, k);
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    doc();
    slv();
}
