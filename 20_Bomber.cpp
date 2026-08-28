//https://atcoder.jp/contests/abc472/tasks/abc472_d
//https://atcoder.jp/contests/abc472/submissions/78732868
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using ll = long long;
using namespace std;

void solve()
{
    int R,C,K; cin >> R >> C >> K;
    vector<string> g(R);
    for(int row=0; row<R; row++) cin >> g[row];
    vector<bool> br(R, false), bc(C, false);
    
    for(int row=0; row<R; row++)
    {
        for(int col=0; col<C; col++)
        {
            if(g[row][col]=='#')
            {
                br[row] = bc[col] = true;
            }
        }
    }

    queue<pair<int,int>> q;
    vector<vector<bool>> vis(R, vector<bool>(C,false));
    for(int row=0; row<R; row++)
    {
        for(int col=0; col<C; col++)
        {
            if(!br[row] && !bc[col])
            {
                q.push(make_pair(row,col));
                vis[row][col] = true;
            }
        }
    }

    int hops = 0, cellcnt = 0;
    const int diff[5] = {0,1,0,-1,0};
    while(!q.empty() && hops<=K)
    {
        hops++;
        int qsize = q.size();
        cellcnt+=qsize;
        while(qsize--)
        {
            auto[row,col] = q.front(); q.pop();
            for(int i=0; i<4; i++)
            {
                int ar = row+diff[i], ac = col+diff[i+1];
                if(ar>=0 && ar<R && ac>=0 && ac<C && !vis[ar][ac] && g[ar][ac]=='.')
                {
                    q.push(make_pair(ar,ac));
                    vis[ar][ac] = true;
                }
            }
        }
    }
    cout << cellcnt << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    while(tc--) solve();
    return 0;
}

