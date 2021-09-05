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



ll t, n, m, a, b, k, c = 0, freee = 0;
ll x11, x22, y11, y22;
string s;
char arr[501][501];
ll visited[501][501];

bool check(ll a, ll b){
    return a < n && a >= 0 && b < m && b >= 0;
}
void bfs(ll a, ll b){
    memset(visited, 0, sizeof(visited));
    queue<pll> q;
    q.push({a, b});
    visited[a][b] = 1;
    c = 1;
    while (q.size()){
        ll f = q.front().first;
        ll s = q.front().second;
        q.pop();
        f(i, 0, 4){
            a = f + dirX[i], b = s + dirY[i];
            if (check(a, b) && !visited[a][b] && arr[a][b] == '.' && c < freee){
                visited[a][b] = 1;
                q.push({a, b});
                c++;
            }
            if (c >= freee ) return;
        }

    }
    return;
}


int main() {
    MohamedMotaz
    cin >> n >> m >> k;
    f(i, 0, n) f(j, 0, m) { cin >> arr[i][j]; if (arr[i][j] == '.') freee++, a = i, b = j;}
    freee -= k;
    bfs(a, b);
    f(i, 0, n){
        f(j, 0 ,m){
            if (visited[i][j]) cout << '.';
            else if (arr[i][j] == '.') cout << 'X';
            else cout << arr[i][j];
        }cout << endl;
    }


}