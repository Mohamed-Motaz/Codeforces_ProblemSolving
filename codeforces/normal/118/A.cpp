#include <bits/stdc++.h>

using namespace std;



int main() {

	string s;

	cin >> s;

	
	for (auto character : s) {
		character = tolower(character);
		if (!(character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u' || character == 'y')) {
			cout << ".";
			cout << character;
		}
		
	}

	
}