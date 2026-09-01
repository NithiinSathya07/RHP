// https://atcoder.jp/contests/abc473/tasks/abc473_e
//https://atcoder.jp/contests/abc473/submissions/78888314
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;

void solve()
{
    int N, K; cin >> N >> K;
    vector<int> dp(N + 1, 0);
    ll rem = 0;
    map<int, int> m;
    m[0] = 0;
    
    for (int i = 1; i <= N; i++)
    {
        ll curr; 
        cin >> curr;
        rem = ((rem + curr) % K + K) % K;
        dp[i] = dp[i - 1];
        if (m.find(rem) != m.end())
        {
            dp[i] = max(dp[i], m[rem] + 1);
        }
        m[rem] = max(m[rem], dp[i]);
    }

    cout << dp[N] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc = 1;
    while (tc--) solve();
    
    return 0;
}