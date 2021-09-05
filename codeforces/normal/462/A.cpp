
#include <bits/stdc++.h>

using namespace std;



int main() {

	long long x, y, counter = 0;
	char board[107][107];

	cin >> x;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			
				counter = 0;



				if (i - 1 >= 0) {
					if (board[i - 1][j] == 'o') counter++;

				}if (i + 1 < x) {
					if (board[i + 1][j] == 'o') counter++;

				}if (j - 1 >= 0) {
					if (board[i][j - 1] == 'o') counter++;

				}if (j + 1 < x) {
					if (board[i][j + 1] == 'o') counter++;

				}
			
	
			if (counter % 2 != 0) {
				cout << "NO";
				return 0;
			
			}
		}
	}

	cout << "YES";

}