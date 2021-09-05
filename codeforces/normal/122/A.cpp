#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

long long total = 0;
long long succesful = 0;
bool done = false;
void recursion(long long initialVal, long long toCheck) {

	if (initialVal != 0 && toCheck % initialVal == 0) {
		//cout << initialVal << endl;
		done = true;
		return;
	}
	if (initialVal >= toCheck) {
		return;
	}

	recursion(initialVal * 10 + 4, toCheck);
	recursion(initialVal * 10 + 7, toCheck);
}
int main() {

	long long x;
	cin >> x;
	recursion(0, x);
	if (done) cout << "YES";
	else cout << "NO";
}