#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
clock_t T;
#define ctime cerr <<endl<< "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define debug(x) cout << (#x) << " " << (x) <<" "<< endl
#define debug2(x, y) cerr << (#x) << " " << (x) <<" "<< (#y) << " " << (y) <<" "<< endl
#define debug3(x, y, z) cout << (#x) << " " << (x) <<" "<< (#y) << " " << (y) <<" "<< (#z) << " " << (z) << endl
#define marwan ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);ios_base::sync_with_stdio(0);
#define read freopen("input.txt", "r", stdin);
#define write  freopen("output.txt", "w", stdout);
#define f(a, b, c) for(ll a = b; a < c; a++)
#define fr(a, b, c) for(int a = b; a >= c; a--)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define cinvec(v, n) f(i, 0, n){ll a;cin>>a;v.pb(a);};
#define printvec(v, n) for (auto e: v) cout << e << " "; cout << endl;
#define pb push_back
#define pf push_front
#define RESET(a, b) memset(a, b, sizeof(a))
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double pi = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};
using namespace std;

ll mod = 1000000000 + 7;


ll solve()
{

}

int main() {

#ifdef offline_debug
    read
#endif
    marwan

    ll n,q;
    cin>>n>>q;
    set<pll>st;
    set<pll>::iterator it;
    vll v(n);
    for(int i=1;i<=n;i++)
    {
        ll a;
        cin>>a;
        st.insert(make_pair(a,i));
        v[i]=a;

    }
    while(q--)
    {
        string s;
        ll a;
        cin>>s>>a;
        if(s=="in")
        {
            it=st.lower_bound(make_pair(a,0));
            if(it!=st.end())
            {
                cout<<it->second<<endl;
                st.erase(it);
            }else cout<<-1<<endl;

        }
        else 
        {
            //debug2(v[a],a);
            st.insert(make_pair(v[a],a));
        }
    }


    return 0;
}