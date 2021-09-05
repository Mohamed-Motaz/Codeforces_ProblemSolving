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
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int dp[105][105]={};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>dp[i][j];
                dp[i][j]+=dp[i-1][j];
                dp[i][j]+=dp[i][j-1];
                dp[i][j]-=dp[i-1][j-1];
            }
        }

        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int x=i;x<=n;x++){
                    for(int y=j;y<=m;y++){
                        int cnt=dp[x][y];
                        cnt-=dp[x][j-1];
                        cnt-=dp[i-1][y];
                        cnt+=dp[i-1][j-1];
                        if(cnt<=k){
                            ans=max(ans,(x-i+1)*(y-j+1));
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}