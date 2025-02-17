#include <bits/stdc++.h>
using namespace std;

#define     alla(a,n) a+1,a+n+1
#define     el "\n"
#define     all(x) x.begin(),x.end()
#define     pb push_back
#define     ll long long
#define     fi first
#define     se second
#define     fr(i,a,b) for(int i=a;i<=b;i++)
#define     frd(i,a,b) for(int i=a;i>=b;i--)
const ll MN=1e9+7;
const ll MF=1e6+7;
const ll inf=1e18+7;

struct node{ll x,y;};
struct bg{ll id,ts;};
struct pll{ll fi,se;};
struct init{ll in,va;bool operator <(init const&a)const{return this->va>a.va;}};

namespace sub
{

}

ll q, n, k, a[MF] , pre[MF];
bool b[MF] = {0};
void input()
{
    cin >> q;
}
void slv()
{
    while(q--){
        cin >> n >> k;
        fr(i, 1, n)  cin >> a[i];
        fr(i, 1, n) b[i] = 0;
        ll ans = 0;
        if(k%2 == 0){
            ll value = k/2;
            ll res = 0;
            fr(i, 1, n){
                res+=a[i];
                if(res > value){
                    res-=a[i];
                    a[i] = a[i] - (value - res);
                    break;
                }
                b[i] = 1;
                ans++;
            }
            res = 0;
            frd(i, n, 1){
                res+=a[i];
                if(res > value || b[i]){
                    res-=a[i];
                    break;
                }
                ans++;
            }
        }
        else{
            ll value = k/2 + 1;
            ll res = 0;
            fr(i, 1, n){
                res+=a[i];
                if(res > value){
                    res-=a[i];
                    a[i] = a[i] - (value - res);
                    break;
                }
                b[i] = 1;
                ans++;
            }
            value = k/2;
            res = 0;
            frd(i, n, 1){
                res+=a[i];
                if(res > value || b[i]){
                    res-=a[i];
                    break;
                }
                ans++;
            }
        }
        cout << ans << el;
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool qs=0;
    ll ntest=1;
    if(qs) cin>>ntest;
    fr(i,1,ntest){
        input();
        slv();
    }
}


