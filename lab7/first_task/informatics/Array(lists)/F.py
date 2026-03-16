A = list(map(int, input().split()))
count = 0
for i in range(2, len(A)):
    if A[i] == A[i-2]:
        count += 1
print(count)
