/*****************************************************************************************
*AUTHOR: PROMISE ANENDAH T.
*SINCE:  DECEMBER, 2017
*SUBJECT: COMBINATION ALGORITHM
*AIM: FIND AND PRINT THE TOTAL COMBINATION OF A SET OF NUMBERS
*     A GOOD IMPLEMENTATION OF THIS ALGORITHM CAN BE USED TO SOLVE THE KNAPSACK PROBLEM
******************************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Print the elements of a collection 
//set - this is a vector containing the indices that define the combination
//the number of indices mustt be the same with the number of items to print from the collection
//Class T is the item type the container holds
template <class T>
void PrintSet(vector<int> set, vector<T> collection)
{
	cout<<'{';
	for(int a = 0; a < set.size(); a++)
	{
		cout<<collection[set[a]]<<", ";
	}
	cout<<'}'<<endl;
}

//Initializes the first combination of each new combination size.
//indexes - is the set containing the combination indexes.
void InitIndexes(vector<int> &indexes)
{
	for(int a = 0; a < indexes.size(); a++)
	{
		indexes[a] = a;		
	}
}

//Finds and prints all subsets(Combinations) of a certain set of elements.
//collection - is the collection whose combination need to be found.
//numberOfElements - number of elements in each combination.
//noUpperBound - true if to print from numberOfElements to N, where N is the cardinality of 'collection'.
//             - if false, prints combination of 'numberOfElements' elements only.
//Time Complexity: O(n^2) if 'noUpperBound' is true, else O(n)
//Class T is the type of elements
template <class T>
void PrintAllCombinations(const vector<T> collection, int numberOfElements = 0, bool noUpperBound = true)
{
	cout<<"Printing all subsets..."<<endl;
	//containing index of combination
	vector<int> indexes(numberOfElements);	
	int maxNumberOfElements = collection.size();
	int nCombinations = 0;

    if(!noUpperBound)
	{
		maxNumberOfElements = numberOfElements;
	}
	
	while(indexes.size() <= maxNumberOfElements)
	{
		InitIndexes(indexes);

		PrintSet(indexes, collection);
		nCombinations++;

		int b = collection.size(); //set cardinality
		int size = indexes.size();
		
		//a is the current index in indexes to start incrementing
		int a = size - 1; 	
		while(indexes.size() != 0)
		{
			indexes[a]++;
			//the max value an index in indexes can contain is index a + (b - size)
			//this because when the size of collection increases the max value increases, likewise when the size of 
			//indexes reduces
			if(indexes[a] > a + b - size)
			{
				if(a == 0) 
				{
					break;
				}
				a--;
				continue;
			}
			if(a == size - 1)
			{			
				//print if at the last index
				PrintSet(indexes, collection);
				nCombinations++;
			}else
			{
				a++;
				indexes[a] = indexes[a - 1];
			}		
		}
		indexes.push_back(0);
	}
	cout<<endl<<nCombinations<<" combinations printed!"<<endl;
}