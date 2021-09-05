#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef unsigned long long ull;

#define pr1(x)        cout<<x<<"\n"
#define pr2(x,y)      cout<<x<<" "<<y<<"\n"
#define isprime(x) (!np[x]&&(x&1))
#define MUHAMMED_HISHAM ios_base::sync_with_stdio(false);cin.tie(NULL);
/*
 /*
ll NCR[31][31];

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
/*grid graph
int t,n,m;
map < char,int > mp;
pair<pair< int,int >,char>p;
vector<string>v;
vector<pair<int,char>>ans;
deque <pair<pair<int,int >, char>>d;
int vis[100][100],a,b,cnt,test=1 ;
int di[]= {1,0,-1,0};
int dj[]= {0,1,0,-1};
int f;
void bfs (int x,int y,char c)
{
    f++;
    mp[c]--;
    d.clear();
    d.push_back({{x,y},c});
    while (d.size()!=0)
    {
        p=d.front();
        d.pop_front();
        vis[p.first.first][p.first.second]=1;
        for (int i=0; i<4; i++)
        {
            int arr
            a=p.first.first +di[i];
            b=p.first.second+dj[i];
            if(a>=0 && a<n && b>=0 && b<m && !vis[a][b]&&v[a][b]==p.second)
                d.push_front({{a,b},p.second});
        }
    }
}*/
/*
const int mxxx = 100005;
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
*//////////////////////////////////////////////////////////////////////////////
long long  fast_power(long long  x, long long  n, long  mood)
{
    if (n == 0)return 1;
    else  if (n % 2 == 0)return fast_power(x * x, n / 2, mood);
    else  return (x * fast_power((x * x) % mood, (n - 1) / 2, mood));
}
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
long long  power(long long   x, long long  y)
{
    long long   temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
    {
        if (y > 0)
            return x * temp * temp;
        else
            return (temp * temp) / x;
    }
}
//////////////////////////////////////////////////////////

ll GcdRecursive(ll a, ll b)
{
    if (b == 0) return a;
    return GcdRecursive(b, a % b);
}
int main()
{

    int n;
    vector<pair<int,int >>v,copy,arr;
    cin >> n;
    int a,c;
    int found=0;
    for (int i=0; i<n; i++)
    {
        cin>>a>>c;
        arr.push_back({a,c});
        if(i>0&&arr[i].second==arr[i-1].second&&arr[i].first<arr[i-1].first)
            found=1;
    }

    if(found==0)cout<<"YES";
    else cout<<"NO";
}