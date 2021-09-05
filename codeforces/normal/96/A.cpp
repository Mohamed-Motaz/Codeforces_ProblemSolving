#include <set>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){
	string s;
	cin >> s;
	long long maxi1 = 0;
	long long maxi2 = 0;
	long long counter1 = 0, counter2 = 0;
	bool one = false;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '1'){
			counter1++;
			if (counter2 > maxi2) maxi2 = counter2;
			counter2 = 0;
		}
		else{
			counter2++;
			if (counter1 > maxi1) maxi1 = counter1;
			counter1 = 0;

		}
	}
	if (counter2 > maxi2) maxi2 = counter2;
	if (counter1 > maxi1) maxi1 = counter1;
	//cout << maxi1 << " " << maxi2;
	if (maxi1 >= 7 || maxi2 >= 7){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}