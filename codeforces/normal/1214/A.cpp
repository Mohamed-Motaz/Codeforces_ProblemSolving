#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	ll x, dol, eur;
	ll dollars[] = {1,2,5,10,20,50,100};
	ll euros[] = { 5,10,20,50,100,200 };
	cin >> x;
	cin >> dol;
	cin >> eur;

	if (x % dol == 0 || x % eur == 0) {
		cout << 0; return 0;
	}
	if (dol > eur) {
		for (int i = 6; i >= 0; i--) {
			while (dollars[i] * dol <= x) {
				x -= dollars[i] * dol;
			}
		}
		for (int i = 5; i >= 0; i--) {
			while (euros[i] * eur <= x) {
				x -= euros[i] * eur;
			}
		}

	}
	else {
		for (int i = 5; i >= 0; i--) {
			while (euros[i] * eur <= x) {
				x -= euros[i] * eur;
			}
		}
		for (int i = 6; i >= 0; i--) {
			while (dollars[i] * dol <= x) {
				x -= dollars[i] * dol;
			}
		}
		
	}
	cout << x;

}