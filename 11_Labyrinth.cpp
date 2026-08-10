#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long int
using namespace std;

const int diff[5] = {0,-1,0,1,0};
string dir = "LURD";
string getPath(int R, int C, int prow, int pcol, vector<string>& g)
{
    string ans="";
    
    while(g[prow][pcol]!='A')
    {
        char ch = g[prow][pcol];
        ans += ch;
        if(ch=='L') pcol++;
        else if(ch=='R') pcol--;
        else if(ch=='U') prow++;
        else if(ch=='D') prow--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve()
{
    int R, C; cin >> R >> C;
    vector<string> g(R);
    for(int r=0; r<R; r++) cin >> g[r];
    queue<pair<int, int>> q;
    for(int row=0; row<R; row++)
    {
        for(int col=0; col<C; col++)
        {
            if(g[row][col]=='A')
            {
                q.push(make_pair(row,col));
                row = R;
                break;
            }
        }
    }
    int hops=-1,brow=-1,bcol=-1;
    bool found = false;
    while(!q.empty())
    {
        int qsize=q.size();
        hops++;
        if(found)
        {
            cout << "YES" << endl;
            cout << hops << endl;
            cout << getPath(R, C, brow, bcol, g);
            return;
        }
        while(qsize--)
        {
            auto[row,col] = q.front(); q.pop();
            for(int i=0; i<4; i++)
            {
                int ar = row+diff[i], ac = col+diff[i+1];
                if(ar>=0 && ar<R && ac>=0 && ac<C)
                {
                    if(g[ar][ac]=='.')
                    {
                        g[ar][ac]=dir[i];
                        q.push(make_pair(ar,ac));
                    }
                    else if(g[ar][ac]=='B')
                    {
                        g[ar][ac] = dir[i];
                        brow = ar;
                        bcol = ac;
                        found = true;
                        q.push(make_pair(ar,ac));
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    while(tc--) solve();
    return 0;
}