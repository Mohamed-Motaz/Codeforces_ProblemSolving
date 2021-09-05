#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <complex>
#include <iomanip>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <set>

#define ll long long
#define ld long double
#define HS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define INF 0x3f3f3f3f3f3f3f3f
#define point complex <double>
#define all(a) a.begin(), a.end()
#define pi acos(-1)
#define mod 998244353
using namespace std;
ll arr[200000];
int n, t;



int main() {
    HS;
    ld x, y, xx, yy;
    cin >> x >> y >> xx >> yy;

    ld first = x * x + y * y;
    ld second = xx * xx + yy * yy;
    if (fabs(first - second) < 1e-9) cout << "Empate";
    else if (first > second) cout << "Wil";
    else cout << "Russo";

}