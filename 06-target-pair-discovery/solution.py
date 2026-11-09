def main():
    line1 = input().split()
    n = int(line1[0])
    target = int(line1[1])

    a = list(map(int, input().split()))

    # Map each value to a list of its 1-based indices
    pos = {}
    for i in range(n):
        if a[i] not in pos:
            pos[a[i]] = []
        pos[a[i]].append(i + 1)

    # Check each index i (from 1 to n)
    for i in range(n):
        needed = target - a[i]

        if needed in pos:
            for j in pos[needed]:
                if j > i + 1:
                    print(i + 1, j)
                    return

    print("-1 -1")


if __name__ == "__main__":
    main()
