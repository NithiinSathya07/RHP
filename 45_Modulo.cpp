//https://atcoder.jp/contests/abc103/tasks/abc103_c
//https://atcoder.jp/contests/abc103/submissions/79154227
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
    int temp = 0;
    int sum = 0;
    for(int i=0; i<N; i++)
    {
        cin >> temp;
        sum += temp;
    }
    cout << sum - N << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    while(tc--) solve();
    return 0;
}