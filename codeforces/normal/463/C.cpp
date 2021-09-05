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
const ll N = 2e3 + 7;
const ll LLinf = 1e18 + 5;
const int INTinf = 1e8 + 7;

ll t, n, m, a, b, k, c = 0, d, x , y;
ll x11, x22, y11, y22;

ll arr[N][N], s1[N][N], s2[N][N];

void firstDiagonal(){
    f(i, 1, n + 1){
        f(j, 1, n + 1){
            s1[i][j] += s1[i - 1][j - 1] + arr[i][j];
        }
    }
    fr(i, n, 1){
        fr(j, n, 1){
            s1[i - 1][j - 1] = s1[i][j];
        }
    }
}
void secondDiagonal(){
    f(i, 1, n + 1){
        fr(j, n, 1){
            s2[i][j] += s2[i - 1][j + 1] + arr[i][j];
        }
    }

    fr(i, n - 1 , 1){
        f(j, 2, n + 1){
            s2[i][j] = s2[i + 1][j - 1];
        }
    }
}


int main() {
    MohamedMotaz
    cin >> n;

    memset(arr, 0, sizeof(arr));
    memset(s1, 0, sizeof(s1));
    memset(s2, 0, sizeof(s2));

    f(i, 1, n + 1) f(j, 1, n + 1) cin >> arr[i][j];

    firstDiagonal();
    secondDiagonal();

//    f(i, 1, n + 1){
//        f(j,1, n + 1) cout << s1[i][j] << " "; cout << endl;
//    }
//    cout << endl;
//    f(i, 1, n + 1){
//        f(j,1, n + 1) cout << s2[i][j] << " "; cout << endl;
//    }

    vector<pair<ll, pll>> e, o;
    f(i, 1, n + 1){
        f(j, 1, n + 1){
            ((i + j) % 2) ?  o.push_back({s1[i][j] + s2[i][j] - arr[i][j], {i, j}}) : e.push_back({s1[i][j] + s2[i][j] - arr[i][j], {i, j}});
        }
    }

    sort(rall(o)), sort(rall(e));
    cout << o[0].first + e[0].first << endl;
    cout << o[0].second.first << " " << o[0].second.second << " " << e[0].second.first << ' ' << e[0].second.second;
}