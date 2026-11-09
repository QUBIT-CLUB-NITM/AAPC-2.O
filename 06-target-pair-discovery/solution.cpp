#include <iostream>
#include <map>

using namespace std;

long long a[200005];

int main() {
    int n;
    long long target;
    cin >> n >> target;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Store the first and second 1-based positions of each number
    map<long long, int> first_pos;
    map<long long, int> second_pos;

    for (int i = 0; i < n; i++) {
        if (first_pos.find(a[i]) == first_pos.end()) {
            first_pos[a[i]] = i + 1;
        } else if (second_pos.find(a[i]) == second_pos.end()) {
            second_pos[a[i]] = i + 1;
        }
    }

    // Find pair (i, j) with i < j such that a[i] + a[j] == target
    // We check i from 0 to n - 1 to minimize i first, then j
    for (int i = 0; i < n; i++) {
        long long needed = target - a[i];

        if (needed == a[i]) {
            if (second_pos.find(needed) != second_pos.end()) {
                cout << (i + 1) << " " << second_pos[needed] << endl;
                return 0;
            }
        } else {
            if (first_pos.find(needed) != first_pos.end()) {
                int j = first_pos[needed];
                if (j > i + 1) {
                    cout << (i + 1) << " " << j << endl;
                    return 0;
                }
            }
        }
    }

    cout << "-1 -1" << endl;
    return 0;
}
