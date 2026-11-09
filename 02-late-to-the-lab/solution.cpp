#include <iostream>

using namespace std;

int a[100005];

int main() {
    int n, t;
    cin >> n >> t;

    int late_count = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > t) {
            late_count++;
        }
    }

    cout << late_count << endl;
    return 0;
}
