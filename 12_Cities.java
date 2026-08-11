import java.util.*;

class Main
{
    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt();
        Map<Integer, List<int[]>> g = new HashMap<>();
        while(R-- > 0)
        {
            int a = sc.nextInt(), b = sc.nextInt(), dist = sc.nextInt();
            if(!g.containsKey(a))
            {
                g.put(a, new ArrayList<>());
            }
            g.get(a).add(new int[]{b, dist});
            if(!g.containsKey(b)) g.put(b,new ArrayList<>());
            g.get(b).add(new int[]{a,dist});
        }
        int st = sc.nextInt(), end = sc.nextInt();
        Set<Integer> vis = new HashSet<>();
        //Min Heap
        PriorityQueue<int[]> pq = new PriorityQueue<>((x,y)->{return x[1]-y[1];});
        pq.add(new int[]{st,0});
        while(!pq.isEmpty())
        {
            int[] curr = pq.poll();
            int currCity = curr[0], currDist = curr[1];
            if(currCity==end)
            {
                System.out.println(currDist); return;
            }
            if(vis.contains(currCity)) continue;

            vis.add(currCity);
            if(g.containsKey(currCity))
            {
                for(int ocarr[] : g.get(currCity))
                {
                    int oc = ocarr[0], ocd = ocarr[1];
                    if(!vis.contains(oc))
                    {
                        pq.add(new int[]{oc, ocd+currDist});
                    }
                }
            }
        }
        sc.close();
    }
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