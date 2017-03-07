/* Problem: Longest Palindrome Length in a string
 * ID: 11151 UVA, Status: Accepted
 * Author: Sunil Kumar
 * Technique Used: DP
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <map> //std::map
#include <string>
#include <utility> //std::pair

int longestPalindrome(std::string input,std::map<std::string, int> &ans)
{
	if(ans.count(input)) return ans.at(input); //if it is already in the memory return it
	int length=input.length();
	int tempAns=0; //will hold the answer temporarily
	if(!length) return 0; //blank input hence longest palindrome = 0
	else if(length == 1) tempAns=1; // if single character then palindrome length = 1
	 /* If length > 2 and first character = last character then longest
	  * palindrome = 2 + remaining string's longest palindrome
	  */
	else if(input[0] == input.back()) tempAns = 2+longestPalindrome(input.substr(1,length-2),ans);
	 /* If length > 2 and first character != last character then longest
	  * palindrome is equal to longer palindrome out of two substrings' palindrome namely
	  * first substring: when first character is taken with last character not taken
	  * second substring: when first character is not taken with last character taken
	  */
	else tempAns = std::max(longestPalindrome(input.substr(0,length-1),ans),longestPalindrome(input.substr(1,length-1),ans));
	ans[input] = tempAns; //Memoize this answer corresponding to this input string
	return ans[input];
}

int main(int argc, char const *argv[])
{
	std::map<std::string, int> ans; //used for memoization
	int testcase;
	std::cin>>testcase;
	std::vector<std::string> v(testcase);
	std::cin.ignore(); //here new line is ignored as an input
	for (int i = 0; i < testcase; ++i)
	{
		std::string str="";
		std::getline(std::cin, str); //if input line is blank it will read that line too as one input
		v[i] = str;
	}

	for (int i = 0; i < testcase; ++i)
	{
		std::cout<<longestPalindrome(v[i],ans) << std::endl;
		ans.clear();
	}
	return 0;
}