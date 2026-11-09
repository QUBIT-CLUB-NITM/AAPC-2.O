#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    long long max_val = -1;
    int max_idx = -1;

    for (int i = 0; i < n; i++) {
        long long val;
        scanf("%lld", &val);
        if (val > max_val) {
            max_val = val;
            max_idx = i;
        }
    }

    int left_count = max_idx;
    int right_count = n - 1 - max_idx;

    printf("%d %d\n", left_count, right_count);
    return 0;
}
