/* Problem: Strategic Defense Initiative [Longest Increasing Subsequence]
 * ID: 497 UVA, Status: Accepted
 * Author: Sunil Kumar
 * Technique Used: DP
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void Solve(std::vector<int>& input)
{
	int totalElements = input.size();
	std::vector<int> index(totalElements,0); //stores the index of longest subsequence
	std::vector<int> LIS(totalElements,1); //LIS: longest increasing subsequence, used as DP
	int answer = 1; //Length of longest increasing subsequence in the input
	int rememberMaxIndex = 0; // ending index of answer
 	for (int i = 1; i < totalElements; ++i)
	{
		index[i] = i; //initially index of answer assumed to be itself
		for (int j = 0; j < i; ++j)
		{
			/* if present number (ith) is greater than number at jth
			 * input number (i > j) then it can  contribute in the longest
			 * increasing subsequence so check for it.
			 */
			if(input[i] > input[j])
			{
				LIS[i] = std::max(LIS[i],LIS[j]+1);
				/* if j the number contributes in the longest increasing
				 * subsequnce then remember the jth index
				 */
				if(LIS[i] == LIS[j]+1) index[i] = j;
			}
		}
		/* answer remembers the maximum number out of all the longest
		 * increasing subsequences ending at different locations
		 * within the array.
		 */
		answer = std::max(answer,LIS[i]);
		if(answer == LIS[i]) rememberMaxIndex = i;
	}
	LIS.clear(); //clears the DP array
	while(rememberMaxIndex >= 0)
	{
		int tempIndex = rememberMaxIndex;
		LIS.push_back(input[tempIndex]);
		rememberMaxIndex = index[rememberMaxIndex];
		if (tempIndex <= rememberMaxIndex)
			break;
	}

	std::cout<<"Max hits: " << answer << std::endl;
	for (auto i = LIS.rbegin(); i != LIS.rend(); ++i)
	{
		std::cout<<*i<<std::endl;
	}
}

int main(int argc, char const *argv[])
{
	int testacse = 1;
	std::cin>>testacse;
	std::string line="";
	std::getline(std::cin,line);
	int lineNumber = 0;
	int totalLines = testacse;
	std::vector<std::vector<int> > input(testacse,std::vector<int>());
	std::cin.ignore();
	while(testacse--)
	{
		std::string line="";
		/* Reading all the inputs*/
		while(std::getline(std::cin,line) && !line.empty()) input[lineNumber].push_back(std::stoi(line));
		++lineNumber;
	}

	for (int i = 0; i < totalLines; ++i)
	{
		Solve(input[i]); //will solve the longest increasing subsequence problem for given input array
		if(i < totalLines-1)
			std::cout<<std::endl;
	}

	return 0;
}