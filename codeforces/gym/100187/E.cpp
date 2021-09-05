#include <bits/stdc++.h>

#define Jo ios::sync_with_stdio(0); cin.tie(NULL); ios_base::sync_with_stdio(0); cout.tie(NULL); //freopen("phantom.in","r",stdin);freopen("output.txt","w",stdout);
#define INF 1e18+5
#define endl '\n'
#define point complex<double>
#define mk make_pair
const long long N = 1e5 + 5;
const long long mod = 1e9 + 7;
const double Phi = (sqrt(5) + 1) / 2;
const double PI = acos(-1.0);
using namespace std;
int dx[] = {0, -1, 0, 1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
int n, m;
bool vis[505][505];
vector<string> arr1(505), arr2(505);

bool valid(long long i, long long j) { return i >= 0 && j >= 0 && i < n && j < m; }

int bfs(vector<string> v) {
    queue<pair<pair<int, int>, int>> q;
    q.push(mk(mk(0, 0), 0));
    vis[0][0] = 1;
    while (q.size()) {
        int x = q.front().first.first, y = q.front().first.second, dist=q.front().second;
        q.pop();
        if (x == n - 1 && y == m - 1) {
            return dist;
        }
        for (int i = 0; i < 4; i++) {
            int curX = x + dx[i], curY = y + dy[i];
            if (valid(curX, curY) && !vis[curX][curY] && v[curX][curY] == '.') {
                vis[curX][curY] = 1;
                q.push(mk(mk(curX, curY), dist + 1));
            }
        }
    }
}

int bfs1() {
    queue<pair<pair<int, int>, int>> q;
    q.push(mk(mk(0, 0), 0));
    vis[0][0] = 1;
    while (q.size()) {
        int x = q.front().first.first, y = q.front().first.second, dist=q.front().second;
        q.pop();
        if (x == n - 1 && y == m - 1) {
            return dist;
        }
        for (int i = 0; i < 4; i++) {
            int curX = x + dx[i], curY = y + dy[i];
            if (valid(curX, curY) && !vis[curX][curY] && arr1[curX][curY] == '.' && arr2[curX][curY] == '.') {
                vis[curX][curY] = 1;
                q.push(mk(mk(curX, curY), dist + 1));
            }
        }
    }
}

int main() {
    Jo
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    int first = bfs(arr1);
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[i][j] = 0;
        }
    }
    int second = bfs(arr2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[i][j] = 0;
        }
    }
    int common = bfs1();
    if (common == first && common == second) {
        return cout << "YES\n", 0;
    }
    cout << "NO\n";


    return 0;
}