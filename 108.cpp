/* Author: Sunil Kumar
 * Problem : Maximum sum of a subrectangle [in a matrix], ID: 108, Judge: UVA
 * Technique used: Kadane's algorithm
 * Time Complexity ; O(n^3)
 */
#include <iostream>
#include <algorithm>
#include <utility>
#include <climits>
#include <vector>

typedef std::pair<int,int> pair;
typedef std::vector<int> vi;
typedef std::vector<vi > vii;

int maxans = INT_MIN;

void kadane(int start,int end,const vii& matrix)
{
	vi store(matrix.size(),0);
	for (int row=0;row<matrix.size();row++)
		for (int col = start; col <= end; ++col)
			store[row] += matrix[row][col];

	// Printvector(store,0,store.size()-1);
	int maxendingHere=store[0];
	int maxsoFar=store[0];
	int first=0,last=0,rememberIndex=0; //rememberIndex is for remebering the max sum subarray to

	for (int i = 1; i < store.size(); ++i)
	{
		maxendingHere = std::max(store[i],store[i]+maxendingHere);
		maxsoFar = std::max(maxsoFar,maxendingHere);
		//following code is used to remeber the max sum subarray
		// if (store[i] == maxendingHere)
		// 	rememberIndex = i;

		// if (maxendingHere == maxsoFar)
		// {
		// 	first = rememberIndex;
		// 	last = i;
		// }
	}
	maxans = std::max(maxans,maxsoFar); //change globally

	return;
}



int main(int argc, char const *argv[])
{
	int rows;
	std::cin>>rows;
	vii matrix(rows,vi(rows));
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < rows; ++j)
			std::cin>>matrix[i][j];

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < rows; ++j)
			kadane(i,j,matrix);

	std::cout<<maxans<<std::endl;

	return 0;
}