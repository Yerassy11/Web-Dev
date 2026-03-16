from collections import defaultdict

n, m = map(int, input().split())

# Словарь: слово -> список индексов
positions = defaultdict(list)

for i in range(1, n + 1):
    word = input().strip()
    positions[word].append(i)

for _ in range(m):
    query = input().strip()
    if query in positions:
        print(" ".join(map(str, positions[query])))
    else:
        print(-1)
