def main():
    n = int(input())
    codes = list(map(int, input().split()))

    if 404 in codes:
        print(1)
    else:
        print(0)


if __name__ == "__main__":
    main()
