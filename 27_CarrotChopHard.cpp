//https://codeforces.com/contest/2258/problem/B2
//https://codeforces.com/contest/2258/submission/389714815
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using ll = long long unsigned int;
using namespace std;

void solve()
{
    int N, M; cin >> N >> M;

    //Building Count Array.
    vector<int> cnt(M+1,0);
    for(int i=1; i<=N; i++)
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

    vector<ll> ans(M+1,0);
    for(int cut=1; cut<=min(M,18); cut++)
    {
        ll maxc = 0;
        for(int x=1; x<=M; x++)
        {
            ll currc = 0;
            for(int mul=1; mul*x <= M; mul++)
            {
                int lt = mul*x, rt = lt+x-1;
                currc += min(1LL*mul, ((1LL<<cut) - 1)) * (psum[min(rt,M)] - psum[lt-1]);
            }
            if((1LL<<cut)*x<=M)
            {
                currc += cnt[(1LL<<cut)*x];
            }
            maxc = max(maxc, currc);
        }

        ans[cut] = maxc;
    }

    for(int cut=1; cut<=M; cut++)
    {
        cout << ans[min(cut, 18)] << (cut == M ?"\n" :" ");
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
} 