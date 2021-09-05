#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 2e3 + 5;
int X[N], Y[N];

struct Point {
    int x, y;

    bool operator<(const Point &b) const {
        if (x == b.x)
            return y < b.y;
        return x < b.x;

    }

} p[N];

int mp[N][N];
int sum[N][N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &X[i], &Y[i]);
        p[i].x = X[i], p[i].y = Y[i];
    }


    sort(X + 1, X + n + 1);
    sort(Y + 1, Y + n + 1);
    int qq = unique(X + 1, X + n + 1) - X - 1;
    int pp = unique(Y + 1, Y + n + 1) - Y - 1;
    for (int i = 1; i <= n; i++) {
        p[i].x = lower_bound(X + 1, X + qq + 1, p[i].x) - X;
        p[i].y = lower_bound(Y + 1, Y + pp + 1, p[i].y) - Y;
        mp[p[i].x][p[i].y] = 1;
    }
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = mp[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (p[i].x >= p[j].x || p[i].y >= p[j].y) continue;
            if (mp[p[j].x][p[i].y] && mp[p[i].x][p[j].y]) {
                int x1 = min(p[i].x, p[j].x);
                int y1 = min(p[i].y, p[j].y);
                int x2 = max(p[i].x, p[j].x);
                int y2 = max(p[i].y, p[j].y);
                if (sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] != 4) continue;
                ans++;
            }

        }
    }
    cout << ans << endl;
    return 0;

}