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
#define debug(x, y) cerr << (#x) << " " << (#y) <<" is " << (x) <<" "<< (y) << endl
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

ll gcd(ll a, ll b) {
    if (!b)return a;
    return gcd(b, a % b);
}
ll lcm (ll a, ll b) {
    return a * b / gcd(a, b);
}

const ll MOD = 998244353;
//const ll mod = 1e9 + 7;
const ll N = 1e3 + 7;
const ll llinf = INT64_MAX;
const int intinf = INT32_MAX;

int n, p;
string s;

bool findPalindrome(string s){
    f(i, 1, s.size()){
        //two alike
        if (s[i] == s[i - 1]) return true;
    }
    f(i, 1, s.size() - 1){
        if (s[i - 1] == s[i + 1]) return true;
    }
    return false;
}

int main() {
    MohamedMotaz
    cin >> n >> p;
    cin >> s;
    int i = n - 1;
    s[i]++;
    while (i < n && i >= 0){
        if (s[i] - 'a' >= p) s[i--] = 'a', (i >= 0) ? s[i]++: 0; //move to the letter before && inc, let this one b a.  cbd -> cca
        else if (i >= 1 && s[i] == s[i - 1]) s[i]++;
        else if (i >= 2 && s[i] == s[i - 2]) s[i]++;
        else i++;
    }

    (i < 0) ? cout << "NO" : cout << s;


}