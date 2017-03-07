# Author: Sunil Kumar
# Problem: Luggage ID: 10664 Online Judge: UVA
# Status: Accepted
# Technique Used: DP
testcase=int(input())
while testcase > 0:
	testcase = testcase -1
	inputlist=[int(x) for x in input().split()]
	reqwt=sum(inputlist)
	if reqwt%2 != 0:
		print('NO')
		continue
	possiblewt=[0]
	flag=0
	for x in inputlist:
		for y in range(0,len(possiblewt)):
			possiblewt.append(x+possiblewt[y])
		if reqwt/2 in possiblewt:
			print('YES')
			flag=1
			break
	if flag == 0:
		print('NO')
