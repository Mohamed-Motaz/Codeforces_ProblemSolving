#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(4)
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pi acos(-1.0)
#define LL long long
//#define mp make_pair
#define pb push_back
#define ls rt<<1, l, m
#define rs rt<<1|1, m+1, r
#define ULL unsigned LL
#define pll pair<LL, LL>
#define pli pair<LL, int>
#define pii pair<int, int>
#define piii pair<pii, int>
#define mem(a, b) memset(a, b, sizeof(a))
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fopen freopen("in.txt", "r", stdin);freopen("out.txt", "w", stout);
//head

const int N = 150, M = 1e3 + 5;
const int MOD = 1e9 + 9;
LL dp[N][M][2];
int main() {
    int k, b;
    scanf("%d %d", &k, &b);
    dp[0][0][0] = 1;
    dp[0][0][1] = 0;
    for (int i = 1; i <= b; i++) {
        for (int j = 0; j < k; j++) {
            (dp[i][(j*2)%k][0] += dp[i-1][j][0]) %= MOD;
            (dp[i][(j*2+1)%k][0] += dp[i-1][j][0]) %= MOD;

            (dp[i][(j*2)%k][1] += dp[i-1][j][1]) %= MOD;
            (dp[i][(j*2+1)%k][1] += dp[i-1][j][1] + dp[i-1][j][0]) %= MOD;
        }
    }
    printf("%lld\n", dp[b][0][1]);
    return 0;
}