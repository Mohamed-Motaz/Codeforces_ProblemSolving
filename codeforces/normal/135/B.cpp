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

#define vp vector<point>
#define pi acos(-1)
#define point complex<double>


using namespace std;

const ll mod = 1e9 + 7;

ll fact[1000001]; ll inv[1000001];
ll primes[100007];
ll arr[1000007];
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
    for (int i = 2; i <= val; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= val; j += i) {
                primes[j] = 0;
            }
        }
    }

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

point RotateAbout(point a, point about, double angle){
    return (a - about) * polar(1.0, angle) + about;
}
//atan2 returns angle between vec and x axis atan2(a.imag(), a.real())


const ll MOD = 998244353;
//const ll mod = 1e9 + 7;
const ll N = 1e3 + 7;
const ll inf = 1e18 + 5;





vpld v(8);


//bool rect(vld s){
//
//    //for (auto e: s) cout << e << " "; cout << endl;
//
//}
//
//bool square(vld s){
//    //if (!rect(s)) return false;
//    //cout << "in" << endl;
//    ld mn = inf, c = 0;
//    map<ld, ld> mp;
//    f(i,0,4){
//        f(j, i + 1, 4){
//            point a(v[s[i]].first, v[s[i]].second);
//            point b(v[s[j]].first, v[s[j]].second);
//            mn = min(mn, (ld)abs(a - b));
//            mp[abs(a - b)]++;
//        }
//    }
//    //cout << "mn is now: " << mn << endl;
//    f(i, 0, 4){
//        f(j, i + 1, 4){
//            point a(v[s[i]].first, v[s[i]].second);
//            point b(v[s[j]].first, v[s[j]].second);
//            //cout << abs(a - b) << " ";
//            if (abs(a - b) == mn) c++;
//
//        }
//    }
//    //cout << "              " << c << endl;
//    //if (c == 4) {cout << "yayayyaa" << endl; return true;}
//
//    for (auto e: mp) if (e.second == 4) return true;
//    return c == 4;
//}


