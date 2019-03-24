total =0

class Head():
	def __init__(self):
		self.link = []

#	def

child = 0

class Node(object):
	def __init__(self,data):
		self.data = data
		self.Leftchild = child
		self.Rightchild = child

	def add_Leftchild(self, obj):
		self.Leftchild = obj

	def add_Rightchild(self, obj):
		self.Rightchild = obj
		
	def get_Leftchild(self):
		return self.Leftchild.data

#def makeheader(

def maketree(DLR,LDR):
	global total
	total = total+1
	root = DLR[0]
	print "%d : %d " %(total,root)
#	print "%d %d " %(len(DLR),len(LDR))

#	temp = Node(root)

	if(len(DLR) != 1) or (len(LDR) != 1):
#		print "%d IN" %(total)
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

			
		if(len(DLRleft) != 0) or (len(DLRleft) != 0):
			maketree(DLRleft,LDRleft)
		if(len(DLRright) != 0) or (len(DLRright) != 0):
			maketree(DLRright,LDRright)



DLR=[3,6,5,4,8,7,1,2]
LDR=[5,6,8,4,3,1,2,7]
maketree(DLR,LDR)
"""
print DLR[0]
val =DLR[0]
root = LDR.index(val)
left = LDR[:root]
right = LDR[root+1:]

index2 = len(left)
DLRleft = DLR[1:index2+1]
DLRright = DLR[index2+1:]



print DLRleft
print DLRright
print left
print right

n = Node(5)
b = Node(4)
c = Node(9)
n.add_Leftchild(b)
n.add_Rightchild(c)

print n.get_Leftchild()
"""
