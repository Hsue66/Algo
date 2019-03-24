arr = input()

wrong = 0
alpha = []
number = []

for i in range(len(arr)):
    if 'A' <= arr[i] and arr[i] <= 'Z':
        alpha.append(arr[i])

    elif 'a' <= arr[i] and arr[i] <= 'z':
        if len(alpha) <= 0:
            wrong = 1;
            break
        alpha[len(alpha)-1] = alpha[len(alpha)-1]+arr[i]

    elif arr[i] == '0':
        if len(number) <= 0:
            wrong = 1;
            break
        number[len(number)-1] = number[len(number)-1]+arr[i]

    elif '1' <= arr[i] and arr[i] <= '9':
        number.append(arr[i])

# print(alpha)
# print(number)

if len(number) <= 0 or len(alpha) <= 0 or len(alpha) != len(number):
    wrong = 1


result = '';
if wrong:
    result = 'error'
else:
    for l in range(len(alpha)):
        if len(alpha[l]) > 2:
            result = 'error'
            break;
        else:
            result = result+alpha[l]
            if(number[l] != '1'):
                result = result+number[l]

print(result)
