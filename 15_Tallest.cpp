//https://atcoder.jp/contests/abc463/tasks/abc463_c
//https://atcoder.jp/contests/abc463/submissions/78313044
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define ll long long int;
using namespace std;

void solve()
{
    //N - Number of Takahashi 
    int N; cin >> N;
    vector<pair<int,int>> arr(N);
    for(int i=0; i<N; i++)
    {
        //ht - Height, lt - leaving time
        int ht, lt; cin >> ht >> lt;
        arr[i] = make_pair(ht,lt);
    }
    //Sorting in descending order
    sort(arr.begin(),arr.end(), greater<>());
    //prevt - previous time
    int prevt = 0;
    //ltarr - leaving time array, htarr - height array
    vector<int> ltarr, htarr;
    for(auto[ht,lt] : arr)
    {
        if(lt>prevt) 
        {
            prevt = lt;
            ltarr.push_back(lt);
            htarr.push_back(ht);
        }
    }
    //Q - Number of Queries
    int Q; cin >> Q;
    while(Q--)
    {
        //t - time
        int t; cin >> t;
        auto it = upper_bound(ltarr.begin(),ltarr.end(),t);
        int idx = it - ltarr.begin();
        //Maximum height of the Takahashi leaving at the time t;
        cout << htarr[idx] << endl;
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