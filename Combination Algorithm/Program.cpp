#include "CombinationAlgorithm.h"

int main(int argv, char* args[])
{
	vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);
	numbers.push_back(6);
	numbers.push_back(7);
	numbers.push_back(8);
	numbers.push_back(9);
	numbers.push_back(0);
	
	PrintAllCombinations(numbers, 4, false);
	
	cout<<"Press enter to continue...";
	cin.ignore();
	return 0;
}