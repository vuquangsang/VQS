/*
+---NOTE---------------------------------------+
Name: DQN
Website:
Link:
+----------------------------------------------+
..... (¯`v´¯)♥
.......•.¸.•´
....¸.•´
... (
 ☻/
/▌ my ... ♥♥
/ \♥♥♥♥♥♥♥♥♥
*/
#define TASK "ginger"
#define INPUT TASK".INP"
#define OUTPUT TASK".OUT"
bool mtt = 0 ;
int test = 1 ;

#include<bits/stdc++.h>
using namespace std;

#define             ll  long long
#define             db  double
#define             iv  vector<int>
#define            str  string
#define             pb  push_back
#define             pk  pop_back
#define             el  '\n'
#define            	ii  pair<int,int>
#define             mp  make_pair
#define             fi  first
#define             se  second
#define     fok(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define     fod(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define         all(a)  a.begin(),a.end()
#define     BIT(msk,i)  (msk>>(i)&1)
#define        Mask(i)  (1ll<<(i))
#define           btpc  __builtin_popcountll
#define            ctz  __builtin_ctzll

int fx[] = {0,-1,0,1} ;
int fy[] = {-1,0,1,0} ;

const ll inf = 1e18 , sm = 1e9+7;
const int maxn = 2e5+5 , oo = 2e9 ;
const int N = 3005 , MAX = 500 ;

struct bg{
	int u , v , w , id ;
}	e[maxn] ;

int n , m , k ;

void doc( void )
{
	cin >> n >> m >> k ;
	fok(i,1,m)
	{
		int u , v , c ;
		cin >> u >> v >> c ;
 		e[i] = { u , v , c , i } ;
	}
}

namespace sub1
{

	struct bg1 {
		int u , w , id ;
	}	;

	int f[maxn] , heo[maxn] ;
	// bool vis[maxn] ;
	vector<bg1> adj[maxn] ;

	bool cmp( bg a , bg b )	{ return a.w < b.w ; }

	int FIND( int u )
	{
		if( f[u] > 0 )
		{
			f[u] = FIND(f[u]) ;
			return f[u] ;
		}
		else return u ;
	}

	void join( int r1 , int r2 )
	{
		int t = f[r1] + f[r2] ;
		if( abs( f[r1] ) < abs( f[r2] ) )	swap( r1 , r2 ) ;
		f[r1] = t ;
		f[r2] = r1 ;
	}

	bg1 par[maxn] ;

	void dfs( int u , int p )
	{
		for( auto x : adj[u] )
		{
			int v = x.u , w = x.w , id = x.id ;
			if( v == p )	continue ;
			par[v] = { u , w , id } ;
			dfs( v , u ) ;
		}
	}

	// void bfs( int u )
	// {
	// 	queue<int> q ;
	// 	q.push(u) ;
	// 	vis[u] = 1 ;
	// 	while( q.size() )
	// 	{
	// 		int u = q.front() ;	q.pop() ;
	// 		for( auto x : adj[u] )
	// 		{
	// 			int v = x.u , w = x.w , id = x.id ;
	// 			if( vis[v] )	continue ;
	// 			par[v] = { u , w , id } ;
	// 			vis[v] = 1 ;
	// 			q.push(v) ;
	// 		}
	// 	}
	// }

	void solve( void )
	{
		sort( e + 1 , e + m + 1 , cmp ) ;
		fok(i,1,m)
		{
			int r1 = FIND( e[i].u ) , r2 = FIND( e[i].v ) ;
			if( r1 != r2 )
			{
				join( r1 , r2 ) ;
				adj[ e[i].u ].pb({ e[i].v , e[i].w , e[i].id }) ;
				adj[ e[i].v ].pb({ e[i].u , e[i].w , e[i].id }) ;
			}
			else
			{
				// dfs( 1 , 0 ) ;
				// fok(i,1,n)	if( !par[i].u )	dfs(i,0) ;

				dfs( e[i].u , 0 ) ;

				if( !par[e[i].v].u )	swap( e[i].u , e[i].v ) ;

				int res = 0 ;
                int r = e[i].v , cur = 0 ;

				while( r != e[i].u )
				{
					++cur ;
					heo[ cur ] = par[r].id ;
					res = max( res , par[r].w ) ;
					r = par[r].u ;
				}

				res = max( res , e[i].w ) ;

				cout << 1ll * res * res + k*(cur+1) << el ;
				cout << e[i].v << ' ' << cur+1 << el ;

				// cout << e[i].id << ' ' ;
				fok(j, 1, cur)	cout << heo[j] << ' ' ;
				cout << e[i].id ;
				return ;
			}
		}
		cout << "Poor girl" ;
	}

}

namespace sub2
{

	void solve( void )
	{

	}

}

signed main( void )
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(time(0));
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin) ;
        freopen(OUTPUT,"w",stdout);
    }
    if(mtt)	cin >> test;
    fok(i,1,test)
    {
        doc() ;
        sub1::solve() ;
    }
}
