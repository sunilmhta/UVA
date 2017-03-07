ans = {}
def longestPalindrome(inputStr):
	global ans
	if inputStr in ans:
		return ans[inputStr]
	if not inputStr:
		return 0
	if len(inputStr)==1:
		return 1
	if inputStr[0]==inputStr[-1]:
		ans[inputStr] = 2+longestPalindrome(inputStr[1:-1])
	else:
		ans[inputStr] = max(longestPalindrome(inputStr[1:]),longestPalindrome(inputStr[:-1]))
	return ans[inputStr]

testcases = int(input())
while testcases > 0:
	string = input()
	longestPalindrome(string)
	print(ans[string])
	ans={}
	testcases -= 1