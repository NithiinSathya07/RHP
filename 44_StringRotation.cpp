//https://atcoder.jp/contests/abc103/tasks/abc103_b
//https://atcoder.jp/contests/abc103/submissions/79152459
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using ll = long long;
using namespace std;

void solve()
{
    string s,t; cin >> s >> t;
    string dt = t+t;
    cout << (dt.contains(s) ? "Yes" : "No") << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    while(tc--) solve();
    return 0;
}