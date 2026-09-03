//https://codeforces.com/problemset/problem/2157/E
//https://codeforces.com/contest/2157/submission/389282466
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using ll = long long;
using namespace std;

void solve()
{
    int N,K,curr; cin >> N >> K;
    vector<int> cnt(N+N+N+1, 0);
    for(int i=0; i<N; i++)
    {
        cin >> curr;
        cnt[curr]++;
    }
    int ans = 0;
    for(int val=1; val<=N+N+1; val++)
    {
        int curr = val;
        while(cnt[curr]>K)
        {
            cnt[curr+1] += cnt[curr] - 1;
            cnt[curr] = 1;
            curr++;
        }
        ans = max(ans,curr-val);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while(tc--) solve();
    return 0;
}