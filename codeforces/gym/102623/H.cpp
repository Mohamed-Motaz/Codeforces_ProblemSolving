#include <iostream>
#include <stdio.h>
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

#define pi acos(-1)
#define point complex<ld>
using namespace std;

const ll mod = 1e9 + 7;
const ll sizee = 0;
int dirX[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
int dirY[] = { -1, 0, 1, 0, 1, -1, -1, 1 };

ll fact[sizee]; ll inv[sizee];
ll arr[sizee];
ll primes[sizee];

ll modPower(ll b, ll p) {
    if (p == 0)
        return 1;

    ll halfpow = modPower(b, p / 2);
    ll toReturn = (halfpow * halfpow) % mod;
    if (p % 2)
        toReturn = (toReturn * b) % mod;

    return toReturn;
}

ll fastPower(ll b, ll p) {
    if (p == 0)
        return 1;
    ll ans = fastPower(b, p / 2);
    ans = (ans * ans);
    if (p % 2 != 0)
        ans = (ans * b);
    return ans;
}
double bigPower(double a, int n)
{
    double x = a, ret = 1;
    while(n)
    {
        int currentBit = n&1;
        if(currentBit)
            ret *= x;
        x*=x;
        n = n>>1;
    }
    return ret;
}
ll GcdRecursive(ll a, ll b) {
    if (b == 0) return a;
    return GcdRecursive(b, a % b);
}
ll modLCM(ll a, ll b) {
    ll val = GcdRecursive(a, b);
    ll tmp = ((a % mod) * (b % mod)) % mod;
    ll finalVal = ((tmp % mod) * (arr[val] % mod)) % mod;
    return finalVal;

}
ll LCM(ll a, ll b) {
    return (a * b) / GcdRecursive(a, b);
}
void move1step(ll& a, ll& b, ll q) { // a and b by reference
    ll c = a - q * b;
    a = b;
    b = c;
}
ll GcdIterative(ll a, ll b) {
    while (b) move1step(a, b, a / b);
    return a;
}

void pre(ll n) {

    fact[0] = 1;
    inv[0] = 1;

    for (ll i = 1; i <= n; i++) {
        fact[i] = (i * fact[i - 1]) % mod;
        inv[i] = modPower(fact[i], mod - 2);
        arr[i] = modPower(i, mod - 2);
    }
}

ll npr(ll n, ll r) {
    return ((fact[n] * inv[n - r]) % mod);
}

ll ncr(ll n, ll r) {
    return ((((fact[n] * inv[n - r]) % mod) * inv[r]) % mod);
}

void sieve(ll val) {
    memset(primes, 1, sizeof primes);
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= val; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= val; j += i) {
                primes[j] = 0;
            }
        }
    }

}


