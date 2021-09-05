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


int main() {

#ifdef offline_debug
    read
#endif
    marwan
    ll n, m, k;
    ld x1[3], x2[3],y1[3],y2[3];
    for (int i = 0; i < 3; i++) {
        cin >> x1[i]>>y1[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> x2[i]>>y2[i];
    }
    ld x[3],y[3];
    x[0]=((x1[0]-x1[1])*(x1[0]-x1[1]))+((y1[0]-y1[1])*(y1[0]-y1[1]));
    x[1]=((x1[0]-x1[2])*(x1[0]-x1[2]))+((y1[0]-y1[2])*(y1[0]-y1[2]));
    x[2]=((x1[1]-x1[2])*(x1[1]-x1[2]))+((y1[1]-y1[2])*(y1[1]-y1[2]));

    y[0]=((x2[0]-x2[1])*(x2[0]-x2[1]))+((y2[0]-y2[1])*(y2[0]-y2[1]));
    y[1]=((x2[0]-x2[2])*(x2[0]-x2[2]))+((y2[0]-y2[2])*(y2[0]-y2[2]));
    y[2]=((x2[1]-x2[2])*(x2[1]-x2[2]))+((y2[1]-y2[2])*(y2[1]-y2[2]));
    sort(x,x+3);
    sort(y,y+3);
    if(x[0]/y[0]==x[1]/y[1]&&x[1]/y[1]==x[2]/y[2])cout<<"YES";
    else cout<<"NO";

    return 0;
}