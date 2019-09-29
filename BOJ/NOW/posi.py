def solution2(A):
    # write your code in Python 3.6
    min = 0

    while(min+1 in A):
        min = min+1

    return min+1

def solution3(A):
    # write your code in Python 3.6
    A = list(set(sorted(A)))
    min = 0
    for a in A:
        if a <= 0:
            pass
        else:
            if min+1 == a:
                min = min+1
            else:
                break

    return min+1


def solution(s):
    list = []
    dicA = {}
    dicA[3] = 1;
    dicA[2]  = 0;
    dicA[3] = 3;
    print(dicA)


solution('1234')
