//https://codeforces.com/contest/2259/problem/B
//https://codeforces.com/contest/2259/submission/389831718
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using ll = long long;
using namespace std;

void solve()
{
    int N; cin >> N;
    int odd = 0, eoq = 0, eeq = 0;
    for(int i=0; i<N; i++)
    {
        int curr; cin >> curr;
        if(curr&1) odd++;
        else
        {
            int q = curr/2;
            if(q&1) eoq++;
            else eeq++;
        }
    }
    cout << max(odd, max(eoq, eeq)) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}