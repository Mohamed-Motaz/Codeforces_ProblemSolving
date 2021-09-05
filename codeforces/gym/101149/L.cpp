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
const ll N = 2e6+7;
ll n;


vector<pair<ll, ll>> graph[N];


vll dist0(N);
vll dista(N);
vll distb(N);

void dijkstra(int startNode,vll &dist)
{

    for (int i = 0; i <= N; i++)
        dist[i] = inf;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.push({0, startNode});
    dist[startNode] = 0;
    while (!pq.empty())
    {
        int node = pq.top().second;
        int curCost = pq.top().first;
        pq.pop();
        if (curCost > dist[node])
            continue;
        for (auto it: graph[node])
        {
            int child = it.first;
            int newCost = curCost + it.second;
            if (newCost < dist[child])
            {
                pq.push({newCost, child});
                dist[child] = newCost;
            }
        }
    }
    return ;
}

int main() {

#ifdef offline_debug
    read
#endif
    marwan

    ll m, k,a,b;
    cin >> n >> m >> a>>b;


    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b ;
        graph[a].pb({b, 1});
        graph[b].pb({a, 1});

    }

    dijkstra(0,dist0);
    dijkstra(a,dista);
    dijkstra(b,distb);




    ll ans2=1e18;
    for(int i=0;i<=n;i++)
    {
        ans2=min(ans2,distb[i]+dista[i]+dist0[i]);
    }
    cout<<ans2;



//
//    for (auto e:edge) {
//        ll a = e.first, b = e.second;
//        ll temp = 0;
//        ll tmp = dist[a][b];
//        dist[a][b] = 0;
//        for (int i = 0; i < k; i++) {
//            ll from = arr[i].first, to = arr[i].second;
//            //el distance ya ema heya heya 3ady mt8ryt4
//            //aw distnace from el 'from' l7d el a plus el from 'b' to 'to'
//            //zy msln lw 1...2...5...6 wna 4eltel edgde 2...5 fa h7sb mn  1...2 plus 5...6
//
//            temp += min({dist[from][to], dist[from][a] + dist[b][to], dist[to][a] + dist[b][from]});
//        }
//        dist[a][b] = tmp;
//        ans = min(ans, temp);
//    }
//    cout << ans << endl;
    return 0;
}