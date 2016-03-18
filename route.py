total =0

child = 0

class Head():
	def __init__(self):
		self.link = child

	def add_link(self,obj):
		self.link = obj

	def get_link(self):
		return self.link


class Node(object):
	def __init__(self,data):
		self.data = data
		self.Leftchild = child
		self.Rightchild = child

	def add_Leftchild(self, obj):
		self.Leftchild = obj

	def add_Rightchild(self, obj):
		self.Rightchild = obj
	
	def get_data(self):
		return self.data	
	
	def get_Leftchild(self):
		return self.Leftchild

	def get_Rightchild(self):
		return self.Rightchild


def makehead(DLR,LDR,tree):
	root = DLR[0]
	print "%d : %d " %(total,root)
	temp = Node(root)
	tree.add_link(temp)

	maketree(DLR,LDR,temp,0)
#	print "%d %d " %(len(DLR),len(LDR))



def maketree(DLR,LDR,subtree,chk):
	print "IN"
	global total
	total = total+1
	
	root = DLR[0]
	temp = Node(root)
		
	if(chk ==1):
		subtree.add_Leftchild(temp)

	elif(chk ==2):
		subtree.add_Rightchild(temp)

	else:
		root = subtree.get_data()

	print "%d : %d " %(total,root)


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
			maketree(DLRleft,LDRleft,subtree,1)
		if(len(DLRright) != 0) or (len(DLRright) != 0):
			maketree(DLRright,LDRright,subtree,2)

def postHead(tree):
	print "start "
	root = tree.get_link()
	print "%d" %root.get_data()
	postOrder(root)


def postOrder(subtree):
	if(subtree):
		postOrder(subtree.get_Leftchild())
#postOrder(subtree.get_Rightchild())
		print subtree.get_data()


DLR=[3,6,5,4,8,7,1,2]
LDR=[5,6,8,4,3,1,2,7]

#DLR=[1,2,4,7,8,5,3,6,9]
#LDR=[7,4,8,2,5,1,3,9,6]


tree = Head()
#a= Node(5)
#print a.get_data()
#tree.add_link(a)
#print tree.get_link().get_data()

makehead(DLR,LDR,tree)
postHead(tree)
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
