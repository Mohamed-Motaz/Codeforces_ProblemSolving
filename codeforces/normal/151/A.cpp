#include <bits/stdc++.h>

using namespace std;



int main() {

	long long numFriends, numSoftDrink, miliLiterInDrink, numLimes, numLimesSlices, numSaltGrams,
		miliLiterDrinkNeededPerPerson, saltGramsNeededPerPerson;

	cin >> numFriends >> numSoftDrink >> miliLiterInDrink >> numLimes >> numLimesSlices>> 
		numSaltGrams >> miliLiterDrinkNeededPerPerson >> saltGramsNeededPerPerson;

	long long numberAvaialbleForSalt = numSaltGrams / saltGramsNeededPerPerson;
	long long numberAvailbleForLimes = numLimes * numLimesSlices;
	long long numberAvailableForDrinks = numSoftDrink * miliLiterInDrink/ miliLiterDrinkNeededPerPerson;
	long long numberAvailableForToasts = numberAvailableForDrinks / numFriends;
	

	long long tempMin = min(numberAvaialbleForSalt, numberAvailableForDrinks);
	long long tempTempMin = min(tempMin, numberAvailbleForLimes);

	cout << tempTempMin / numFriends;

}