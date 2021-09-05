#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl "\n"
#define MohamedMotaz ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second


using namespace std;

vector<ll> adjList[10];
ll visited[10000] = {};
ll x, y; // x - employees num, y- languages num
ll counter = 0;

void dfs(ll node) {
	if (visited[node]) return;

	for (auto child : adjList[node]) {
		dfs(child);
	}
}

int main() {

	MohamedMotaz;

	cin >> x >> y;

	for (int q = 0; q < x; q++) {
		ll val1, val2;
		cin >> val1;
		if (val1 == 0) {
			counter++;
			visited[q] = 1;
			continue;
		}
		for (int i = 0; i < val1; i++) {
			cin >> val2;
			adjList[i].push_back(val2);
		}
		for (int i = 0; i < x; i++) {
			if (!visited[i]) {
				dfs(i);
			}
		}

	}
	cout << counter << endl;



}