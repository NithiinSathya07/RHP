//https://atcoder.jp/contests/abc218/tasks/abc218_e
//https://atcoder.jp/contests/abc218/submissions/78337390
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define ll long long int;
using namespace std;

int find(vector<int>& ldr, int node) {
    if (ldr[node] != node) {
            ldr[node] = find(ldr, ldr[node]);
        }
        return ldr[node];
}

void join(vector<int>& ldr, int lt, int rt) {
        ldr[find(ldr, rt)] = find(ldr, lt);
}

void solve()
{
    int N, E; cin >> N >> E;
    vector<int> ldr(N+1);
    vector<pair<int, pair<int,int>>> edges;
    for(int node=1; node<=N; node++) ldr[node] = node;

    while(E--)
    {
        int a,b,cost; cin >> a >> b >> cost;
        if(cost<=0)
        {
            join(ldr, a, b);
        }
        else
        {
            edges.push_back(make_pair(cost, make_pair(a, b)));
        }
    }

    long long int rewards = 0;
    sort(edges.begin(), edges.end());
    for(auto[cost,p]:edges)
    {
        int a = p.first, b = p.second;
        if(find(ldr,a)!=find(ldr,b))
        {
            join(ldr,a,b);
        }
        else
        {
            rewards += cost;
        }
    }
    cout << rewards << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    while(tc--) solve();
    return 0;
}