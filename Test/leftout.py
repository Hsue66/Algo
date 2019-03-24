def inputT():
    size = int(input())
    Header = input().split(' ')

    Table = {}
    ids = []
    for i in range(size-1):
        temp = input().split(' ')
        Table[temp[0]] = {}
        ids.append(temp[0])
        for t in range(1,len(temp)):
            Table[temp[0]][Header[t]]=temp[t]

    return size,Header,ids,Table

sizeA,HeaderA,idsA,TableA = inputT()
sizeB,HeaderB,idsB,TableB = inputT()

idsA = sorted(idsA)
Header = HeaderA+HeaderB[1:]

print(" ".join(Header))
for elem in idsA:
    result = [elem]
    for h in Header[1:]:
        if elem in TableA and h in TableA[elem]:
            result.append(TableA[elem][h])
        elif elem in TableB and h in TableB[elem]:
            result.append(TableB[elem][h])
        else:
            result.append('NULL')
    print(" ".join(result))
