

if __name__ == "__main__":
	testcase = input()

	for t in range(testcase):
		pattern = raw_input()
		samples = []
		number = input()
		
		for i in range(number):
			temp = raw_input()
			samples.append(temp)

		print pattern
		print samples
