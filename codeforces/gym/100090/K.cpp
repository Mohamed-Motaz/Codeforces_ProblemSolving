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
    string s;
    cin>>s;
    stack<int>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push(1);
        }
        else{
            if(st.empty()){
                return cout<<"IMPOSSIBLE\n", 0;
            }
            else{
                st.pop();
            }
        }
    }
    cout<<s;
    for(int i=0;i<st.size();i++){
        cout<<')';
    }
    return 0;
}