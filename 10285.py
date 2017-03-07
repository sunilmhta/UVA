# Problem : Longest Run on a Snowboard, Online Judge:UVA , ID:10285
# Author: Sunil Kumar, Status: Accepted
# This code finds the longest decreasing subsequence in a 2-D matrix
# Technique used here is DP
# DP[i][j] = 1 + max(neighbours of i,j with value less than matrix[i][j])
# else DP[i][j] = 1
def dfs(matrix,row,col):
	global ans
	if (row,col) in ans:
		return ans[(row,col)]
	neighbours=[(row-1,col),(row,col-1),(row,col+1),(row+1,col)]
	newlist=[dfs(matrix,x[0],x[1]) for x in neighbours if matrix[x[0]][x[1]] < matrix[row][col]]
	ans[(row,col)] = 1 + max(newlist) if newlist else 1
	return ans[(row,col)]

def function(matrix,row,col):
	global ans
	ans = {}
	for x in range(1,row+1):
		for y in range(1,col+1):
			if (x,y) not in ans:
				ans[(x,y)] = dfs(matrix,x,y)
	m=max(ans,key=ans.get)
	return	ans[m]

testcase = int(input())
while testcase:
	inp=input().split()
	name,row,col = inp[0],int(inp[1]),int(inp[2])
	matrix=[[500]*(col+2)]+[[500]+[int(x) for x in input().split()]+[500]for i in range(0,row)]+[[500]*(col+2)]
	print("%s: %s"%(name.strip(),function(matrix,row,col)))
	testcase -= 1