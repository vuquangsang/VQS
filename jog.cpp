/* Vu Quang Sang from Le Khiet High School for Gifted */
#include <bits/stdc++.h>
using namespace std;

#define     ll int
#define     pb push_back

#define     fr(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define     frd(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define     REP(i, a, b) for(int i = (a), _b = (b); i < _b; i++)




const int MAX = 1e5 + 5;
int n, r, m, len[MAX];
void input()
{
    cin >> n >> r >> m; fr(i, 1, m) cin >> len[i];

}
namespace sub1
{

    ll star[MAX], cnt[MAX];
    vector<int> cycle;
    bool vis[MAX];
    long long res[MAX];
    void slv()
    {
        ll pos = 0;
        fr(i, 1, m) {
            pos = (pos + len[i])%n;
            if(pos < 0) pos+=n;
            cnt[pos]++;
        }

        int cur = 0;
        while(!vis[cur]) {
            vis[cur] = 1;
            cycle.pb(cur);
            cur = (cur + pos)%n;
        } // number node to -> cycle
        for(int p : cycle) star[p]+=r/cycle.size();
        if(r%cycle.size() != 0) {
            fr(i, 0, (r%cycle.size()) - 1) star[cycle[i]]++;
        }
        fr(i, 0, n - 1) fr(j, 0, n - 1) {
            int  p = i + j;
            if(p >= n) p-=n;
            res[p]+=1ll*star[i]*cnt[j];
        } res[0]++;
        fr(i, 0, n - 1) cout << res[i] << " ";
    }
}
//namespace sub2
//{
//    ll cnt[MAX];
//    void slv()
//    {
//        ll pos = 0;
//        fr(t, 1, r) fr(i, 1, m) {
//            pos = (pos + len[i])%n;
//            if(pos < 0) pos+=n;
//            cnt[pos]++;
//        } cnt[0]++;
//        fr(i, 0, n - 1) cout << cnt[i] << " ";
//    }
//}

main()
{
    #define TASK "jog"
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
        cerr << clock();
    //    sub2::slv();
    }
}



