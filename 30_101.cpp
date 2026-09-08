//https://codeforces.com/contest/2259/problem/C
//https://codeforces.com/contest/2259/submission/389835189
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
    for(int i=0; i<N; i++) cin >> arr[i];
    int lt = 0, rt = N-1;
    while(lt<N && arr[lt]==0) lt++;
    while(rt>=0 && arr[rt]==0) rt--;
    if(lt<=rt)
    {
        for(int i=lt+1; i<rt; i++)
        {
            if(arr[i]==-1) arr[i] = 0;
        }
        arr[lt] = arr[rt] = 1;
    }
    for(int i=0; i<N; i++) cout << arr[i] << (i==N-1 ?"\n" :" ");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}