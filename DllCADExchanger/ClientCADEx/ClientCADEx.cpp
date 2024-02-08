#include <iostream>
#include <math.h>
#include <random>
#include <iomanip>
#include <ctime> 
#include <cstdlib>


#include "Circle.h"
#include "Ellips.h"
#include "Helix.h"


void HoaraSorting(vector <Circle*>& unsortedList, int first, int last) {

	auto size = unsortedList.size();
	int i = first, j = last;
	double reference = unsortedList[(first + last) / 2]->GetRadius();
	vector <Circle*> temp = { new Circle() };
	do {
		while (unsortedList[i]->GetRadius() < reference) {
			i++;
		}
		while (unsortedList[j]->GetRadius() > reference) {
			j--;
		}

		if (i <= j)
		{
			if (i < j)
			{
				temp[0] = unsortedList[i];
				unsortedList[i] = unsortedList[j];
				unsortedList[j] = temp[0];
			}
			i++;
			j--;
		}

	} while (i <= j);

	if (i < last)
		HoaraSorting(unsortedList, i, last);
	if (first < j)
		HoaraSorting(unsortedList, first, j);
}

int main()
{
	// 2 task
	srand(time(NULL));
	int countOfElements = 5 + rand() % 40;
	vector <Circle*> randomList;
	int number;
	for (int i = 0; i < countOfElements; i++) {
		number = 1 + rand() % 3;
		switch (number) {
		case 1: {
			randomList.push_back(new Circle(rand() % 20));
			break;
		}
		case 2: {
			randomList.push_back(new Ellips(rand() % 20, rand() % 25));
			break;
		}
		case 3:
			randomList.push_back(new Helix(rand() % 15, rand() % 360));
			break;
		}
	}

	// 3 task

	cout << "|\tType of curve\t||\tx\t||\ty\t||\tz\t||\tderivative\t|" << endl;
	for (int i = 0; i < countOfElements; i++) {
		randomList[i]->SetT(PI / 4);
		vector <double> tempInfo = randomList[i]->GetInfo();
		cout << "|\t " << randomList[i]->GetTypeName() << " \t|";
		for (double j : tempInfo) {
			cout << "|\t" << setprecision(5) << fixed << j << "\t|";
		}
		cout << endl;
	}

	// 4 task
	vector <Circle*> onlyCirclesList;
	for (int i = 0; i < countOfElements; i++) {
		if (randomList[i]->GetTypeName() == "Circle") {
			onlyCirclesList.push_back(randomList[i]);
		}
	}
	cout << endl << endl << endl;

	// 5 task 
	cout << "The sorted objects by radius:" << endl;
	auto size = onlyCirclesList.size();
	HoaraSorting(onlyCirclesList, 0, onlyCirclesList.size() - 1);
	for (int i = 0; i < size; i++) {
		cout << "|\t " << onlyCirclesList[i]->GetRadius() << " \t|" << endl;
	}

	// 6 task
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += onlyCirclesList[i]->GetRadius();
	}
	cout << endl << "Sum of radiuses in vector with only circles: " << sum << endl;
	system("pause");
	return 0;
}
