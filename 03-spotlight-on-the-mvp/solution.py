def main():
    n = int(input())
    ratings = list(map(int, input().split()))

    max_val = ratings[0]
    max_idx = 0

    for i in range(1, n):
        if ratings[i] > max_val:
            max_val = ratings[i]
            max_idx = i

    left_count = max_idx
    right_count = n - 1 - max_idx

    print(left_count, right_count)


if __name__ == "__main__":
    main()
