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
        int n,m;
        cin>>n>>m;
        set<int>s1,s2;
        map<int,int>mp1,mp2;
        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            mp1[x]++;
        }
        for(int i=0; i<m; i++)
        {
            int x;
            cin>>x;
            mp2[x]++;
        }
        bool valid;
        int i=1;
        for(auto it:mp1)
        {
            valid=0;
            for(; i<=50; i++)
            {
                if(mp2[i]>=it.second)
                {
                    valid=1;
                    i++;
                    break;
                }
            }
            if(!valid)
            {
                cout<<"NO\n";
                break;
            }
        }
        if(valid) cout<<"YES\n";
    }
    cout<<endl;
    /*
    3
    3 6
    5 15 10
    2 2 2 3 3 4
    4 4
    5 5 6 7
    5 4 6 6
    5 6
    8 6 7 5 5
    1 2 1 3 1 2
    */

    return 0;
}