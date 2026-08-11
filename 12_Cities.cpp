#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <string>
#define ll long long int;
using namespace std;

void solve()
{
    int R; cin >> R;
    map<int, vector<pair<int,int>>> g;
    set<int> vis;
    while(R--)
    {
        int src,dest,dist; cin >> src >> dest >> dist;
        g[src].push_back(make_pair(dest,dist));
        g[dest].push_back(make_pair(src,dist));
    }
    int st,end; cin >> st >> end;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0,st));

    while(!pq.empty())
    {
        auto[currdist, city] = pq.top(); pq.pop();
        if(vis.find(city)==vis.end())
        {
            vis.insert(city);
            if(city==end)
            {
                cout << currdist; return;
            }
            for(auto[oc,ocd]:g[city])
            {
                if(vis.find(oc)==vis.end())
                {
                    pq.push(make_pair(currdist+ocd,oc));
                }
            }
        }
    }
    cout << "City" << end << " cannot be reached from City " << st;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    while(tc--) solve();
    return 0;
}

// Problem Statement
// Given a directed, weighted graph represented by a set of edges, find the minimum weight path from a starting node to a destination node.

// Input:
// An integer representing the number of edges.
// A series of edges defined as (start_node, end_node, weight).
// A query pair (start, destination) to find the shortest path between.
// OUTPUT:
// The minimum distance from the start and destination

// Test Case:
//INPUT:
// 6
// 1 4 100
// 1 2 10
// 2 7 25
// 7 4 70
// 2 5 5
// 5 7 60
// 1 4
//OUTPUT:
// 100