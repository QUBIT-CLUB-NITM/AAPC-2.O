def main():
    n = int(input())

    judge1 = list(map(int, input().split()))
    judge2 = list(map(int, input().split()))
    judge3 = list(map(int, input().split()))

    judges = [judge1, judge2, judge3]

    # A judge is valid if they gave at least one score != -1
    valid_judges = [any(score != -1 for score in judge) for judge in judges]

    best_team = 1
    best_sum = 0
    best_cnt = 0

    for i in range(n):
        cur_sum = 0
        cur_cnt = 0

        for j in range(3):
            if valid_judges[j] and judges[j][i] != -1:
                cur_sum += judges[j][i]
                cur_cnt += 1

        # Compare averages using cross-multiplication: cur_sum * best_cnt > best_sum * cur_cnt
        if cur_cnt > 0:
            if best_cnt == 0 or cur_sum * best_cnt > best_sum * cur_cnt:
                best_sum = cur_sum
                best_cnt = cur_cnt
                best_team = i + 1

    print(best_team)


if __name__ == "__main__":
    main()
