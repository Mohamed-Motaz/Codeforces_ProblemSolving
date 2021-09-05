#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cmath>
#include <string>

#define ll long long
#define endl '\n'

using namespace std;

ll factorial[100000];
ll inverse[100000];
ll mod;


ll pre(){
	factorial[0] = factorial[1] = 1;
	inverse[0] = 1;
	
	for (int i = 1; i < 100000; i++){
		factorial[i] = i * factorial[i - 1];
		inverse[i] = pow(i, mod - 2);
	}
	return 0;
}




int main(){
	//pre();
	
	string s; cin >> s;
	bool found = false;

	for (int i = 0; i < s.size(); i++){
		if (s[i] == '0'){
			cout << s.substr(0, i) + s.substr(i + 1, s.size());
			found = true;
			break;
		}
	}
	if (!found){
		cout << s.substr(1, s.size());
	}

}