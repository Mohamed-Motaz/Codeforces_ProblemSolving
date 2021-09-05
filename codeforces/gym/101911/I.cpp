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


int main() {
    HS;
    int n;
    cin >> n;
    int arr[1005];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int stolen = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] - arr[i - 1] != 1)
            stolen+=arr[i]-arr[i-1]-1;
    cout << stolen << endl;


    return 0;
}