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
#define ull unsigned long long
#define endl "\n"
#define MohamedMotaz ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);
#define f(a, b, c) for(int a = b; a < c; a++)
#define fr(a, b, c) for(int a = b; a >= c; a--)
#define all(a) a.begin(), a.end()
#define vll vector<ll>
#define vld vector<ld>
#define vi vector<int>
#define vs vector<string>
#define pll pair<ll,ll>
#define pld pair<ld, ld>
#define vpll vector<pll>
#define vpld vector<pld>
#define vc vector<char>
#define vs vector<string>
#define vp vector<point>
#define vb vector<bool>
#define mll map<ll,ll>
#define mllv map<ll, vll>
#define mcll map<char, ll>
#define msll map<string, ll>
#define mss map<string, string>
#define mcs map<char, string>
#define sll set<ll>
#define pi acos(-1)
#define point complex<ld>
using namespace std;

const ll mod = 1e9 + 7;
int dirX[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
int dirY[] = { -1, 0, 1, 0, 1, -1, -1, 1 };


const ll MOD = 998244353;
//const ll mod = 1e9 + 7;
const ll N = 1e5 + 7;
const ll inf = 1e18 + 5;



ll t, n, m, a, b, k, c = 0, d;
ll x11, x22, y11, y22;

vll adjList[N], v;
bool vis[N] = {};
ll init[N], goal[N];

        // 0 is original state, 1 is flipped
void bfs(){
            //node lvl odd even
    queue<pair<pll, pll>> q;
    q.push({{1, 0}, {0, 0}});
    vis[1] = 1;

    while (q.size()){

        ll node = q.front().first.first;
        ll lvl = q.front().first.second;
        bool odd = q.front().second.first;
        bool even = q.front().second.second;
        q.pop();
        vis[node] = 1;
        if (even && !(lvl % 2)) init[node] ^= 1;
        if (odd && lvl % 2) init[node] ^= 1;

        if (init[node] != goal[node]){
            v.push_back(node);
            if (lvl % 2) odd ^= 1;
            else even ^= 1;
        }
        for (auto child: adjList[node]) if (!vis[child]) q.push({{child, lvl + 1}, {odd, even}});
    }

}

int main() {
    MohamedMotaz
    cin >> n;

    f(i, 0, n - 1){
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    f(i, 1, n + 1) cin >> init[i];
    f(i, 1, n + 1) cin >> goal[i];

    bfs();

    cout << v.size() << endl;
    for (auto e: v) cout << e << endl;

}