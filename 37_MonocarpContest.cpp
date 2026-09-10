//https://codeforces.com/problemset/problem/2260/A
//https://codeforces.com/problemset/submission/2260/390158958
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
    vector<int> arr(N);
    int oc = 0;
    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
        oc += arr[i];
    }
    int zc = N-oc;
    if(zc<2)
    {
        cout << "-1\n"; return;
    }
    //There are atleast 2 zeroes
    int ans = 0;
    if(arr[0]) ans++;
    if(arr[N-1]) ans++;
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