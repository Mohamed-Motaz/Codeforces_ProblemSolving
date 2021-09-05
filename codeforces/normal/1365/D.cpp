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

ll GcdRecursive(ll a, ll b) {
	if (b == 0) return a;
	return GcdRecursive(b, a % b);
}

const ll mod = 1e9 + 7;
int dirX[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
int dirY[] = { -1, 0, 1, 0, 1, -1, -1, 1 };


const ll MOD = 998244353;
//const ll mod = 1e9 + 7;
const ll N = 2e5 + 7;
const ll LLinf = 1e18 + 5;
const int INTinf = 1e8 + 7;


ll t, n, m,  k, c = 0, d, x , y;
ll x11, x22, y11, y22;
int good = 0;
string s;
char arr[55][55];
bool visited[55][55];

bool valid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solve(int x, int y){
    if (valid(x, y) && arr[x][y] == '.' ) arr[x][y] = '#';
}

void dfs(int x, int y){
    if (!valid(x, y) ||visited[x][y] ||  arr[x][y] == '#') return;
    visited[x][y] = 1;
    //if (arr[x][y] == 'G') good--;
    f(i, 0, 4) dfs(x + dirX[i], y + dirY[i]);
}
//1
//2 2
//BG
//#.
int main() {
    MohamedMotaz
    cin >> t;
    while (t--){
        cin >> n >> m;
        good = 0;
        memset(visited, 0, sizeof(visited));
        f(i, 0, n ) f(j, 0, m ) {cin >> arr[i][j]; if (arr[i][j] == 'G') good++;}

        f(i, 0, n ) f(j, 0, m ) if (arr[i][j] == 'B') f(x, 0, 4) solve(i + dirX[x], j + dirY[x]);
        if (arr[n - 1][m - 1] == '.') dfs(n - 1, m - 1);
//        f(i, 0, n) f(j, 0, m) cout << arr[i][j] << ' '; cout << endl;
//        (!good)? cout << "yes": cout << "no"; cout << endl;
        bool done = false;
        f(i, 0, n){
            f(j, 0, m){
                if (arr[i][j] == 'G' && !visited[i][j]) done = true;
                if (arr[i][j] == 'B' && visited[i][j]) done = true;
            }
        }
        if (done) cout << "No";
        else cout << "Yes";
        cout << endl;
    }
}