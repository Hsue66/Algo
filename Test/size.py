import math

N = int(input())
pivot = math.floor(math.sqrt(N))

for i in range(pivot,0,-1):
    if N%i == 0:
        other = int(N/i)
        print(int(math.fabs(other-i)))
        break