int main() {
    MohamedMotaz

    f(i, 0, 8) cin >> v[i].first >> v[i].second;

    f(i, 0, 8){
        f(j, 0, 8){
            f(k, 0, 8){
                f(l, 0, 8){
                    if (i != j && i != k && i != l && j != k && j != l && k != l){
                        vll s1, s2;

                        map<ld, ll> mp;
                        ld cnt1 = 0, cnt2 = 0, rct = 0, sq = 0;
                        point a(v[i].first, v[i].second);
                        point b(v[j].first, v[j].second);
                        point c(v[k].first, v[k].second);
                        point d(v[l].first, v[l].second);
                        if ( dot ( b - a, c - a) == 0 ||
                             dot ( b - a, d - a) == 0 ||
                             dot ( c - a, d - a) == 0 ) {
                            cnt1++;
                        }
                        if ( dot (a - b, c - b) == 0 ||
                             dot ( a - b, d - b) == 0 ||
                             dot ( c  - b, d - b) == 0 ) {
                            cnt1++;
                        }
                        if ( dot ( b - c, a - c) == 0 ||
                             dot ( b - c, d - c) == 0 ||
                             dot ( a - c, d - c) == 0 ) {
                            cnt1++;
                        }
                        if ( dot (b - d, c - d) == 0 ||
                             dot ( b - d, a - d) == 0 ||
                             dot ( c - d, a - d) == 0 ) {
                            cnt1++;
                        }
                        //cout <<" in" << endl;
                        if (cnt1 == 4) rct++;


                        f(m, 0, 8){
                            if (m != i && m != j && m != k && m != l) s2.push_back(m);
                            else s1.push_back(m);
                        }

                        point aa(v[s2[0]].first, v[s2[0]].second);
                        point bb(v[s2[1]].first, v[s2[1]].second);
                        point cc(v[s2[2]].first, v[s2[2]].second);
                        point dd(v[s2[3]].first, v[s2[3]].second);

                        if ( dot ( bb - aa, cc - aa) == 0 ||
                             dot ( bb - aa, dd - aa) == 0 ||
                             dot ( cc - aa, dd - aa) == 0 )
                            cnt2++;
                        if ( dot (aa - bb, cc - bb) == 0 ||
                             dot ( aa - bb, dd - bb) == 0 ||
                             dot ( cc  - bb, dd - bb) == 0 )
                            cnt2++;
                        if ( dot ( bb - cc, aa - cc) == 0 ||
                             dot ( bb - cc, dd - cc) == 0 ||
                             dot ( aa - cc, dd - cc) == 0 )
                            cnt2++;
                        if ( dot (bb - dd, cc - dd) == 0 ||
                             dot ( bb - dd, aa - dd) == 0 ||
                             dot ( cc - dd, aa - dd) == 0 )
                            cnt2++;

                        mp [ abs ( bb - aa)] ++;
                        mp [ abs ( cc - aa)] ++;
                        mp [ abs ( dd - aa)] ++;
                        mp [ abs ( bb - cc)] ++;
                        mp [ abs ( cc - dd)] ++;
                        mp [ abs ( dd - bb)] ++;

                        if ((( mp [ abs ( bb - aa)] == 4 ||
                                mp [ abs ( cc - aa)] == 4 ||
                                mp [ abs ( dd - aa)] == 4 ||
                                mp [ abs ( bb - cc)] == 4 ||
                                mp [ abs ( cc - dd)] == 4 ||
                                mp [ abs ( dd - bb)] == 4 )
                                && cnt2 == 4))
                            sq ++ ;
                        if (sq == 2 || (rct && sq)){
                            cout << "YES" << endl;
                            for (auto e: s2) cout << ++e << " "; cout << endl;
                            for (auto e: s1) cout << ++e << " ";
                            return 0;
                        }

    //                    if (square(s1)) cout << "s1 sq" << endl;
    //                    else cout << "s1 not sq" << endl;
    //                    if (square(s2)) cout << "s2 sq" << endl;
    //                    else cout << "s2 not sq" << endl;
    //                    if (rect(s1)) cout << "s1 rec" << endl;
    //                    else cout << "s1 not rec" << endl;
    //                    if (rect(s2)) cout << "s2 rec" << endl;
    //                    else cout << "s2 not rec" << endl;
    //                    cout << endl endl;
    //                    if (square(s1) && rect(s2)){
    //                        cout << "YES" << endl;
    //                        for (auto e: s1) cout << ++e << " "; cout << endl;
    //                        for (auto e: s2) cout << ++e << ' ';
    //                        return 0;
    //                    }
    //                    if (square(s2) && rect(s1)){
    //                        cout << "YES" << endl;
    //                        for (auto e: s2) cout << ++e << " "; cout << endl;
    //                        for (auto e: s1) cout << ++e << ' ';
    //                        return 0;
    //                    }
    //                    if (square(s2) && square(s1)){
    //                        cout << "YES" << endl;
    //                        for (auto e: s2) cout << ++e << " "; cout << endl;
    //                        for (auto e: s1) cout << ++e << ' ';
    //                        return 0;
    //                    }

    //                    if (rect(s1)){
    //                        cout << "s1 is rect" << endl;
    //                        for (auto e: s2) cout << e << " "; cout << endl;
    //                        for (auto e: s1) cout << e << " "; cout << endl;
    //
    //                    }
    //                    if (rect(s2)){
    //                        cout << "s2 is rect" << endl;
    //                        for (auto e: s1) cout << e << " "; cout << endl;
    //                        for (auto e: s2) cout << e << " "; cout << endl;
    //
    //                    }
    //                    if (square(s1)){
    //                        cout << "s1 is sq" << endl;
    //                        for (auto e: s1) cout << e << " "; cout << endl;
    //                        for (auto e: s2) cout << e << " "; cout << endl;
    //
    //                    }
    //                    if (square(s2)){
    //                        cout << "s2 is sq" << endl;
    //                        for (auto e: s2) cout << e << " "; cout << endl;
    //                        for (auto e: s1) cout << e << " "; cout << endl;
    //
    //                    }
    //                    cout << "done" << endl;
    //
    //                    if (square(s1) && rect(s2)) return cout << "FOUND0", 0;
    //                    if (square(s2) && rect(s1)) return cout << "FOUND1", 0;
                    }
                }
            }
        }
    }

    cout << "NO";


}