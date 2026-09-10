//https://codeforces.com/problemset/problem/2260/C
//https://codeforces.com/problemset/submission/2260/390164582
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using ll = long long;
using namespace std;

void solve()
{
    int x,y; cin >> x >> y;
    int sum = x + y, rx=0, ry=0; //rx - Revised x value and ry - Revised y value
    for(int sh=30; sh>=0; sh--)
    {
        if((sum&(1<<sh))!=0)
        {
            //set bit means 1 in that position
            //we need to maximise x only then the operations will be minimum
            if((rx|1<<sh)<=x)
            {
                rx = rx|(1<<sh);
            }
            else
            {
                ry = ry|(1<<sh);
            }
        }
    }

    cout << sum << " " << x-rx << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}