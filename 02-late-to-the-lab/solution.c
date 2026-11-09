#include <stdio.h>

int main() {
    int n, t;
    scanf("%d %d", &n, &t);

    int late_count = 0;
    for (int i = 0; i < n; i++) {
        int arrival;
        scanf("%d", &arrival);
        if (arrival > t) {
            late_count++;
        }
    }

    printf("%d\n", late_count);
    return 0;
}
