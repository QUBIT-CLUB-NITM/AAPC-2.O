#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);

    int scores[3][1000];
    bool valid_judge[3] = {false, false, false};

    // Read scores for 3 judges
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &scores[j][i]);
            if (scores[j][i] != -1) {
                valid_judge[j] = true;
            }
        }
    }

    int best_team = 1;
    long long best_sum = 0;
    long long best_cnt = 0;

    for (int i = 0; i < n; i++) {
        long long sum = 0;
        long long cnt = 0;

        for (int j = 0; j < 3; j++) {
            if (valid_judge[j] && scores[j][i] != -1) {
                sum += scores[j][i];
                cnt++;
            }
        }

        // Compare fractions using cross-multiplication: sum * best_cnt > best_sum * cnt
        if (cnt > 0) {
            if (best_cnt == 0 || sum * best_cnt > best_sum * cnt) {
                best_sum = sum;
                best_cnt = cnt;
                best_team = i + 1; // 1-based index
            }
        }
    }

    printf("%d\n", best_team);
    return 0;
}
