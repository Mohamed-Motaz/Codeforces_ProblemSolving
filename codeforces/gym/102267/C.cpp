#include <iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<iomanip>
#include<cmath>
#include<stack>
#include <cctype>
#include <cstdio>
#define pi acos(-1)
#define endl '\n'
#define Bedoazim ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

const long long mod = 1e9 + 7, N = 1e5 + 9, inf = 1e18;

set<long long> GetDivisors(long long val) {

    set<long long> st;

    for (int i = 1; i <= sqrt(val); i++) {

        if (val % i == 0) {
            st.insert(i);
            st.insert(val / i);
        }
    }
    return st;
}

map<int, int>sub;

int n;

long long seq[1005], dp[1005][1005];

long long solve(int ind,int prev) {

    if (ind == n) {

        sub[dp[ind - 1][prev]]++;

        return 0;
    }

    if (dp[ind][prev] != -1)
        return dp[ind][prev];

    long long ans = 0;

    if (seq[ind] > seq[prev]) {

        ans = 1 + solve(ind + 1, ind);
    }

    return dp[ind][prev] = max(ans, solve(ind + 1, ind));
}


int main()
{

    Bedoazim;
    
    long long s, x;

    cin >> s >> x;

    int ans = 0;

    while (s) {

        s /= x;

        ans++;
    }

    cout << ans;
}