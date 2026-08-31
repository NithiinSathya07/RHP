//https://atcoder.jp/contests/abc473/tasks/abc473_c
//https://atcoder.jp/contests/abc473/submissions/78869999
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using ll = long long;
using namespace std;

void solve()
{
    int N,K; cin >> N >> K;
    vector<int> cnt(K+1,0);
    for(int s=1; s<=N; s++)
    {
        int cl; cin >> cl;
        cnt[cl]++;
    }
    int maxi =* max_element(cnt.begin(), cnt.end());
    int canjoin = 0;
    for(int cl=1; cl<=K; cl++)
    {
        if(cnt[cl]>=maxi-1)
        {
            canjoin++;
        }
    }

    cout << canjoin << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    while(tc--) solve();
    return 0;
}