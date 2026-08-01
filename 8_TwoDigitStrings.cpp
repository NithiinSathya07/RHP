#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    string a, b;
    if (!(cin >> a >> b)) return;

    int R = a.length(), C = b.length();
    vector<int> pa(R + 1, 0), pb(C + 1, 0);

    for (int i = 1; i <= R; i++) {
        pa[i] = (pa[i - 1] + (a[i - 1] - '0')) % 10;
    }
    for (int i = 1; i <= C; i++) {
        pb[i] = (pb[i - 1] + (b[i - 1] - '0')) % 10;
    }

    // Total digit sum modulo 10 must match for both strings
    if (pa[R] != pb[C]) {
        cout << -1 << "\n";
        return;
    }

    // Standard LCS DP on prefix sums modulo 10
    vector<vector<int>> dp(R + 1, vector<int>(C + 1, 0));

    for (int row = 1; row <= R; row++) {
        for (int col = 1; col <= C; col++) {
            if (pa[row] == pb[col]) {
                dp[row][col] = 1 + dp[row - 1][col - 1];
            } else {
                dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]);
            }
        }
    }

    cout << dp[R][C] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;
    if (cin >> tc) {
        while (tc--) {
            solve();
        }
    }
    return 0;
}