#include <iostream>

using namespace std;

long long a[100005];

int main() {
    int n;
    cin >> n;

    long long max_val = -1;
    int max_idx = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > max_val) {
            max_val = a[i];
            max_idx = i;
        }
    }

    int left_count = max_idx;
    int right_count = n - 1 - max_idx;

    cout << left_count << " " << right_count << endl;
    return 0;
}
