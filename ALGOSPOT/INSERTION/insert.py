# global var
move = []


if __name__ == "__main__":
	
	testcase = input()
	for i in range(testcase):
		length = input()
		move =[]
		arrange =[]
		original =[]
		
		temp = raw_input()
		temp = temp.split(" ")

		for j in range(length):
			move.append(int(temp[j]))
			arrange.append(j+1)
			original.append(0)

		for idx in range(length):
			now = length-1-idx
			point = length-1-idx-(move[now])
			original[now] = arrange[point]
			arrange = arrange[:point]+arrange[point+1:]

		answer = ""
		for idx in range(length):
			answer= answer+str(original[idx])+" "
		print answer
