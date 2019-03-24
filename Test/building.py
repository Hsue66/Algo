n = int(input())
Bs = []
for i in range(n):
    Bs.append(int(input()))

keys = sorted(set(Bs),reverse=True)

max = 0
for k in range(len(keys)):
    indices = [i for i, b in enumerate(Bs) if b == keys[k]]
    #print(indices)
    for p in range(len(indices)-1):
        if max < indices[p+1]-indices[p]:
            max = indices[p+1]-indices[p]
    if k < len(keys)-1:
        for p in indices:
            Bs[p] = keys[k+1]
        #print(Bs)

print(max)
