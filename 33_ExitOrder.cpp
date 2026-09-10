//https://atcoder.jp/contests/abc474/tasks/abc474_b
//https://atcoder.jp/contests/abc474/submissions/79090008
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
    int st = 1, end = 10;
    for(int ctr=1; ctr<=N; ctr++)
    {
        int curr; cin >> curr;
        if(!(curr>=st && curr<=end))
        {
            cout << "No" << endl; return;
        }
        if(ctr%10==0)
        {
            st+=10; end+=10;
        }
    }
    cout << "Yes" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    while(tc--) solve();
    return 0;
}