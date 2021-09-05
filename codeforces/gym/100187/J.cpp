#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
clock_t T;
#define ctime cerr <<endl<< "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define debug(x) cout << (#x) << " " << (x) <<" "<< endl
#define debug2(x, y) cerr << (#x) << " " << (x) <<" "<< (#y) << " " << (y) <<" "<< endl
#define debug3(x, y, z) cout << (#x) << " " << (x) <<" "<< (#y) << " " << (y) <<" "<< (#z) << " " << (z) << endl
#define marwan ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);ios_base::sync_with_stdio(0);
#define read freopen("input.txt", "r", stdin);
#define write  freopen("output.txt", "w", stdout);
#define f(a, b, c) for(ll a = b; a < c; a++)
#define fr(a, b, c) for(int a = b; a >= c; a--)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define cinvec(v, n) f(i, 0, n){ll a;cin>>a;v.pb(a);};
#define printvec(v, n) for (auto e: v) cout << e << " "; cout << endl;
#define pb push_back
#define pf push_front
#define RESET(a, b) memset(a, b, sizeof(a))
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double pi = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};
using namespace std;

ll mod=1e9+9;
ll modPower(ll b, ll p) {
    if (p == 0)
        return 1;

    ll halfpow = modPower(b, p / 2);
    ll toReturn = (halfpow * halfpow) % mod;
    if (p % 2)
        toReturn = (toReturn * b) % mod;

    return toReturn;
}
long long fact[1000001];
long long inv[1000001];
void pre(long long n)
{
    fact[0] = 1;
    inv[0] = 1;
    for (long long i = 1; i <= n; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
        inv[i] = modPower(fact[i], mod - 2);
    }
}

ll npr(ll n, ll r) {
    return ((fact[n] * inv[n - r]) % mod);
}

ll ncr(ll n, ll r) {
    return ((((fact[n] * inv[n - r]) % mod) * inv[r]) % mod);
}

ll vis[1000005];
vll adj[1000005];
void dfs(ll node)
{
    vis[node]=1;
    for(auto child :adj[node])
    {
        if(!vis[child])
        {
            dfs(child);
        }
    }
}


int main() {

#ifdef offline_debug
    read
#endif
    marwan
    ll n;
    cin>>n;
    vll v;
    cinvec(v,n);
    ll t;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ll a;
            cin>>a;
            if(a==j)continue;
            adj[a].pb(j);
        }
    }

    ll x,idx=0;
    cin>>x;
    for(int i=0;i<n;i++)
    {
        if(v[i]==x)
        {
            idx=i+1;break;
        }
    }

    dfs(idx);
    if(vis[1])cout<<"YES";
    else cout<<"NO";




    return 0;
}