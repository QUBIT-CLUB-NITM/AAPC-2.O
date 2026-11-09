#include <iostream>

using namespace std;

int scores[3][1005];
bool valid_judge[3];

int main() {
    int n;
    cin >> n;

    // Read scores for the 3 judges
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < n; i++) {
            cin >> scores[j][i];
            if (scores[j][i] != -1) {
                valid_judge[j] = true;
            }
        }
    }

    int best_team = 1;
    long long best_sum = 0;
    long long best_cnt = 0;

    // Find the team with the highest average score
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
                best_team = i + 1; // 1-based team ID
            }
        }
    }

    cout << best_team << endl;
    return 0;
}
