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

const int inf = 2e9;
const ll N = 1e6;



vector<ll> adj[N];

ll dist[N];
ll vis[N];

//void dijkstra(int startNode) {
//
//    for (int i = 1; i <= n; i++) {
//        dist[i] = inf;
//        vis[i] = 0;
//    }
//    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
//    pq.push({0, startNode});
//    dist[startNode] = 0;
//
//    while (!pq.empty()) {
//        int node = pq.top().second;
//        pq.pop();
//        if (vis[node])continue;
//        vis[node] = 1;
//        for (auto child: adj[node]) {
//            if (dist[node] < dist[child]) {
//                dist[child] = dist[node] + 1;
//                pq.push({dist[child], child});
//            }
//        }
//    }
//
//}
//bool vis[200005];
//ll dist[200005];
//
//void bfs() {
//    queue<int> q;
//    q.push(1);
//    dist[1] = 0;
//    vis[1] = 1;
//    while (q.size()) {
//        int node = q.front();
//        q.pop();
//            if (!vis[e]) {
//                vis[e] = 1;
//        for (auto e:graph[node]) {
//                q.push(e);
//                dist[e] = dist[node] + 1;
//            }
//        }
//    }
//}

int main() {

#ifdef offline_debug
    read
#endif
    marwan

  ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n%2==0)
        {
            cout<<n/2<<" "<<n/2;
        }
        else
        {cout<<(n/2)+1<<" "<<n/2;}
        cout<<endl;
    }



    return 0;
}