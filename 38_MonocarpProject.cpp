//https://codeforces.com/problemset/problem/2260/B
//https://codeforces.com/problemset/submission/2260/390160854
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using ll = long long;
using namespace std;

void solve()
{
    ll x,y,k; cin >> x >> y >> k;
    ll ans = 0, ctr = 0;
    while(ctr<k)
    {
        ll rem = (y+ctr) % (x+ctr);
        if(rem == y-x) break;
        ans += rem; ctr++;
    }
    if(k>ctr)
    {
        ans += (k-ctr) * (y-x);
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