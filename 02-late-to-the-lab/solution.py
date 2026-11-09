def main():
    line = input().split()
    n = int(line[0])
    t = int(line[1])

    arrivals = list(map(int, input().split()))

    late_count = 0
    for time in arrivals:
        if time > t:
            late_count += 1

    print(late_count)


if __name__ == "__main__":
    main()
