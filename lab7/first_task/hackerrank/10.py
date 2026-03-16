from itertools import combinations

def split_and_join(line):
    return "-".join(line.split())

if __name__ == '__main__':
    s, k = input().split()
    k = int(k)
    s = sorted(s)
    for i in range(1, k + 1):
        for combo in combinations(s, i):
            print("".join(combo))
