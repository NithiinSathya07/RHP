// https://atcoder.jp/contests/abc058/tasks/arc071_a
//https://atcoder.jp/contests/abc058/submissions/79132174
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
    vector<int> cmn(26, 50);
    for(int ctr=1; ctr<=N; ctr++)
    {
        string s; cin >> s;
        vector<int> curr(26, 0);
        for(char ch : s)
        {
            curr[(ch-'a')]++;
        }
        for(int i=0; i<26; i++)
        {
            cmn[i] = min(cmn[i], curr[i]);
        }
    }
    for(int i=0; i<26; i++)
    {
        while(cmn[i]--)
            cout << (char) ('a'+i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    while(tc--) solve();
    return 0;
}