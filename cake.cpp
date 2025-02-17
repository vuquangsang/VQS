#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb  push_back
#define ll  long long
#define el  "\n"
#define alla(a,n)  a+1,a+n+1
#define fi first
#define se second
#define all(v)  v.begin(),v.end()
#define fu(i,a,b)  for(ll i=a;i<=b;i++)
#define fud(i,a,b)  for(ll i=a;i>=b;i--)

const ll MOD=1e9+7 ;//1234567891;
const ll inf=1e18;
const ll base = 311;
const ll N=2e5+5;
const ll N1=1e3+5;
template <class T> bool mini(T &x, T y){return (x > y ? x = y, 1 : 0);}
template <class T> bool maxi(T &x, T y){return (x < y ? x = y, 1 : 0);}
template <class T> void add(T &x, ll y){x += y; if(x >= MOD) x -= MOD;}
template <class T> void sub(T &x, T y){x -= y; if(x < 0) x += MOD;}
/*v*/
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1},
    dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

struct bg
{
	ll x,cost;
} a[N],b[N];


ll n,m,k,x,s;

bool cmp(bg a,bg b)
{
	return a.cost<b.cost;
}

ll ma[N];

ll find(ll s)
{
	ll l=1,r=k;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(b[mid].cost<=s) l=mid+1;
		else r=mid-1;
	}
	return ma[l-1];
}

signed main(void)
{
    #define TASK  "cake"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0));
    if(fopen(TASK".inp","r"))
    {
        freopen(TASK".inp" ,"r",stdin) ; freopen(TASK".out" ,"w",stdout);
    }

    cin>>n>>m>>k>>x>>s;
    fu(i,1,m) cin>>a[i].x;
    fu(i,1,m) cin>>a[i].cost;
    fu(i,1,k) cin>>b[i].x;
    fu(i,1,k) cin>>b[i].cost;
    sort(alla(a,m),cmp);
    sort(alla(b,k),cmp);
    ma[1]=b[1].x;
    fu(i,2,k) ma[i]=max(ma[i-1],b[i].x);
    ll ans=n*x;
    ans=min(ans,(n-find(s))*x);
    fu(i,1,m)
    {
    	ll res=a[i].x;
    	ll ss=s-a[i].cost;
    	if(ss<0) break;
    	ans=min(ans,(n-find(ss))*res);
    }
    cout<<ans<<el;


    return 0;
}
