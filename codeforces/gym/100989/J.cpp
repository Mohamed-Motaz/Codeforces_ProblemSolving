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
vector<vll > v(1e6);
char expanded[1000000];
ll vis[1000000];

ll dfs(ll node, ll cnt) {
    if (vis[node])return 0;
    vis[node] = 1;
    for (int i = 0; i < cnt; i++) {
        cout << "  ";
    }
    if (v[node].size() == 0) {
        cout << "  object" << node << endl;
        return 0;
    } else {
        cout << expanded[node] << " object" << node << endl;
        if (expanded[node] == '-') {
            for (auto child : v[node]) {
                dfs(child, cnt + 1);
            }
        }
    }


}

int main() {

#ifdef offline_debug
    read
#endif
    marwan

    ll n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        char c;
        ll x;
        cin >> c >> x;
        expanded[i] = c;
        for (int j = 1; j <= x; j++) {
            ll y;
            cin >> y;
            v[i].push_back(y);
        }
    }
    if (n == 0) {
        cout << "  project";
        return 0;
    } else {
        if (expanded[0] == '+') {
            cout << expanded[0] << " project\n";
        } else {
            cout<<expanded[0]<<" project"<<endl;
            for (auto x: v[0]) {
                dfs(x, 1);
            }
        }
    }


    return 0;
}