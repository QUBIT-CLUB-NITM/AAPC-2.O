#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 1) {
        int dummy;
        for (int i = 0; i < n; i++) {
            scanf("%d", &dummy);
        }
        printf("0\n");
        return 0;
    }

    int min_price;
    scanf("%d", &min_price);

    int max_profit = 0;

    for (int i = 1; i < n; i++) {
        int price;
        scanf("%d", &price);

        int profit = price - min_price;
        if (profit > max_profit) {
            max_profit = profit;
        }
        if (price < min_price) {
            min_price = price;
        }
    }

    printf("%d\n", max_profit);
    return 0;
}
