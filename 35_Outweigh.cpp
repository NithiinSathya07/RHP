//https://atcoder.jp/contests/abc474/tasks/abc474_d
//https://atcoder.jp/contests/abc474/submissions/79092099
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
    vector<int> a(N), b(N);
    for(int i=0; i<N; i++) cin >> a[i];
    for(int i=0; i<N; i++) cin >> b[i];
    ll am = 0, bm = 0;
    for(int i=0; i<N; i++)
    {
        if(a[i]>b[i]) am+=(a[i]-b[i]);
        else if(b[i]>a[i]) bm += (b[i]-a[i]);
    }
    if(am==0)
    {
        cout << "No" << endl; return;
    }
    ll amweight = (bm/am) + 2;
    vector<ll> ans;
    for(int i=0; i<N; i++)
    {
        if(a[i]<=b[i]) ans.push_back(1);
        else ans.push_back(amweight);
    }
    cout << "Yes" << endl;
    for(ll wt : ans) cout << wt << " ";
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