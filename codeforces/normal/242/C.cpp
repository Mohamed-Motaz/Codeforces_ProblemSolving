#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <iomanip>
#include <complex>

#define ll long long
#define ld long double
#define debug(x) cerr << (#x) << " " << (x) <<" "<< endl
#define ull unsigned long long
#define endl "\n"
#define MohamedMotaz ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);
#define f(a, b, c) for(ll a = b; a < c; a++)
#define fr(a, b, c) for(int a = b; a >= c; a--)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define vll vector<ll>
#define vld vector<ld>
#define vii vector<int>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define pld pair<ld, ld>
#define vpii vector<pii>
#define vpll vector<pll>
#define vpld vector<pld>
#define vc vector<char>
#define vs vector<string>
#define vp vector<point>
#define vb vector<bool>
#define mll map<ll,ll>
#define mii map<int, int>
#define mllv map<ll, vll>
#define mcll map<char, ll>
#define mci map<char, int>
#define msll map<string, ll>
#define mss map<string, string>
#define mcs map<char, string>
#define sll set<ll>
#define pi acos(-1)
#define point complex<ld>
using namespace std;


int dirX[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
int dirY[] = { -1, 0, 1, 0, 1, -1, -1, 1 };


const ll MOD = 998244353;
const ll mod = 1e9 + 7;
const ll N = 1e7 + 7;
const ll llinf = INT64_MAX;
const int intinf = INT32_MAX;

int ix, iy, tx, ty, n;
ll a, b, r;
int main() {
    MohamedMotaz
    cin >> ix >> iy >> tx >> ty;
    cin >> n;
    set<pll> st;
    map<pll, int> visited, dist;
    f(i, 0, n){
        cin >> r >> a >> b;
        f(j, a, b + 1) st.insert({r, j});
    }

    pll initial = {ix, iy};
    queue<pll> q;
    q.push(initial);
    visited[initial] = 1;
    dist[initial] = 0;

    while (q.size()){
        pll cur = q.front();
        q.pop();
        f(i, 0, 8){
            pll newDir = {cur.first + dirX[i], cur.second + dirY[i]};
            if (st.count(newDir) && !visited[newDir]){ //present in grid and not visited
                q.push(newDir);
                visited[newDir] = 1;
                dist[newDir] = dist[cur] + 1;
            }
            if (newDir.first == tx && newDir.second == ty) break;
        }

    }
    pll target = {tx, ty};

    if (visited[target]) cout << dist[target];
    else cout << -1;

}