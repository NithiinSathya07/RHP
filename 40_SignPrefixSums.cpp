//https://codeforces.com/problemset/problem/2260/D
//https://codeforces.com/problemset/submission/2260/390182595
//This can be run in: C++23 (GCC 14-64, msys2)
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
using ll = long long;
using namespace std;

void solve()
{
    int N; string s; cin >> N >> s;
    if(s[0]=='0' || s.contains("00"))
    {
        cout << "-1" << endl; return;
    }
    int ans = -1;
    if(s.contains("+-") || s.contains("-+"))
    {
        if(s.contains("+--+") || s.contains("-++-"))
        {
            ans = 3;
        }
        else
        {
            ans = 2;
        }
    }
    else
    {
        ans = 1;
        for(int i=0; i<N; i+=2)
        {
            if(s[i]=='0')
            {
                ans = 2;
                break;
            }
        }
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