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
const int N = 1e5 + 7;

bool can = false;
int n;
string s;
int dp[1004][4][4][2][2];
//0 is R  1 is G   2 is B  3 is none
int solve(int idx, int prevFirstPile, int prevSecondPile, bool firstPileOops, bool secondPileOops){
    if (idx == n){
        can = true;
        cout << "YES";
        exit(0);
    }
    int &ans=dp[idx][prevFirstPile][prevSecondPile][firstPileOops][secondPileOops];
    if(ans!=-1) return ans;
    ans=0;
    char curLetter = s[idx];
    int num = 3;
    if (curLetter == 'R')
        num = 0;
    if (curLetter == 'G')
        num = 1;
    if (curLetter == 'B')
        num = 2;

    if (prevFirstPile == 3){
        //can put anything or not
        ans|=solve(idx + 1, num, prevSecondPile, firstPileOops, secondPileOops);
        if (num != prevSecondPile){
            if (!secondPileOops)
                ans|=solve(idx + 1, prevFirstPile, num, firstPileOops, 1);
        }else{
            ans|=solve(idx + 1, prevFirstPile, num, firstPileOops, secondPileOops);
        }
    }
     if (prevSecondPile == 3){
        //can put anything or not
        ans|=solve(idx + 1, prevFirstPile, num, firstPileOops, secondPileOops);
        if (num != prevFirstPile){
            if (!firstPileOops)
                ans|=solve(idx + 1, num, prevSecondPile, 1, secondPileOops);
        }else{
            ans|=solve(idx + 1, num, prevSecondPile, firstPileOops, secondPileOops);
        }
    }if(prevFirstPile!=3&&prevSecondPile!=3){
        //can put it anywhere
        if (num == prevFirstPile)
            ans|=solve(idx + 1, num, prevSecondPile, firstPileOops, secondPileOops);
        if (num == prevSecondPile)
            ans|=solve(idx + 1, prevFirstPile, num, firstPileOops, secondPileOops);

        if (num != prevFirstPile){
            if (!firstPileOops)
                ans|=solve(idx + 1, num, prevSecondPile, 1, secondPileOops);
        }

        if (num != prevSecondPile){
            if (!secondPileOops)
                ans|=solve(idx + 1, prevFirstPile, num, firstPileOops, 1);
        }
    }
    return ans;
}

int main(){
    MohamedMotaz;
    cin >> s;
    n = s.size();
    memset(dp,-1,sizeof dp);
    if(solve(0, 3, 3, 0, 0))
        cout<<"YES\n";
    else cout << "NO\n";

}
//RRGG BB