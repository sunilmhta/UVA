 # Author: Sunil Kumar
 # Problem : Maximum sum of a subrectangle [in a matrix], ID: 108, Judge: UVA
 # Technique used: Kadane's algorithm
 # Time Complexity ; O(n^3)
ans=-15000000
def kadane(start,end,matrix):
	storelist=[sum(matrix[i][start:end+1]) for i in range(0,len(matrix))]
	maxendinghere=maxtillnow = storelist[0]
	for x in range(1,len(storelist)):
		maxendinghere = max(maxendinghere+storelist[x],storelist[x])
		maxtillnow = max(maxtillnow,maxendinghere)
	global ans
	ans=max(ans,maxtillnow)
	return

num=int(input())
matrix=[[int(x) for x in input().split()]for i in range(0,num)]
newlist=[[kadane(startcol,endcol,matrix) for endcol in range(0,num)]for startcol in range(0,num)]
print(ans)