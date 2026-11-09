#include <iostream>

using namespace std;

int prices[100005];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    if (n <= 1) {
        cout << 0 << endl;
        return 0;
    }

    int min_price = prices[0];
    int max_profit = 0;

    for (int i = 1; i < n; i++) {
        int profit = prices[i] - min_price;
        if (profit > max_profit) {
            max_profit = profit;
        }
        if (prices[i] < min_price) {
            min_price = prices[i];
        }
    }

    cout << max_profit << endl;
    return 0;
}
