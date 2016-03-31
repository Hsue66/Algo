
# global var
total=0

def same(numbers):
	if (numbers[0] == numbers[1]) and (numbers[1] == numbers[2]):
		return 1
	else:
		return 0


def search(numbers):
	if len(numbers)==0:	# finish condition
		print total
	else:
		# split and check range
		subnumbers = numbers[0:3]
		if len(numbers)-3 == 1:
			subnumbers = numbers[0:4]
		elif len(numbers)-3 == 2:
			subnumbers = numbers[0:5]


		if same(subnumbers) == 1:
			for idx in range(2):
				if (len(numbers)-len(subnumbers) !=0) and (subnumbers[len(subnumbers)-1] == numbers[len(subnumbers)]):

#					if subnumbers[len(subnumbers)-1] == numbers[len(subnumbers)]:
					subnumbers = numbers[0:len(subnumbers)+1]
						
				else:
					break

		print subnumbers


if __name__=="__main__":
	testcase = input()
	
	for i in range(testcase):
		numbers = raw_input()

		search(numbers)	

