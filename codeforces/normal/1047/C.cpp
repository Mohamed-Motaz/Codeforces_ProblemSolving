#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl "\n"
#define MohamedMotaz ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);

using namespace std;






const ll inf = 1e18, mod = 1e9 + 7;
const ll N = 15000000 + 7;
ll primes[N] = {};
ll x, GCD;
ll tmp[300000 + 7] = {}, cnt[N] = {};
set<ll> h;
void sieve(ll val) {
	//memset(primes, 1, sizeof primes);
	primes[1] = primes[0] = 1;
	for (int i = 2; i <= val; i++)
	{
		if (!primes[i])
		{
			//make prime factor of each elem;
			primes[i] = i;
			for (int j = i + i; j <= val; j += i)
				primes[j] = i;
		}
	}
}

int main()
{
	MohamedMotaz;
	sieve(N);
	cin >> x;
	for (int i = 0; i < x; i++) {
		cin >> tmp[i];
		GCD = gcd(GCD, tmp[i]);
		h.insert(tmp[i]);
	}

	sort(tmp, tmp + x);
	if (h.size() == 1) return cout << -1, 0;
	/*for (int i = 0; i < 100; i++) {
		cout << primes[i] << " ";
	}*/
	for (int i = 0; i < x; i++) {
		tmp[i] /= GCD;
	}
	ll ans = 1;
	for (int i = 0; i < x; i++) {

		// set each elem to its prime factors
		while (tmp[i] > 1) {
			ll val = primes[tmp[i]];
			//if (val == 0) continue;
			cnt[val]++;
			while (tmp[i] % val == 0) {
				tmp[i] /= val;
			}
			ans = max(ans, cnt[val]);
		}


	}

	cout << x - ans;
}