#include <iostream>

using namespace std;

int a[105];

int main() {
    int n;
    cin >> n;

    bool found = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 404) {
            found = true;
        }
    }

    if (found) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
