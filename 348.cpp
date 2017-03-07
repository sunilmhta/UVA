/* Matrix Chain Multiplication
 * Problem ID: 348 Judge: UVA
 * Author: Sunil Kumar
 * Status: Accepted
 * Technique Used: DP
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>
typedef std::pair<int,int> pair;
typedef std::vector<pair> vp;
typedef std::vector<int> vi;
int caseNum = 0;
void PrintParenthesis(const std::vector<vi>& bracket,int start,int end)
{
	if (start==end)
	{
		std::cout<<"A"<<start;
		return;
	}
	std::cout<<"("; //left bracket
	PrintParenthesis(bracket,start,bracket[start][end]);
	std::cout<<" x "; //Multiplication sign
	PrintParenthesis(bracket,bracket[start][end]+1,end);
	std::cout<<")"; //right bracket
}

bool solve()
{
	int num;
	std::cin>>num;
	if(!num) return false;
	vp input(num+1,std::make_pair(0,0));//inputs initialized with (0,0)
	for (int i = 1; i < num+1; ++i)
		std::cin>>input[i].first >> input[i].second;

	std::vector<vi> cost(num+1,vi(num+1));
	for (int i = 0; i < num+1; ++i) //one length matrix multipliction cost=0
		cost[i][i] = 0;

	std::vector<vi> bracket(num+1,vi(num+1));
	for (int length = 2; length < num+1; ++length)
	{
		for (int startIndex = 1; startIndex < num+1-length+1; ++startIndex)
		{
			int endIndex = startIndex + length-1;
			cost[startIndex][endIndex] = INT_MAX;
			for (int breakPoint = startIndex; breakPoint < endIndex; ++breakPoint)
			{
				/* Mutilplication cost will be cost to multiply Left part
				 * plus Right part plus cost for two matrix obtained by resultant
				 * of these left and right parts.
				 */
				int bothCost = input[startIndex].first * input[breakPoint].second * input[endIndex].second;
				int currentCost = cost[startIndex][breakPoint]+cost[breakPoint+1][endIndex]+bothCost ;
				if (currentCost < cost[startIndex][endIndex])
				{
					cost[startIndex][endIndex] = currentCost;
					/* Each entry bracket[i][j] shows where to split the
					 * Product array i,i+1,i+2,...,j for the minimum cost
					 */
					bracket[startIndex][endIndex] = breakPoint;
				}
			}

		}
	}

	std::cout<<"Case "<<++caseNum<<": ";
	PrintParenthesis(bracket,1,num);
	std::cout<<std::endl;
	return true;
}

int main(int argc, char const *argv[])
{
	while(solve());
	return 0;
}