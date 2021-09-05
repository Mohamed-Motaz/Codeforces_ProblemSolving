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
int main()
{
    Jo
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long arr[n+1]= {};
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        long long ans=0, diff=100-arr[n-1];
        for(int i=0; i<n; i++)
        {
            if(arr[i]+diff>=50)
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    cout<<endl;

    return 0;
}