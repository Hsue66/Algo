import sys

testcase = input()

for t in range(testcase):
	temp = raw_input()
	temp = temp.split(" ")
		
	soldiers = []

	value = int(temp[0])
	for v in range(value):
		soldiers.append(v+1)
	skip = int(temp[1])

	idx =0
	del soldiers[idx]

	while len(soldiers)!=2:
		del soldiers[skip-1]
		soldiers = soldiers[skip-1:]+soldiers[0:skip-1]

	print "%d %d" %(soldiers[0],soldiers[1])

sys.exit(0)
