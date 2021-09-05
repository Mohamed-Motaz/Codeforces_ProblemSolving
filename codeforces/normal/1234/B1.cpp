#include <bits/stdc++.h>

using namespace std;


int main() {

	long long x, y; cin >> x >> y;
	map<long long, long long> mp;
	queue<long long> q;

	while (x--) {
		long long value; cin >> value;
		
		if (q.size() < y) {
			if (mp[value] == 0) {
				q.push(value);
				mp[value] = 1;
			}
		}
		else {
			if (mp[value] == 0) {
				mp[q.front()] = 0;
				q.pop();
				q.push(value);
				mp[value] = 1;
			}
		}

	}


	cout << q.size() << endl;
	vector<long long> temp;
	while (!q.empty()) {
		temp.push_back(q.front());
		q.pop();
	}
	for (int i = temp.size() - 1; i >= 0; i--) {
		cout << temp[i] << " ";
	}
}