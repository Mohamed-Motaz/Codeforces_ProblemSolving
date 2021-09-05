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
    double x1,y1,r1,x2,y2,r2;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    if(x1>x2) swap(x1,x2), swap(y1,y2), swap(r1,r2);
    double dist=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    double rad=(r1+r2-dist)/2;
    double x=(dist-r2+rad)/dist*(x2-x1);
    double y=(dist-r2+rad)/dist*(y2-y1);
    cout<<fixed<<setprecision(12)<<x+x1<<' '<<y+y1<<' '<<rad<<endl;
    return 0;
}