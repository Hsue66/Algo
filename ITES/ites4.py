#global var
number = 0
wish = 0
A = [1983]
List = [0]
first = 0
total = 0
now = 0

def makeNum(i):
	if len(A) < (i+1):
		A.append((A[i-1]*214013+2531011)%(2**32))
	return A[i-1]%10000+1

def find():
	global now,first,total
	idx = 1
	while idx <= number:
		temp = makeNum(idx)	
		List.append(temp)
		now = now + temp

		if wish == now:
			total = total +1
		elif wish < now:
		 	while now > wish:
				del List[first]
				now = now - List[first]
				if wish == now:
					total = total +1
		
		idx = idx+1
	print total

if __name__ == "__main__":
	testcase = input()

	for t in range(testcase):
		temp = raw_input()
		temp = temp.split(" ")
		wish = int(temp[0])
		number = int(temp[1])

		List = [0]
		first = 0
		total = 0
		now = 0

		find()
