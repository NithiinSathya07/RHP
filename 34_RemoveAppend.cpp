//https://atcoder.jp/contests/abc474/tasks/abc474_c
//https://atcoder.jp/contests/abc474/submissions/79090760
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using ll = long long;
using namespace std;

void solve()
{
    int N,Q; cin >> N >> Q;
    vector<int> pos(N+1, 0);
    for(int p=1; p<=N; p++)
    {
        int curr; cin >> curr;
        pos[curr] = p;
    }
    int nextpos = N+1; 
    while(Q--)
    {
        int val; cin >> val;
        pos[val] = nextpos++;
    }
    vector<pair<int,int>> arr;
    for(int val=1; val<=N; val++)
    {
        arr.push_back(make_pair(pos[val], val));
    }
    sort(arr.begin(), arr.end());
    for(auto[pos,val] : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    while(tc--) solve();
    return 0;
}