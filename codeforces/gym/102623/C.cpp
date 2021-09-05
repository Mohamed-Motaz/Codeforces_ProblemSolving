#include<bits/stdc++.h>
using namespace std;

#define isprime(x) (!np[x]&&(x&1))
#define ll long long
#define MUHAMMED_HISHAM ios_base::sync_with_stdio(false);cin.tie(NULL);/*
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
*/
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
    if (v.size()==1)cout<<"Neither\n";
    else if (v.size()==2)cout<<"Prime\n";
    else cout<<"Composite\n";
}

/////////////////////////power////////////////constant, power
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


long long  fast_power(long long  x, long long  n, long  mood)
{
    if (n == 0)return 1;
    else  if (n % 2 == 0)return fast_power(x * x, n / 2, mood);
    else  return (x * fast_power((x * x) % mood, (n - 1) / 2, mood));
}

/*

ll solve(ll i,ll last,ll cap)
{

    if(i>n)
    {
        // cout<<cap<<endl;
        if(cap==0)
        {
            return 0;
        }
        else return 1e9+100;
    }
    ll &ret=dp[i][last][cap];
    if(ret!=-1)
    {
        return ret;
    }
    ret=1e9+100;
    if(last==0)return ret=min(solve(i+1,i,cap-1),solve(i+1,last,cap));
    return ret=min((cap>0)?solve(i+1,i,cap-1)+(a[i]+a[last])*(i-last):100000500,solve(i+1,last,cap));
}
*/


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
/*//*
set<int>s;
    int t,n,x;
    cin>>t;
    while (t--)
    {
        for (int i=0;i<n;i++)
        {
            cin>>x;
            s.insert(x);
        }
        if (n==1)
        {
            cout<<"T\n";return 0;
        }
        auto it =s.end();
        x=0;
        auto it2=s.begin();
        for (auto it2:s)
        {
            x++;
            if (x==s.size()-1)break;
        }
        while (1)
        {
           if(*it==0) {cout<<"HL\n";break;}
           else {*it--;}
           if(*it2==0){cout<<"T\n";break;}
           else {*it2--;}
        }

    }*/
/////////////////////////////////////////////////////////////////
/*
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
const int MAX_CHAR = 26;

// Utility function to find factorial of n.
int factorial(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact = fact * i;
    return fact;
}

// Returns count of distinct permutations
// of str.
int countDistinctPermutations(string str)
{
    int length = str.length();

    int freq[MAX_CHAR];
    memset(freq, 0, sizeof(freq));

    // finding frequency of all the lower case
    // alphabet and storing them in array of
    // integer
    for (int i = 0; i < length; i++)
        if (str[i] >= 'a')
            freq[str[i] - 'a']++;

    // finding factorial of number of appearances
    // and multiplying them since they are
    // repeating alphabets
    int fact = 1;
    for (int i = 0; i < MAX_CHAR; i++)
        fact = fact * factorial(freq[i]);

    // finding factorial of size of string and
    // dividing it by factorial found after
    // multiplying
    return factorial(length) / fact;
}

// Driver code
string s;
void insert(int x)
{
    string temp="";
    temp+=s[x];
    s.insert(x+1, temp);
}
int main()
{
    int n,m;
    cin>>n>>m;
    string s;
    map<string,int >mp;
    vector<int>v;
    int  ans=0;
    int res=0;
    while (m--)
    {
        cin>>s;
        if(mp[s]==0)
        {
            mp[s]=s.size();
          if(v.size()==0)v.push_back(s.size());
          else           v.push_back(s.size()+1);
        }
    }

    sort(v.begin(),v.end());
    for (int i=0;i<v.size();i++)
    {
        if(ans+v[i]>n) continue;
        else {ans+=v[i];res++;}
       // cout<<ans<<" "<<res<<endl;
    }
    cout<<res;
    return 0;
}