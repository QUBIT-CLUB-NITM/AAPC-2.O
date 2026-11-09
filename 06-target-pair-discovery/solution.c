#include <stdio.h>
#include <stdlib.h>

struct Element {
    long long val;
    int idx; // 1-based index
};

// Comparator to sort elements by value, then by index
int compare(const void *a, const void *b) {
    const struct Element *e1 = (const struct Element *)a;
    const struct Element *e2 = (const struct Element *)b;
    if (e1->val != e2->val) {
        return (e1->val < e2->val) ? -1 : 1;
    }
    return e1->idx - e2->idx;
}

// Find first index where element.val >= target
int lower_bound(struct Element arr[], int n, long long target) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid].val < target) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int main() {
    int n;
    long long target;
    if (scanf("%d %lld", &n, &target) != 2) {
        return 0;
    }

    long long *a = (long long *)malloc(n * sizeof(long long));
    struct Element *arr = (struct Element *)malloc(n * sizeof(struct Element));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        arr[i].val = a[i];
        arr[i].idx = i + 1; // 1-based index
    }

    qsort(arr, n, sizeof(struct Element), compare);

    // Check each index i (from 1 to n)
    for (int i = 0; i < n; i++) {
        long long needed = target - a[i];
        int pos = lower_bound(arr, n, needed);

        // Check matching elements with val == needed
        while (pos < n && arr[pos].val == needed) {
            if (arr[pos].idx > i + 1) {
                printf("%d %d\n", i + 1, arr[pos].idx);
                free(a);
                free(arr);
                return 0;
            }
            pos++;
        }
    }

    printf("-1 -1\n");
    free(a);
    free(arr);
    return 0;
}
