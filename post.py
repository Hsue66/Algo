import sys

postarray = []

def makePostarray(num):
	for i in range(num):
		postarray.append(0)



def postorder(DLR,LDR,start,last):
	root = DLR[0]
	postarray[last] = root

	if(len(DLR) != 1) or (len(LDR) != 1):
		LDRleft=[]
		LDRright=[]
		DLRleft=[]
		DLRright=[]

		index = LDR.index(root)
		LDRleft = LDR[:index]
		LDRright = LDR[index+1:]

		index2 = len(LDRleft)+1
		DLRleft = DLR[1:index2]
		DLRright = DLR[index2:]
		
		if(len(DLRleft) != 0) or (len(LDRleft) != 0):
			postorder(DLRleft,LDRleft,start,last-len(LDRright)-1)
		if(len(DLRright) != 0) or (len(LDRright) != 0):
			postorder(DLRright,LDRright,last-len(LDRright),last-1)

def main():
	loop = input()
	for i in range(loop):
		global postarray
		length = input() 
		DLR = []
		LDR = []
		num1 = raw_input()
		num1.split(" ")

#	for j in range(length):
#			DLR.append(num1[j*2])
	
		num2 = raw_input()
		num2.split(" ")
#		for j in range(length):
#			LDR.append(num2[j*2])
		
		makePostarray(length)
		postorder(num1,num2,0,length-1)

#	print postarray
	
		val =""
		for i in range(length):
			val += postarray[i] +" "
		del postarray
		postarray=[]
		print val

if __name__=='__main__':
	sys.exit(main());


