def main():
    n = int(input())
    prices = list(map(int, input().split()))

    if n <= 1:
        print(0)
        return

    min_price = prices[0]
    max_profit = 0

    for i in range(1, n):
        profit = prices[i] - min_price
        if profit > max_profit:
            max_profit = profit
        if prices[i] < min_price:
            min_price = prices[i]

    print(max_profit)


if __name__ == "__main__":
    main()
