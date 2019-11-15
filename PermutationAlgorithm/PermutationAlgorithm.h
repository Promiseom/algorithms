/*************************************
*AUTHOR: PROMISE ANENDAH T.
*SINCE:  JANUARY, 2018
*SUBJECT: PERMUTATION ALGORITHM
*AIM: FIND ALL PERMUTATIONS OF A SET
**************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
void PrintPermutation(vector<T> permutation)
{
	cout<<"{";
	for(int i = 0; i < permutation.size(); i++)
	{
		cout<<permutation[i]<<", ";
	}
	cout<<"}"<<endl;
}

template <class T>
void Swap(T &x, T &y)
{
	int temp = x;
	x = y;
	y = temp;
}

//Gives all permutations of a collection
//All the permutations are return via the vector passed by reference to the function
template <class T>
void GetAllPermutations(vector<T> primaryPermutation, vector<vector<T>> &allPermutations, int referencePoint = 0)
{
	//base of the recursion
	if(referencePoint == primaryPermutation.size() - 2)
	{
		PrintPermutation(primaryPermutation);
		allPermutations.push_back(primaryPermutation);
		Swap(primaryPermutation[referencePoint], primaryPermutation[primaryPermutation.size() - 1]);
		PrintPermutation(primaryPermutation);
		allPermutations.push_back(primaryPermutation);
		Swap(primaryPermutation[referencePoint], primaryPermutation[primaryPermutation.size() - 1]);
		return;
	}

	//this is the number of secondary permutation that can be generated from this primary permutation
	//this is because they are generated base on reference points
	int size = primaryPermutation.size() - referencePoint;

	//get all secondary permutations of the primary permutation
	for(int i = 0, j = referencePoint; i < size; i++)
	{
		//this swap turns the primary permutation into a secondary permutation
		Swap(primaryPermutation[referencePoint], primaryPermutation[j]);
		GetAllPermutations(primaryPermutation, allPermutations, referencePoint + 1);
		//reverse back to primary permutation
		Swap(primaryPermutation[referencePoint], primaryPermutation[j]);
		j++;
	}
}