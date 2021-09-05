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
#define mcii map<char, int>
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
const ll N = 1e5 + 7;
const ll llinf = INT64_MAX;
const int intinf = INT32_MAX;

int main() {
    MohamedMotaz
    int t;
    cin >> t;
    while (t--){
        int n, m;
        bool flag = false;
        cin >> n >> m;
        int arr[n + 2][m + 2];
        memset(arr, 0, sizeof(arr));
        f(i, 1, n + 1) {
            f(j, 1, m + 1) {
                cin >> arr[i][j];
                if (arr[i][j] > 4) flag = true;
                if ((i == 1 && j == 1) || (i == n  && j == m )|| (i == n && j == 1) || (i == 1 && j == m)){
                    if (arr[i][j] > 2) flag = true;
                }
                if (i == 1 || j == 1 || i == n  || j == m ){
                    if (arr[i][j] > 3) flag = true;
                }
            }
        }
        if (flag) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        f(i, 1, n + 1){
            f(j, 1, m + 1){
                if ((i == 1 && j == 1) || (i == n  && j == m ) || (i == n && j == 1) || (i == 1 && j == m)) cout << 2 << " ";
                else if (i == 1 || j == 1 || i == n  || j == m ) cout << 3 << ' ';
                else cout << 4 << " ";
            }cout << endl;
        }

    }

}