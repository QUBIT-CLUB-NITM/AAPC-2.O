#include <iostream>

using namespace std;

long long a[1000005];

int main() {
    int n, k;
    cin >> n >> k;

    long long max_val = -1;
    int max_idx = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > max_val) {
            max_val = a[i];
            max_idx = i;
        }
    }

    int l = max_idx;
    int r = n - 1 - max_idx;

    // Minimum operations to delete elements to the left and to the right
    int ops_l = (l > 0) ? (l + k - 1) / k : 0;
    int ops_r = (r > 0) ? (r + k - 1) / k : 0;

    cout << (ops_l + ops_r) << endl;
    return 0;
}
