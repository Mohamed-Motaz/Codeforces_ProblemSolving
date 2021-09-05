#include <bits/stdc++.h>
#define Jo ios::sync_with_stdio(0); cin.tie(NULL); ios_base::sync_with_stdio(0); cout.tie(NULL); //freopen("phantom.in","r",stdin);freopen("output.txt","w",stdout);
#define INF 1e18+5
#define endl '\n'
#define point complex<double>
const long long N =1e5+5;
const long long mod=1e9+7;
const double Phi=(sqrt(5)+1)/2;
const double PI=acos(-1.0);
using namespace std;
/*int dx[] = {0,-1,0,1,1,1,-1,-1};
int dy[] = {1,0,-1,0,1,-1,1,-1};*/
//bool valid(long long i, long long j){return i>=0&&j>=0&&i<n&&j<m;}
set<long long> GetDivisors(long long val)
{
    set<long long> st;
    for(int i=1; i<=sqrt(val); i++)
    {
        if (val % i == 0) st.insert(i), st.insert(val / i);
    }
    return st;
}
int main()
{
    Jo
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        long long arr[n+1]= {};
        map<long long,vector<int>>mp;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        for(int i=0; i<n; i++)
        {
            mp[arr[i]].push_back(i);
        }

        set<long long>s=GetDivisors(m);
        bool found=0;
        long long x=0,y=0;
        for(int i=0; i<n; i++)
        {
            long long rem=0;
            if(arr[i]) rem=m/arr[i];
            if(rem*arr[i]!=m) continue;
            for(auto it:mp[rem])
            {
                if(it!=i)
                {
                    x=arr[i], y=rem;
                    found=1;
                    break;
                }
            }
            if(found) break;
        }
        if(found) cout<<x<<' '<<y<<endl;
        else cout<<-1<<endl;
    }
    /*
    4
    6 12
    3 6 2 4 2 9
    2 1
    1 2
    4 36
    12 18 3 36
    4 12
    1 2 6 12
    */
    cout<<endl;

    return 0;
}