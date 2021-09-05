#include <bits/stdc++.h>

using namespace std;



int main() {

	long long x, y, value, rowsCounter = 0, colsCounter = 0;
	bool row, col;
	char matrix[17][17];

	cin >> x >> y;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			
			cin >> matrix[i][j];
		}
	}


	for (int i = 0; i < x; i++) {
		row = false;
		
		for (int j = 0; j < y; j++) {
			if (matrix[i][j] != '.') row = true;
		}
		if (row) rowsCounter++;
	}
	for (int i = 0; i < y; i++) {
		col = false;

		for (int j = 0; j < x; j++) {
			if (matrix[j][i] != '.') col = true;
		}
		if (col) colsCounter++;
	}

	/*cout << "rowsCounter: " << rowsCounter << endl;
	cout << "colsCounter: " << colsCounter << endl;*/

	long long finalrowsCounter = (x - rowsCounter) * y;
	long long finalcolsCounter = (y - colsCounter) * x;
	
	/*cout << "finalrowsCounter: " << finalrowsCounter << endl;
	cout << "finalcolsCounter: " << finalcolsCounter << endl;*/

	cout << abs(finalrowsCounter - finalcolsCounter * colsCounter);
}