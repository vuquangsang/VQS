/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
#include "egg.h"
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


const int N = 1e3 + 5;
int solve(int e, int n )
{
    long long dp[N][N];
    int best[N][N];
    fr(i, 1, n) dp[i][0] = inf;
    fr(i, 1, n) fr(j, 1, e) {
        if(i == 1) {
            dp[i][j] = best[i][j] = 1;
            continue;
        }
        dp[i][j] = inf;
        fr(m, 1, i - 1) {
            ll cost = max(dp[m - 1][j - 1], dp[i - m][j]) + 1;
            if(mini(dp[i][j], cost)) {
                best[i][j] = m;
            }
        }
    }
    int E = e;
    int N1 = n;
    int ans = 0;
    while(N1 > 0) {
        int m = best[N1][E];
        if(drop(ans + m)) {
            N1 = N1 - m;
            ans+=m;
        }
        else {
            N1 = m - 1;
            E--;
        }
    }
    return ans;
}



