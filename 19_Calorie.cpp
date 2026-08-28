//https://atcoder.jp/contests/abc472/tasks/abc472_c
//https://atcoder.jp/contests/abc472/submissions/78732472
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int N, M;
    ll K;
    if (!(cin >> N >> M >> K)) return;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<bool> eaten(N, false);
    ll current_sum = 0;

    for (int i = 0; i < N; ++i) {
        // Remove the calories of the snack from (i - M) days ago if it was eaten
        if (i >= M && eaten[i - M]) {
            current_sum -= A[i - M];
        }

        // Check if eating today's snack stays within calorie limit K
        if (current_sum + A[i] <= K) {
            eaten[i] = true;
            current_sum += A[i];
            cout << "Yes\n";
        } else {
            eaten[i] = false;
            cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}