/* Author : Sunil Kumar
 * Problem : Cutting Sticks , ID: 10003,Online Judge : UVA, Accepted
 * Techniques Used: DP
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>
#include <climits>
#define  MAX 55
typedef std::vector<int> vi;
int dp[MAX+2][MAX+2];

int cost(int start,int end,const vi& pos)
{
	if(start < 0 || start >= MAX || end < 0 || end >= MAX || start >= end) return 0;
	if (dp[start][end] >= 0) return dp[start][end];
	if(start+1 >= end ) return dp[start][end] = 0;

	int currcost=INT_MAX;
	for (int i = start+1; i < end; ++i)
		currcost = std::min(cost(start,i,pos)+cost(i,end,pos)+(pos[end]-pos[start]),currcost);
	currcost == INT_MAX ? dp[start][end] = 0: dp[start][end] = currcost;
	return dp[start][end];
}

void solve(int length)
{
	std::memset(dp,-1,sizeof(dp));
	int numberofcuts;
	std::cin>>numberofcuts;
	vi positions(numberofcuts+2);
	positions[0] = 0;
	positions[numberofcuts+1] = length;
	for (int i = 1; i <= numberofcuts; ++i)
		std::cin>>positions[i];
	std::cout<<"The minimum cutting is "<<cost(0,numberofcuts+1,positions)<<".\n";
}


int main(int argc, char const *argv[])
{
	int length=1;
	std::cin>>length;
	while(length)
	{
		solve(length);
		std::cin>>length;
	}
	return 0;
}
