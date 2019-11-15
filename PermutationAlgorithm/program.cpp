#include "PermutationAlgorithm.h"

int main()
{
	vector<int> elements;
	elements.push_back(1);
	elements.push_back(2);
	elements.push_back(3);

	vector<vector<int>> allPermutations;
	GetAllPermutations<int>(elements, allPermutations);

	return 0;
}