/*Author: Promise Anendah
 *Date: November 2019
 *From December 2017 Combination Code
 */

#include <iostream>

using namespace std;

void Print(int* arr, int size)
{
	cout<<"{";
	for(int a = 0; a < size; a++)
	{
		cout<<arr[a]<<", ";
	}
	cout<<"}"<<endl;
}

/*
Generates 'n' combination 'r'
Can be used to generate all combinations of a set (r = 0 ... r = n)
n - is the number of items you are getting combination from
r - is the cardinality of the combination

Time Complexity: O(n)
*/
void PrintCombination(int n, int r)
{
	int* arr = new int[r];
	//initialize the array with first combination	
	for(int i = 0; i < r; i++)
	{
		arr[i] = i;
	}
	Print(arr, r);

	//generate the other combinations
	//a is current index in combination
	int a = r - 1;
	while(r > 0)
	{
		arr[a]++;
		//the maximum value an index can contain is a + (n - r)
		if(arr[a] > a + n - r)
		{
			//when the item at index a has reached its maximum value
			if(a == 0)
			{
				//if this is the first item in the combination 
				break;
			}
			a--;
			continue;
		}
		if(a == r - 1)
		{
			//print if at the last index
			Print(arr, r);
		}else
		{
			a++;
			arr[a] = arr[a - 1];
		}
	}
}

int main()
{
	int n = 5;
	int r = 2;
	for(int r = 0; r < n; r++)
	{
		cout<<"Printing "<<5<<" Combination "<<r<<endl;
		PrintCombination(n, r);
	}	

	return 0;
}