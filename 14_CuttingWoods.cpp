//https://atcoder.jp/contests/abc217/tasks/abc217_d
//https://atcoder.jp/contests/abc217/submissions/78311710
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define ll long long int;
#define INF 2e9
using namespace std;

void solve()
{
    int L, Q; cin >> L >> Q;
    set<int> st;
    st.insert(0); st.insert(L);
    while(Q--)
    {
        int qt,x; cin >> qt >> x;
        if(qt==1) st.insert(x);
        else
        {
            auto it = st.upper_bound(x);
            cout << *it - *(prev(it)) << endl;
        }
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