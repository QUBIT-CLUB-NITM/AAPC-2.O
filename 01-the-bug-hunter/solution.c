#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int found = 0;
    for (int i = 0; i < n; i++) {
        int code;
        scanf("%d", &code);
        if (code == 404) {
            found = 1;
        }
    }

    printf("%d\n", found);
    return 0;
}
