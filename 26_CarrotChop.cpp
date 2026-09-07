//https://codeforces.com/contest/2258/problem/B1
//https://codeforces.com/contest/2258/submission/389708771
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using ll = long long;
using namespace std;

void solve()
{
    int N, M; cin >> N >> M;

    //Building Count Array.
    vector<int> cnt(M+1,0);
    for(int i=0; i<N; i++)
    {
        int curr; cin >> curr;
        cnt[curr]++;
    }

    //Building Prefix Sum Array.
    vector<int> psum(M+1,0);
    for(int i=1; i<=M; i++)
    {
        psum[i] = psum[i-1] + cnt[i];
    }

    int ans = 0;
    for(int x=1; x<=M; x++)
    {
        int carrotCnt = psum[M] - psum[x-1]; //Added once for 2x.
        if(2*x <= M)  // Added the value for the double the x value case.
        {
            carrotCnt += cnt[2*x];
        }
        ans = max(ans, carrotCnt);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}