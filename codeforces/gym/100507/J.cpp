#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

typedef unsigned long long ull;

#define pr1(x)        cout<<x<<"\n"
#define pr2(x,y)      cout<<x<<" "<<y<<"\n"
#define isprime(x) (!np[x]&&(x&1))
#define MUHAMMED_HISHAM ios_base::sync_with_stdio(false);cin.tie(NULL);
/*
/*
ll NCR[4005][40005];

ll compinatorics(int n,int r)
{
    NCR[0][0]=1;
    for (int i = 1; i <= 30; ++i)
    {
        NCR[i][0] = 1;
        NCR[i][i] = 1;
        for (int j = 1; j <= i; ++j)
        {
            NCR[i][j] = NCR[i - 1][j - 1] + NCR[i - 1][j];
        }
    }
    return NCR[n][r];
}
/////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void primeFactors(int n)
{
    vector<int>v;
    while (n % 2 == 0)
    {
        v.push_back(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            v.push_back(i);
            n = n / i;
        }
    }
    if (n > 2)
    {
        v.push_back(n);
    }
    v.push_back(1);
}

/////////////////////////power/////////////////////////////constant, power
int xx,yy;
const int mxxx = 1e7+1;
bool np[mxxx];
int si, primes[mxxx];

void sieve()
{
    si = 0;
    np[0] = np[1] = 1;
    for (long long i = 3; i * i <= mxxx; i += 2)
    {
        if (np[i] == 0)
        {
            for (long long j = i * i; j < mxxx; j += (i * 2))
                np[j] = 1;
        }
    }
    primes[si++] = 2;
    for (int i = 0; i < mxxx; i++)
    {
        if (np[i] == 0 && i % 2)
            primes[si++] = i;
    }
}


int di[]= {1,0,-1,0};
int dj[]= {0,1,0,-1};
/*
int vis[2005][2005]= {},arr[2005][2005],x,y,a,b,t,n,m;
deque<pair<pair<int,int>,string>>d;
pair<pair<int,int>,string >p;
string ans="";
void bfs(int x,int y)
{
    ans="";
    d.clear();
    for(int i=0; i<n; i++)for(int j=0; j<m; j++)vis[i][j]=0;
    d.push_back({{x,y},""});
    while (d.size())
    {
        p=d.front();
        if(arr[p.first.first][p.first.second]==2)
        {
            ans=d.front().second;
            cout<<ans;
            break;
        }
        d.pop_front();
        vis[p.first.first][p.first.second]=1;
        for(int i=0; i<4; i++)
        {
            a=p.first.first +di[i];
            b=p.first.second+dj[i];
            //if(vallid(a,b))
            {
                if (i==1)          d.push_front({{a,b},p.second+'R'});
                else if      (i==0)d.push_front({{a,b},p.second+'D'});
                else if (i==2)     d.push_front({{a,b},p.second+'U'});
                else               d.push_front({{a,b},p.second+'L'});
                if(arr[a][b]==2)break;
            }
        }
        if(arr[a][b]==2)
        {
            ans=d.front().second;
            cout<<ans;
            break;
        }
    }
}
*/
/*
const ll mod=998244353;
/*
const int N=1e7+1;
ll modPower(ll b, ll p)
{
    if (p == 0)
        return 1;

    ll halfpow = modPower(b, p / 2);
    ll toReturn = (halfpow * halfpow) % mod;
    if (p % 2)
        toReturn = (toReturn * b) % mod;

    return toReturn;
}
ll fact[N],inv[N],arr[N];
void pre(ll n)
{

    fact[0] = 1;
    inv[0] = 1;

    for (ll i = 1; i <= n; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
        inv[i] = modPower(fact[i], mod - 2);
        arr[i] = modPower(i, mod - 2);
    }
}
*/
/*
ll  fast_power(ll  x, ll  n, ll  mood)
{
    if (n == 0)return 1;
    else  if (n % 2 == 0)return fast_power(x * x, n / 2, mood);
    else  return (x * fast_power((x * x) % mood, (n - 1) / 2, mood));
}
const ll N = 3e5+5;
ll  power(ll   x, ll y)
{
    ll temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
    {
        if (y > 0)return x * temp * temp;
        else      return (temp * temp) / x;
    }
}
//////////////////////////////////////////////////////////

ll GcdRecursive(ll a, ll b)
{
    if (b == 0) return a;
    return GcdRecursive(b, a % b);
}
*/
const int N = 1005;

int n;
int a[N], b[N], p1[7], p2[7];
vector<int> v1[7], v2[7],ans1, ans2;


int main()
{
    cin>>n;
    int suma=0,sumb=0;
    for (int i = 1; i <= n; ++i)
    {
        cin>>a[i];suma+=a[i];
        v1[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        cin>>b[i]; sumb+=b[i];
        v2[b[i]].push_back(i);
    }
    for (int i = 0; i <= 6; ++i)
    {
        p1[i] = 0;p2[i] = 0;
        int len1 = v1[i].size(), len2 = v2[i].size();
        while (p1[i] < len1 && p2[i] < len2)
        {ans1.push_back(v1[i][p1[i]]), ans2.push_back(v2[i][p2[i]]);++p1[i], ++p2[i];}
    }
    if(suma > sumb)
    {for (int i = 0; i <= 6; ++i){
     for (int j = p1[i]; j < v1[i].size(); ++j)
     {ans1.push_back(v1[i][j]);}}
     for (int i = 6; i >= 0; --i){
     for (int j = p2[i]; j < v2[i].size(); ++j){
      ans2.push_back(v2[i][j]);}}
    }
     else
    { for (int i = 6; i >= 0; --i)
     {for (int j = p1[i]; j < v1[i].size(); ++j)
      {ans1.push_back(v1[i][j]);}}
      for (int i = 0; i <= 6; ++i)
     {for (int j = p2[i]; j < v2[i].size(); ++j)
      {ans2.push_back(v2[i][j]);}}
    }

    for (int i = 0; i < n; ++i)
    cout<<ans1[i]<<" "<<ans2[i]<<"\n";

    return 0;
}