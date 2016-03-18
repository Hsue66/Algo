# global var
result = 987654321
SWITCH = [[0,1,2],[3,7,9,11],[4,10,14,15],[0,4,5,6,7],[6,7,8,10,12],[0,2,14,15],[3,14,15],[4,5,7,14,15],[1,2,3,4,5],[3,4,5,9,13]]


def pushSwitch(CLOCK, sIdx, pushCnt, pushAcc):
	
	# copy
	subCLOCK=[0 for idx in range(16)]
	for idx in range(16):
		subCLOCK[idx] = CLOCK[idx]

	# update time
	if sIdx-1 == -1:
#		print "sidx"
		pass
	elif pushCnt == 0:
#		print "pushcnt"
		pass
	else:
		pushAcc = pushAcc + pushCnt

		for i in range(len(SWITCH[sIdx-1])):
			subCLOCK[SWITCH[sIdx-1][i]] = (subCLOCK[SWITCH[sIdx-1][i]]+(3*pushCnt))%12
			if subCLOCK[SWITCH[sIdx-1][i]] == 0:
				subCLOCK[SWITCH[sIdx-1][i]]=12
				

	TorF=0
	# check finish
	for	idx in range(16):
		if subCLOCK[idx]!=12:
			TorF = 1
			break

#	print pushAcc
#	print subCLOCK
	
	

	global result
	# finish or not
	if TorF == 0:
		if pushAcc < result:
			result = pushAcc
#			print "answer : %d" %result
#	elif sIdx == 10  and TorF==1 and result==987654321:
#		print "answer : -1"
	else:
#		print "for loop"
		if sIdx < 10:
			for idx in range(4):	
				pushSwitch(subCLOCK,sIdx+1,idx,pushAcc)
#		print "answer : %d" %result
		
		

		


if __name__ == "__main__":
	testcase = input()

	for t in range(testcase):
		value = raw_input()
		temp = value.split(" ")
		
		result = 987654321

		# make clock
		CLOCK=[0 for idx in range(16)]

		for idx in range(16):
			CLOCK[idx] = int(temp[idx])

		pushSwitch(CLOCK,0,0,0)

		if result==987654321:
			result =-1

		print "%d" %result

