/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

#define     ll int
#define     Mask(i) (1<<(i))
#define     fr(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define     frd(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define     REP(i, a, b) for(int i = (a), _b = (b); i < _b; i++)

const ll MN = 1e9 + 2;
const ll MF = 11e5 + 3;
const long long inf = 2e9;
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}


const short MAX = 502;
ll n, k, pos[MAX], cost[MAX][MAX];
ll f[MF][21], res = inf;
void input()
{
    cin >> n >> k;
    fr(i, 1, n) fr(j, 1, n) cin >> cost[i][j];
    fr(i, 1, k) cin >> pos[i];
}
//namespace sub1
//{


    void slv()
    {
        fr(k, 1 , n) fr(i, 1, n) fr(j, 1, n) {
            mini(cost[i][j], cost[i][k] + cost[k][j]);
        }
        REP(msk, 0, Mask(k)) fr(i, 1, k) f[msk][i] = inf;
        fr(i, 1, k) f[1 << (i - 1)][i] = cost[1][pos[i]];
        REP(msk, 1, Mask(k)) {
            fr(i, 1, k) if(msk&(1 << (i - 1))) {
                for (int tmp = (Mask(k) - 1) ^ msk; tmp > 0; tmp ^= tmp & -tmp) {
                    int j = __builtin_ctz(tmp & -tmp) + 1;
                    ll new_msk = msk|(1 << (j - 1));
                    mini(f[new_msk][j], f[msk][i] + cost[pos[i]][pos[j]]);
                }
            }
        }
        fr(i, 1, k) mini(res, f[Mask(k) - 1][i] + cost[pos[i]][1]);
        cout << res ;
    }


main()
{
    #define TASK "banhkhuc"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if( fopen( TASK".INP", "r") ){
        freopen( TASK".INP", "r", stdin);
        freopen( TASK".OUT", "w", stdout);
    }
//    bool qs = 0;
//    ll mtt = 1;
//    if(qs) cin >> mtt;
//    fr(i, 1, mtt){
        input();
        slv();
    //    sub2::slv();
//    }
}



