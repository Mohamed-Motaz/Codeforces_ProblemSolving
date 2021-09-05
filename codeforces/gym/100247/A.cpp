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
}*/
/////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
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

int n,m,q;
char arr[5005][5005];
pair<int,int> cord[2];
/////////////////////is vallid or not////////////////////////////
bool vallid(int xx,int yy)
{
    if(xx>=0 && xx<n && yy>=0 && yy<m &&arr[xx][yy] != '#')return 1;
    return 0;
}
///////////////////////horizontally check ///////////////////////
bool hori(int x1,int y1,int x2,int y2)
{
    for (int i=y1;i<m;i++)
    {
        if(i==y2)return 1;
        if(arr[x1][i]=='#' )return 0;
    }
    return 1;
}
///////////////////////horizontally check ///////////////////////
bool vertical(int x1,int y1,int x2,int y2)
{
    for (int i=x1;i<n;i++)
    {
        if(i==x2)           return 1;
        if(arr[i][y1]=='#' )return 0;
    }
    return 1;
}
//////////////////////////////////////////////////////////////////
int main()
{
    cin>>n>>m;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cin>>arr[i][j];
        }
    }

    cin>>q;
    for(int i=0; i<q; i++)
    {
        cin>>cord[0].first>>cord[0].second;
        cin>>cord[1].first>>cord[1].second;
        sort(cord,cord+2);
        int x1=cord[0].first-1,y1=cord[0].second-1,
            x2=cord[1].first-1,y2=cord[1].second-1;
        if(x1==x2&&y1==y2)cout<<"YES\n";
        else if(x1==x2)//horizontally  * .... *
        {
            if(hori(x1,y1,x2,y2))             cout<<"YES\n";
            else                              cout<<"NO\n";
        }
        else if(y1==y2)//vertical
        {
            if(vertical(x1,y1,x2,y2))         cout<<"YES\n";
            else                              cout<<"NO\n";
        }
        else
        {

            if((vertical(   min(x1,x2),y1,max(x1,x2),y1)&&hori(x2,min(y1,y2),x2,max(y1,y2))
             ||(vertical(   min(x1,x2),y2,max(x1,x2),y2)&&hori(x2,min(y1,y2),x2,max(y1,y2)))))
                                              cout<<"YES\n";
            else                              cout<<"NO\n";
        }
       // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2 <<endl;
    }
    return 0;
}

*/
const int maxn=1e7+5;
struct node
{
    int a[3];
    int id;
    bool operator <(const node &t)
    {
        return a[2]<t.a[2];
    }
} no[maxn];

int bb[maxn],cnt,n;

int main()
{
    cin>>n;
    int m2=0,m3=0;
    for(int i=0; i<n; i++)
    {
        no[i].id=i;
        cin>>no[i].a[0]>>
             no[i].a[1]>>
             no[i].a[2];

        sort(no[i].a,no[i].a+3);
        if(m2<no[i].a[1])m2=no[i].a[1];
        if(m3<no[i].a[0])m3=no[i].a[0];
    }
    sort(no,no+n);
    for(int i=0; i<n; i++)
    {
        if(no[i].a[2]>=m2&&no[i].a[1]>=m3)
        {
            bb[cnt]=no[i].id;
            cnt++;
        }


    }
    cout<<cnt<<endl;
    sort(bb,bb+cnt);
    
    for(int i=0; i<cnt; i++)
        cout<<bb[i]+1<<" ";
    return 0;
}