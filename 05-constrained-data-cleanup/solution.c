#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

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

    int l = max_idx;
    int r = n - 1 - max_idx;

    int ops_l = (l > 0) ? (l + k - 1) / k : 0;
    int ops_r = (r > 0) ? (r + k - 1) / k : 0;

    printf("%d\n", ops_l + ops_r);
    return 0;
}
