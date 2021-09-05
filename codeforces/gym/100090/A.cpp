#include <iostream>
#include <stdio.h>
#include <functional>
#include <string>
#include <cstring>
#include <cstdio>
#include <numeric>
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
#include <unordered_set>
#include <assert.h>
#include <sstream>


#define ll long long
#define ld long double

#define debug1(x) cout << (#x) << " " << (x) <<" "<< endl
#define debug2(x,y) cout << (#x) << " " << (x) <<" "<< (#y) << " " << (y) <<" "<< endl
#define debug3(x,y,z) cout << (#x) << " " << (x) <<" "<< (#y) << " " << (y) <<" "<< (#z) << " " << (z) << endl
#define debug4(x,y,z, a) cout << (#x) << " " << (x) <<" "<< (#y) << " " << (y) <<" "<< (#z) << " " << (z) << " "<< (#a) << " " << (a) << endl

#define trace1(x) cerr<<#x<<": "<<x<<" "<<endl
#define trace2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl

#define ull unsigned long long
#define endl "\n"
#define MohamedMotaz ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);
#define readwrite freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define clr(x, y) memset(x, y, sizeof(x));
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
#define sz(x) (ll)x.size()
#define cinvec(v) f(i, 0, v.size()) cin >> v[i]
#define coutvec(v) for (auto e: v) cout << e << " "; cout << endl;
#define printvec(v) for (auto e: v) cout << e << " "; cout << endl;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pi acos(-1)
#define point complex<ld>

using namespace std;
const int mod = 1e9 + 7;
const int N = 2e6 + 7;
vector<pair<int, int>> wallsX;
vector<pair<int, int>> wallsY;
char arr[2507][2507];
int n, m;
int x11, y11, x22, y22;

bool func(int x, int y){
    bool f1 = false, f2 = false;
    if (arr[x][y] != '#'){
        //search if any y is in the way of my x
        int mn = min(x11, x22);
        int mx = max(x11, x22);
        auto it = lower_bound(all(wallsY), make_pair(y, mn + 1));
        if (it == wallsY.end()){
            //no wall found, may continue
            f1 = true;
        }
        else{
            if (it->first != y ||  it->second > mx){
                //ok its fine can continue
                f1 = true;
            }else{
                //need to break out cause cant with this one
                f1 = false;
            }
        }
        mn = min(y11, y22);
        mx = max(y11, y22);
        it = lower_bound(all(wallsX), make_pair(x, mn + 1));
        if (it == wallsX.end()){
            f2 = true;
        }else{
            if (it->first != x || it->second > mx){
                f2 = true;
            }else{
                //need to break out
                f2 = false;
            }
        }

    }
    return f1 && f2;
}


int main(){
    MohamedMotaz;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            char c;
            cin >> c;
            arr[i][j] = c;
            if (c == '#')
                wallsX.push_back({i, j}), wallsY.push_back({j, i});
        }

    sort(all(wallsX));
    sort(all(wallsY));
//    for (auto e: wallsX)
//        cout << e.first << " " << e.second << endl;
//    cout << endl;
//
//    for (auto e: wallsY)
//        cout << e.first << " " << e.second << endl;
//    cout << endl;
    int q;
    cin >> q;
    while (q--){
        cin >> x11 >> y11 >> x22 >> y22;
        x11--;
        y11--;
        x22--;
        y22--;
        //first point of intersection
        int x = x11;
        int y = y22;

        if (func(x, y) || func(x22, y11)){
            cout << "YES" << endl;
            continue;
        }else{
            cout << "NO" << endl;
        }
    }

}




//1 3 5 4