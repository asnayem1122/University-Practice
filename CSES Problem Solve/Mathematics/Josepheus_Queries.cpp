#include <bits/stdc++.h>

using namespace std;

int solve(int n, int k) {
    // Base case: only one child left
    if (n == 1) return 1;

    // If k is in the first half (removing 2, 4, 6...)
    if (k <= (n + 1) / 2) {
        if (2 * k <= n) return 2 * k;
        else return 1; // Last element when n is odd
    }

    // If k is in the second half, we recurse
    int temp = solve(n / 2, k - (n + 1) / 2);
    
    if (n % 2 == 0) {
        // Even case: 1, 3, 5... map to 2x - 1
        return 2 * temp - 1;
    } else {
        // Odd case: 3, 5, 7... map to 2x + 1
        return 2 * temp + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }
    return 0;
}