ll power(ll b,ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
bool isPrime (ll n) {
    if (n <= 1)
        return false;

    for (int i = 2; i*i <=n; i++)
        if (n % i == 0)
            return false;

    return true;
}
string findSmallestLexoWithoutDupilcates (string s) {
    int cnt[27];
    bool vis[27];
    for (int i=0; i<s.size(); i++) cnt[s[i]-'a']++;
    string ans="";
    for (int i=0; i<s.size(); i++){
        int x=s[i]-'a';
        cnt[x]--;
        if(vis[x]) continue;
        while (ans.size()>0 && s[i]<ans.back() && cnt[ans.back()-'a']>0){
            vis[ans.back()-'a']=false;
            ans.pop_back();
        }
        ans.push_back(s[i]);
        vis[x]=true;
    }
    return ans;
}
ld dot(point a, point b) {
    return (conj(a) * b).real();
}
ld cross(point a, point b){
    return (conj(a) * b).imag();
}
//length of vector is abs(complex)
//hypot(3, 4) returns 5
//arg(3, 3) * 180 / pi returns angle between vector and x-axis
//point a(2, 3), b(4, 2);  (b - a) return vector between two points
//a *= polar(1.0, - pi / 45) rotates by 45 degrees clockwise about origin
//to rotate about a point, minus it from my origin a = (a - b) * polar(1.0, pi) + b
ld angleBetVec(point a, point b){
    ld d = dot(a, b);
    d/= abs(a);
    d/= abs(b);
    //now i have cos of angle in rad
    return  acos(d) * 180 / pi;
}
//atan2 returns angle between vec and x axis atan2(a.imag(), a.real())

point RotateAbout(point a, point about, ld angle){
    return (a - about) * polar((ld)1.0, angle) + about;
}

// Note: if there is a cycle, the size of the return will be less than n.
vector<int> topological_sort(const vector<vector<int>> &adj) {
    int n = int(adj.size());
    vector<int> in_degree(n, 0);
    vector<int> order;

    for (int i = 0; i < n; i++)
        for (int neighbor : adj[i])
            in_degree[neighbor]++;

    for (int i = 0; i < n; i++)
        if (in_degree[i] == 0)
            order.push_back(i);

    int current = 0;

    while (current < int(order.size())) {
        int node = order[current++];

        for (int neighbor : adj[node])
            if (--in_degree[neighbor] == 0)
                order.push_back(neighbor);
    }

    return order;
}

set<int> GetDivisors(ll val){
    set<int> st;
    f(i, 1, sqrt(val) + 1) if (val % i == 0) st.insert(i), st.insert(val / i);
    return st;
}

void LoopDiagonally(int a, int b){
    //length and width
    for( int k = 0 ; k <= a + b - 2; k++ ) {
        string t = "";
        for( int j = 0 ; j <= k ; j++ ) {
            int i = k - j;
            if( i < a && j < b ) {
                //t += v[i][j];
            }
        }
        //v3.push_back(t);
    }
    //cout << "in" << endl;
    for( int k = 0 ; k <= a + b - 2; k++ ) {
        string t = "";
        for( int j = 0 ; j <= k ; j++ ) {
            int i = a - (k - j);
            if( i >= 0 && i < a && j < b ) {
                // t += v[i][j];
            }
        }
        //v3.push_back(t);
    }
}

int getBits(int val){
    int ctr = 0;
    while (val) {
        ctr += val & 1;
        val >>= 1;
    }
    return ctr;
}


void DSUfunctions(){
//    int n, cnt, par[N];
//    int findpar(int u)
//    {
//        return u == par[u] ? u : findpar(par[u]);
//    }
//    bool sameset(int u, int v)
//    {
//        return findpar(u) == findpar(v);
//    }
//    void join(int u, int v)
//    {
//        if(sameset(u, v))
//            return;
//        par[findpar(u)] = par[findpar(v)];
//    }
}
inline void fasterLLDivMod(unsigned long long x, unsigned y, unsigned &out_d, unsigned &out_m) {
    unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
#ifdef __GNUC__
    asm(
    "divl %4 \n\t"
    : "=a" (d), "=d" (m)
    : "d" (xh), "a" (xl), "r" (y)
    );
#else
    __asm {
        mov edx, dword ptr[xh];
        mov eax, dword ptr[xl];
        div dword ptr[y];
        mov dword ptr[d], eax;
        mov dword ptr[m], edx;
    };
#endif
    out_d = d; out_m = m;
}
inline unsigned long long modd(unsigned long long x, unsigned long long y) {
    unsigned dummy, r;
    fasterLLDivMod(x, y, dummy, r);
    return r;
}

const ll MOD = 998244353;
//const ll mod = 1e9 + 7;
const ll N = 3e5 + 7;
const ll llinf = INT64_MAX;
const int intinf = INT32_MAX;
const int infClr = 0x3f3f3f3f;


int t;
ll n, k, m, a, b, r, c, d, x, y, q, z, f, l, p;


int main() {
    MohamedMotaz;
    cin >> n >> m >> k;
    pair<ull, ull> brr[n + 2][m + 2];
    f(i, 1, n + 1) f(j, 1, m + 1) cin >> a, brr[i][j] = {a, 0}; //time seen last
    ll total = 0;
    while(k--){
        char c;
        cin >> c >> a >> b;
        if (c == 'r'){
            f(i, 1, m + 1){
                ll ans = (modd(brr[a][i].first, MOD) * (modd(b - brr[a][i].second,MOD)));
                ans = modd(ans, MOD);
                brr[a][i].second = b;
                total += ans;
                total = modd(total, MOD);
            }
        }else{
            f(i, 1, n + 1){
                ll ans = (modd(brr[i][a].first, MOD) * (modd(b - brr[i][a].second, MOD) ) );
                ans = modd(ans, MOD);
                brr[i][a].second = b;
                total += ans;
                total = modd(total, MOD);
            }
        }
    }
    cout << modd(total, MOD) << endl;


}