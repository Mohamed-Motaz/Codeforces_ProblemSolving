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


const ll mod = 1e9 + 7;
int dirX[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
int dirY[] = { -1, 0, 1, 0, 1, -1, -1, 1 };


const ll MOD = 998244353;
//const ll mod = 1e9 + 7;
const ll N = 1e3 + 7;
const ll llinf = INT64_MAX;
const int intinf = INT32_MAX;

int sum, limit;

int main() {
    MohamedMotaz
    cin >> sum >> limit;
    //if num is odd, lowbit is 1
    int val = limit, ans = -1, idx  =-1, finalSum;
    if (limit % 2) --val;
    vii vec;
    //need to get maxSum without exceeding limit
    for (int i = val; i > 0; i -= 2){
        bitset<32> bs(i);
        string s = "";
        f(j, 0, 32) s+= to_string(bs[j]);
        f(j, 0, 32){
            if (s[j] == '1'){
                idx = j ;
                break;
            }
        }
        int tempsum = pow(2, idx);
        if (tempsum + finalSum <= sum ){
            vec.push_back(i), finalSum += tempsum;
        }
    }
    //cout << mxValue << " " << mxSum << endl;
    int oddNumbersAvailable = limit / 2;
    (limit % 2) ? oddNumbersAvailable++ : 0;
    //cout << oddNumbersAvailable << endl;
    if (sum - finalSum > oddNumbersAvailable) return cout << -1, 0;

    cout << sum - finalSum + vec.size() << endl;
    for (auto e: vec) cout << e << " ";
    int counter = 1;
    f(i, 0, sum - finalSum) cout << counter << " ", counter += 2;
}