def main():
    line = input().split()
    n = int(line[0])
    k = int(line[1])

    a = list(map(int, input().split()))

    max_val = a[0]
    max_idx = 0
    for i in range(1, n):
        if a[i] > max_val:
            max_val = a[i]
            max_idx = i

    l = max_idx
    r = n - 1 - max_idx

    ops_l = (l + k - 1) // k if l > 0 else 0
    ops_r = (r + k - 1) // k if r > 0 else 0

    print(ops_l + ops_r)


if __name__ == "__main__":
    main()
